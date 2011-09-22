// OETest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <objbase.h>
#include <atlbase.h>
#include <atlcom.h>

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr;

	CComBSTR bstrFileName = L"c:\\sandbox\\OnlineEditor\\demo.doc";
	hr = StgIsStorageFile(bstrFileName);
	if ( hr == S_OK ){
		MessageBox(NULL, L"Is Storage File", L"", MB_OK);
		// Open the template for read access only...
		IStorage *pstgTemplate = NULL;
        hr = StgOpenStorage(bstrFileName, NULL, 
            (STGM_READ | STGM_SHARE_DENY_WRITE | STGM_TRANSACTED),
             NULL, 0, &pstgTemplate);
		if ( hr == STG_E_FILEALREADYEXISTS ){
			MessageBox(NULL, L"STG_E_FILEALREADYEXISTS", L"", MB_OK);
		}
		char buff[100];
		itoa((int)hr, buff, 16);
		CComBSTR bstrError = buff;
		MessageBox(NULL, bstrError, L"", MB_OK);

		if ( pstgTemplate != NULL ){
			pstgTemplate->Release();
			pstgTemplate = NULL;
		}
	}
	return 0;
}

