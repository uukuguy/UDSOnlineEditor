// HttpRequest.cpp : HttpRequest µÄÊµÏÖ

#include "stdafx.h"
#include "HttpRequest.h"
#include <stdlib.h>
#include <urlmon.h>
#include <atlwin.h>

#pragma comment(lib, "Wininet.lib")
#pragma comment(lib, "Urlmon.lib")

STDMETHODIMP HttpRequest::Send(IHttpResponse** pVal)
{
    
	HRESULT hr=S_OK;
    
	ATLASSERT(pVal);
	(*pVal)=NULL;
	if(!this->m_szUrl || _tcslen(this->m_szUrl)==0) {
		InfoMsgBox(_T("请先指定请求的目标URL地址！"));
		return hr;
	}
    
	//显示进度
	rcContext.hOpen=this->m_hOpen;
	rcContext.dwPostFileLength=0;
	rcContext.dwPostedLength=0;
	rcContext.dwContentLength=0;
	rcContext.dwReceivedLength=0;
	if (this->m_blShowRequestProgress){
		ZeroMemory(rcContext.szMemo,sizeof(rcContext.szMemo));//STRLEN_DEFAULT);
		_tcscpy_s(rcContext.szMemo,_T("请稍候，正在准备连接..."));
		rcContext.hThread=CreateThread(NULL, 0,(LPTHREAD_START_ROUTINE)ProgressDialog,0,0,&(rcContext.dwThreadID));
	}

	//请求方法
	TCHAR szUrl[STRLEN_4K]={0};
	_tcscpy_s(szUrl,m_szUrl);
	TCHAR szMethod[STRLEN_SMALL]=_T("POST");
	if(this->m_szMethod && _tcslen(this->m_szMethod)>0){
		ZeroMemory(szMethod,sizeof(szMethod));
		_tcscpy_s(szMethod,m_szMethod);
	}

	//±äÁ¿¶¨Òå
	DWORD dwError=0;
	DWORD dwFlags=0;
	HINTERNET hConnect=0;			//Internet»á»°
	HINTERNET hRequest=0;			//InternetÁ¬½Ó
	INTERNET_PORT dwPort;

	BOOL postFileFlag=FALSE;	//ÊÇ·ñÓÐÓÐÐ§µÄÌá½»ÎÄ¼þ¡£
	HANDLE hPostFile=0;
	DWORD dwPostFileSize=0;

	BOOL sendRequestSucceeded=TRUE;	//·¢ËÍÇëÇóÊÇ·ñ³É¹¦

	DWORD dwSize=0;

	DWORD dwStatusCode=0;	//httpÇëÇóÏìÓ¦´úÂë
	DWORD dwContentLength=0;	//httpÇëÇóÏìÓ¦ÄÚÈÝ³¤¶È
	DWORD dwErrorCode=0;	//httpÇëÇóÏìÓ¦´íÎóÂë
	TCHAR szContentType[STRLEN_DEFAULT]={0};	//httpÇëÇóÏìÓ¦ÄÚÈÝÀàÐÍ
	CComBSTR szResText(L"");				//httpÇëÇóÏìÓ¦·µ»Ø½á¹ûÎÄ±¾
	TCHAR* szHeader=NULL;	//httpÇëÇóÏìÓ¦Í·ÐÅÏ¢

	BOOL getHeanderSucceeded=TRUE;	//»ñÈ¡httpÇëÇóÏìÓ¦Í·ÐÅÏ¢ÊÇ·ñ³É¹¦

	char readBuffer[STRLEN_1K]={0};	//Ã¿´Î¶ÁÈ¡µÄÏìÓ¦ÄÚÈÝ
	DWORD dwCalcLength=0;	//Í¨¹ýÄÚÈÝ¼ÆËã³öÀ´µÄContentLength
	
	BOOL responseFileFlag=FALSE;	//ÊÇ·ñÓÐÓÐÐ§µÄÏìÓ¦ÄÚÈÝ±¾µØ±£´æÎÄ¼þ
	HANDLE hResponseFile=0;	//ÇëÇóÏìÓ¦ÄÚÈÝ±£´æµ½±¾µØÎÄ¼þµÄÎÄ¼þ¾ä±ú

	int requestCount=1;	//ÇëÇó´ÎÊý
	
	TCHAR szAccept[] = _T("*/*");
	LPTSTR AcceptTypes[2]={0};
	AcceptTypes[0]=szAccept;
	AcceptTypes[1]=NULL;

	
	CComPtr<IHttpResponse> response;	//ÇëÇóÏìÓ¦¶ÔÏó

	//Á¬½Ó
	dwPort=this->m_usUrlPort;	//¶Ë¿ÚºÅ
	dwFlags= INTERNET_FLAG_NO_CACHE_WRITE | INTERNET_FLAG_RELOAD |INTERNET_FLAG_KEEP_CONNECTION;
	if (this->m_blUrlIsSSL) dwFlags |= INTERNET_FLAG_SECURE | INTERNET_FLAG_IGNORE_CERT_CN_INVALID | INTERNET_FLAG_IGNORE_CERT_DATE_INVALID;
	
	//´ò¿ªÁ¬½Ó
	if ( !(hConnect = InternetConnect(this->m_hOpen,this->m_szUrlHost , dwPort, _T(""),  _T(""), INTERNET_SERVICE_HTTP, 0, (DWORD)&rcContext))){
		dwError=GetLastError();
		ErrorMsgBox(dwError,_T("Internet连接错误：%s"));
		goto clean;
	}
	
reconnect:
	//´ò¿ªÇëÇó
	if ( !(hRequest = HttpOpenRequest(hConnect,this->m_szMethod,this->m_szUrlFile, _T("HTTP/1.1"), _T(""),(LPCTSTR*)AcceptTypes, dwFlags ,(DWORD)&rcContext))){
		dwError=GetLastError();
		ErrorMsgBox(dwError,_T("Internet打开请求错误：%s"));
		goto clean;
	}
	
	//ÓÐÖ¸¶¨Ìá½»ÎÄ¼þ
	if (this->m_szPostFile && _tcslen(this->m_szPostFile)) {
		postFileFlag=PathFileExists(this->m_szPostFile);
	}
	
	//Èç¹ûÓÐÌá½»µÄÎÄ¼þ
	if(postFileFlag) {
		if ((hPostFile = CreateFile(this->m_szPostFile,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,(HANDLE)NULL)) == (HANDLE)(-1))
		{
			dwError=GetLastError();
			ErrorMsgBox(dwError,_T("提交的文件不存在或者无法打开：%s"));			
			goto clean;
		}        
		dwPostFileSize=GetFileSize(hPostFile,NULL);
		rcContext.dwPostFileLength=dwPostFileSize;
		TCHAR szPostFileSize[STRLEN_SMALL]={0};
		_stprintf_s(szPostFileSize,_T("%d"),dwPostFileSize);
		this->AddHeader(T2BSTR(_T("Content-Length")),T2BSTR(szPostFileSize));
	}
	
	//ÉèÖÃÇëÇóÍ·
	if (this->m_szHeader && _tcslen(this->m_szHeader)) {
		if (!HttpAddRequestHeaders(hRequest,this->m_szHeader,-1L,HTTP_ADDREQ_FLAG_REPLACE | HTTP_ADDREQ_FLAG_ADD)){
			dwError=GetLastError();
			ErrorMsgBox(dwError,_T("设置请求头错误：%s"));
			goto clean;
		}
	}
	/*
	InternetSetOption(FhRequest,     
                  INTERNET_OPTION_CLIENT_CERT_CONTEXT,   
                  (LPVOID)pdDesiredCert,     
                  sizeof(CERT_CONTEXT));   
 INTERNET_FLAG_KEEP_CONNECTION£¬INTERNET_FLAG_EXISTING_CONNECT
	*/
	//´¦Àí¶îÍâÉèÖÃ£¨ºöÂÔÒ»Ð©´íÎó£©
	dwFlags=0;
	dwFlags |= SECURITY_FLAG_IGNORE_UNKNOWN_CA|SECURITY_FLAG_IGNORE_REVOCATION|SECURITY_FLAG_IGNORE_REDIRECT_TO_HTTP|SECURITY_FLAG_IGNORE_REDIRECT_TO_HTTPS|SECURITY_FLAG_IGNORE_CERT_DATE_INVALID|SECURITY_FLAG_IGNORE_CERT_CN_INVALID;
	if (!InternetSetOption (hRequest, INTERNET_OPTION_SECURITY_FLAGS,&dwFlags,sizeof(dwFlags))){
		dwError=GetLastError();
		ErrorMsgBox(dwError,_T("设置请求选项错误：%s"));
		goto clean;
	}
	
	//·¢ËÍÇëÇó
again:
	if(postFileFlag){	//ÓÐÌá½»ÎÄ¼þÄÚÈÝ
		INTERNET_BUFFERS BufferIn = {0};
		DWORD dwBytesWritten;
		BYTE bts[STRLEN_1K]={0};
		DWORD dwBtsRead=0;
		DWORD dwTotalBytes=0;

		BufferIn.dwStructSize = sizeof(INTERNET_BUFFERS);
		BufferIn.Next=NULL;
		BufferIn.dwBufferTotal=dwPostFileSize;

		sendRequestSucceeded=HttpSendRequestEx(hRequest, &BufferIn, NULL, HSR_INITIATE,(DWORD)&rcContext);
		
		while(ReadFile(hPostFile, bts, STRLEN_1K, &dwBtsRead, NULL) && dwBtsRead>0 && dwTotalBytes<=dwPostFileSize){
			if (!InternetWriteFile(hRequest, bts,dwBtsRead, &dwBytesWritten))
			{
				dwError=GetLastError();
				ErrorMsgBox(dwError,_T("发送文件内容错误：%s"));
				goto clean;
			}
			dwTotalBytes+=dwBtsRead;
			rcContext.dwPostedLength=dwTotalBytes;
		}
		
		if(!HttpEndRequest(hRequest, NULL, 0, 0))
		{
			dwError=GetLastError();
			ErrorMsgBox(dwError,_T("关闭HTTP连接时错误：%s"));
			goto clean;
		}
	}//if end
	else{	//Ã»ÓÐÌá½»ÎÄ¼þÄÚÈÝ
		sendRequestSucceeded=HttpSendRequest(hRequest, NULL, 0, NULL, 0);
	}	//else end

	//²é¿´ÊÇ·ñÇëÇó·¢ËÍ³É¹¦
	if (!sendRequestSucceeded){
		dwError=GetLastError();
		switch(dwError){
			case ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED:
				if(InternetErrorDlg(GetDesktopWindow(),hRequest,ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED,FLAGS_ERROR_UI_FILTER_FOR_ERRORS|FLAGS_ERROR_UI_FLAGS_GENERATE_DATA|FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS,NULL)!=ERROR_SUCCESS)
				{
					requestCount++;
					if (requestCount>2) {
						InfoMsgBox(_T("已经尝试发送请求操作2次仍无法成功，请联系系统管理员！"));
						goto clean;
					}	//Èç¹ûÑ­»·ÇëÇó´ÎÊý¶àÓÚÁ½´Î£¬ÄÇÃ´²»ÔÙÑ­»·
					else goto again;
				}
				break;
			case ERROR_SUCCESS:
				break;
			default:
				ErrorMsgBox(dwError,_T("发送请求错误：%s"));
				goto clean;
		}//switch end
	}//if end

	//È¡ÏìÓ¦×´Ì¬ÏûÏ¢
	dwSize= sizeof(DWORD);
	if (!HttpQueryInfo(hRequest,HTTP_QUERY_STATUS_CODE | HTTP_QUERY_FLAG_NUMBER, &dwStatusCode, &dwSize, NULL))
	{
		dwError=GetLastError();
		ErrorMsgBox(dwError,_T("获取响应代码错误：%s"));
		goto clean;
	}

	switch(dwStatusCode){
		case HTTP_STATUS_DENIED:	//ÐèÒªµÇÂ¼
		case HTTP_STATUS_PROXY_AUTH_REQ:
			InfoMsgBox(_T("请求的地址需要登录，请您先登录后再发送请求！"));
			goto clean;
		case HTTP_STATUS_REDIRECT:	//ÖØ¶¨Ïò
		case HTTP_STATUS_MOVED:
			{
				TCHAR szRedirect[4096]={0};
				DWORD dwRedirect=sizeof(szRedirect);
				if (!HttpQueryInfo(hRequest,HTTP_QUERY_LOCATION,(LPVOID)szRedirect,&dwRedirect,NULL)){
					dwError=GetLastError();
					ErrorMsgBox(hr,_T("获取重定向地址错误：%s"));
					goto clean;
				}
				this->put_Url(szRedirect);
				//ÏÈ¹Ø±ÕÁ¬½ÓºÍÇëÇó£¬È»ºóÖØÐÂÁ¬½Ó
				if (!InternetCloseHandle(hRequest))
				{
					dwError=GetLastError();
					ErrorMsgBox(dwError,_T("关闭HTTP请求错误：%s"));
					goto clean;
				}
				//if (!InternetCloseHandle(hConnect))
				//{
				//	dwError=GetLastError();
				//	ErrorMsgBox(dwError,_T("关闭HTTP连接错误：%s"));
				//	goto clean;
				//}
				//MessageBox(0,szRedirect,_T("重定向"),0);
				goto reconnect;
			}
		case HTTP_STATUS_OK:
		default:
			break;
	}

	//¹¹ÔìÇëÇóÏìÓ¦¡£
	response.p=NULL;
	hr=response.CoCreateInstance(_T("YRExchange.HttpResponse"));
	if (FAILED(hr)) {
		ErrorMsgBox(hr,_T("创建HttpResponse错误：%s"));
		goto clean;
	}
	response->put_StatusCode(dwStatusCode);
	response->put_ErrorCode(dwError);

	//ÏìÓ¦ÄÚÈÝ´óÐ¡
	dwSize=sizeof(dwContentLength);
	if (HttpQueryInfo(hRequest,HTTP_QUERY_CONTENT_LENGTH | HTTP_QUERY_FLAG_NUMBER ,&dwContentLength,&dwSize,NULL)){
		//dwError=GetLastError();	
		//ErrorMsgBox(dwError,_T("获取请求响应内容长度错误：%s"));
		//goto clean;
		if (dwContentLength>0) {
			response->put_ContentLength(dwContentLength);
			rcContext.dwContentLength=dwContentLength;
		}
	}

	//ÏìÓ¦ÄÚÈÝÀàÐÍ 
	dwSize=sizeof(szContentType);
	if (HttpQueryInfo(hRequest,HTTP_QUERY_CONTENT_TYPE ,(LPVOID)szContentType,&dwSize,NULL)){
		//dwError=GetLastError();	
		//ErrorMsgBox(dwError,_T("获取请求响应内容类型错误：%s"));
		//goto clean;
		if (_tcslen(szContentType)>0) response->put_ContentType(T2BSTR(szContentType));
	}
	
	//ËùÓÐÏìÓ¦Í·ÐÅÏ¢
	szHeader=new TCHAR[STRLEN_8K];
	dwSize=STRLEN_8K*sizeof(TCHAR);
getheader:
	getHeanderSucceeded=HttpQueryInfo(hRequest,HTTP_QUERY_RAW_HEADERS_CRLF ,(LPVOID)szHeader,&dwSize,NULL);
	if(!getHeanderSucceeded){
		dwError=GetLastError();
		if (dwError==ERROR_INSUFFICIENT_BUFFER){
			TCHAR szXX[100]={0};
			_stprintf_s(szXX,_T("dwError=%d,dwSize=%d"),dwError,dwSize);
			InfoMsgBox(szXX);
			SAFE_FREE_STRING_PTR(szHeader);
			szHeader=new TCHAR[dwSize+2];
			dwSize+=2;
			dwSize=dwSize*sizeof(TCHAR);
			goto getheader;
		}
		else if (dwError!=ERROR_SUCCESS){
			ErrorMsgBox(dwError,_T("获取请求响应头信息错误：%s"));
			goto clean;
		}
	}
	if(szHeader) response->put_Header(T2BSTR(szHeader));
	//ÏìÓ¦ÄÚÈÝ´¦Àí
	if (this->m_blSaveResponseToFile && this->m_szResponseFile && _tcslen(this->m_szResponseFile)>0 && dwStatusCode != 201){	//°ÑÏìÓ¦ÄÚÈÝ±£´æµ½ÎÄ¼þ
		//´´½¨ÎÄ¼þ 
		hResponseFile = CreateFile(this->m_szResponseFile,GENERIC_WRITE,0,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
		if (hResponseFile == INVALID_HANDLE_VALUE) 
		{ 
			dwError=GetLastError();
			ErrorMsgBox(dwError,_T("打开响应内容本地保存文件错误：%s"));
			goto clean;
		}
		responseFileFlag=TRUE;
	}
	do{
		ZeroMemory(readBuffer,STRLEN_1K);
		dwSize=0;
		if (!InternetReadFile(hRequest,(LPVOID)readBuffer,sizeof(readBuffer),&dwSize)){
			dwError=GetLastError();
			ErrorMsgBox(dwError,_T("读取请求响应内容错误：%s"));
			goto clean;
		}
		if (dwSize!=0){
			dwCalcLength+=dwSize;
			if (responseFileFlag){	//Ð´ÎÄ¼þ
				DWORD dwWritten=0;
				if (!WriteFile(hResponseFile,readBuffer,dwSize,&dwWritten,NULL)){
					dwError=GetLastError();
					ErrorMsgBox(dwError,_T("写入响应内容本地保存文件错误：%s"));
					goto clean;
				}
			}
			else{	//×·¼Óµ½ÏàÓ¦ÎÄ±¾
				char buffer[STRLEN_1K+2]={0};
				strncpy_s(buffer,readBuffer,dwSize);
				if (szResText) szResText.Append(buffer);
			}
			if (dwCalcLength==dwContentLength) break;
			rcContext.dwReceivedLength=dwCalcLength;
		}//if end
	}while(dwSize!=0);
	
	//°ÑÏìÓ¦ÄÚÈÝ±£´æµ½ÏìÓ¦ÎÄ±¾
	if (!responseFileFlag){
		response->put_ContentText(szResText.Detach());
	}//
	//×ÊÔ´»ØÊÕ
clean:
	//¹Ø±ÕÎÄ¼þ
	if(hPostFile) CloseHandle(hPostFile);
	if(hResponseFile) {
		FlushFileBuffers(hResponseFile);
		CloseHandle(hResponseFile);
	}

	//»ØÊÕhttpÁ¬½ÓºÍÇëÇó¾ä±ú
	if (hRequest) InternetCloseHandle(hRequest);
	if (hConnect) InternetCloseHandle(hConnect);

	//¹Ø±Õ×´Ì¬¿ò
	//if (this->m_blShowRequestProgress) WaitForMultipleObjects(1,&rcContext.hThread,TRUE,INFINITE); 
	if (this->m_blShowRequestProgress) EndDialog(rcContext.hProgressWnd,0);

	SAFE_FREE_STRING_PTR(szHeader);

	response.CopyTo(pVal);

	return S_OK;
}

// HttpRequest
STDMETHODIMP HttpRequest::get_Url(BSTR* pVal)
{
	ATLASSERT(pVal);
	*pVal=NULL;
	if (_tcslen(m_szUrl)>0) *pVal=T2BSTR(m_szUrl);
	return S_OK;
}

STDMETHODIMP HttpRequest::put_Url(BSTR newVal)
{
	ATLASSERT(newVal);
	if(IsValidURL(NULL,newVal,0)!=S_OK){
		ErrorMsgBox(0,_T("请求地址不合法！"));
		return S_OK;
	}

	DWORD dwSize=STRLEN_4K;
	if (!InternetCanonicalizeUrl(newVal,m_szUrl,&dwSize,ICU_BROWSER_MODE)){
		ErrorMsgBox(GetLastError(),_T("请求地址不合法或者长度太大：%s"));
		ZeroMemory(m_szUrl,sizeof(m_szUrl));
		return S_OK;
	}
	ZeroMemory(m_szUrl,sizeof(m_szUrl));
	_tcsncpy_s(m_szUrl,newVal,_tcslen(newVal));
	
	ZeroMemory(m_szUrlProtocol,sizeof(m_szUrlProtocol));
	ZeroMemory(m_szUrlHost,sizeof(m_szUrlHost));
	ZeroMemory(m_szUrlFile,sizeof(m_szUrlFile));
	m_usUrlPort=DEFAULT_HTTP_PORT;
	m_blUrlIsSSL=VARIANT_FALSE;

	if (!m_szUrl || _tcslen(m_szUrl)==0) return S_OK;

	//»ñÈ¡urlÐ­Òé²¿·Ö
	for(size_t i=0;i<sizeof(m_szUrl);i++){
		if (m_szUrl[i]==_T(':') || i>=sizeof(m_szUrlProtocol)) break;
		m_szUrlProtocol[i]=m_szUrl[i];
	}
	
	//ÊÇ·ñsslºÍsslÄ¬ÈÏ¶Ë¿Ú
	if (_tcsicmp(m_szUrlProtocol,_T("https"))==0) {
		m_blUrlIsSSL=VARIANT_TRUE;
		if (m_usUrlPort==DEFAULT_HTTP_PORT) m_usUrlPort=DEFAULT_HTTPS_PORT;
	}

	//»ñÈ¡url¶Ë¿Ú²¿·Ö
	TCHAR* szPos1=_tcschr(m_szUrl+_tcslen(m_szUrlProtocol)+1,_T(':'));
	TCHAR* szPos2=_tcschr(m_szUrl+_tcslen(m_szUrlProtocol)+3,_T('/'));
	if (szPos1 && szPos2){
		TCHAR szPort[STRLEN_SMALL]={0};
		_tcsncpy_s(szPort,szPos1+1,szPos2-szPos1-1);
		
		TCHAR *stop;
		m_usUrlPort=(USHORT)_tcstoul(szPort,&stop,0);
	}
	
	//»ñÈ¡urlÖ÷»ú²¿·Ö
	int idx=0;
	for(size_t i=_tcslen(m_szUrlProtocol)+3;i<sizeof(m_szUrl);i++){
		if (m_szUrl[i]==_T(':') || m_szUrl[i]==_T('/')) break;
		m_szUrlHost[idx++]=m_szUrl[i];
	}
	
	//»ñÈ¡urlÎÄ¼þ²¿·Ö
	TCHAR* szPos3=_tcschr(m_szUrl+_tcslen(m_szUrlProtocol)+3,_T('/'));
	if(szPos3) _tcscpy_s(this->m_szUrlFile,szPos3);
	else this->m_szUrlFile[0]=_T('/');
	
	return S_OK;
}

STDMETHODIMP HttpRequest::get_SessionKey(BSTR* pVal)
{
	ATLASSERT(pVal);
	*pVal=NULL;
	if (_tcslen(m_szSessionKey)>0) *pVal=T2BSTR(m_szSessionKey);
	return S_OK;
}

STDMETHODIMP HttpRequest::put_SessionKey(BSTR newVal)
{
	ATLASSERT(newVal);
	ZeroMemory(m_szSessionKey,sizeof(m_szSessionKey));
	_tcsncpy_s(m_szSessionKey,newVal,STRLEN_DEFAULT);
	return S_OK;
}

STDMETHODIMP HttpRequest::get_Method(BSTR* pVal)
{
	ATLASSERT(pVal);
	*pVal=NULL;
	if (m_szMethod!=NULL) *pVal=T2BSTR(m_szMethod);
	return S_OK;
}

STDMETHODIMP HttpRequest::put_Method(BSTR newVal)
{
	ATLASSERT(newVal);
	ZeroMemory(m_szMethod,sizeof(m_szMethod));
	_tcsncpy_s(m_szMethod,newVal,STRLEN_SMALL);
	_tcsupr_s(m_szMethod);
	return S_OK;
}

STDMETHODIMP HttpRequest::get_ShowRequestProgress(VARIANT_BOOL* pVal)
{
	ATLASSERT(pVal);
	*pVal=this->m_blShowRequestProgress;
	return S_OK;
}

STDMETHODIMP HttpRequest::put_ShowRequestProgress(VARIANT_BOOL newVal)
{
	this->m_blShowRequestProgress=(newVal?VARIANT_TRUE:VARIANT_FALSE);
	return S_OK;
}

STDMETHODIMP HttpRequest::get_PostFile(BSTR* pVal)
{
	ATLASSERT(pVal);
	*pVal=NULL;
	if (m_szPostFile!=NULL) *pVal=T2BSTR(m_szPostFile);
	return S_OK;
}

STDMETHODIMP HttpRequest::put_PostFile(BSTR newVal)
{ 
	ATLASSERT(newVal);
	ZeroMemory(m_szPostFile,sizeof(m_szPostFile));
	_tcsncpy_s(m_szPostFile,newVal,_tcslen(newVal));//MAX_PATH);
	return S_OK;
}

STDMETHODIMP HttpRequest::get_ResponseFile(BSTR* pVal)
{
	ATLASSERT(pVal);
	*pVal=NULL;
	if (m_szResponseFile!=NULL) *pVal=T2BSTR(m_szResponseFile);
	return S_OK;
}

STDMETHODIMP HttpRequest::put_ResponseFile(BSTR newVal)
{
	ATLASSERT(newVal);
	ZeroMemory(m_szResponseFile,sizeof(m_szResponseFile));
	_tcsncpy_s(m_szResponseFile,newVal,_tcslen(newVal));//MAX_PATH);
	return S_OK;
}

STDMETHODIMP HttpRequest::get_SaveResponseToFile(VARIANT_BOOL* pVal)
{
	ATLASSERT(pVal);
	*pVal=this->m_blSaveResponseToFile;
	return S_OK;
}

STDMETHODIMP HttpRequest::put_SaveResponseToFile(VARIANT_BOOL newVal)
{
	this->m_blSaveResponseToFile=(newVal?VARIANT_TRUE:VARIANT_FALSE);
	return S_OK;
}

STDMETHODIMP HttpRequest::get_UrlProtocol(BSTR* pVal){
	ATLASSERT(pVal);
	*pVal=T2BSTR(this->m_szUrlProtocol);
	return S_OK;
}
STDMETHODIMP HttpRequest::get_UrlPort(USHORT* pVal){
	ATLASSERT(pVal);
	*pVal=this->m_usUrlPort;
	return S_OK;
}
STDMETHODIMP HttpRequest::get_UrlHost(BSTR* pVal){
	ATLASSERT(pVal);
	*pVal=T2BSTR(this->m_szUrlHost);
	return S_OK;
}
STDMETHODIMP HttpRequest::get_UrlFile(BSTR* pVal){
	ATLASSERT(pVal);
	*pVal=T2BSTR(this->m_szUrlFile);
	return S_OK;
}
STDMETHODIMP HttpRequest::get_UrlIsSSL(VARIANT_BOOL* pVal){
	ATLASSERT(pVal);
	*pVal=this->m_blUrlIsSSL;
	return S_OK;
}

STDMETHODIMP HttpRequest::AddHeader(BSTR szName,BSTR szValue){
	ATLASSERT(szName);
	ATLASSERT(szValue);
	size_t lenName=_tcslen(szName);
	size_t lenValue=_tcslen(szValue);
	if(lenName==0 || lenValue==0) return S_OK;
	CComBSTR str(_T(""));
	if(this->m_szHeader){
		str.Append(this->m_szHeader);
		SAFE_FREE_STRING_PTR(this->m_szHeader);
	}
	str.AppendBSTR(szName);
	str.Append(_T(": "));
	str.AppendBSTR(szValue);
	str.Append(_T("\r\n"));
	size_t newLen=str.Length()+1;
	this->m_szHeader=new TCHAR[newLen];
	ZeroMemory(this->m_szHeader,newLen*sizeof(TCHAR));
	_tcscpy_s(this->m_szHeader,newLen,str.Detach());
	return S_OK;
}

void HttpRequest::ErrorMsgBox(DWORD dwErrorCode,TCHAR* szTemplet){
	BOOL hasTemplet=TRUE;

	if (!szTemplet || _tcslen(szTemplet)==0) hasTemplet=FALSE;

	if(dwErrorCode==0 && hasTemplet){
		MessageBox(GetForegroundWindow(),szTemplet,_T("亿榕公文交换平台错误"),MB_OK|MB_ICONERROR);
		return ;
	}

	TCHAR* szPos=NULL;
	if (hasTemplet) szPos=_tcsstr(szTemplet,_T("%s"));
	LPVOID lpMsgBuf;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |FORMAT_MESSAGE_FROM_SYSTEM,NULL,dwErrorCode,MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpMsgBuf,0, NULL );
	TCHAR szTip[STRLEN_DEFAULT]={0};
	_stprintf_s(szTip,(szPos?szTemplet:_T("%s")),(lpMsgBuf==NULL?_T("未知错误"):lpMsgBuf));
	LocalFree(lpMsgBuf);
	if (rcContext.hProgressWnd!=0) EndDialog(rcContext.hProgressWnd,0);
	MessageBox(GetForegroundWindow(),szTip,_T("亿榕公文交换平台错误"),MB_OK|MB_ICONERROR);
}

void HttpRequest::InfoMsgBox(TCHAR* szTip){
	MessageBox(GetForegroundWindow(),szTip,_T("亿榕公文交换平台提示"),MB_OK|MB_ICONINFORMATION);
}

void CALLBACK INetStatusCallBack(HINTERNET hInternet, DWORD dwContext, DWORD dwInternetStatus,LPVOID lpvStatusInformation, DWORD dwStatusInformationLength)
{
  REQUEST_CONTEXT *cpContext;
  cpContext = (REQUEST_CONTEXT*)dwContext;
	TCHAR statusTxt[STRLEN_DEFAULT]={0};
	int isSetTxt=1;
  switch (dwInternetStatus)
	{
    case INTERNET_STATUS_CLOSING_CONNECTION:
			break;
    case INTERNET_STATUS_CONNECTED_TO_SERVER:
			break;
    case INTERNET_STATUS_CONNECTING_TO_SERVER:
			break;
    case INTERNET_STATUS_CONNECTION_CLOSED:
			break;
    case INTERNET_STATUS_HANDLE_CLOSING:
			SetDlgItemText(rcContext.hProgressWnd,IDC_STATIC1,_T("完成！"));
			EndDialog(cpContext->hProgressWnd,0);
			break;
    case INTERNET_STATUS_HANDLE_CREATED:
			SetDlgItemText(rcContext.hProgressWnd,IDC_STATIC1,_T("连接成功..."));
			break;
    case INTERNET_STATUS_INTERMEDIATE_RESPONSE:
			break;
    case INTERNET_STATUS_NAME_RESOLVED:
			break;
    case INTERNET_STATUS_RECEIVING_RESPONSE:
			break;
    case INTERNET_STATUS_RESPONSE_RECEIVED:
			{
				ZeroMemory(rcContext.szMemo,STRLEN_DEFAULT*sizeof(TCHAR));
				if (rcContext.dwContentLength>0){
					_stprintf_s(rcContext.szMemo,_T("已接收“%d%%”共“%dK”。"),(int)(((double)rcContext.dwReceivedLength/(double)rcContext.dwContentLength)*100.0),rcContext.dwContentLength/1024);
				}
				else{
					_stprintf_s(rcContext.szMemo,_T("已接收“%d”字节。"),rcContext.dwReceivedLength/1024);
				}
				HWND hIdc1=GetDlgItem(rcContext.hProgressWnd,IDC_STATIC1);
				RedrawWindow(hIdc1,NULL,NULL,RDW_INVALIDATE|RDW_FRAME|RDW_INTERNALPAINT|RDW_ERASE|RDW_UPDATENOW|RDW_ERASENOW|RDW_NOCHILDREN);
			}
			break;
    case INTERNET_STATUS_REDIRECT:
			break;
    case INTERNET_STATUS_REQUEST_COMPLETE:
      break;
    case INTERNET_STATUS_REQUEST_SENT:
			{
				ZeroMemory(rcContext.szMemo,STRLEN_DEFAULT*sizeof(TCHAR));
				if (rcContext.dwPostFileLength>0){
					_stprintf_s(rcContext.szMemo,_T("已发送“%d%%”共“%dK”。"),(int)(((double)rcContext.dwPostedLength/(double)rcContext.dwPostFileLength)*100.0),rcContext.dwPostFileLength/1024);
					HWND hIdc1=GetDlgItem(rcContext.hProgressWnd,IDC_STATIC1);
					RedrawWindow(hIdc1,NULL,NULL,RDW_INVALIDATE|RDW_FRAME|RDW_INTERNALPAINT|RDW_ERASE|RDW_UPDATENOW|RDW_ERASENOW|RDW_NOCHILDREN);
				}
			}
			break;
    case INTERNET_STATUS_RESOLVING_NAME:
			break;
    case INTERNET_STATUS_SENDING_REQUEST:
			break;
    case INTERNET_STATUS_STATE_CHANGE:
			break;
    default:
			break;
	}
}

BOOL CALLBACK ProgressProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){
	switch(message)
	{
		case WM_INITDIALOG:		
			SetCursor(LoadCursor(NULL,IDC_WAIT));
			rcContext.hProgressWnd=hWnd;
			
			SetWindowLong(GetDlgItem(hWnd,IDC_STATIC1),GWL_WNDPROC,(LONG)Static1WndProc); 

			hWndGif= GetDlgItem(hWnd,IDC_STATIC2);
			if (hWndGif)
			{
				m_wndBanner.SubclassWindow(hWndGif);
				if (m_wndBanner.Load(MAKEINTRESOURCE(IDR_BUSY),_T("GIF"))){
					m_wndBanner.Draw();
				}
			};
			SetCursor(LoadCursor(NULL,IDC_ARROW));
			return TRUE;
		case WM_ERASEBKGND:
			{
				RECT bgRect;
				GetWindowRect(hWnd,&bgRect);
				HRGN bgRgn=CreateRectRgnIndirect(&bgRect);
				HWND hIDC1=GetDlgItem(hWnd,IDC_STATIC1);
				RECT idc1Rect;
				GetWindowRect(hIDC1,&idc1Rect);
				HRGN idc1Rgn=CreateRectRgnIndirect(&idc1Rect);
				if (!CombineRgn(bgRgn, bgRgn,idc1Rgn, RGN_XOR)) return FALSE;
				HBRUSH hBrush=CreateSolidBrush(GetSysColor(COLOR_3DFACE));
				POINT pt;
				HDC hdc=(HDC)wParam;
				GetWindowOrgEx(hdc,&pt);
				SetWindowOrgEx(hdc,bgRect.left,bgRect.top,NULL);
				FillRgn(hdc,bgRgn,hBrush);
				SetWindowOrgEx(hdc,pt.x,pt.y,NULL);
				DeleteObject(hBrush);
			}
			return FALSE;
		case WM_CTLCOLORSTATIC:
			SetBkMode((HDC)wParam,TRANSPARENT);
			return (BOOL)GetStockObject(NULL_BRUSH);
		case WM_DESTROY:
			SetCursor(LoadCursor(NULL,IDC_WAIT));
			CloseHandle(rcContext.hThread);
			rcContext.hProgressWnd=0;
			EndDialog(hWnd,0);
			SetCursor(LoadCursor(NULL,IDC_ARROW));
			return TRUE;
		default:
			return FALSE;
	}
}
DWORD WINAPI ProgressDialog(LPVOID lpParam){
	//初始化回调信息上下文
	rcContext.hWindow=HWND_DESKTOP;

	//开始实际http请求
	VARIANT_BOOL ret=false;

	//显示进度窗口
	DialogBox(_AtlBaseModule.GetModuleInstance(),MAKEINTRESOURCE(IDD_Progress), rcContext.hWindow,(DLGPROC)ProgressProc);
	return 0;
}

LRESULT CALLBACK Static1WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam){ 
	switch (uMsg) 
	{ 
		case WM_PAINT:
			//HDC memDC;
			{
				PAINTSTRUCT m_ps;
				HDC dc=BeginPaint(hwnd, &m_ps);
				SetBkColor(dc,GetSysColor(COLOR_3DFACE));
				HFONT ft=(HFONT)GetStockObject(DEFAULT_GUI_FONT);
				SelectObject(dc,ft);
				SetTextColor(dc,RGB(0,0,0));
				TextOut(dc,0,0,rcContext.szMemo,_tcslen(rcContext.szMemo));
				//memDC=CreateCompatibleDC(dc);
				//RECT rc;
				//GetClipBox(memDC,&rc);
				//HBRUSH hBrush=CreateSolidBrush(GetSysColor(COLOR_3DFACE));
				//FillRect(memDC,&rc,hBrush);
				//DeleteObject(hBrush);
				DeleteObject(ft);
				EndPaint(hwnd,&m_ps);
			}
			return FALSE;//DefWindowProc(hwnd,WM_PAINT, (WPARAM)memDC, (LPARAM)0);
		case WM_ERASEBKGND:
			return FALSE;
		default: 
			return DefWindowProc(hwnd, uMsg, wParam, lParam); 
	} 
	return 0; 
}
