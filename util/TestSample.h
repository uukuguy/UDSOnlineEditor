// TestSample.h : CTestSample 的声明

#pragma once
#include "resource.h"       // 主符号

#include "util.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// CTestSample

class ATL_NO_VTABLE CTestSample :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTestSample, &CLSID_TestSample>,
	public IDispatchImpl<ITestSample, &IID_ITestSample, &LIBID_utilLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CTestSample()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TESTSAMPLE)


BEGIN_COM_MAP(CTestSample)
	COM_INTERFACE_ENTRY(ITestSample)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		//InfoMsgBox(_T("construct"));
		num = 0;
		return S_OK;
	}

	void FinalRelease()
	{
		//InfoMsgBox(_T("release"));
	}

public:
	void InfoMsgBox(TCHAR* szTip);	//输出szTip为消息内容的提示消息对话框。

public:
	STDMETHOD(FindCerts)(void);
private:
	int num;
	STDMETHOD(AddNums)(BSTR* rtnum);
	STDMETHOD(FindCertByUser)(BSTR cuser,BSTR* ccontainer);
};

OBJECT_ENTRY_AUTO(__uuidof(TestSample), CTestSample)
