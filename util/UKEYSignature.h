// UKEYSignature.h : UKEYSignature 的声明

#pragma once
#include "resource.h"       // 主符号

#include "util.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// UKEYSignature

class ATL_NO_VTABLE UKEYSignature :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<UKEYSignature, &CLSID_UKEYSignature>,
	public IObjectWithSiteImpl<UKEYSignature>,
	public IDispatchImpl<IUKEYSignature, &IID_IUKEYSignature, &LIBID_utilLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IObjectSafetyImpl<UKEYSignature,INTERFACESAFE_FOR_UNTRUSTED_CALLER |INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	UKEYSignature()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_UKEYSIGNATURE)


BEGIN_COM_MAP(UKEYSignature)
	COM_INTERFACE_ENTRY(IUKEYSignature)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:
	STDMETHOD(Sign)(BSTR szMessage,BSTR* szSignature);
	STDMETHOD(VerifySignature)(BSTR szSignature,BSTR szMessage,VARIANT_BOOL* blRet);
	STDMETHOD(getCertXML)(BSTR* szXml);
private:
	void ErrorMsgBox(DWORD dwErrorCode,TCHAR* szTemplet);	//获取错误码（dwErrorCode）对应的错误消息，并把消息用（szTemplet）的文本模板输出（如果文本模板部提供，则只输出dwErrorCode对应错误消息）到错误提示对话框。
	void InfoMsgBox(TCHAR* szTip);	//输出szTip为消息内容的提示消息对话框。
	void __Sign(BSTR provider_name, BSTR container_name, BSTR szMessage, BSTR szSignature_dat, BSTR cuser, BSTR* szSignature);
	STDMETHOD(NewSign)(BSTR provider_name, BSTR container_name, BSTR szMessage, BSTR szSignature_dat, BSTR* szSignature);
	STDMETHOD(HAND_Sign)(BSTR provider_name, BSTR container_name, BSTR szMessage, BSTR szSignature_dat, BSTR cuser, BSTR* szSignature);
	STDMETHOD(SignByUser)(BSTR szMessage, BSTR szUser, BSTR* szSignature);
	STDMETHOD(GetCertSId)(BSTR inCertName, BSTR* outCertSid);
	STDMETHOD(GetCertSubject)(BSTR inCertName, BSTR* outSubject);
};

OBJECT_ENTRY_AUTO(__uuidof(UKEYSignature), UKEYSignature)
