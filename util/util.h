

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Thu Sep 22 20:24:03 2011
 */
/* Compiler settings for .\util.idl:
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

#ifndef __util_h__
#define __util_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDialog_FWD_DEFINED__
#define __IDialog_FWD_DEFINED__
typedef interface IDialog IDialog;
#endif 	/* __IDialog_FWD_DEFINED__ */


#ifndef __IFileWriter_FWD_DEFINED__
#define __IFileWriter_FWD_DEFINED__
typedef interface IFileWriter IFileWriter;
#endif 	/* __IFileWriter_FWD_DEFINED__ */


#ifndef __IFileEncrypter_FWD_DEFINED__
#define __IFileEncrypter_FWD_DEFINED__
typedef interface IFileEncrypter IFileEncrypter;
#endif 	/* __IFileEncrypter_FWD_DEFINED__ */


#ifndef __IFileDecrypter_FWD_DEFINED__
#define __IFileDecrypter_FWD_DEFINED__
typedef interface IFileDecrypter IFileDecrypter;
#endif 	/* __IFileDecrypter_FWD_DEFINED__ */


#ifndef __IUKEYSignature_FWD_DEFINED__
#define __IUKEYSignature_FWD_DEFINED__
typedef interface IUKEYSignature IUKEYSignature;
#endif 	/* __IUKEYSignature_FWD_DEFINED__ */


#ifndef __ITestSample_FWD_DEFINED__
#define __ITestSample_FWD_DEFINED__
typedef interface ITestSample ITestSample;
#endif 	/* __ITestSample_FWD_DEFINED__ */


#ifndef ___IDialogEvents_FWD_DEFINED__
#define ___IDialogEvents_FWD_DEFINED__
typedef interface _IDialogEvents _IDialogEvents;
#endif 	/* ___IDialogEvents_FWD_DEFINED__ */


#ifndef __Dialog_FWD_DEFINED__
#define __Dialog_FWD_DEFINED__

#ifdef __cplusplus
typedef class Dialog Dialog;
#else
typedef struct Dialog Dialog;
#endif /* __cplusplus */

#endif 	/* __Dialog_FWD_DEFINED__ */


#ifndef __FileWriter_FWD_DEFINED__
#define __FileWriter_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileWriter FileWriter;
#else
typedef struct FileWriter FileWriter;
#endif /* __cplusplus */

#endif 	/* __FileWriter_FWD_DEFINED__ */


#ifndef __FileEncrypter_FWD_DEFINED__
#define __FileEncrypter_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileEncrypter FileEncrypter;
#else
typedef struct FileEncrypter FileEncrypter;
#endif /* __cplusplus */

#endif 	/* __FileEncrypter_FWD_DEFINED__ */


#ifndef __FileDecrypter_FWD_DEFINED__
#define __FileDecrypter_FWD_DEFINED__

#ifdef __cplusplus
typedef class FileDecrypter FileDecrypter;
#else
typedef struct FileDecrypter FileDecrypter;
#endif /* __cplusplus */

#endif 	/* __FileDecrypter_FWD_DEFINED__ */


#ifndef __UKEYSignature_FWD_DEFINED__
#define __UKEYSignature_FWD_DEFINED__

#ifdef __cplusplus
typedef class UKEYSignature UKEYSignature;
#else
typedef struct UKEYSignature UKEYSignature;
#endif /* __cplusplus */

#endif 	/* __UKEYSignature_FWD_DEFINED__ */


#ifndef __TestSample_FWD_DEFINED__
#define __TestSample_FWD_DEFINED__

#ifdef __cplusplus
typedef class TestSample TestSample;
#else
typedef struct TestSample TestSample;
#endif /* __cplusplus */

#endif 	/* __TestSample_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDialog_INTERFACE_DEFINED__
#define __IDialog_INTERFACE_DEFINED__

/* interface IDialog */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDialog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("68D280CB-030B-40F9-9556-EA617F39FBC5")
    IDialog : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectFolder( 
            /* [retval][out] */ BSTR *szFolderResult) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectFiles( 
            /* [defaultvalue][in] */ BSTR szDefaultFileName,
            /* [defaultvalue][in] */ BSTR szTitle,
            /* [defaultvalue][in] */ BSTR szFilter,
            /* [defaultvalue][in] */ VARIANT_BOOL blAllowMultiSelect,
            /* [retval][out] */ BSTR *szFile) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveFile( 
            /* [defaultvalue][in] */ BSTR szDefaultFileName,
            /* [defaultvalue][in] */ BSTR szTitle,
            /* [defaultvalue][in] */ BSTR szFilter,
            /* [retval][out] */ BSTR *szFile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDialogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDialog * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDialog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDialog * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDialog * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDialog * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDialog * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDialog * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectFolder )( 
            IDialog * This,
            /* [retval][out] */ BSTR *szFolderResult);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectFiles )( 
            IDialog * This,
            /* [defaultvalue][in] */ BSTR szDefaultFileName,
            /* [defaultvalue][in] */ BSTR szTitle,
            /* [defaultvalue][in] */ BSTR szFilter,
            /* [defaultvalue][in] */ VARIANT_BOOL blAllowMultiSelect,
            /* [retval][out] */ BSTR *szFile);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveFile )( 
            IDialog * This,
            /* [defaultvalue][in] */ BSTR szDefaultFileName,
            /* [defaultvalue][in] */ BSTR szTitle,
            /* [defaultvalue][in] */ BSTR szFilter,
            /* [retval][out] */ BSTR *szFile);
        
        END_INTERFACE
    } IDialogVtbl;

    interface IDialog
    {
        CONST_VTBL struct IDialogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDialog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDialog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDialog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDialog_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDialog_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDialog_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDialog_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDialog_SelectFolder(This,szFolderResult)	\
    ( (This)->lpVtbl -> SelectFolder(This,szFolderResult) ) 

#define IDialog_SelectFiles(This,szDefaultFileName,szTitle,szFilter,blAllowMultiSelect,szFile)	\
    ( (This)->lpVtbl -> SelectFiles(This,szDefaultFileName,szTitle,szFilter,blAllowMultiSelect,szFile) ) 

#define IDialog_SaveFile(This,szDefaultFileName,szTitle,szFilter,szFile)	\
    ( (This)->lpVtbl -> SaveFile(This,szDefaultFileName,szTitle,szFilter,szFile) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDialog_INTERFACE_DEFINED__ */


#ifndef __IFileWriter_INTERFACE_DEFINED__
#define __IFileWriter_INTERFACE_DEFINED__

/* interface IFileWriter */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFileWriter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A5D4CDA-FAA0-452A-B80C-7FC56B08539D")
    IFileWriter : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateFile( 
            /* [in] */ BSTR szFileName) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE AppendFileContent( 
            /* [in] */ BSTR szContent) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE WriteFile( 
            /* [retval][out] */ VARIANT_BOOL *blSuccess) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFileWriterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileWriter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileWriter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileWriter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileWriter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileWriter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileWriter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileWriter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CreateFile )( 
            IFileWriter * This,
            /* [in] */ BSTR szFileName);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AppendFileContent )( 
            IFileWriter * This,
            /* [in] */ BSTR szContent);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *WriteFile )( 
            IFileWriter * This,
            /* [retval][out] */ VARIANT_BOOL *blSuccess);
        
        END_INTERFACE
    } IFileWriterVtbl;

    interface IFileWriter
    {
        CONST_VTBL struct IFileWriterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileWriter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileWriter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileWriter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileWriter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileWriter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileWriter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileWriter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFileWriter_CreateFile(This,szFileName)	\
    ( (This)->lpVtbl -> CreateFile(This,szFileName) ) 

#define IFileWriter_AppendFileContent(This,szContent)	\
    ( (This)->lpVtbl -> AppendFileContent(This,szContent) ) 

#define IFileWriter_WriteFile(This,blSuccess)	\
    ( (This)->lpVtbl -> WriteFile(This,blSuccess) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileWriter_INTERFACE_DEFINED__ */


#ifndef __IFileEncrypter_INTERFACE_DEFINED__
#define __IFileEncrypter_INTERFACE_DEFINED__

/* interface IFileEncrypter */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFileEncrypter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4D88249-2999-4B51-B630-9FF5AA9A7BFF")
    IFileEncrypter : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE EncryptFile( 
            /* [in] */ BSTR szInFN,
            /* [in] */ BSTR szOutFN,
            /* [defaultvalue][in] */ BSTR szPwd = L"") = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFileEncrypterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileEncrypter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileEncrypter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileEncrypter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileEncrypter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileEncrypter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileEncrypter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileEncrypter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *EncryptFile )( 
            IFileEncrypter * This,
            /* [in] */ BSTR szInFN,
            /* [in] */ BSTR szOutFN,
            /* [defaultvalue][in] */ BSTR szPwd);
        
        END_INTERFACE
    } IFileEncrypterVtbl;

    interface IFileEncrypter
    {
        CONST_VTBL struct IFileEncrypterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileEncrypter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileEncrypter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileEncrypter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileEncrypter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileEncrypter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileEncrypter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileEncrypter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFileEncrypter_EncryptFile(This,szInFN,szOutFN,szPwd)	\
    ( (This)->lpVtbl -> EncryptFile(This,szInFN,szOutFN,szPwd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileEncrypter_INTERFACE_DEFINED__ */


#ifndef __IFileDecrypter_INTERFACE_DEFINED__
#define __IFileDecrypter_INTERFACE_DEFINED__

/* interface IFileDecrypter */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFileDecrypter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F8525D5-20B7-4EF3-91AE-3622EA1043A5")
    IFileDecrypter : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE DecryptFile( 
            /* [in] */ BSTR mailer,
            /* [in] */ BSTR out_mailer,
            /* [retval][out] */ BSTR *rtinfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewDecryptFile( 
            /* [in] */ BSTR provider_name,
            /* [in] */ BSTR container_name,
            /* [in] */ BSTR mailer,
            /* [in] */ BSTR out_mailer,
            /* [retval][out] */ BSTR *rtinfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PIN_DecryptFile( 
            /* [in] */ BSTR pin,
            /* [in] */ BSTR mailer,
            /* [in] */ BSTR out_mailer,
            /* [retval][out] */ BSTR *rtinfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HAND_DecryptFile( 
            /* [in] */ BSTR provider_name,
            /* [in] */ BSTR container_name,
            /* [in] */ BSTR bsPin,
            /* [in] */ BSTR mailer,
            /* [in] */ BSTR out_mailer,
            /* [retval][out] */ BSTR *rtinfo) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE P11LogOutFinalize( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindCertByUser( 
            /* [in] */ BSTR provider_name,
            /* [in] */ BSTR cuser,
            /* [retval][out] */ BSTR *ccontainer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFileDecrypterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFileDecrypter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFileDecrypter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFileDecrypter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFileDecrypter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFileDecrypter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFileDecrypter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFileDecrypter * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *DecryptFile )( 
            IFileDecrypter * This,
            /* [in] */ BSTR mailer,
            /* [in] */ BSTR out_mailer,
            /* [retval][out] */ BSTR *rtinfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewDecryptFile )( 
            IFileDecrypter * This,
            /* [in] */ BSTR provider_name,
            /* [in] */ BSTR container_name,
            /* [in] */ BSTR mailer,
            /* [in] */ BSTR out_mailer,
            /* [retval][out] */ BSTR *rtinfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PIN_DecryptFile )( 
            IFileDecrypter * This,
            /* [in] */ BSTR pin,
            /* [in] */ BSTR mailer,
            /* [in] */ BSTR out_mailer,
            /* [retval][out] */ BSTR *rtinfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HAND_DecryptFile )( 
            IFileDecrypter * This,
            /* [in] */ BSTR provider_name,
            /* [in] */ BSTR container_name,
            /* [in] */ BSTR bsPin,
            /* [in] */ BSTR mailer,
            /* [in] */ BSTR out_mailer,
            /* [retval][out] */ BSTR *rtinfo);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *P11LogOutFinalize )( 
            IFileDecrypter * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindCertByUser )( 
            IFileDecrypter * This,
            /* [in] */ BSTR provider_name,
            /* [in] */ BSTR cuser,
            /* [retval][out] */ BSTR *ccontainer);
        
        END_INTERFACE
    } IFileDecrypterVtbl;

    interface IFileDecrypter
    {
        CONST_VTBL struct IFileDecrypterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFileDecrypter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFileDecrypter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFileDecrypter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFileDecrypter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFileDecrypter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFileDecrypter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFileDecrypter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFileDecrypter_DecryptFile(This,mailer,out_mailer,rtinfo)	\
    ( (This)->lpVtbl -> DecryptFile(This,mailer,out_mailer,rtinfo) ) 

#define IFileDecrypter_NewDecryptFile(This,provider_name,container_name,mailer,out_mailer,rtinfo)	\
    ( (This)->lpVtbl -> NewDecryptFile(This,provider_name,container_name,mailer,out_mailer,rtinfo) ) 

#define IFileDecrypter_PIN_DecryptFile(This,pin,mailer,out_mailer,rtinfo)	\
    ( (This)->lpVtbl -> PIN_DecryptFile(This,pin,mailer,out_mailer,rtinfo) ) 

#define IFileDecrypter_HAND_DecryptFile(This,provider_name,container_name,bsPin,mailer,out_mailer,rtinfo)	\
    ( (This)->lpVtbl -> HAND_DecryptFile(This,provider_name,container_name,bsPin,mailer,out_mailer,rtinfo) ) 

#define IFileDecrypter_P11LogOutFinalize(This)	\
    ( (This)->lpVtbl -> P11LogOutFinalize(This) ) 

#define IFileDecrypter_FindCertByUser(This,provider_name,cuser,ccontainer)	\
    ( (This)->lpVtbl -> FindCertByUser(This,provider_name,cuser,ccontainer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFileDecrypter_INTERFACE_DEFINED__ */


#ifndef __IUKEYSignature_INTERFACE_DEFINED__
#define __IUKEYSignature_INTERFACE_DEFINED__

/* interface IUKEYSignature */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IUKEYSignature;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ED770C81-946B-47BC-A25F-5C72902382A1")
    IUKEYSignature : public IDispatch
    {
    public:
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE Sign( 
            /* [in] */ BSTR szMessage,
            /* [retval][out] */ BSTR *szSignature) = 0;
        
        virtual /* [helpcontext][helpstring][id] */ HRESULT STDMETHODCALLTYPE VerifySignature( 
            /* [in] */ BSTR szSignature,
            /* [in] */ BSTR szMessage,
            /* [retval][out] */ VARIANT_BOOL *blRet) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE NewSign( 
            /* [in] */ BSTR provider_name,
            /* [in] */ BSTR container_name,
            /* [in] */ BSTR szMessage,
            /* [in] */ BSTR szSignature_dat,
            /* [retval][out] */ BSTR *szSignature) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HAND_Sign( 
            /* [in] */ BSTR provider_name,
            /* [in] */ BSTR container_name,
            /* [in] */ BSTR szMessage,
            /* [in] */ BSTR szSignature_dat,
            /* [in] */ BSTR cuser,
            /* [retval][out] */ BSTR *szSignature) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SignByUser( 
            /* [in] */ BSTR szMessage,
            /* [in] */ BSTR szUser,
            /* [retval][out] */ BSTR *szSignature) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCertSId( 
            /* [in] */ BSTR inCertName,
            /* [retval][out] */ BSTR *outCertSid) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCertSubject( 
            /* [in] */ BSTR inCertName,
            /* [retval][out] */ BSTR *outSubject) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE getCertXML( 
            /* [retval][out] */ BSTR *szXml) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IUKEYSignatureVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUKEYSignature * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUKEYSignature * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUKEYSignature * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IUKEYSignature * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IUKEYSignature * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IUKEYSignature * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IUKEYSignature * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sign )( 
            IUKEYSignature * This,
            /* [in] */ BSTR szMessage,
            /* [retval][out] */ BSTR *szSignature);
        
        /* [helpcontext][helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *VerifySignature )( 
            IUKEYSignature * This,
            /* [in] */ BSTR szSignature,
            /* [in] */ BSTR szMessage,
            /* [retval][out] */ VARIANT_BOOL *blRet);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *NewSign )( 
            IUKEYSignature * This,
            /* [in] */ BSTR provider_name,
            /* [in] */ BSTR container_name,
            /* [in] */ BSTR szMessage,
            /* [in] */ BSTR szSignature_dat,
            /* [retval][out] */ BSTR *szSignature);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HAND_Sign )( 
            IUKEYSignature * This,
            /* [in] */ BSTR provider_name,
            /* [in] */ BSTR container_name,
            /* [in] */ BSTR szMessage,
            /* [in] */ BSTR szSignature_dat,
            /* [in] */ BSTR cuser,
            /* [retval][out] */ BSTR *szSignature);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SignByUser )( 
            IUKEYSignature * This,
            /* [in] */ BSTR szMessage,
            /* [in] */ BSTR szUser,
            /* [retval][out] */ BSTR *szSignature);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCertSId )( 
            IUKEYSignature * This,
            /* [in] */ BSTR inCertName,
            /* [retval][out] */ BSTR *outCertSid);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCertSubject )( 
            IUKEYSignature * This,
            /* [in] */ BSTR inCertName,
            /* [retval][out] */ BSTR *outSubject);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *getCertXML )( 
            IUKEYSignature * This,
            /* [retval][out] */ BSTR *szXml);
        
        END_INTERFACE
    } IUKEYSignatureVtbl;

    interface IUKEYSignature
    {
        CONST_VTBL struct IUKEYSignatureVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IUKEYSignature_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IUKEYSignature_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IUKEYSignature_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IUKEYSignature_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IUKEYSignature_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IUKEYSignature_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IUKEYSignature_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IUKEYSignature_Sign(This,szMessage,szSignature)	\
    ( (This)->lpVtbl -> Sign(This,szMessage,szSignature) ) 

#define IUKEYSignature_VerifySignature(This,szSignature,szMessage,blRet)	\
    ( (This)->lpVtbl -> VerifySignature(This,szSignature,szMessage,blRet) ) 

#define IUKEYSignature_NewSign(This,provider_name,container_name,szMessage,szSignature_dat,szSignature)	\
    ( (This)->lpVtbl -> NewSign(This,provider_name,container_name,szMessage,szSignature_dat,szSignature) ) 

#define IUKEYSignature_HAND_Sign(This,provider_name,container_name,szMessage,szSignature_dat,cuser,szSignature)	\
    ( (This)->lpVtbl -> HAND_Sign(This,provider_name,container_name,szMessage,szSignature_dat,cuser,szSignature) ) 

#define IUKEYSignature_SignByUser(This,szMessage,szUser,szSignature)	\
    ( (This)->lpVtbl -> SignByUser(This,szMessage,szUser,szSignature) ) 

#define IUKEYSignature_GetCertSId(This,inCertName,outCertSid)	\
    ( (This)->lpVtbl -> GetCertSId(This,inCertName,outCertSid) ) 

#define IUKEYSignature_GetCertSubject(This,inCertName,outSubject)	\
    ( (This)->lpVtbl -> GetCertSubject(This,inCertName,outSubject) ) 

#define IUKEYSignature_getCertXML(This,szXml)	\
    ( (This)->lpVtbl -> getCertXML(This,szXml) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IUKEYSignature_INTERFACE_DEFINED__ */


#ifndef __ITestSample_INTERFACE_DEFINED__
#define __ITestSample_INTERFACE_DEFINED__

/* interface ITestSample */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ITestSample;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E27D2FA-DF40-45E4-BB2B-B10E833B8F45")
    ITestSample : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindCerts( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddNums( 
            /* [retval][out] */ BSTR *rtnum) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE FindCertByUser( 
            /* [in] */ BSTR cuser,
            /* [retval][out] */ BSTR *ccontainer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ITestSampleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITestSample * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITestSample * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITestSample * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITestSample * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITestSample * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITestSample * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITestSample * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindCerts )( 
            ITestSample * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddNums )( 
            ITestSample * This,
            /* [retval][out] */ BSTR *rtnum);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *FindCertByUser )( 
            ITestSample * This,
            /* [in] */ BSTR cuser,
            /* [retval][out] */ BSTR *ccontainer);
        
        END_INTERFACE
    } ITestSampleVtbl;

    interface ITestSample
    {
        CONST_VTBL struct ITestSampleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITestSample_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITestSample_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITestSample_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITestSample_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITestSample_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITestSample_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITestSample_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITestSample_FindCerts(This)	\
    ( (This)->lpVtbl -> FindCerts(This) ) 

#define ITestSample_AddNums(This,rtnum)	\
    ( (This)->lpVtbl -> AddNums(This,rtnum) ) 

#define ITestSample_FindCertByUser(This,cuser,ccontainer)	\
    ( (This)->lpVtbl -> FindCertByUser(This,cuser,ccontainer) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITestSample_INTERFACE_DEFINED__ */



#ifndef __utilLib_LIBRARY_DEFINED__
#define __utilLib_LIBRARY_DEFINED__

/* library utilLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_utilLib;

#ifndef ___IDialogEvents_DISPINTERFACE_DEFINED__
#define ___IDialogEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDialogEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IDialogEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("AF898AB8-DF43-451C-A035-1FDA1D19CA2D")
    _IDialogEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDialogEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDialogEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDialogEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDialogEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDialogEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDialogEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDialogEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDialogEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IDialogEventsVtbl;

    interface _IDialogEvents
    {
        CONST_VTBL struct _IDialogEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDialogEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IDialogEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IDialogEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IDialogEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IDialogEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IDialogEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IDialogEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDialogEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Dialog;

#ifdef __cplusplus

class DECLSPEC_UUID("25EEDB0E-D632-4824-B0B1-45DF67D6FA7C")
Dialog;
#endif

EXTERN_C const CLSID CLSID_FileWriter;

#ifdef __cplusplus

class DECLSPEC_UUID("2A874C33-1FA2-4C30-8FCB-94F40FF231C0")
FileWriter;
#endif

EXTERN_C const CLSID CLSID_FileEncrypter;

#ifdef __cplusplus

class DECLSPEC_UUID("28438672-0B29-4912-92E7-8026360006F4")
FileEncrypter;
#endif

EXTERN_C const CLSID CLSID_FileDecrypter;

#ifdef __cplusplus

class DECLSPEC_UUID("C435BB0F-4127-407C-975E-96FAC18A9835")
FileDecrypter;
#endif

EXTERN_C const CLSID CLSID_UKEYSignature;

#ifdef __cplusplus

class DECLSPEC_UUID("C0BDBE2F-BC5B-486B-847A-7E6D21034588")
UKEYSignature;
#endif

EXTERN_C const CLSID CLSID_TestSample;

#ifdef __cplusplus

class DECLSPEC_UUID("36B86070-5967-4512-8B72-5349EE1DBB47")
TestSample;
#endif
#endif /* __utilLib_LIBRARY_DEFINED__ */

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


