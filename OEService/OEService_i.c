

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, IID_IOEEditing,0xC49F79D8,0x96E1,0x42A5,0x91,0xFD,0x1F,0xC4,0xE2,0x8F,0x61,0x65);


MIDL_DEFINE_GUID(IID, LIBID_OEServiceLib,0xED53FBE4,0xE28B,0x450C,0x92,0xFF,0xEC,0x82,0x3C,0xF5,0xBD,0x1D);


MIDL_DEFINE_GUID(IID, DIID__IOEEditingEvents,0x3A388A23,0x591E,0x4E78,0xAA,0xFA,0x2E,0x42,0xAD,0x06,0xA4,0x38);


MIDL_DEFINE_GUID(CLSID, CLSID_OEEditing,0xE69FEC44,0x1B28,0x4BF4,0xB0,0x7F,0x9E,0xBC,0xAC,0xE4,0x8D,0x79);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



