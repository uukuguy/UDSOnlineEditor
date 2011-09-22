

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Sep 22 21:03:00 2011
 */
/* Compiler settings for .\net.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __net_h__
#define __net_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHttpResponse_FWD_DEFINED__
#define __IHttpResponse_FWD_DEFINED__
typedef interface IHttpResponse IHttpResponse;
#endif 	/* __IHttpResponse_FWD_DEFINED__ */


#ifndef __IHttpRequest_FWD_DEFINED__
#define __IHttpRequest_FWD_DEFINED__
typedef interface IHttpRequest IHttpRequest;
#endif 	/* __IHttpRequest_FWD_DEFINED__ */


#ifndef ___IHttpRequestEvents_FWD_DEFINED__
#define ___IHttpRequestEvents_FWD_DEFINED__
typedef interface _IHttpRequestEvents _IHttpRequestEvents;
#endif 	/* ___IHttpRequestEvents_FWD_DEFINED__ */


#ifndef __HttpRequest_FWD_DEFINED__
#define __HttpRequest_FWD_DEFINED__

#ifdef __cplusplus
typedef class HttpRequest HttpRequest;
#else
typedef struct HttpRequest HttpRequest;
#endif /* __cplusplus */

#endif 	/* __HttpRequest_FWD_DEFINED__ */


#ifndef ___IHttpResponseEvents_FWD_DEFINED__
#define ___IHttpResponseEvents_FWD_DEFINED__
typedef interface _IHttpResponseEvents _IHttpResponseEvents;
#endif 	/* ___IHttpResponseEvents_FWD_DEFINED__ */


#ifndef __HttpResponse_FWD_DEFINED__
#define __HttpResponse_FWD_DEFINED__

#ifdef __cplusplus
typedef class HttpResponse HttpResponse;
#else
typedef struct HttpResponse HttpResponse;
#endif /* __cplusplus */

#endif 	/* __HttpResponse_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IHttpResponse_INTERFACE_DEFINED__
#define __IHttpResponse_INTERFACE_DEFINED__

/* interface IHttpResponse */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IHttpResponse;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C6BDF3ED-45D6-44A4-8057-7B62F99B2403")
    IHttpResponse : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_StatusCode( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_StatusCode( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContentType( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ContentType( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContentText( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ContentText( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContentLength( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ContentLength( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Header( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Header( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorCode( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ErrorCode( 
            /* [in] */ LONG newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHttpResponseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHttpResponse * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHttpResponse * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHttpResponse * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHttpResponse * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHttpResponse * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHttpResponse * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHttpResponse * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_StatusCode )( 
            IHttpResponse * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_StatusCode )( 
            IHttpResponse * This,
            /* [in] */ LONG newVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContentType )( 
            IHttpResponse * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ContentType )( 
            IHttpResponse * This,
            /* [in] */ BSTR newVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContentText )( 
            IHttpResponse * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ContentText )( 
            IHttpResponse * This,
            /* [in] */ BSTR newVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ContentLength )( 
            IHttpResponse * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ContentLength )( 
            IHttpResponse * This,
            /* [in] */ LONG newVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Header )( 
            IHttpResponse * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Header )( 
            IHttpResponse * This,
            /* [in] */ BSTR newVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorCode )( 
            IHttpResponse * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ErrorCode )( 
            IHttpResponse * This,
            /* [in] */ LONG newVal);
        
        END_INTERFACE
    } IHttpResponseVtbl;

    interface IHttpResponse
    {
        CONST_VTBL struct IHttpResponseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHttpResponse_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHttpResponse_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHttpResponse_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHttpResponse_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHttpResponse_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHttpResponse_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHttpResponse_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHttpResponse_get_StatusCode(This,pVal)	\
    ( (This)->lpVtbl -> get_StatusCode(This,pVal) ) 

#define IHttpResponse_put_StatusCode(This,newVal)	\
    ( (This)->lpVtbl -> put_StatusCode(This,newVal) ) 

#define IHttpResponse_get_ContentType(This,pVal)	\
    ( (This)->lpVtbl -> get_ContentType(This,pVal) ) 

#define IHttpResponse_put_ContentType(This,newVal)	\
    ( (This)->lpVtbl -> put_ContentType(This,newVal) ) 

#define IHttpResponse_get_ContentText(This,pVal)	\
    ( (This)->lpVtbl -> get_ContentText(This,pVal) ) 

#define IHttpResponse_put_ContentText(This,newVal)	\
    ( (This)->lpVtbl -> put_ContentText(This,newVal) ) 

#define IHttpResponse_get_ContentLength(This,pVal)	\
    ( (This)->lpVtbl -> get_ContentLength(This,pVal) ) 

#define IHttpResponse_put_ContentLength(This,newVal)	\
    ( (This)->lpVtbl -> put_ContentLength(This,newVal) ) 

#define IHttpResponse_get_Header(This,pVal)	\
    ( (This)->lpVtbl -> get_Header(This,pVal) ) 

#define IHttpResponse_put_Header(This,newVal)	\
    ( (This)->lpVtbl -> put_Header(This,newVal) ) 

#define IHttpResponse_get_ErrorCode(This,pVal)	\
    ( (This)->lpVtbl -> get_ErrorCode(This,pVal) ) 

#define IHttpResponse_put_ErrorCode(This,newVal)	\
    ( (This)->lpVtbl -> put_ErrorCode(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHttpResponse_INTERFACE_DEFINED__ */


#ifndef __IHttpRequest_INTERFACE_DEFINED__
#define __IHttpRequest_INTERFACE_DEFINED__

/* interface IHttpRequest */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IHttpRequest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("80B48C37-5703-41FC-BDBB-F42FC5C482CF")
    IHttpRequest : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Url( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Url( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SessionKey( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SessionKey( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Method( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Method( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowRequestProgress( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowRequestProgress( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_PostFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_PostFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SaveResponseToFile( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SaveResponseToFile( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [retval][out] */ IHttpResponse **pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UrlProtocol( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UrlPort( 
            /* [retval][out] */ USHORT *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UrlHost( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UrlFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UrlIsSSL( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE AddHeader( 
            /* [in] */ BSTR szName,
            /* [in] */ BSTR szValue) = 0;
        
        virtual /* [helpcontext][helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ResponseFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpcontext][helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ResponseFile( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHttpRequestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHttpRequest * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHttpRequest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHttpRequest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHttpRequest * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHttpRequest * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHttpRequest * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHttpRequest * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Url )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Url )( 
            IHttpRequest * This,
            /* [in] */ BSTR newVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SessionKey )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SessionKey )( 
            IHttpRequest * This,
            /* [in] */ BSTR newVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Method )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Method )( 
            IHttpRequest * This,
            /* [in] */ BSTR newVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowRequestProgress )( 
            IHttpRequest * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowRequestProgress )( 
            IHttpRequest * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PostFile )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PostFile )( 
            IHttpRequest * This,
            /* [in] */ BSTR newVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SaveResponseToFile )( 
            IHttpRequest * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SaveResponseToFile )( 
            IHttpRequest * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Send )( 
            IHttpRequest * This,
            /* [retval][out] */ IHttpResponse **pVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UrlProtocol )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UrlPort )( 
            IHttpRequest * This,
            /* [retval][out] */ USHORT *pVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UrlHost )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UrlFile )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UrlIsSSL )( 
            IHttpRequest * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddHeader )( 
            IHttpRequest * This,
            /* [in] */ BSTR szName,
            /* [in] */ BSTR szValue);
        
        /* [helpcontext][helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResponseFile )( 
            IHttpRequest * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpcontext][helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ResponseFile )( 
            IHttpRequest * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IHttpRequestVtbl;

    interface IHttpRequest
    {
        CONST_VTBL struct IHttpRequestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHttpRequest_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHttpRequest_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHttpRequest_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHttpRequest_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHttpRequest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHttpRequest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHttpRequest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHttpRequest_get_Url(This,pVal)	\
    ( (This)->lpVtbl -> get_Url(This,pVal) ) 

#define IHttpRequest_put_Url(This,newVal)	\
    ( (This)->lpVtbl -> put_Url(This,newVal) ) 

#define IHttpRequest_get_SessionKey(This,pVal)	\
    ( (This)->lpVtbl -> get_SessionKey(This,pVal) ) 

#define IHttpRequest_put_SessionKey(This,newVal)	\
    ( (This)->lpVtbl -> put_SessionKey(This,newVal) ) 

#define IHttpRequest_get_Method(This,pVal)	\
    ( (This)->lpVtbl -> get_Method(This,pVal) ) 

#define IHttpRequest_put_Method(This,newVal)	\
    ( (This)->lpVtbl -> put_Method(This,newVal) ) 

#define IHttpRequest_get_ShowRequestProgress(This,pVal)	\
    ( (This)->lpVtbl -> get_ShowRequestProgress(This,pVal) ) 

#define IHttpRequest_put_ShowRequestProgress(This,newVal)	\
    ( (This)->lpVtbl -> put_ShowRequestProgress(This,newVal) ) 

#define IHttpRequest_get_PostFile(This,pVal)	\
    ( (This)->lpVtbl -> get_PostFile(This,pVal) ) 

#define IHttpRequest_put_PostFile(This,newVal)	\
    ( (This)->lpVtbl -> put_PostFile(This,newVal) ) 

#define IHttpRequest_get_SaveResponseToFile(This,pVal)	\
    ( (This)->lpVtbl -> get_SaveResponseToFile(This,pVal) ) 

#define IHttpRequest_put_SaveResponseToFile(This,newVal)	\
    ( (This)->lpVtbl -> put_SaveResponseToFile(This,newVal) ) 

#define IHttpRequest_Send(This,pVal)	\
    ( (This)->lpVtbl -> Send(This,pVal) ) 

#define IHttpRequest_get_UrlProtocol(This,pVal)	\
    ( (This)->lpVtbl -> get_UrlProtocol(This,pVal) ) 

#define IHttpRequest_get_UrlPort(This,pVal)	\
    ( (This)->lpVtbl -> get_UrlPort(This,pVal) ) 

#define IHttpRequest_get_UrlHost(This,pVal)	\
    ( (This)->lpVtbl -> get_UrlHost(This,pVal) ) 

#define IHttpRequest_get_UrlFile(This,pVal)	\
    ( (This)->lpVtbl -> get_UrlFile(This,pVal) ) 

#define IHttpRequest_get_UrlIsSSL(This,pVal)	\
    ( (This)->lpVtbl -> get_UrlIsSSL(This,pVal) ) 

#define IHttpRequest_AddHeader(This,szName,szValue)	\
    ( (This)->lpVtbl -> AddHeader(This,szName,szValue) ) 

#define IHttpRequest_get_ResponseFile(This,pVal)	\
    ( (This)->lpVtbl -> get_ResponseFile(This,pVal) ) 

#define IHttpRequest_put_ResponseFile(This,newVal)	\
    ( (This)->lpVtbl -> put_ResponseFile(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHttpRequest_INTERFACE_DEFINED__ */



#ifndef __netLib_LIBRARY_DEFINED__
#define __netLib_LIBRARY_DEFINED__

/* library netLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_netLib;

#ifndef ___IHttpRequestEvents_DISPINTERFACE_DEFINED__
#define ___IHttpRequestEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IHttpRequestEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IHttpRequestEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("61BBE002-0D56-4147-A3FC-4577EF77334D")
    _IHttpRequestEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IHttpRequestEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IHttpRequestEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IHttpRequestEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IHttpRequestEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IHttpRequestEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IHttpRequestEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IHttpRequestEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IHttpRequestEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IHttpRequestEventsVtbl;

    interface _IHttpRequestEvents
    {
        CONST_VTBL struct _IHttpRequestEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IHttpRequestEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IHttpRequestEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IHttpRequestEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IHttpRequestEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IHttpRequestEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IHttpRequestEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IHttpRequestEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IHttpRequestEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_HttpRequest;

#ifdef __cplusplus

class DECLSPEC_UUID("99C0FB3E-3871-43DF-9316-C524FD8F0E02")
HttpRequest;
#endif

#ifndef ___IHttpResponseEvents_DISPINTERFACE_DEFINED__
#define ___IHttpResponseEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IHttpResponseEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IHttpResponseEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3AE591E6-5016-470D-8524-316F779374F0")
    _IHttpResponseEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IHttpResponseEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IHttpResponseEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IHttpResponseEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IHttpResponseEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IHttpResponseEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IHttpResponseEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IHttpResponseEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IHttpResponseEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IHttpResponseEventsVtbl;

    interface _IHttpResponseEvents
    {
        CONST_VTBL struct _IHttpResponseEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IHttpResponseEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IHttpResponseEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IHttpResponseEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IHttpResponseEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IHttpResponseEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IHttpResponseEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IHttpResponseEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IHttpResponseEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_HttpResponse;

#ifdef __cplusplus

class DECLSPEC_UUID("72AD7AD0-47B7-4C3B-9455-7312B46F55D3")
HttpResponse;
#endif
#endif /* __netLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


