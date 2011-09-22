

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Thu Jul 07 08:39:13 2011
 */
/* Compiler settings for .\base.idl:
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

#ifndef __base_h__
#define __base_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IUNIDProvider_FWD_DEFINED__
#define __IUNIDProvider_FWD_DEFINED__
typedef interface IUNIDProvider IUNIDProvider;
#endif 	/* __IUNIDProvider_FWD_DEFINED__ */


#ifndef __IShell_FWD_DEFINED__
#define __IShell_FWD_DEFINED__
typedef interface IShell IShell;
#endif 	/* __IShell_FWD_DEFINED__ */


#ifndef __UNIDProvider_FWD_DEFINED__
#define __UNIDProvider_FWD_DEFINED__

#ifdef __cplusplus
typedef class UNIDProvider UNIDProvider;
#else
typedef struct UNIDProvider UNIDProvider;
#endif /* __cplusplus */

#endif 	/* __UNIDProvider_FWD_DEFINED__ */


#ifndef __Shell_FWD_DEFINED__
#define __Shell_FWD_DEFINED__

#ifdef __cplusplus
typedef class Shell Shell;
#else
typedef struct Shell Shell;
#endif /* __cplusplus */

#endif 	/* __Shell_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IUNIDProvider_INTERFACE_DEFINED__
#define __IUNIDProvider_INTERFACE_DEFINED__

/* interface IUNIDProvider */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IUNIDProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8ED4D781-FA2E-4904-A14E-4A683077EB48")
    IUNIDProvider : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ProvideGUID( 
            /* [retval][out] */ BSTR *szGUID) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ProvideUNID( 
            /* [retval][out] */ BSTR *szUNID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUNIDProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUNIDProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUNIDProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUNIDProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUNIDProvider * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUNIDProvider * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUNIDProvider * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUNIDProvider * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProvideGUID )( 
            IUNIDProvider * This,
            /* [retval][out] */ BSTR *szGUID);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ProvideUNID )( 
            IUNIDProvider * This,
            /* [retval][out] */ BSTR *szUNID);
        
        END_INTERFACE
    } IUNIDProviderVtbl;

    interface IUNIDProvider
    {
        CONST_VTBL struct IUNIDProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUNIDProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IUNIDProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IUNIDProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IUNIDProvider_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IUNIDProvider_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IUNIDProvider_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IUNIDProvider_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IUNIDProvider_ProvideGUID(This,szGUID)	\
    (This)->lpVtbl -> ProvideGUID(This,szGUID)

#define IUNIDProvider_ProvideUNID(This,szUNID)	\
    (This)->lpVtbl -> ProvideUNID(This,szUNID)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IUNIDProvider_ProvideGUID_Proxy( 
    IUNIDProvider * This,
    /* [retval][out] */ BSTR *szGUID);


void __RPC_STUB IUNIDProvider_ProvideGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IUNIDProvider_ProvideUNID_Proxy( 
    IUNIDProvider * This,
    /* [retval][out] */ BSTR *szUNID);


void __RPC_STUB IUNIDProvider_ProvideUNID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IUNIDProvider_INTERFACE_DEFINED__ */


#ifndef __IShell_INTERFACE_DEFINED__
#define __IShell_INTERFACE_DEFINED__

/* interface IShell */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IShell;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C9953D90-6240-48C0-AAFC-3C57BA8A0578")
    IShell : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSystemFolder( 
            /* [retval][out] */ BSTR *szFolder) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWorkFolder( 
            /* [retval][out] */ BSTR *szFolder) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWorkFolderTemp( 
            /* [retval][out] */ BSTR *szFolder) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWindowsVersionString( 
            /* [retval][out] */ BSTR *szVer) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFileVersionString( 
            /* [in] */ BSTR szFile,
            /* [retval][out] */ BSTR *szVer) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetWindowsUserName( 
            /* [retval][out] */ BSTR *szUser) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPersonalFolder( 
            /* [retval][out] */ BSTR *szFolder) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetFileLength( 
            /* [in] */ BSTR szFilePath,
            /* [retval][out] */ ULONG *ulFileLength) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE GetInstallPath( 
            /* [retval][out] */ BSTR *szPath) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearTempWorkFolder( void) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE DeleteTempFile( 
            /* [in] */ BSTR szFileName,
            /* [retval][out] */ VARIANT_BOOL *bSuccess) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE FileExists( 
            /* [in] */ BSTR szFilePath,
            /* [retval][out] */ VARIANT_BOOL *bSuccess) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE LaunchFile( 
            /* [in] */ BSTR szFilePath,
            /* [defaultvalue][in] */ BSTR szVerb = L"open") = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE FindAssocProgram( 
            /* [in] */ BSTR szFilePath,
            /* [defaultvalue][in] */ BSTR szVerb,
            /* [retval][out] */ BSTR *szProgram) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE CheckFileOpened( 
            /* [in] */ BSTR szFilePath,
            /* [retval][out] */ VARIANT_BOOL *bSuccess) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IShellVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IShell * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IShell * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IShell * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IShell * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IShell * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IShell * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IShell * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetSystemFolder )( 
            IShell * This,
            /* [retval][out] */ BSTR *szFolder);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetWorkFolder )( 
            IShell * This,
            /* [retval][out] */ BSTR *szFolder);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetWorkFolderTemp )( 
            IShell * This,
            /* [retval][out] */ BSTR *szFolder);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetWindowsVersionString )( 
            IShell * This,
            /* [retval][out] */ BSTR *szVer);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileVersionString )( 
            IShell * This,
            /* [in] */ BSTR szFile,
            /* [retval][out] */ BSTR *szVer);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetWindowsUserName )( 
            IShell * This,
            /* [retval][out] */ BSTR *szUser);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetPersonalFolder )( 
            IShell * This,
            /* [retval][out] */ BSTR *szFolder);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetFileLength )( 
            IShell * This,
            /* [in] */ BSTR szFilePath,
            /* [retval][out] */ ULONG *ulFileLength);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetInstallPath )( 
            IShell * This,
            /* [retval][out] */ BSTR *szPath);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearTempWorkFolder )( 
            IShell * This);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DeleteTempFile )( 
            IShell * This,
            /* [in] */ BSTR szFileName,
            /* [retval][out] */ VARIANT_BOOL *bSuccess);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FileExists )( 
            IShell * This,
            /* [in] */ BSTR szFilePath,
            /* [retval][out] */ VARIANT_BOOL *bSuccess);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LaunchFile )( 
            IShell * This,
            /* [in] */ BSTR szFilePath,
            /* [defaultvalue][in] */ BSTR szVerb);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindAssocProgram )( 
            IShell * This,
            /* [in] */ BSTR szFilePath,
            /* [defaultvalue][in] */ BSTR szVerb,
            /* [retval][out] */ BSTR *szProgram);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CheckFileOpened )( 
            IShell * This,
            /* [in] */ BSTR szFilePath,
            /* [retval][out] */ VARIANT_BOOL *bSuccess);
        
        END_INTERFACE
    } IShellVtbl;

    interface IShell
    {
        CONST_VTBL struct IShellVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IShell_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IShell_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IShell_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IShell_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IShell_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IShell_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IShell_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IShell_GetSystemFolder(This,szFolder)	\
    (This)->lpVtbl -> GetSystemFolder(This,szFolder)

#define IShell_GetWorkFolder(This,szFolder)	\
    (This)->lpVtbl -> GetWorkFolder(This,szFolder)

#define IShell_GetWorkFolderTemp(This,szFolder)	\
    (This)->lpVtbl -> GetWorkFolderTemp(This,szFolder)

#define IShell_GetWindowsVersionString(This,szVer)	\
    (This)->lpVtbl -> GetWindowsVersionString(This,szVer)

#define IShell_GetFileVersionString(This,szFile,szVer)	\
    (This)->lpVtbl -> GetFileVersionString(This,szFile,szVer)

#define IShell_GetWindowsUserName(This,szUser)	\
    (This)->lpVtbl -> GetWindowsUserName(This,szUser)

#define IShell_GetPersonalFolder(This,szFolder)	\
    (This)->lpVtbl -> GetPersonalFolder(This,szFolder)

#define IShell_GetFileLength(This,szFilePath,ulFileLength)	\
    (This)->lpVtbl -> GetFileLength(This,szFilePath,ulFileLength)

#define IShell_GetInstallPath(This,szPath)	\
    (This)->lpVtbl -> GetInstallPath(This,szPath)

#define IShell_ClearTempWorkFolder(This)	\
    (This)->lpVtbl -> ClearTempWorkFolder(This)

#define IShell_DeleteTempFile(This,szFileName,bSuccess)	\
    (This)->lpVtbl -> DeleteTempFile(This,szFileName,bSuccess)

#define IShell_FileExists(This,szFilePath,bSuccess)	\
    (This)->lpVtbl -> FileExists(This,szFilePath,bSuccess)

#define IShell_LaunchFile(This,szFilePath,szVerb)	\
    (This)->lpVtbl -> LaunchFile(This,szFilePath,szVerb)

#define IShell_FindAssocProgram(This,szFilePath,szVerb,szProgram)	\
    (This)->lpVtbl -> FindAssocProgram(This,szFilePath,szVerb,szProgram)

#define IShell_CheckFileOpened(This,szFilePath,bSuccess)	\
    (This)->lpVtbl -> CheckFileOpened(This,szFilePath,bSuccess)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_GetSystemFolder_Proxy( 
    IShell * This,
    /* [retval][out] */ BSTR *szFolder);


void __RPC_STUB IShell_GetSystemFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_GetWorkFolder_Proxy( 
    IShell * This,
    /* [retval][out] */ BSTR *szFolder);


void __RPC_STUB IShell_GetWorkFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_GetWorkFolderTemp_Proxy( 
    IShell * This,
    /* [retval][out] */ BSTR *szFolder);


void __RPC_STUB IShell_GetWorkFolderTemp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_GetWindowsVersionString_Proxy( 
    IShell * This,
    /* [retval][out] */ BSTR *szVer);


void __RPC_STUB IShell_GetWindowsVersionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_GetFileVersionString_Proxy( 
    IShell * This,
    /* [in] */ BSTR szFile,
    /* [retval][out] */ BSTR *szVer);


void __RPC_STUB IShell_GetFileVersionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_GetWindowsUserName_Proxy( 
    IShell * This,
    /* [retval][out] */ BSTR *szUser);


void __RPC_STUB IShell_GetWindowsUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_GetPersonalFolder_Proxy( 
    IShell * This,
    /* [retval][out] */ BSTR *szFolder);


void __RPC_STUB IShell_GetPersonalFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_GetFileLength_Proxy( 
    IShell * This,
    /* [in] */ BSTR szFilePath,
    /* [retval][out] */ ULONG *ulFileLength);


void __RPC_STUB IShell_GetFileLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_GetInstallPath_Proxy( 
    IShell * This,
    /* [retval][out] */ BSTR *szPath);


void __RPC_STUB IShell_GetInstallPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_ClearTempWorkFolder_Proxy( 
    IShell * This);


void __RPC_STUB IShell_ClearTempWorkFolder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_DeleteTempFile_Proxy( 
    IShell * This,
    /* [in] */ BSTR szFileName,
    /* [retval][out] */ VARIANT_BOOL *bSuccess);


void __RPC_STUB IShell_DeleteTempFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_FileExists_Proxy( 
    IShell * This,
    /* [in] */ BSTR szFilePath,
    /* [retval][out] */ VARIANT_BOOL *bSuccess);


void __RPC_STUB IShell_FileExists_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_LaunchFile_Proxy( 
    IShell * This,
    /* [in] */ BSTR szFilePath,
    /* [defaultvalue][in] */ BSTR szVerb);


void __RPC_STUB IShell_LaunchFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_FindAssocProgram_Proxy( 
    IShell * This,
    /* [in] */ BSTR szFilePath,
    /* [defaultvalue][in] */ BSTR szVerb,
    /* [retval][out] */ BSTR *szProgram);


void __RPC_STUB IShell_FindAssocProgram_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE IShell_CheckFileOpened_Proxy( 
    IShell * This,
    /* [in] */ BSTR szFilePath,
    /* [retval][out] */ VARIANT_BOOL *bSuccess);


void __RPC_STUB IShell_CheckFileOpened_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IShell_INTERFACE_DEFINED__ */



#ifndef __baseLib_LIBRARY_DEFINED__
#define __baseLib_LIBRARY_DEFINED__

/* library baseLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_baseLib;

EXTERN_C const CLSID CLSID_UNIDProvider;

#ifdef __cplusplus

class DECLSPEC_UUID("C9F0828D-EA68-4F38-B391-A8067841A9FD")
UNIDProvider;
#endif

EXTERN_C const CLSID CLSID_Shell;

#ifdef __cplusplus

class DECLSPEC_UUID("A2FE9A5C-DDF4-4D29-9A14-11870A12D50D")
Shell;
#endif
#endif /* __baseLib_LIBRARY_DEFINED__ */

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


