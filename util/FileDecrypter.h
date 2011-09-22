// FileDecrypter.h : FileDecrypter 的声明

#pragma once
#include "resource.h"       // 主符号

#include "util.h"
#include "testp11.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// FileDecrypter

class ATL_NO_VTABLE FileDecrypter :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<FileDecrypter, &CLSID_FileDecrypter>,
	public IObjectWithSiteImpl<FileDecrypter>,
	public IDispatchImpl<IFileDecrypter, &IID_IFileDecrypter, &LIBID_utilLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IObjectSafetyImpl<FileDecrypter,INTERFACESAFE_FOR_UNTRUSTED_CALLER |INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	FileDecrypter()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FILEDECRYPTER)


BEGIN_COM_MAP(FileDecrypter)
	COM_INTERFACE_ENTRY(IFileDecrypter)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		hSession=0;
		loadDllPkcs11_Lib();
		return S_OK;
	}

	void FinalRelease()
	{
		if (hSession) WT11_LogOutFinalize(hSession);
		freeDllPkcs11_Lib();
	}
private:
	CK_SESSION_HANDLE hSession;
public:
	STDMETHOD(DecryptFile)(BSTR mailer, BSTR out_mailer, BSTR* rtinfo);
private:
	void ErrorMsgBox(DWORD dwErrorCode,TCHAR* szTemplet);	//获取错误码（dwErrorCode）对应的错误消息，并把消息用（szTemplet）的文本模板输出（如果文本模板部提供，则只输出dwErrorCode对应错误消息）到错误提示对话框。
	void InfoMsgBox(TCHAR* szTip);	//输出szTip为消息内容的提示消息对话框。
	void loadDllPkcs11_Lib();//转载p11dll
	void freeDllPkcs11_Lib();//卸载p11dll
	bool GetPinDlg(unsigned char *pin);
	void __DecryptFile(BSTR provider_name, BSTR container_name, BSTR bsPin, BSTR mailer, BSTR out_mailer, BSTR* rtinfo);
	STDMETHOD(NewDecryptFile)(BSTR provider_name, BSTR container_name, BSTR mailer, BSTR out_mailer, BSTR* rtinfo);
	STDMETHOD(PIN_DecryptFile)(BSTR pin, BSTR mailer, BSTR out_mailer, BSTR* rtinfo);
	STDMETHOD(HAND_DecryptFile)(BSTR provider_name, BSTR container_name, BSTR bsPin, BSTR mailer, BSTR out_mailer, BSTR* rtinfo);
	STDMETHOD(P11LogOutFinalize)(void);//释放P11
	STDMETHOD(FindCertByUser)(BSTR provider_name, BSTR cuser, BSTR* ccontainer);
};

OBJECT_ENTRY_AUTO(__uuidof(FileDecrypter), FileDecrypter)
