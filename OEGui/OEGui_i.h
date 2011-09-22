

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Sep 22 20:15:49 2011
 */
/* Compiler settings for .\OEGui.idl:
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

#ifndef __OEGui_i_h__
#define __OEGui_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IOEGOffice_FWD_DEFINED__
#define __IOEGOffice_FWD_DEFINED__
typedef interface IOEGOffice IOEGOffice;
#endif 	/* __IOEGOffice_FWD_DEFINED__ */


#ifndef ___IOEGOfficeEvents_FWD_DEFINED__
#define ___IOEGOfficeEvents_FWD_DEFINED__
typedef interface _IOEGOfficeEvents _IOEGOfficeEvents;
#endif 	/* ___IOEGOfficeEvents_FWD_DEFINED__ */


#ifndef __OEGOffice_FWD_DEFINED__
#define __OEGOffice_FWD_DEFINED__

#ifdef __cplusplus
typedef class OEGOffice OEGOffice;
#else
typedef struct OEGOffice OEGOffice;
#endif /* __cplusplus */

#endif 	/* __OEGOffice_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IOEGOffice_INTERFACE_DEFINED__
#define __IOEGOffice_INTERFACE_DEFINED__

/* interface IOEGOffice */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IOEGOffice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E043E43A-3241-46D4-BBCB-F7B343CFABFC")
    IOEGOffice : public IDispatch
    {
    public:
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_AutoSize( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_AutoSize( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONG_PTR *pHWND) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BorderVisible( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BorderVisible( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DocComments( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DocRevisions( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenDocument( 
            /* [in] */ BSTR filename,
            /* [in] */ VARIANT_BOOL bReadonly,
            /* [retval][out] */ VARIANT_BOOL *opened) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseDocument( 
            /* [retval][out] */ VARIANT_BOOL *closed) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveDocument( 
            /* [retval][out] */ VARIANT_BOOL *saved) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowRevisions( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowRevisions( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowComments( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowComments( 
            /* [in] */ VARIANT_BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UploadToUDS( 
            /* [in] */ BSTR uploadURL,
            /* [retval][out] */ VARIANT_BOOL *uploaded) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Test( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOEGOfficeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOEGOffice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOEGOffice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOEGOffice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOEGOffice * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOEGOffice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOEGOffice * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOEGOffice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSize )( 
            IOEGOffice * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSize )( 
            IOEGOffice * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            IOEGOffice * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IOEGOffice * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IOEGOffice * This,
            /* [retval][out] */ LONG_PTR *pHWND);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderVisible )( 
            IOEGOffice * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderVisible )( 
            IOEGOffice * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocComments )( 
            IOEGOffice * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DocRevisions )( 
            IOEGOffice * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenDocument )( 
            IOEGOffice * This,
            /* [in] */ BSTR filename,
            /* [in] */ VARIANT_BOOL bReadonly,
            /* [retval][out] */ VARIANT_BOOL *opened);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseDocument )( 
            IOEGOffice * This,
            /* [retval][out] */ VARIANT_BOOL *closed);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveDocument )( 
            IOEGOffice * This,
            /* [retval][out] */ VARIANT_BOOL *saved);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowRevisions )( 
            IOEGOffice * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowRevisions )( 
            IOEGOffice * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowComments )( 
            IOEGOffice * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowComments )( 
            IOEGOffice * This,
            /* [in] */ VARIANT_BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UploadToUDS )( 
            IOEGOffice * This,
            /* [in] */ BSTR uploadURL,
            /* [retval][out] */ VARIANT_BOOL *uploaded);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Test )( 
            IOEGOffice * This);
        
        END_INTERFACE
    } IOEGOfficeVtbl;

    interface IOEGOffice
    {
        CONST_VTBL struct IOEGOfficeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOEGOffice_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOEGOffice_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOEGOffice_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOEGOffice_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOEGOffice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOEGOffice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOEGOffice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOEGOffice_put_AutoSize(This,vbool)	\
    ( (This)->lpVtbl -> put_AutoSize(This,vbool) ) 

#define IOEGOffice_get_AutoSize(This,pbool)	\
    ( (This)->lpVtbl -> get_AutoSize(This,pbool) ) 

#define IOEGOffice_put_Enabled(This,vbool)	\
    ( (This)->lpVtbl -> put_Enabled(This,vbool) ) 

#define IOEGOffice_get_Enabled(This,pbool)	\
    ( (This)->lpVtbl -> get_Enabled(This,pbool) ) 

#define IOEGOffice_get_HWND(This,pHWND)	\
    ( (This)->lpVtbl -> get_HWND(This,pHWND) ) 

#define IOEGOffice_put_BorderVisible(This,vbool)	\
    ( (This)->lpVtbl -> put_BorderVisible(This,vbool) ) 

#define IOEGOffice_get_BorderVisible(This,pbool)	\
    ( (This)->lpVtbl -> get_BorderVisible(This,pbool) ) 

#define IOEGOffice_get_DocComments(This,pVal)	\
    ( (This)->lpVtbl -> get_DocComments(This,pVal) ) 

#define IOEGOffice_get_DocRevisions(This,pVal)	\
    ( (This)->lpVtbl -> get_DocRevisions(This,pVal) ) 

#define IOEGOffice_OpenDocument(This,filename,bReadonly,opened)	\
    ( (This)->lpVtbl -> OpenDocument(This,filename,bReadonly,opened) ) 

#define IOEGOffice_CloseDocument(This,closed)	\
    ( (This)->lpVtbl -> CloseDocument(This,closed) ) 

#define IOEGOffice_SaveDocument(This,saved)	\
    ( (This)->lpVtbl -> SaveDocument(This,saved) ) 

#define IOEGOffice_get_ShowRevisions(This,pVal)	\
    ( (This)->lpVtbl -> get_ShowRevisions(This,pVal) ) 

#define IOEGOffice_put_ShowRevisions(This,newVal)	\
    ( (This)->lpVtbl -> put_ShowRevisions(This,newVal) ) 

#define IOEGOffice_get_ShowComments(This,pVal)	\
    ( (This)->lpVtbl -> get_ShowComments(This,pVal) ) 

#define IOEGOffice_put_ShowComments(This,newVal)	\
    ( (This)->lpVtbl -> put_ShowComments(This,newVal) ) 

#define IOEGOffice_UploadToUDS(This,uploadURL,uploaded)	\
    ( (This)->lpVtbl -> UploadToUDS(This,uploadURL,uploaded) ) 

#define IOEGOffice_Test(This)	\
    ( (This)->lpVtbl -> Test(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOEGOffice_INTERFACE_DEFINED__ */



#ifndef __OEGuiLib_LIBRARY_DEFINED__
#define __OEGuiLib_LIBRARY_DEFINED__

/* library OEGuiLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_OEGuiLib;

#ifndef ___IOEGOfficeEvents_DISPINTERFACE_DEFINED__
#define ___IOEGOfficeEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOEGOfficeEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOEGOfficeEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("B6676F8B-0FFA-4BE8-A5C5-1ADBB48CF7B8")
    _IOEGOfficeEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOEGOfficeEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IOEGOfficeEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IOEGOfficeEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IOEGOfficeEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IOEGOfficeEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IOEGOfficeEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IOEGOfficeEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IOEGOfficeEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IOEGOfficeEventsVtbl;

    interface _IOEGOfficeEvents
    {
        CONST_VTBL struct _IOEGOfficeEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOEGOfficeEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IOEGOfficeEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IOEGOfficeEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IOEGOfficeEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IOEGOfficeEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IOEGOfficeEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IOEGOfficeEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOEGOfficeEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OEGOffice;

#ifdef __cplusplus

class DECLSPEC_UUID("BDBC281B-0180-41AF-AA9D-AF61A2D46FDC")
OEGOffice;
#endif
#endif /* __OEGuiLib_LIBRARY_DEFINED__ */

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


