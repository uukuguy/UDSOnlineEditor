

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IDialog,0x68D280CB,0x030B,0x40F9,0x95,0x56,0xEA,0x61,0x7F,0x39,0xFB,0xC5);


MIDL_DEFINE_GUID(IID, IID_IFileWriter,0x6A5D4CDA,0xFAA0,0x452A,0xB8,0x0C,0x7F,0xC5,0x6B,0x08,0x53,0x9D);


MIDL_DEFINE_GUID(IID, IID_IFileEncrypter,0xC4D88249,0x2999,0x4B51,0xB6,0x30,0x9F,0xF5,0xAA,0x9A,0x7B,0xFF);


MIDL_DEFINE_GUID(IID, IID_IFileDecrypter,0x4F8525D5,0x20B7,0x4EF3,0x91,0xAE,0x36,0x22,0xEA,0x10,0x43,0xA5);


MIDL_DEFINE_GUID(IID, IID_IUKEYSignature,0xED770C81,0x946B,0x47BC,0xA2,0x5F,0x5C,0x72,0x90,0x23,0x82,0xA1);


MIDL_DEFINE_GUID(IID, IID_ITestSample,0x8E27D2FA,0xDF40,0x45E4,0xBB,0x2B,0xB1,0x0E,0x83,0x3B,0x8F,0x45);


MIDL_DEFINE_GUID(IID, LIBID_utilLib,0x9B3BFE4D,0xE770,0x4703,0x9F,0x23,0x5D,0x1B,0x35,0x07,0xC4,0x86);


MIDL_DEFINE_GUID(IID, DIID__IDialogEvents,0xAF898AB8,0xDF43,0x451C,0xA0,0x35,0x1F,0xDA,0x1D,0x19,0xCA,0x2D);


MIDL_DEFINE_GUID(CLSID, CLSID_Dialog,0x25EEDB0E,0xD632,0x4824,0xB0,0xB1,0x45,0xDF,0x67,0xD6,0xFA,0x7C);


MIDL_DEFINE_GUID(CLSID, CLSID_FileWriter,0x2A874C33,0x1FA2,0x4C30,0x8F,0xCB,0x94,0xF4,0x0F,0xF2,0x31,0xC0);


MIDL_DEFINE_GUID(CLSID, CLSID_FileEncrypter,0x28438672,0x0B29,0x4912,0x92,0xE7,0x80,0x26,0x36,0x00,0x06,0xF4);


MIDL_DEFINE_GUID(CLSID, CLSID_FileDecrypter,0xC435BB0F,0x4127,0x407C,0x97,0x5E,0x96,0xFA,0xC1,0x8A,0x98,0x35);


MIDL_DEFINE_GUID(CLSID, CLSID_UKEYSignature,0xC0BDBE2F,0xBC5B,0x486B,0x84,0x7A,0x7E,0x6D,0x21,0x03,0x45,0x88);


MIDL_DEFINE_GUID(CLSID, CLSID_TestSample,0x36B86070,0x5967,0x4512,0x8B,0x72,0x53,0x49,0xEE,0x1D,0xBB,0x47);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



