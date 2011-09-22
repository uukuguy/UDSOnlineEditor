// OEEditing.h : Declaration of the COEEditing

#pragma once
#include "resource.h"       // main symbols

#include "OEService_i.h"
#include "_IOEEditingEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// COEEditing

class ATL_NO_VTABLE COEEditing :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COEEditing, &CLSID_OEEditing>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<COEEditing>,
	public CProxy_IOEEditingEvents<COEEditing>,
	public IDispatchImpl<IOEEditing, &IID_IOEEditing, &LIBID_OEServiceLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	COEEditing()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_OEEDITING)


BEGIN_COM_MAP(COEEditing)
	COM_INTERFACE_ENTRY(IOEEditing)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(COEEditing)
	CONNECTION_POINT_ENTRY(__uuidof(_IOEEditingEvents))
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

	STDMETHOD(OpenWord)(BSTR fileName, BSTR uploadURL, BSTR* docID);
	STDMETHOD(CloseEditingDocument)(BSTR docID, BSTR docInfo);
	STDMETHOD(FetchDocumentInfo)(BSTR docID, BSTR* docInfo);
};

OBJECT_ENTRY_AUTO(__uuidof(OEEditing), COEEditing)
