// OEEditing.cpp : Implementation of COEEditing

#include "stdafx.h"
#include "OEEditing.h"
#include <comdef.h>

// COEEditing

STDMETHODIMP COEEditing::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IOEEditing
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP COEEditing::OpenWord(BSTR fileName, BSTR uploadURL, BSTR* docID)
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

CComBSTR bstrDocInfo = ::SysAllocString(L"");

STDMETHODIMP COEEditing::CloseEditingDocument(BSTR docID, BSTR docInfo)
{
	USES_CONVERSION;

	bstrDocInfo = _com_util::ConvertBSTRToString(docInfo);
	Fire_AfterEditDocument("");
	

	return S_OK;
}

STDMETHODIMP COEEditing::FetchDocumentInfo(BSTR docID, BSTR* docInfo)
{
	*docInfo = bstrDocInfo;

	return S_OK;
}

