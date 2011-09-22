// OEControl.cpp : Implementation of COEControl
#include "stdafx.h"
#include "OEControl.h"


// COEControl

LRESULT COEControl::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
/*	//MessageBox(_T("Hello OnlineEditor"));
	IDispatch* pDisp = NULL;
	CLSID clsid;
	DISPID dispID;
	HRESULT hr;

	hr = CLSIDFromProgID(L"Word.Application", &clsid);
	if ( FAILED(hr) ){
		MessageBox(_T("Word is not installed."));
	} else {
		hr = CoCreateInstance(clsid, NULL, CLSCTX_LOCAL_SERVER, IID_IDispatch, (void **)&pDisp);
		if ( FAILED(hr) ){
			MessageBox(_T("Couldn't start Word."));
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
*/
	return TRUE;
}
