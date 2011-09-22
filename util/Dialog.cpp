// Dialog.cpp : Dialog 的实现

#include "stdafx.h"
#include "Dialog.h"
#include <shlobj.h>

// Dialog

STDMETHODIMP Dialog::SelectFolder(BSTR* szFolderResult)
{
	HRESULT hr=S_OK;
	* szFolderResult=NULL;
	BROWSEINFO bi = { 0 };
	bi.lpszTitle = _T("选择目标路径");
	bi.ulFlags=BIF_RETURNONLYFSDIRS |BIF_USENEWUI;
	LPITEMIDLIST pidl =SHBrowseForFolder(&bi);
	if ( pidl != 0 )
	{
		TCHAR path[MAX_PATH]={0};
		// 获取路径名称
		if (SHGetPathFromIDList(pidl,path)) *szFolderResult=T2BSTR(path);
		else *szFolderResult=SysAllocString(L"0");
		// 释放内存
		IMalloc * imalloc = 0;
		if ( SUCCEEDED( SHGetMalloc ( &imalloc )) )
		{
			imalloc->Free(pidl);
			imalloc->Release();
		}
	}
	return hr;
}

STDMETHODIMP Dialog::SelectFiles(BSTR szDefaultFileName,BSTR szTitle,BSTR szFilter,VARIANT_BOOL blAllowMultiSelect,BSTR* szFile){
	*szFile=NULL;
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = GetForegroundWindow();

	const size_t MAX_SIZE=1024;
	TCHAR szResult[MAX_SIZE]={0};
	if (szDefaultFileName && _tcslen(szDefaultFileName)>0){
		_tcsncpy_s(szResult,szDefaultFileName,MAX_PATH);
	}
	
	size_t szFilterSize=_tcslen(szFilter)+2;
	TCHAR* lptstrFilter=new TCHAR[szFilterSize];
	_tcscpy_s(lptstrFilter,szFilterSize,szFilter);
	for(size_t i=0;i<szFilterSize;i++){
		if (*(lptstrFilter+i)==_T('|') || *(lptstrFilter+i)==_T(',')){
			*(lptstrFilter+i)=_T('\0');
		}
	}
	*(lptstrFilter+szFilterSize-1)=_T('\0');
	*(lptstrFilter+szFilterSize-2)=_T('\0');
	ofn.lpstrFilter = lptstrFilter;
	ofn.nFilterIndex = 1;
	ofn.lpstrDefExt=NULL;
	ofn.lpstrFile=szResult;
	ofn.nMaxFile = MAX_SIZE;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle=0;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrTitle=szTitle;

	ofn.Flags =   OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_EXPLORER | OFN_LONGNAMES;;
	if (blAllowMultiSelect) ofn.Flags |=OFN_ALLOWMULTISELECT;
	if (GetOpenFileName(&ofn)==TRUE){
		if (!blAllowMultiSelect){
			*szFile=T2BSTR(szResult);
		}
		else{
			TCHAR szPath[MAX_PATH]={0};
			_tcscpy_s(szPath,szResult);
			if(szResult[ofn.nFileOffset-1]==_T('\0')){
				CComBSTR str(_T(""));
				BOOL appendPathFlag=TRUE;
				for(int i=ofn.nFileOffset;i<MAX_SIZE;i++){
					if (szResult[i]==_T('\0')) {
						appendPathFlag=TRUE;
						continue;
					}
					if(appendPathFlag){
						if (str.Length()>0) str.Append(_T('|'));
						str.Append(szPath);
						str.Append(_T('\\'));
						appendPathFlag=FALSE;
					}
					str.Append(szResult[i]);
				}
				str.CopyTo(szFile);
			}
			else *szFile=T2BSTR(szResult);
		}
	}
	else{
		if (CommDlgExtendedError()==FNERR_BUFFERTOOSMALL){
			MessageBox(NULL,_T("对不起，您不能一次性选择太多文件！"),_T("提示"),MB_OK|MB_ICONWARNING);
		}
	}
	delete[] lptstrFilter;
	return S_OK;
}
STDMETHODIMP Dialog::SaveFile(BSTR szDefaultFileName,BSTR szTitle,BSTR szFilter,BSTR* szFile){
	*szFile=NULL;
	OPENFILENAME ofn;
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = GetForegroundWindow();

	TCHAR szExtName[MAX_PATH]={0};
	TCHAR szResult[MAX_PATH]={0};
	if (szDefaultFileName && _tcslen(szDefaultFileName)>0){
		_tcsncpy_s(szResult,szDefaultFileName,MAX_PATH);
		TCHAR* szTmp=_tcsrchr(szResult,_T('.'));
		if (szTmp) _tcsncpy_s(szExtName,szTmp+1,MAX_PATH);
	}
	
	size_t szFilterSize=_tcslen(szFilter)+2;
	TCHAR* lptstrFilter=new TCHAR[szFilterSize];
	_tcscpy_s(lptstrFilter,szFilterSize,szFilter);
	for(size_t i=0;i<szFilterSize;i++){
		if (*(lptstrFilter+i)==_T('|') || *(lptstrFilter+i)==_T(',')){
			*(lptstrFilter+i)=_T('\0');
		}
	}
	*(lptstrFilter+szFilterSize-1)=_T('\0');
	*(lptstrFilter+szFilterSize-2)=_T('\0');
	ofn.lpstrFilter = lptstrFilter;
	ofn.nFilterIndex = 1;
	ofn.lpstrDefExt=szExtName;
	ofn.lpstrFile=szResult;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle=0;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrTitle=szTitle;

	ofn.Flags =  OFN_OVERWRITEPROMPT| OFN_EXPLORER | OFN_LONGNAMES;

	if (GetSaveFileName(&ofn)==TRUE){
		*szFile=T2BSTR(szResult);
	}
	delete[] lptstrFilter;
	return S_OK;
}