// HttpResponse.cpp : HttpResponse 的实现

#include "stdafx.h"
#include "HttpResponse.h"


// HttpResponse

STDMETHODIMP HttpResponse::get_StatusCode(LONG* pVal)
{
	ATLASSERT(pVal);
	*pVal=m_lStatusCode;
	return S_OK;
}
STDMETHODIMP HttpResponse::put_StatusCode(LONG newVal)
{
	m_lStatusCode=newVal;
	return S_OK;
}

STDMETHODIMP HttpResponse::get_ContentType(BSTR* pVal)
{
	ATLASSERT(pVal);
	*pVal=NULL;
	if (m_szContentType!=NULL) *pVal=T2BSTR(m_szContentType);
	return S_OK;
}
STDMETHODIMP HttpResponse::put_ContentType(BSTR newVal)
{
	ATLASSERT(newVal);
	ZeroMemory(m_szContentType,sizeof(m_szContentType));
	_tcsncpy_s(m_szContentType,newVal,MAX_PATH);
	return S_OK;
}

STDMETHODIMP HttpResponse::get_ContentLength(LONG* pVal)
{
	ATLASSERT(pVal);
	*pVal=m_lContentLength;
	return S_OK;
}
STDMETHODIMP HttpResponse::put_ContentLength(LONG newVal)
{
	m_lContentLength=newVal;
	return S_OK;
}

STDMETHODIMP HttpResponse::get_ErrorCode(LONG* pVal)
{
	ATLASSERT(pVal);
	*pVal=m_lErrorCode;
	return S_OK;
}
STDMETHODIMP HttpResponse::put_ErrorCode(LONG newVal)
{
	m_lErrorCode=newVal;
	return S_OK;
}

STDMETHODIMP HttpResponse::get_ContentText(BSTR* pVal)
{
	ATLASSERT(pVal);
	*pVal=NULL;
	if (m_szContentText!=NULL) *pVal=T2BSTR(m_szContentText);
	return S_OK;
}
STDMETHODIMP HttpResponse::put_ContentText(BSTR newVal)
{
	ATLASSERT(newVal);
	size_t len=_tcslen(newVal);
	if (len==0) return S_OK;
	len+=2;
	SAFE_FREE_STRING_PTR(m_szContentText);
	m_szContentText=new TCHAR[len];
	ZeroMemory(m_szContentText,len*sizeof(TCHAR));
	_tcscpy_s(m_szContentText,len,newVal);
	return S_OK;
}

STDMETHODIMP HttpResponse::get_Header(BSTR* pVal)
{
	ATLASSERT(pVal);
	*pVal=NULL;
	if (m_szHeader!=NULL) *pVal=T2BSTR(m_szHeader);
	return S_OK;
}
STDMETHODIMP HttpResponse::put_Header(BSTR newVal)
{
	ATLASSERT(newVal);
	size_t len=_tcslen(newVal);
	if (len==0) return S_OK;
	len+=2;
	SAFE_FREE_STRING_PTR(m_szHeader);
	m_szHeader=new TCHAR[len];
	ZeroMemory(m_szHeader,len*sizeof(TCHAR));
	_tcscpy_s(m_szHeader,len,newVal);
	return S_OK;
}