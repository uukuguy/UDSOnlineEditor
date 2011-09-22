

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, IID_IOELauncher,0x89A20F8C,0x72C6,0x4E05,0x8B,0xBB,0x18,0x40,0x39,0x21,0x6A,0x26);


MIDL_DEFINE_GUID(IID, LIBID_OEProxyLib,0x96A4F481,0x3B6C,0x4924,0x9B,0x7A,0xF0,0x4A,0x8C,0x52,0x0D,0x4F);


MIDL_DEFINE_GUID(IID, DIID__IOELauncherEvents,0xABF6AA8B,0xFD5A,0x49D6,0xAC,0xED,0x05,0x23,0xCE,0xF0,0x9B,0x20);


MIDL_DEFINE_GUID(CLSID, CLSID_OELauncher,0x89C5CDD8,0xD5EF,0x4FEB,0x9B,0x1C,0x91,0x5E,0xC2,0xAF,0x9A,0x86);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



