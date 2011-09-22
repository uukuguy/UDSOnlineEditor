// UKEYSignature.cpp : UKEYSignature 的实现

#include "stdafx.h"
#include "UKEYSignature.h"
#include <wincrypt.h>
#include "cryptcls.h"
#include "base64util.h"
#include "comutil.h"
#include "PKIDtManager.h"

#define STRLEN_DEFAULT 1024

#define MY_ENCODING_TYPE  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)
#define PROVIDER_NAME _T("HaiTai Cryptographic Service Provider")	//"Rainbow iKey 1000 RSA Cryptographic Service Provider"

// UKEYSignature
STDMETHODIMP UKEYSignature::Sign(BSTR szMessage,BSTR* szSignature){
	
	__Sign(PROVIDER_NAME, L"dtcertcontainer", szMessage, L"", L"", szSignature);
	
	return S_OK;
}
STDMETHODIMP UKEYSignature::VerifySignature(BSTR szSignature,BSTR szMessage,VARIANT_BOOL* blRet){
	if(!szSignature || _tcslen(szSignature)==0) {
		InfoMsgBox(_T("您必须提供一个签名！"));
		return S_OK;
	}

	if(!szMessage || _tcslen(szMessage)==0) {
		InfoMsgBox(_T("您必须提供一个待验证的消息原文！"));
		return S_OK;
	}

	ATLASSERT(blRet);
	*blRet=VARIANT_FALSE;

	//int msgLen=FromUTF16(szMessage,NULL,0);
	//if (msgLen>0) msgLen+=1;
	BYTE *pbBuffer= (BYTE *)"The data that is to be hashed and signed.";	//new BYTE[msgLen];
	//ZeroMemory(pbBuffer,msgLen);
	//FromUTF16(szMessage,(char*)pbBuffer,msgLen);

	DWORD dwBufferLen = strlen((char *)pbBuffer)+1;

	HCRYPTPROV hProv;
	HCRYPTHASH hHash;
	HCRYPTKEY hKey;
	HCRYPTKEY hPubKey;
	BYTE *pbKeyBlob; 

	USES_CONVERSION;
	int b64encLen=strlen(CT2A(szSignature).m_psz);
	int sigLen=b64encLen / 4 * 3 + 1;
	BYTE *pbSignature=new BYTE[sigLen];
	DWORD dwSigLen=base64util::b64decode(CT2A(szSignature).m_psz,(char*)pbSignature,b64encLen);
	
	DWORD dwBlobLen=0;
	LPTSTR szDescription = _T("消息说明");

	//初始化CSP上下文
	if(CryptAcquireContext(&hProv,NULL,PROVIDER_NAME,PROV_RSA_FULL,0))
	{
		//正确初始化CSP
	}
	else
	{
		if(!CryptAcquireContext(&hProv,NULL,PROVIDER_NAME,PROV_RSA_FULL,CRYPT_NEWKEYSET)){
			InfoMsgBox(_T("对不起，无法初始化CSP上下文，请确认UKey是否插入电脑且工作正常，并安装了正确的驱动程序！"));
			goto clean;
		}
	}

	if(!CryptGetUserKey(hProv,AT_SIGNATURE,&hKey)) 
	{
		if(!CryptGenKey(hProv,AT_SIGNATURE,0,&hKey)){
			ErrorMsgBox(GetLastError(),_T("无法获取用户密钥，原因是：%s"));
			//InfoMsgBox(_T("无法获取用户密钥！"));
			goto clean;
		}
	}
	if(!CryptExportKey(hKey,0,PUBLICKEYBLOB,0,NULL,&dwBlobLen)) 
	{
		InfoMsgBox(_T("无法导出用户密钥！"));
		goto clean;
	}
	if(!(pbKeyBlob = (BYTE*)malloc(dwBlobLen))) 
	{
		InfoMsgBox(_T("无法分配内存！"));
		goto clean;
	}
	if(!CryptExportKey(hKey,0,PUBLICKEYBLOB,0,pbKeyBlob,&dwBlobLen))
	{
		InfoMsgBox(_T("无法写入密钥块！"));
		goto clean;
	}
	if(!CryptImportKey(hProv,pbKeyBlob,dwBlobLen,0,0,&hPubKey)){
		InfoMsgBox(_T("无法导入用户密钥！"));
		goto clean;
	}
	if(!CryptCreateHash(hProv,CALG_MD5, 0,0,&hHash))
	{
		InfoMsgBox(_T("无法创建哈希！"));
		goto clean;
	}
	if(!CryptHashData(hHash,pbBuffer,dwBufferLen, 0)) 
	{
		InfoMsgBox(_T("无法获取消息的哈希值！"));
		goto clean;
	}
	if(CryptVerifySignature(hHash,pbSignature,dwSigLen,hKey,/*hPubKey*/szDescription,0)) 
	{
		*blRet=VARIANT_TRUE;
	}	else ErrorMsgBox(GetLastError(),_T("验证失败，原因是：%s"));
clean:
	if(hHash) CryptDestroyHash(hHash);
	if (pbKeyBlob) free(pbKeyBlob);
	if(pbSignature) free(pbSignature);
	if(hKey) CryptDestroyKey(hKey); 
	if(hPubKey) CryptDestroyKey(hPubKey); 
	if(hProv) CryptReleaseContext(hProv, 0);

	CryptAcquireContext(&hProv,NULL,PROVIDER_NAME,PROV_RSA_FULL,CRYPT_DELETEKEYSET);
	return S_OK;
}

void UKEYSignature::ErrorMsgBox(DWORD dwErrorCode,TCHAR* szTemplet){
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
	MessageBox(GetForegroundWindow(),szTip,_T("亿榕公文交换平台错误"),MB_OK|MB_ICONERROR);
}

void UKEYSignature::InfoMsgBox(TCHAR* szTip){
	MessageBox(GetForegroundWindow(),szTip,_T("亿榕公文交换平台提示"),MB_OK|MB_ICONINFORMATION);
}
STDMETHODIMP UKEYSignature::NewSign(BSTR provider_name, BSTR container_name, BSTR szMessage, BSTR szSignature_dat, BSTR* szSignature)
{
	__Sign(provider_name, container_name, szMessage, szSignature_dat, L"", szSignature);
	return S_OK;
}

void UKEYSignature::__Sign(BSTR provider_name, BSTR container_name, BSTR szMessage, BSTR szSignature_dat, BSTR cuser, BSTR* szSignature)
{
	// TODO: 在此添加实现代码
	
	

	FILE *hDestination=0; 
	FILE *hPubkeyfile=0; 

	if(!szMessage || _tcslen(szMessage)==0) {
		InfoMsgBox(_T("您必须提供一个待签名的消息！"));
		return;
	}
	ATLASSERT(szSignature);
	*szSignature=NULL;

	BYTE *pbBuffer= (BYTE*)_com_util::ConvertBSTRToString(szMessage); //(BYTE *)"The data that is to be hashed and signed.";	//new BYTE[msgLen];

	DWORD dwBufferLen = strlen((char *)pbBuffer);

	HCRYPTPROV hProv=NULL;
	HCRYPTHASH hHash=NULL;
	HCRYPTKEY hKey=NULL;
	//HCRYPTKEY hPubKey;
	BYTE *pbKeyBlob=NULL;        
	BYTE *pbSignature=NULL;
	DWORD dwSigLen=0;
	DWORD dwBlobLen=0;
	LPTSTR szDescription = _T("消息说明");
	char* szBuffer=NULL;
	char* crOutByteChar = NULL;


	BYTE byContainerName[1024];
	WCHAR crContainer[1024];
	PKIDtManager pkIDtManager;
	if(!cuser || _tcslen(cuser)==0) {
		if (! pkIDtManager.GetContainers(byContainerName)) {
			goto clean;
		}
	} else 
	{
		char *pCertName = (char*)_com_util::ConvertBSTRToString(cuser);
		char *pProvName = (char*)_com_util::ConvertBSTRToString(provider_name);
		if (! pkIDtManager.GetContainers((BYTE*)byContainerName, pCertName, pProvName))
		{
			goto clean;
		}
		delete (pCertName);
		delete (pProvName);
		pCertName = NULL;
		pProvName = NULL;
	}
	memset(crContainer, 0, sizeof(crContainer));
	MultiByteToWideChar(CP_ACP,0,(char *)byContainerName,strlen((char *)byContainerName),crContainer,1024); 

	//初始化CSP上下文
	if(CryptAcquireContext(&hProv,crContainer,provider_name,PROV_RSA_FULL,0))
	{
		
	}
	else
	{
		InfoMsgBox(_T("对不起，无法初始化CSP上下文，请确认UKey是否插入电脑且工作正常，并安装了正确的驱动程序！"));
		goto clean;//无法初始化

	}

	if(!CryptGetUserKey(hProv,AT_KEYEXCHANGE,&hKey)) 
	{
		ErrorMsgBox(GetLastError(),_T("无法获取用户密钥，原因是：%s"));
		goto clean;
	}
	//InfoMsgBox(_T("2"));
	/*
	if(!CryptExportKey(hKey,0,PUBLICKEYBLOB,0,NULL,&dwBlobLen)) 
	{
		InfoMsgBox(_T("无法导出用户密钥！"));
		goto clean;
	}
	if(!(pbKeyBlob = (BYTE*)malloc(dwBlobLen))) 
	{
		InfoMsgBox(_T("无法分配内存！"));
		goto clean;
	}
	if(!CryptExportKey(hKey,0,PUBLICKEYBLOB,0,pbKeyBlob,&dwBlobLen))
	{
		InfoMsgBox(_T("无法导出用户密钥1！"));
		goto clean;
	}
	*/

	if(!CryptCreateHash(hProv,CALG_SHA1, hKey,0,&hHash))
	{
		InfoMsgBox(_T("无法创建哈希！"));
		goto clean;
	}
	if(!CryptHashData(hHash,pbBuffer,dwBufferLen, 0)) 
	{
		InfoMsgBox(_T("无法获取消息的哈希值！"));
		goto clean;
	}
	dwSigLen= 0;
	if(!CryptSignHash(hHash,AT_KEYEXCHANGE, 0,0,0,&dwSigLen)) 
	{
		InfoMsgBox(_T("无法获取签名长度！"));
		goto clean;
	}
	if(!(pbSignature = (BYTE *)malloc(dwSigLen)))
	{
		InfoMsgBox(_T("无法分配签名结果长度内存！"));
		goto clean;
	}
	if(!CryptSignHash(hHash,AT_KEYEXCHANGE, 0, 0, pbSignature,&dwSigLen)) 
	{
		InfoMsgBox(_T("无法签名！"));
		goto clean;
	}
	//签名结果写入文件szSignature_dat
	TCHAR msgTip[STRLEN_DEFAULT]={0};
	if(!(!szSignature_dat || _tcslen(szSignature_dat)==0)) {
		_tfopen_s(&hDestination,szSignature_dat,_T("wb"));
		if(!hDestination){
			_stprintf_s(msgTip,_T("对不起，无法打开文件“%s”！"),szSignature_dat);
			InfoMsgBox(msgTip);
			//goto clean;
		}
		fwrite(pbSignature, 1, dwSigLen, hDestination); 
		if(ferror(hDestination))
		{ 
			InfoMsgBox(_T("对不起，无法写入加密后的数据到目标文件！"));
			//goto clean;
		}
		if(hDestination) fclose(hDestination);
	}

	int outLen=dwSigLen / 3 * 4 + 1;
	if (dwSigLen % 3!=0) outLen+=4;
	szBuffer=new char[outLen];
	ZeroMemory(szBuffer,outLen);
	//转化为b64
	base64util::b64encode((const char*)pbSignature,szBuffer,dwSigLen,0);

	crOutByteChar = new char[dwSigLen*2+1];
	ZeroMemory(crOutByteChar, dwSigLen*2+1);
	crOutByteChar[dwSigLen*2] = '\0';
	
	base64util::ToHexString(crOutByteChar, pbSignature, dwSigLen);

	//FILE *baseOutfile;
	//if( (baseOutfile = fopen( "d:\\temp\\basefile.txt", "w+t" )) != NULL )
	//{
		//for (int i = 0; i < dwKeyBlobLen; i++ )
		//{
      /* Write 25 characters to stream */
			//int numwritten = fwrite( crOutByteChar, 1, dwSigLen*2, baseOutfile );
	//		printf( "Wrote %d items\n", numwritten );
		//}
		//fclose( baseOutfile );
//
	///}
	//else
	//	printf( "Problem opening the file\n" );

	//*szSignature=A2BSTR(szBuffer);

	*szSignature=A2BSTR(crOutByteChar);
clean:
	if(szBuffer) delete[] szBuffer;
	if(crOutByteChar) delete[] crOutByteChar;
	
	if(hHash) CryptDestroyHash(hHash);
	if (pbKeyBlob) free(pbKeyBlob);
	if(pbSignature) free(pbSignature);
	if(hKey) CryptDestroyKey(hKey);
	//if(hPubKey) CryptDestroyKey(hPubKey); 
	if(hProv) CryptReleaseContext(hProv, 0);
	if(pbBuffer) delete(pbBuffer);

}

STDMETHODIMP UKEYSignature::HAND_Sign(BSTR provider_name, BSTR container_name, BSTR szMessage, BSTR szSignature_dat, BSTR cuser, BSTR* szSignature)
{
	// TODO: 在此添加实现代码
	__Sign(provider_name, container_name, szMessage, szSignature_dat, cuser, szSignature);
	return S_OK;
}

STDMETHODIMP UKEYSignature::SignByUser(BSTR szMessage, BSTR szUser, BSTR* szSignature)
{
	// TODO: 在此添加实现代码
	__Sign(PROVIDER_NAME, L"dtcertcontainer", szMessage, L"", szUser, szSignature);
	return S_OK;
}

STDMETHODIMP UKEYSignature::GetCertSId(BSTR inCertName, BSTR* outCertSid)
{
	// TODO: 在此添加实现代码
	PKIDtManager pkiDtManager;
	char btSid[1000];
	int sidLen = 0;
	char *pProvName = "HaiTai Cryptographic Service Provider";
	WD_CERT_INFO_PROP certFindSid = serialNumber;
	if (pkiDtManager.GetCertInfoProp(certFindSid, (BYTE*)btSid, 1000, sidLen, "", pProvName))
	{
		//char containerName[1000];
		//MultiByteToWideChar(CP_ACP, 0, (char*)btContainer, 1000, containerName, 500);
		//InfoMsgBox(containerName);
		char *tmpBtSid = new char[sidLen];
		
		for (int i = 0; i < sidLen; i++)
		{
			tmpBtSid[sidLen - 1 - i] = btSid[i];
		}
		char *hexSid = new char[sidLen * 2 + 1];
		hexSid[sidLen * 2] = '\0';
		base64util::ToHexString(hexSid, (BYTE*)tmpBtSid, sidLen);
		*outCertSid = A2BSTR(hexSid);
		delete[] tmpBtSid;
		delete[] hexSid;
	}
	else
	{
		*outCertSid = A2BSTR("");
	}
	return S_OK;
}

STDMETHODIMP UKEYSignature::GetCertSubject(BSTR inCertName, BSTR* outSubject)
{
	// TODO: 在此添加实现代码
	PKIDtManager pkiDtManager;
	char btSubject[1000];
	int subjectLen = 0;
	char *pProvName = "HaiTai Cryptographic Service Provider";
	WD_CERT_INFO_PROP certFindSubject = subject;
	if (pkiDtManager.GetCertInfoProp(certFindSubject, (BYTE*)btSubject, 1000, subjectLen, "", pProvName))
	{
		if (subjectLen >= 1000)
		{
			*outSubject = A2BSTR("");
		} 
		else
		{
			//btSubject[subjectLen+1] = '\0';
			*outSubject = A2BSTR(btSubject);
		}		
	}
	else
	{
		*outSubject = A2BSTR("");
	}
	return S_OK;
}


STDMETHODIMP UKEYSignature::getCertXML(BSTR* szXml){

	CoInitialize(NULL);
	CLSID clsid;
	CLSIDFromProgID(OLESTR("PkiAtv.pkiAtvNew.1"),&clsid);
	CComPtr<IpkiAtvNew> pki;
	pki.CoCreateInstance(clsid);


	if (pki!=NULL)
	{
		_bstr_t cert = pki->GetCert(1);
		_bstr_t str = pki->GetCertInfo(cert);
		*szXml = str.GetBSTR();		
		pki.Release();

	}else{
		*szXml = A2BSTR("-1");
	}
	
	CoUninitialize();	
	return S_OK;
}