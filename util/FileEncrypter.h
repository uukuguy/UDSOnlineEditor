// FileEncrypter.h : FileEncrypter 的声明

#pragma once
#include "resource.h"       // 主符号

#include "util.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// FileEncrypter

class ATL_NO_VTABLE FileEncrypter :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<FileEncrypter, &CLSID_FileEncrypter>,
	public ISupportErrorInfo,
	public IObjectWithSiteImpl<FileEncrypter>,
	public IDispatchImpl<IFileEncrypter, &IID_IFileEncrypter, &LIBID_utilLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IObjectSafetyImpl<FileEncrypter,INTERFACESAFE_FOR_UNTRUSTED_CALLER |INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	FileEncrypter()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FILEENCRYPTER)


BEGIN_COM_MAP(FileEncrypter)
	COM_INTERFACE_ENTRY(IFileEncrypter)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()

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
	STDMETHOD(EncryptFile)(BSTR szInFN,BSTR szOutFN,BSTR szPwd);
private:
	void ErrorMsgBox(DWORD dwErrorCode,TCHAR* szTemplet);	//获取错误码（dwErrorCode）对应的错误消息，并把消息用（szTemplet）的文本模板输出（如果文本模板部提供，则只输出dwErrorCode对应错误消息）到错误提示对话框。
	void InfoMsgBox(TCHAR* szTip);	//输出szTip为消息内容的提示消息对话框。
};

OBJECT_ENTRY_AUTO(__uuidof(FileEncrypter), FileEncrypter)
