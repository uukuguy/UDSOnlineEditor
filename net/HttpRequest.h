// HttpRequest.h : HttpRequest 的声明

#pragma once
#include "resource.h"       // 主符号
#include "HttpResponse.h"
#include "net.h"
#include "PictureExWnd.h"
#include "_IHttpRequestEvents_CP.h"
#include <SHLGUID.h>
#include <wininet.h>

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

#define DEFAULT_HTTP_PORT 80
#define DEFAULT_HTTPS_PORT 443
#define USER_AGENT	_T("YRExchange.HttpRequest")

void CALLBACK INetStatusCallBack(HINTERNET hInternet, DWORD dwContext, DWORD dwInternetStatus,LPVOID lpvStatusInformation, DWORD dwStatusInformationLength);
LRESULT CALLBACK Static1WndProc(HWND hwnd,UINT uMsg,WPARAM wParam,LPARAM lParam);
BOOL CALLBACK ProgressProc(HWND, UINT, WPARAM, LPARAM);
DWORD WINAPI ProgressDialog(LPVOID lpParam);

typedef struct {
	HWND			hWindow;			//主窗体句柄
	HWND			hProgressWnd;	//进度窗体句柄
	HINTERNET	hOpen;			//InternetOpen打开的句柄
	TCHAR			szMemo[STRLEN_DEFAULT];	//请求状态提示文本
	HANDLE		hThread;	//HTTP请求线程句柄
	DWORD			dwThreadID;	//HTTP请求线程ID
	DWORD			dwContentLength;	//HTTP响应大小
	DWORD			dwReceivedLength;	//已接收HTTP响应大小
	DWORD			dwPostFileLength;	//发送文件大小
	DWORD			dwPostedLength;		//已发送大小。
} REQUEST_CONTEXT;

static REQUEST_CONTEXT rcContext;

CPictureExWnd m_wndBanner;
HWND hWndGif;
// HttpRequest

class ATL_NO_VTABLE HttpRequest :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<HttpRequest, &CLSID_HttpRequest>,
	public IConnectionPointContainerImpl<HttpRequest>,
	public CProxy_IHttpRequestEvents<HttpRequest>,
	public IObjectWithSiteImpl<HttpRequest>,
	public IDispatchImpl<IHttpRequest, &IID_IHttpRequest, &LIBID_netLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IObjectSafetyImpl<HttpRequest,INTERFACESAFE_FOR_UNTRUSTED_CALLER |INTERFACESAFE_FOR_UNTRUSTED_DATA>
{
public:
	HttpRequest(){
		ZeroMemory(m_szUrl,sizeof(m_szUrl));

		ZeroMemory(m_szUrlProtocol,sizeof(m_szUrlProtocol));
		ZeroMemory(m_szUrlHost,sizeof(m_szUrlHost));
		ZeroMemory(m_szUrlFile,sizeof(m_szUrlFile));
		m_usUrlPort=80;
		m_blUrlIsSSL=VARIANT_FALSE;

		ZeroMemory(m_szSessionKey,sizeof(m_szSessionKey));
		ZeroMemory(m_szMethod,sizeof(m_szMethod));
		_tcscpy_s(m_szMethod,_T("POST"));
		ZeroMemory(m_szPostFile,sizeof(m_szPostFile));
		ZeroMemory(m_szResponseFile,sizeof(m_szResponseFile));
		m_blShowRequestProgress=VARIANT_TRUE;
		m_blSaveResponseToFile=VARIANT_FALSE;

		m_szHeader=NULL;

		m_spWebBrowser2=NULL;

		m_hOpen= InternetOpen(USER_AGENT,INTERNET_OPEN_TYPE_PRECONFIG,NULL,0,0);
		//设置回调函数
		if (this->m_hOpen){
			INTERNET_STATUS_CALLBACK iscCallback = InternetSetStatusCallback(this->m_hOpen,(INTERNET_STATUS_CALLBACK)INetStatusCallBack);
		}
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HTTPREQUEST)


BEGIN_COM_MAP(HttpRequest)
	COM_INTERFACE_ENTRY(IHttpRequest)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectWithSite)
	COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(HttpRequest)
	CONNECTION_POINT_ENTRY(__uuidof(_IHttpRequestEvents))
END_CONNECTION_POINT_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		SAFE_FREE_STRING_PTR(this->m_szHeader);
		if (this->m_hOpen) InternetCloseHandle(this->m_hOpen);
	}

	STDMETHODIMP HttpRequest::SetSite(IUnknown *pUnkSite)
	{
		/*if (!pUnkSite) {
			if (this->m_spWebBrowser2) m_spWebBrowser2.Release();
			m_spWebBrowser2=NULL;
			return S_OK;
		}*/
		CComQIPtr<IServiceProvider> spProv(pUnkSite);
		if (spProv)
		{
			CComPtr<IServiceProvider> spProv2;
			HRESULT hr = spProv->QueryService(SID_STopLevelBrowser, IID_IServiceProvider, reinterpret_cast<void **>(&spProv2));
			if (SUCCEEDED(hr) && spProv2){
				 hr=spProv2->QueryService(SID_SWebBrowserApp,IID_IWebBrowser2, reinterpret_cast<void **>(&m_spWebBrowser2));
			}
		}
		
		return S_OK;
	}

public:
	STDMETHOD(get_Url)(BSTR* pVal);
	STDMETHOD(put_Url)(BSTR newVal);
	STDMETHOD(get_SessionKey)(BSTR* pVal);
	STDMETHOD(put_SessionKey)(BSTR newVal);
	STDMETHOD(get_Method)(BSTR* pVal);
	STDMETHOD(put_Method)(BSTR newVal);
	STDMETHOD(get_ShowRequestProgress)(VARIANT_BOOL* pVal);
	STDMETHOD(put_ShowRequestProgress)(VARIANT_BOOL newVal);
	STDMETHOD(get_PostFile)(BSTR* pVal);
	STDMETHOD(put_PostFile)(BSTR newVal);
	STDMETHOD(get_SaveResponseToFile)(VARIANT_BOOL* pVal);
	STDMETHOD(put_SaveResponseToFile)(VARIANT_BOOL newVal);
	STDMETHOD(Send)(IHttpResponse** pVal);
	STDMETHOD(get_UrlProtocol)(BSTR* pVal);
	STDMETHOD(get_UrlPort)(USHORT* pVal);
	STDMETHOD(get_UrlHost)(BSTR* pVal);
	STDMETHOD(get_UrlFile)(BSTR* pVal);
	STDMETHOD(get_UrlIsSSL)(VARIANT_BOOL* pVal);
	STDMETHOD(AddHeader)(BSTR szName,BSTR szValue);
	STDMETHOD(get_ResponseFile)(BSTR* pVal);
	STDMETHOD(put_ResponseFile)(BSTR newVal);
private:
	TCHAR m_szUrl[STRLEN_4K];

	TCHAR m_szUrlProtocol[STRLEN_SMALL];
	TCHAR m_szUrlHost[STRLEN_4K];
	TCHAR m_szUrlFile[STRLEN_4K];
	USHORT m_usUrlPort;
	VARIANT_BOOL m_blUrlIsSSL;

	TCHAR* m_szHeader;

	TCHAR m_szSessionKey[STRLEN_DEFAULT];
	TCHAR m_szMethod[STRLEN_SMALL];
	TCHAR m_szPostFile[MAX_PATH];
	TCHAR m_szResponseFile[MAX_PATH];
	VARIANT_BOOL m_blShowRequestProgress;
	VARIANT_BOOL m_blSaveResponseToFile;

	CComPtr<IWebBrowser2> m_spWebBrowser2;		//浏览器对象

	HINTERNET m_hOpen;		//Internet句柄

	void ErrorMsgBox(DWORD dwErrorCode,TCHAR* szTemplet);	//获取错误码（dwErrorCode）对应的错误消息，并把消息用（szTemplet）的文本模板输出（如果文本模板部提供，则只输出dwErrorCode对应错误消息）到错误提示对话框。
	void InfoMsgBox(TCHAR* szTip);	//输出szTip为消息内容的提示消息对话框。
};

OBJECT_ENTRY_AUTO(__uuidof(HttpRequest), HttpRequest)
