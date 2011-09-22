// Shell.cpp : Shell 的实现

#include "stdafx.h"
#include "Shell.h"
#include <shfolder.h>
#include <winver.h>

#pragma comment(lib, "Version.lib")
// Shell
#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))
STDMETHODIMP Shell::GetWindowsVersionString(BSTR* szVer)
{
	*szVer=NULL;
	OSVERSIONINFO osv;
	osv.dwOSVersionInfoSize=sizeof(osv);
	TCHAR szVersion[80]={0};
	if (GetVersionEx(&osv)){
		_stprintf_s(szVersion,_T("%u.%u.%u"),osv.dwMajorVersion,osv.dwMinorVersion,osv.dwBuildNumber);
		*szVer=T2BSTR(szVersion);
	}
	else return E_FAIL;
	return S_OK;
}

STDMETHODIMP Shell::GetFileVersionString(BSTR szFile, BSTR* szVer)
{
	*szVer=NULL;
	DWORD dwHandle;
	TCHAR *szFileName=OLE2T(szFile);
	DWORD cchver = GetFileVersionInfoSize(szFileName,&dwHandle);
	if (cchver == 0) return GetLastError();
	TCHAR* pver = new TCHAR[cchver];
	BOOL bret = GetFileVersionInfo(szFileName,dwHandle,cchver,pver);
	if (!bret) return GetLastError();
	UINT uLen;
	void *pbuf;
	VS_FIXEDFILEINFO pvsf;
	bret = VerQueryValue(pver,_T("\\"),&pbuf,&uLen);
	if (!bret) return GetLastError();
	memcpy(&pvsf,pbuf,sizeof(VS_FIXEDFILEINFO));
	TCHAR szVersion[80]={0};
	_stprintf_s(szVersion,_T("%u.%u.%u.%u"),HIWORD(pvsf.dwProductVersionMS),LOWORD(pvsf.dwProductVersionMS),HIWORD(pvsf.dwProductVersionLS),LOWORD(pvsf.dwProductVersionLS));
	*szVer=T2BSTR(szVersion);
	delete[] pver;
	return S_OK;
}

STDMETHODIMP Shell::GetWindowsUserName(BSTR* szUser)
{
	*szUser=NULL;
	TCHAR szBuffer[80]={0};
	DWORD dwSize=80;
	if (GetUserName(szBuffer,&dwSize)){
		*szUser=T2BSTR(szBuffer);
	}
	else return GetLastError();
	return S_OK;
}

STDMETHODIMP Shell::GetSystemFolder(BSTR* szFolder)
{
	*szFolder=NULL;
	TCHAR szBuffer[MAX_PATH]={0};
	HRESULT hResult=SHGetFolderPath(NULL, CSIDL_SYSTEM, NULL, 0, szBuffer);
	if (!SUCCEEDED(hResult)) return hResult;
	_tcscat_s(szBuffer,L"\\");
	*szFolder=T2BSTR(szBuffer);
	return S_OK;
}

STDMETHODIMP Shell::GetPersonalFolder(BSTR* szFolder)
{
	*szFolder=NULL;
	TCHAR szBuffer[MAX_PATH]={0};
	HRESULT hResult=SHGetFolderPath(NULL, CSIDL_PERSONAL, NULL, 0, szBuffer);
	if (!SUCCEEDED(hResult)) return hResult;
	_tcscat_s(szBuffer,_T("\\"));
	*szFolder=T2BSTR(szBuffer);
	return S_OK;
}

STDMETHODIMP Shell::GetWorkFolder(BSTR* szFolder)
{
	*szFolder=NULL;
	TCHAR szBuffer[MAX_PATH]={0};
	ZeroMemory(szBuffer,MAX_PATH);
	HRESULT hResult=SHGetFolderPath(NULL, CSIDL_PERSONAL | CSIDL_FLAG_CREATE, NULL, 0, szBuffer);
	if (!SUCCEEDED(hResult)) return hResult;
	_tcscat_s(szBuffer,L"\\exchange");
	CreateDirectory(szBuffer,NULL);
	_tcscat_s(szBuffer,L"\\");
	*szFolder=T2BSTR(szBuffer);
	return S_OK;
}

STDMETHODIMP Shell::GetWorkFolderTemp(BSTR* szFolder)
{
	*szFolder=NULL;
	BSTR szWorkFolder;
	TCHAR szBuffer[MAX_PATH]={0};
	if (GetWorkFolder(&szWorkFolder)==S_OK){
		TCHAR *szRetFolder=OLE2T(szWorkFolder);
		_tcscat_s(szBuffer,szRetFolder);
		_tcscat_s(szBuffer,_T("temp"));
		CreateDirectory(szBuffer,NULL);
		_tcscat_s(szBuffer,_T("\\"));
		*szFolder=T2BSTR(szBuffer);
	}
	else return E_FAIL;
	return S_OK;
}

STDMETHODIMP Shell::GetFileLength(BSTR szFilePath, ULONG* ulFileLength)
{
	HANDLE hFile;
	DWORD dwFileSize;
	LPCTSTR filePath =OLE2T(szFilePath);
	*ulFileLength=0;
	if ((hFile = CreateFile(filePath,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,(HANDLE)NULL)) == (HANDLE)(-1))
	{
		MessageBox(NULL,_T("文件不存在或者无法打开！"),_T("错误"),MB_OK|MB_ICONERROR);
		return E_FAIL;
	}
	
	dwFileSize = GetFileSize (hFile, NULL);
	if (dwFileSize == 0xFFFFFFFF) {
		CloseHandle(hFile);
		MessageBox(NULL,_T("获取文件大小时发生错误！"),_T("错误"),MB_OK|MB_ICONERROR);
		return E_FAIL;
	}
	CloseHandle(hFile);
	*ulFileLength=dwFileSize;
	return S_OK;
}

STDMETHODIMP Shell::GetInstallPath(BSTR* szPath)
{
	*szPath=NULL;
	TCHAR	strPath[MAX_PATH]={0};
	TCHAR sep=_T('\\');
	DWORD dwRet=GetModuleFileName(_AtlBaseModule.m_hInst, strPath, MAX_PATH);
	if (!dwRet) *szPath=SysAllocString(L"");
	else {
		TCHAR* occur=_tcsrchr(strPath,sep);
		*(occur+1)=_T('\0');
		*szPath=T2BSTR(strPath);
	}
	return S_OK;
}

STDMETHODIMP Shell::ClearTempWorkFolder(void)
{
	VARIANT_BOOL ret;
	BSTR files=SysAllocString(_T("*.*"));
	HRESULT hr=DeleteTempFile(files,&ret);
	if (files) SysFreeString(files);
	return hr;
}

STDMETHODIMP Shell::DeleteTempFile(BSTR szFileName, VARIANT_BOOL* bSuccess)
{
	*bSuccess=VARIANT_FALSE;
	if (szFileName==NULL || SysStringLen(szFileName)==0) return Error(_T("没有指定要删除的临时文件！"));

	TCHAR *pszFileName= OLE2T(szFileName);

	BSTR bstrWorkFolderTemp=NULL;
	GetWorkFolderTemp(&bstrWorkFolderTemp);
	
	TCHAR *pszWorkFolderTemp= OLE2T(bstrWorkFolderTemp);

	size_t size=_tcslen(pszWorkFolderTemp)+_tcslen(pszFileName)+2;
	
	TCHAR path[MAX_PATH] ={0};
	_stprintf_s(path,_T("%s%s"),pszWorkFolderTemp,pszFileName);

	TCHAR *pszFrom=new TCHAR[size];
	ZeroMemory(pszFrom,sizeof(TCHAR)*size);
	for(size_t i=0;i<(size-2);i++){
		*(pszFrom+i)=path[i];
	}
	*(pszFrom+size-2)=_T('\0');
	*(pszFrom+size-1)=_T('\0');
	
  SHFILEOPSTRUCT fileop;
	memset(&fileop,0,sizeof(fileop));
	fileop.hwnd   = NULL;					// 不显示状态
  fileop.wFunc  = FO_DELETE;		// 删除标记
  fileop.pFrom  = pszFrom;			// 要删除的文件
  fileop.pTo    = NULL;					// 没有操作目标地址
  fileop.fFlags = FOF_FILESONLY|FOF_NOCONFIRMATION|FOF_SILENT|FOF_NOERRORUI|FOF_NORECURSION ;  // 选项标记
  fileop.fAnyOperationsAborted = FALSE;
  fileop.lpszProgressTitle     = NULL;
  fileop.hNameMappings         = NULL;

  int ret = SHFileOperation(&fileop);
	if(ret==0) *bSuccess=VARIANT_TRUE;
	delete[] pszFrom;
	if (bstrWorkFolderTemp) SysFreeString(bstrWorkFolderTemp);
	return S_OK;
}
STDMETHODIMP Shell::FileExists(BSTR szFilePath, VARIANT_BOOL* bSuccess){
	*bSuccess=VARIANT_FALSE;
	if (!szFilePath || SysStringLen(szFilePath)==0){
		MessageBox(NULL,_T("没有指定要检查的文件（包括完整路径和文件名）！"),_T("错误"),MB_OK|MB_ICONERROR);
		return S_OK;
	}
	HANDLE hFile;
	LPCTSTR filePath =OLE2T(szFilePath);
	if ((hFile = CreateFile(filePath,GENERIC_READ,FILE_SHARE_READ,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,(HANDLE)NULL)) == (HANDLE)(-1))
	{
		return S_OK;
	}
	CloseHandle(hFile);
	*bSuccess=VARIANT_TRUE;
	return S_OK;
}
STDMETHODIMP Shell::LaunchFile(BSTR szFilePath,BSTR szVerb)
{
	TCHAR * verb=_T("open");
	verb=T2BSTR(szVerb);
	if (!verb || _tcslen(verb)<=0) verb=_T("open");

	TCHAR* name=OLE2T(szFilePath);
	TCHAR* pdest=_tcsrchr(name,'\\');
	TCHAR cpy[MAX_PATH]={0};
	_tcsncpy_s(cpy,(pdest?pdest:name),MAX_PATH);
	_tcslwr_s(cpy);
	BOOL bCanExecute=true;
	TCHAR * ext=_tcsrchr(cpy,'.');
	if (!ext) {
		MessageBox(NULL,_T("对不起，您必须指定文件扩展名！"),_T("警告"),MB_OK|MB_ICONWARNING);
		return S_OK;
	}
	else{
		if (_tcsrchr(ext,' ')){
			MessageBox(NULL,_T("对不起，文件不能包含参数！"),_T("警告"),MB_OK|MB_ICONWARNING);
			return S_OK;
		}
		const int al=13;
		const TCHAR* subs[al]={_T(".exe"),_T(".cpl"),_T(".scr"),_T(".lnk"),_T(".com"),_T(".bat"),_T(".vbs"),_T(".com"),_T(".pif"),_T(".inf"),_T(".vb"),_T(".js"),_T(".hta")};
		for(int i=0;i<al;i++){
			if (_tcsstr(cpy,subs[i])){
				bCanExecute=FALSE;
				break;
			}
		}
	}

	if (!bCanExecute){
		MessageBox(NULL,_T("对不起，您不能打开此类型的文件！"),_T("警告"),MB_OK|MB_ICONWARNING);
		return S_OK;
	}
	
	SHELLEXECUTEINFO ShExecInfo;
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
  ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
  ShExecInfo.hwnd = GetForegroundWindow();
	ShExecInfo.lpVerb = verb;
  ShExecInfo.lpFile =name;
  ShExecInfo.lpParameters = NULL;
  ShExecInfo.lpDirectory = NULL;
  ShExecInfo.nShow = SW_SHOWNORMAL;
  ShExecInfo.hInstApp = NULL;

	if (ShellExecuteEx(&ShExecInfo)==0){
		return S_OK;
	}
	return S_OK;
}
STDMETHODIMP Shell::FindAssocProgram(BSTR szFilePath,BSTR szVerb,BSTR* szProgram){
	*szProgram=NULL;
	if (!szFilePath || _tcslen(szFilePath)<=0) {
		MessageBox(NULL,_T("没有指定有效的文件名！"),_T("警告"),MB_OK|MB_ICONERROR);
		return S_OK;
	}

	TCHAR* name=OLE2T(szFilePath);
	TCHAR* pdest=_tcsrchr(name,'\\');
	TCHAR cpy[MAX_PATH]={0};
	_tcsncpy_s(cpy,(pdest?pdest:name),MAX_PATH);
	TCHAR * szExt=_tcsrchr(cpy,'.');
	if (!szExt || _tcslen(szExt)<=0) return S_OK;

	HRESULT hr=S_OK;
	TCHAR szExe[MAX_PATH]={0};
	DWORD cchExe = ARRAY_SIZE(szExe);

	TCHAR * verb=T2BSTR(szVerb);
	if (_tcslen(verb)<=0) verb=_T("open");

	if (SUCCEEDED(hr = AssocQueryString(0, ASSOCSTR_EXECUTABLE,szExt, verb, szExe, &cchExe))){
		*szProgram=T2BSTR(szExe);
		return hr;
	}
	return S_OK;
}

BOOL foundFileInWindowText=FALSE;	//是否发现文件在窗口标题中
//窗口枚举函数
BOOL CALLBACK searcher(HWND hWnd, LPARAM lParam)
{
	TCHAR strTitle[MAX_PATH]={0};
	LPCTSTR file=(LPCTSTR)lParam;
	int res=GetWindowText(hWnd,strTitle,MAX_PATH);
	foundFileInWindowText=FALSE;
	if (_tcsstr(strTitle,file)!=NULL){
		if (!IsWindowVisible(hWnd)) ShowWindow(hWnd, SW_SHOW);
		if (IsIconic(hWnd)) ShowWindow(hWnd,SW_RESTORE);
		SetForegroundWindow(hWnd);
		foundFileInWindowText=TRUE;
		return FALSE;	//停止枚举 
	}
	else foundFileInWindowText=FALSE;
  return TRUE;	//继续枚举
}

STDMETHODIMP Shell::CheckFileOpened(BSTR szFilePath,VARIANT_BOOL* bSuccess)
{
	*bSuccess=VARIANT_FALSE;
	foundFileInWindowText=FALSE;
	if (!szFilePath || _tcslen(szFilePath)<=0) return S_OK;

	TCHAR* filePath =OLE2T(szFilePath);
	TCHAR szFN[MAX_PATH]={0};
	TCHAR* strFileName=_tcsrchr(filePath,_T('\\'));
	if (strFileName){
	TCHAR* p=_tcschr(strFileName,_T('.'));
		if (p!=NULL && p>strFileName) {
			int i=1;
			while (true){
				if ((strFileName+i)<p){
					szFN[i-1]=*(strFileName+i);
					i++;
				}
				else break;
			}
			EnumWindows(searcher,(LPARAM)szFN);
			if (!(*bSuccess) && foundFileInWindowText) *bSuccess=VARIANT_TRUE;
		}
	}
	return S_OK;
}