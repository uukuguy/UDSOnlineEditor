// Dialog.h : Dialog 的声明

#pragma once
#include "resource.h"       // 主符号

#include "util.h"
#include "_IDialogEvents_CP.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// Dialog

class ATL_NO_VTABLE Dialog :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<Dialog, &CLSID_Dialog>,
	public IConnectionPointContainerImpl<Dialog>,
	public CProxy_IDialogEvents<Dialog>,
	public IObjectWithSiteImpl<Dialog>,
	public IDispatchImpl<IDialog, &IID_IDialog, &LIBID_utilLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IObjectSafetyImpl<Dialog,INTERFACESAFE_FOR_UNTRUSTED_CALLER |INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	Dialog()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DIALOG)


BEGIN_COM_MAP(Dialog)
	COM_INTERFACE_ENTRY(IDialog)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(Dialog)
	CONNECTION_POINT_ENTRY(__uuidof(_IDialogEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(SelectFolder)(BSTR* szFolderResult);
	STDMETHOD(SelectFiles)(BSTR szDefaultFileName,BSTR szTitle,BSTR szFilter,VARIANT_BOOL blAllowMultiSelect,BSTR* szFile);
	STDMETHOD(SaveFile)(BSTR szDefaultFileName,BSTR szTitle,BSTR szFilter,BSTR* szFile);
};

OBJECT_ENTRY_AUTO(__uuidof(Dialog), Dialog)
