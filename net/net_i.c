

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


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

MIDL_DEFINE_GUID(IID, IID_IHttpResponse,0xC6BDF3ED,0x45D6,0x44A4,0x80,0x57,0x7B,0x62,0xF9,0x9B,0x24,0x03);


MIDL_DEFINE_GUID(IID, IID_IHttpRequest,0x80B48C37,0x5703,0x41FC,0xBD,0xBB,0xF4,0x2F,0xC5,0xC4,0x82,0xCF);


MIDL_DEFINE_GUID(IID, LIBID_netLib,0x743C5A65,0x8B73,0x45A8,0x9C,0xEC,0xEA,0x8F,0xB6,0xE3,0xDA,0x3E);


MIDL_DEFINE_GUID(IID, DIID__IHttpRequestEvents,0x61BBE002,0x0D56,0x4147,0xA3,0xFC,0x45,0x77,0xEF,0x77,0x33,0x4D);


MIDL_DEFINE_GUID(CLSID, CLSID_HttpRequest,0x99C0FB3E,0x3871,0x43DF,0x93,0x16,0xC5,0x24,0xFD,0x8F,0x0E,0x02);


MIDL_DEFINE_GUID(IID, DIID__IHttpResponseEvents,0x3AE591E6,0x5016,0x470D,0x85,0x24,0x31,0x6F,0x77,0x93,0x74,0xF0);


MIDL_DEFINE_GUID(CLSID, CLSID_HttpResponse,0x72AD7AD0,0x47B7,0x4C3B,0x94,0x55,0x73,0x12,0xB4,0x6F,0x55,0xD3);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



