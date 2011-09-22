

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Sep 14 02:44:20 2011
 */
/* Compiler settings for .\OEProxy.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __OEProxy_i_h__
#define __OEProxy_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOELauncher_FWD_DEFINED__
#define __IOELauncher_FWD_DEFINED__
typedef interface IOELauncher IOELauncher;
#endif 	/* __IOELauncher_FWD_DEFINED__ */


#ifndef ___IOELauncherEvents_FWD_DEFINED__
#define ___IOELauncherEvents_FWD_DEFINED__
typedef interface _IOELauncherEvents _IOELauncherEvents;
#endif 	/* ___IOELauncherEvents_FWD_DEFINED__ */


#ifndef __OELauncher_FWD_DEFINED__
#define __OELauncher_FWD_DEFINED__

#ifdef __cplusplus
typedef class OELauncher OELauncher;
#else
typedef struct OELauncher OELauncher;
#endif /* __cplusplus */

#endif 	/* __OELauncher_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOELauncher_INTERFACE_DEFINED__
#define __IOELauncher_INTERFACE_DEFINED__

/* interface IOELauncher */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOELauncher;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("89A20F8C-72C6-4E05-8BBB-184039216A26")
    IOELauncher : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EditWordDocument( 
            /* [in] */ BSTR fileName,
            /* [in] */ BSTR uploadURL,
            /* [retval][out] */ BSTR *xmlDocInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOELauncherVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOELauncher * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOELauncher * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOELauncher * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOELauncher * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOELauncher * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOELauncher * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOELauncher * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EditWordDocument )( 
            IOELauncher * This,
            /* [in] */ BSTR fileName,
            /* [in] */ BSTR uploadURL,
            /* [retval][out] */ BSTR *xmlDocInfo);
        
        END_INTERFACE
    } IOELauncherVtbl;

    interface IOELauncher
    {
        CONST_VTBL struct IOELauncherVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOELauncher_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOELauncher_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOELauncher_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOELauncher_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOELauncher_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOELauncher_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOELauncher_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOELauncher_EditWordDocument(This,fileName,uploadURL,xmlDocInfo)	\
    ( (This)->lpVtbl -> EditWordDocument(This,fileName,uploadURL,xmlDocInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOELauncher_INTERFACE_DEFINED__ */



#ifndef __OEProxyLib_LIBRARY_DEFINED__
#define __OEProxyLib_LIBRARY_DEFINED__

/* library OEProxyLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OEProxyLib;

#ifndef ___IOELauncherEvents_DISPINTERFACE_DEFINED__
#define ___IOELauncherEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOELauncherEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOELauncherEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("ABF6AA8B-FD5A-49D6-ACED-0523CEF09B20")
    _IOELauncherEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOELauncherEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IOELauncherEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IOELauncherEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IOELauncherEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IOELauncherEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IOELauncherEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IOELauncherEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IOELauncherEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IOELauncherEventsVtbl;

    interface _IOELauncherEvents
    {
        CONST_VTBL struct _IOELauncherEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOELauncherEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IOELauncherEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IOELauncherEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IOELauncherEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IOELauncherEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IOELauncherEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IOELauncherEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOELauncherEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OELauncher;

#ifdef __cplusplus

class DECLSPEC_UUID("89C5CDD8-D5EF-4FEB-9B1C-915EC2AF9A86")
OELauncher;
#endif
#endif /* __OEProxyLib_LIBRARY_DEFINED__ */

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


