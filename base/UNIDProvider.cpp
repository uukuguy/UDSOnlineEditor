// UNIDProvider.cpp : UNIDProvider µÄÊµÏÖ

#include "stdafx.h"
#include "UNIDProvider.h"


// UNIDProvider

STDMETHODIMP UNIDProvider::ProvideGUID(BSTR* szGUID)
{
	*szGUID=NULL;
	GUID guid;
	HRESULT hResult;
	hResult=CoCreateGuid(&guid);
	OLECHAR szBuffer[39];
	if (hResult==S_OK){
		if (StringFromGUID2(guid,szBuffer,39)!=0) *szGUID=::SysAllocString(szBuffer);
	}
	else return hResult;
	return S_OK;
}

STDMETHODIMP UNIDProvider::ProvideUNID(BSTR* szUNID)
{
	*szUNID=NULL;
	BSTR guid=NULL;
	if (ProvideGUID(&guid)==S_OK){
		TCHAR *szGuid=OLE2T(guid);
		TCHAR szUnid[33]={0};
		int j=0;
		for (int i=1;i<37;i++){
			if (i!=9 && i!=14 && i!=19 && i!=24) szUnid[j++]=szGuid[i];
		}
		*szUNID=T2BSTR(szUnid);
	}
	return S_OK;
}