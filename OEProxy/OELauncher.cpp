// OELauncher.cpp : Implementation of COELauncher

#include "stdafx.h"
#include "OELauncher.h"


// COELauncher

STDMETHODIMP COELauncher::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IOELauncher
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP COELauncher::EditWordDocument(BSTR fileName, BSTR uploadURL, BSTR* xmlDocInfo)
{
	IDispatch* pDisp = NULL;
	CLSID clsid;
	DISPID dispID;
	HRESULT hr;

	hr = CLSIDFromProgID(L"Word.Application", &clsid);
	if ( FAILED(hr) ){
		MessageBox(NULL, _T("Word is not installed."), _T("Warning"), MB_OK);
	} else {
		hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_IDispatch, (void **)&pDisp);
		if ( FAILED(hr) ){
			MessageBox(NULL, _T("Couldn't start Word."), _T("Warning"), MB_OK);
		} else {
			OLECHAR* szVisible = L"Visible";
			DISPPARAMS dispParams = {NULL, NULL, 0, 0};
			DISPID dispidNamed = DISPID_PROPERTYPUT;
			CComVariant vrTrue = VARIANT_TRUE;

			pDisp->GetIDsOfNames(IID_NULL, &szVisible, 1, LOCALE_USER_DEFAULT, &dispID);

			dispParams.cArgs = 1;
			dispParams.rgvarg = &vrTrue;
			dispParams.cNamedArgs = 1;
			dispParams.rgdispidNamedArgs = &dispidNamed;

			// Set "Visible" property to true.
			pDisp->Invoke(dispID, IID_NULL, LOCALE_SYSTEM_DEFAULT,
				DISPATCH_PROPERTYPUT | DISPATCH_METHOD, &dispParams,
				NULL, NULL, NULL);
			
			//MessageBox(_T("We're done."), _T("Finish"), MB_SETFOREGROUND);

			pDisp->Release();
		}
	}
	
	return S_OK;
}
