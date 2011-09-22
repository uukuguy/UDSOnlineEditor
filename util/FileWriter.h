// FileWriter.h : FileWriter 的声明

#pragma once
#include "resource.h"       // 主符号

#include "util.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif



// FileWriter

class ATL_NO_VTABLE FileWriter :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<FileWriter, &CLSID_FileWriter>,
	public IObjectWithSiteImpl<FileWriter>,
	public IDispatchImpl<IFileWriter, &IID_IFileWriter, &LIBID_utilLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IObjectSafetyImpl<FileWriter,INTERFACESAFE_FOR_UNTRUSTED_CALLER |INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	FileWriter()
	{
		ZeroMemory(m_szFilePath,MAX_PATH*sizeof(TCHAR));
		m_szContent=NULL;
		m_blClosed=FALSE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FILEWRITER)


BEGIN_COM_MAP(FileWriter)
	COM_INTERFACE_ENTRY(IFileWriter)
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
		if (this->m_szContent){
			delete this->m_szContent;
			m_szContent=NULL;
		}
	}

public:
	STDMETHOD(CreateFile)(BSTR szFileName);
	STDMETHOD(AppendFileContent)(BSTR szContent);
	STDMETHOD(WriteFile)(VARIANT_BOOL* blSuccess);
private:
	TCHAR m_szFilePath[MAX_PATH];
	TCHAR* m_szContent;
	BOOL m_blClosed;
};

OBJECT_ENTRY_AUTO(__uuidof(FileWriter), FileWriter)
