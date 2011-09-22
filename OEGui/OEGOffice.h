// OEGOffice.h : Declaration of the COEGOffice
#pragma once
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "OEGui_i.h"
#include "_IOEGOfficeEvents_CP.h"
#include "../DsoFramer_V2.3.0.1/Lib/dsoframerlib.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


// COEGOffice
class ATL_NO_VTABLE COEGOffice :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<COEGOffice, IOEGOffice>,
	public IPersistStreamInitImpl<COEGOffice>,
	public IOleControlImpl<COEGOffice>,
	public IOleObjectImpl<COEGOffice>,
	public IOleInPlaceActiveObjectImpl<COEGOffice>,
	public IViewObjectExImpl<COEGOffice>,
	public IOleInPlaceObjectWindowlessImpl<COEGOffice>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<COEGOffice>,
	public CProxy_IOEGOfficeEvents<COEGOffice>,
	public IObjectWithSiteImpl<COEGOffice>,
	public IServiceProviderImpl<COEGOffice>,
	public IPersistStorageImpl<COEGOffice>,
	public ISpecifyPropertyPagesImpl<COEGOffice>,
	public IQuickActivateImpl<COEGOffice>,
#ifndef _WIN32_WCE
	public IDataObjectImpl<COEGOffice>,
#endif
	public IProvideClassInfo2Impl<&CLSID_OEGOffice, &__uuidof(_IOEGOfficeEvents), &LIBID_OEGuiLib>,
	public IPropertyNotifySinkCP<COEGOffice>,
//#ifdef _WIN32_WCE // IObjectSafety is required on Windows CE for the control to be loaded correctly
	public IObjectSafetyImpl<COEGOffice, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
//#endif
	public CComCoClass<COEGOffice, &CLSID_OEGOffice>,
	public CComCompositeControl<COEGOffice>
{
private:
	_FramerControl* GetFramerControl();
	IUnknown* GetUnknownCP();
	//IUnknown* GetUnknown();
	DWORD m_dwCookie;
	CComBSTR m_bstrFileName;

	IDispatch* GetActiveDocument();

public:


	COEGOffice()
	{
		m_bWindowOnly = TRUE;
		CalcExtent(m_sizeExtent);
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_INSIDEOUT |
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST
)

DECLARE_REGISTRY_RESOURCEID(IDR_OEGOFFICE)


BEGIN_COM_MAP(COEGOffice)
	COM_INTERFACE_ENTRY(IOEGOffice)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
#ifndef _WIN32_WCE
	COM_INTERFACE_ENTRY(IDataObject)
#endif
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IServiceProvider)
//#ifdef _WIN32_WCE // IObjectSafety is required on Windows CE for the control to be loaded correctly
	COM_INTERFACE_ENTRY_IID(IID_IObjectSafety, IObjectSafety)
//#endif
END_COM_MAP()

BEGIN_PROP_MAP(COEGOffice)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY_TYPE("AutoSize", DISPID_AUTOSIZE, CLSID_NULL, VT_BOOL)
	PROP_ENTRY_TYPE("BorderVisible", DISPID_BORDERVISIBLE, CLSID_NULL, VT_BOOL)
	PROP_ENTRY_TYPE("Enabled", DISPID_ENABLED, CLSID_NULL, VT_BOOL)
	// Example entries
	// PROP_ENTRY_TYPE("Property Name", dispid, clsid, vtType)
	// PROP_PAGE(CLSID_StockColorPage)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(COEGOffice)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(__uuidof(_IOEGOfficeEvents))
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(COEGOffice)
	CHAIN_MSG_MAP(CComCompositeControl<COEGOffice>)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

BEGIN_SINK_MAP(COEGOffice)
	//Make sure the Event Handlers have __stdcall calling convention
END_SINK_MAP()

	STDMETHOD(OnAmbientPropertyChange)(DISPID dispid)
	{
		if (dispid == DISPID_AMBIENT_BACKCOLOR)
		{
			SetBackgroundColorFromAmbient();
			FireViewChange();
		}
		return IOleControlImpl<COEGOffice>::OnAmbientPropertyChange(dispid);
	}
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* arr[] =
		{
			&IID_IOEGOffice,
		};

		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IOEGOffice
	void OnAutoSizeChanged()
	{
		ATLTRACE(_T("OnAutoSizeChanged\n"));
	}
	BOOL m_bBorderVisible;
	void OnBorderVisibleChanged()
	{
		ATLTRACE(_T("OnBorderVisibleChanged\n"));
	}
	BOOL m_bEnabled;
	void OnEnabledChanged()
	{
		ATLTRACE(_T("OnEnabledChanged\n"));
	}

	enum { IDD = IDD_OEGOFFICE };
	STDMETHOD(_InternalQueryService)(REFGUID guidService, REFIID riid, void** ppvObject)
	{
		return E_NOTIMPL;
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	STDMETHOD(get_DocComments)(BSTR* pVal);
	STDMETHOD(get_DocRevisions)(BSTR* pVal);
	STDMETHOD(OpenDocument)(BSTR filename, VARIANT_BOOL bReadonly, VARIANT_BOOL* opened);
	STDMETHOD(CloseDocument)(VARIANT_BOOL* closed);
	STDMETHOD(SaveDocument)(VARIANT_BOOL* saved);
	STDMETHOD(get_ShowRevisions)(VARIANT_BOOL* pVal);
	STDMETHOD(put_ShowRevisions)(VARIANT_BOOL newVal);
	STDMETHOD(get_ShowComments)(VARIANT_BOOL* pVal);
	STDMETHOD(put_ShowComments)(VARIANT_BOOL newVal);
	STDMETHOD(UploadToUDS)(BSTR uploadURL, VARIANT_BOOL* uploaded);
	STDMETHOD(Test)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(OEGOffice), COEGOffice)
