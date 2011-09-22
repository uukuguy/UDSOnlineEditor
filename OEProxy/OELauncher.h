// OELauncher.h : Declaration of the COELauncher

#pragma once
#include "resource.h"       // main symbols

#include "OEProxy_i.h"
#include "_IOELauncherEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// COELauncher

class ATL_NO_VTABLE COELauncher :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COELauncher, &CLSID_OELauncher>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<COELauncher>,
	public CProxy_IOELauncherEvents<COELauncher>,
	public IObjectWithSiteImpl<COELauncher>,
	public IDispatchImpl<IOELauncher, &IID_IOELauncher, &LIBID_OEProxyLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	COELauncher()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_OELAUNCHER)


BEGIN_COM_MAP(COELauncher)
	COM_INTERFACE_ENTRY(IOELauncher)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectWithSite)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(COELauncher)
	CONNECTION_POINT_ENTRY(__uuidof(_IOELauncherEvents))
END_CONNECTION_POINT_MAP()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHOD(EditWordDocument)(BSTR fileName, BSTR uploadURL, BSTR* xmlDocInfo);
};

OBJECT_ENTRY_AUTO(__uuidof(OELauncher), COELauncher)
