// HttpResponse.h : HttpResponse 的声明

#pragma once
#include "resource.h"       // 主符号

#include "net.h"
#include "_IHttpResponseEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// HttpResponse

class ATL_NO_VTABLE HttpResponse :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<HttpResponse, &CLSID_HttpResponse>,
	public IConnectionPointContainerImpl<HttpResponse>,
	public CProxy_IHttpResponseEvents<HttpResponse>,
	public IObjectWithSiteImpl<HttpResponse>,
	public IDispatchImpl<IHttpResponse, &IID_IHttpResponse, &LIBID_netLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	HttpResponse()
	{
		ZeroMemory(m_szContentType,sizeof(m_szContentType));
		m_szHeader=NULL;
		m_szContentText=NULL;
		m_lStatusCode=0;
		m_lContentLength=0;
		m_lErrorCode=0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HTTPRESPONSE)


BEGIN_COM_MAP(HttpResponse)
	COM_INTERFACE_ENTRY(IHttpResponse)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(HttpResponse)
	CONNECTION_POINT_ENTRY(__uuidof(_IHttpResponseEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		SAFE_FREE_STRING_PTR(this->m_szHeader);
		SAFE_FREE_STRING_PTR(this->m_szContentText);
	}

public:
	STDMETHOD(get_StatusCode)(LONG* pVal);
	STDMETHOD(put_StatusCode)(LONG newVal);
	STDMETHOD(get_ContentType)(BSTR* pVal);
	STDMETHOD(put_ContentType)(BSTR newVal);
	STDMETHOD(get_ContentLength)(LONG* pVal);
	STDMETHOD(put_ContentLength)(LONG newVal);
	STDMETHOD(get_Header)(BSTR* pVal);
	STDMETHOD(put_Header)(BSTR newVal);
	STDMETHOD(get_ContentText)(BSTR* pVal);
	STDMETHOD(put_ContentText)(BSTR newVal);
	STDMETHOD(get_ErrorCode)(LONG* pVal);
	STDMETHOD(put_ErrorCode)(LONG newVal);
private:
	TCHAR m_szContentType[MAX_PATH];
	TCHAR* m_szHeader;
	TCHAR* m_szContentText;
	LONG m_lStatusCode;
	LONG m_lContentLength;
	LONG m_lErrorCode;
};

OBJECT_ENTRY_AUTO(__uuidof(HttpResponse), HttpResponse)
