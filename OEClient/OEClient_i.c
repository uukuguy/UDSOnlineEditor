

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Wed Aug 31 06:08:16 2011
 */
/* Compiler settings for .\OEClient.idl:
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

MIDL_DEFINE_GUID(IID, IID_IOEControl,0xEEA9D088,0xE6CE,0x41E2,0x84,0xF7,0x2D,0x9E,0xDA,0xAC,0x93,0x35);


MIDL_DEFINE_GUID(IID, LIBID_OEClientLib,0x0BC8F4AD,0xF81C,0x4E8D,0x87,0xC8,0x99,0x4A,0x71,0xC6,0x45,0x75);


MIDL_DEFINE_GUID(IID, DIID__IOEControlEvents,0xF45FD8B7,0x26C8,0x48DD,0xBD,0x69,0xDD,0xC4,0x0A,0x1D,0xA5,0x73);


MIDL_DEFINE_GUID(CLSID, CLSID_OEControl,0x4631D137,0xB7AF,0x4EC1,0xAC,0xD2,0xAA,0x5A,0x95,0xAA,0xBE,0xAF);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



