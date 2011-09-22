

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Sun Sep 04 00:39:40 2011
 */
/* Compiler settings for .\OEService.idl:
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

#ifndef __OEService_i_h__
#define __OEService_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOEEditing_FWD_DEFINED__
#define __IOEEditing_FWD_DEFINED__
typedef interface IOEEditing IOEEditing;
#endif 	/* __IOEEditing_FWD_DEFINED__ */


#ifndef ___IOEEditingEvents_FWD_DEFINED__
#define ___IOEEditingEvents_FWD_DEFINED__
typedef interface _IOEEditingEvents _IOEEditingEvents;
#endif 	/* ___IOEEditingEvents_FWD_DEFINED__ */


#ifndef __OEEditing_FWD_DEFINED__
#define __OEEditing_FWD_DEFINED__

#ifdef __cplusplus
typedef class OEEditing OEEditing;
#else
typedef struct OEEditing OEEditing;
#endif /* __cplusplus */

#endif 	/* __OEEditing_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOEEditing_INTERFACE_DEFINED__
#define __IOEEditing_INTERFACE_DEFINED__

/* interface IOEEditing */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOEEditing;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C49F79D8-96E1-42A5-91FD-1FC4E28F6165")
    IOEEditing : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenWord( 
            /* [in] */ BSTR fileName,
            /* [in] */ BSTR uploadURL,
            /* [retval][out] */ BSTR *docID) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseEditingDocument( 
            /* [in] */ BSTR docID,
            /* [in] */ BSTR docInfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FetchDocumentInfo( 
            /* [in] */ BSTR docID,
            /* [retval][out] */ BSTR *docInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOEEditingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOEEditing * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOEEditing * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOEEditing * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOEEditing * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOEEditing * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOEEditing * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOEEditing * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenWord )( 
            IOEEditing * This,
            /* [in] */ BSTR fileName,
            /* [in] */ BSTR uploadURL,
            /* [retval][out] */ BSTR *docID);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseEditingDocument )( 
            IOEEditing * This,
            /* [in] */ BSTR docID,
            /* [in] */ BSTR docInfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FetchDocumentInfo )( 
            IOEEditing * This,
            /* [in] */ BSTR docID,
            /* [retval][out] */ BSTR *docInfo);
        
        END_INTERFACE
    } IOEEditingVtbl;

    interface IOEEditing
    {
        CONST_VTBL struct IOEEditingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOEEditing_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOEEditing_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOEEditing_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOEEditing_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOEEditing_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOEEditing_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOEEditing_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOEEditing_OpenWord(This,fileName,uploadURL,docID)	\
    ( (This)->lpVtbl -> OpenWord(This,fileName,uploadURL,docID) ) 

#define IOEEditing_CloseEditingDocument(This,docID,docInfo)	\
    ( (This)->lpVtbl -> CloseEditingDocument(This,docID,docInfo) ) 

#define IOEEditing_FetchDocumentInfo(This,docID,docInfo)	\
    ( (This)->lpVtbl -> FetchDocumentInfo(This,docID,docInfo) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOEEditing_INTERFACE_DEFINED__ */



#ifndef __OEServiceLib_LIBRARY_DEFINED__
#define __OEServiceLib_LIBRARY_DEFINED__

/* library OEServiceLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OEServiceLib;

#ifndef ___IOEEditingEvents_DISPINTERFACE_DEFINED__
#define ___IOEEditingEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOEEditingEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOEEditingEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("3A388A23-591E-4E78-AAFA-2E42AD06A438")
    _IOEEditingEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOEEditingEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IOEEditingEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IOEEditingEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IOEEditingEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IOEEditingEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IOEEditingEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IOEEditingEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IOEEditingEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IOEEditingEventsVtbl;

    interface _IOEEditingEvents
    {
        CONST_VTBL struct _IOEEditingEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOEEditingEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IOEEditingEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IOEEditingEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IOEEditingEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IOEEditingEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IOEEditingEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IOEEditingEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOEEditingEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OEEditing;

#ifdef __cplusplus

class DECLSPEC_UUID("E69FEC44-1B28-4BF4-B07F-9EBCACE48D79")
OEEditing;
#endif
#endif /* __OEServiceLib_LIBRARY_DEFINED__ */

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


