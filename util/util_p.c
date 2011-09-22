

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extern to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma warning( disable: 4024 )  /* array to pointer mapping*/
#pragma warning( disable: 4152 )  /* function/data pointer conversion in expression */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */

#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "util.h"

#define TYPE_FORMAT_STRING_SIZE   59                                
#define PROC_FORMAT_STRING_SIZE   809                               
#define EXPR_FORMAT_STRING_SIZE   1                                 
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _util_MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } util_MIDL_TYPE_FORMAT_STRING;

typedef struct _util_MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } util_MIDL_PROC_FORMAT_STRING;

typedef struct _util_MIDL_EXPR_FORMAT_STRING
    {
    long          Pad;
    unsigned char  Format[ EXPR_FORMAT_STRING_SIZE ];
    } util_MIDL_EXPR_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const util_MIDL_TYPE_FORMAT_STRING util__MIDL_TypeFormatString;
extern const util_MIDL_PROC_FORMAT_STRING util__MIDL_ProcFormatString;
extern const util_MIDL_EXPR_FORMAT_STRING util__MIDL_ExprFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IDialog_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IDialog_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFileWriter_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFileWriter_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFileEncrypter_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFileEncrypter_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IFileDecrypter_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IFileDecrypter_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IUKEYSignature_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IUKEYSignature_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ITestSample_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO ITestSample_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will fail with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const util_MIDL_PROC_FORMAT_STRING util__MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure SelectFolder */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter szFolderResult */

/* 16 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 18 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 20 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 22 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 24 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SelectFiles */

/* 28 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 30 */	NdrFcLong( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 38 */	NdrFcShort( 0x6 ),	/* 6 */
/* 40 */	NdrFcShort( 0x8 ),	/* 8 */
/* 42 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x6,		/* 6 */

	/* Parameter szDefaultFileName */

/* 44 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 46 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 48 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szTitle */

/* 50 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 52 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 54 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szFilter */

/* 56 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 58 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 60 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter blAllowMultiSelect */

/* 62 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 64 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 66 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter szFile */

/* 68 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 70 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 72 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 74 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 76 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 78 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure PIN_DecryptFile */


	/* Procedure SaveFile */

/* 80 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 82 */	NdrFcLong( 0x0 ),	/* 0 */
/* 86 */	NdrFcShort( 0x9 ),	/* 9 */
/* 88 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 90 */	NdrFcShort( 0x0 ),	/* 0 */
/* 92 */	NdrFcShort( 0x8 ),	/* 8 */
/* 94 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x5,		/* 5 */

	/* Parameter pin */


	/* Parameter szDefaultFileName */

/* 96 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter mailer */


	/* Parameter szTitle */

/* 102 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter out_mailer */


	/* Parameter szFilter */

/* 108 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter rtinfo */


	/* Parameter szFile */

/* 114 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 116 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 118 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */


	/* Return value */

/* 120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 122 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateFile */

/* 126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x7 ),	/* 7 */
/* 134 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 140 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter szFileName */

/* 142 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 144 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 146 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 150 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendFileContent */

/* 154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 162 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 168 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter szContent */

/* 170 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 172 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 174 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 176 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 178 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WriteFile */

/* 182 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 184 */	NdrFcLong( 0x0 ),	/* 0 */
/* 188 */	NdrFcShort( 0x9 ),	/* 9 */
/* 190 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x22 ),	/* 34 */
/* 196 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter blSuccess */

/* 198 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 200 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 202 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 206 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EncryptFile */

/* 210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x7 ),	/* 7 */
/* 218 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	NdrFcShort( 0x8 ),	/* 8 */
/* 224 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter szInFN */

/* 226 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 228 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 230 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szOutFN */

/* 232 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 234 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 236 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szPwd */

/* 238 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 240 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 242 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Return value */

/* 244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 246 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DecryptFile */

/* 250 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x7 ),	/* 7 */
/* 258 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 264 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter mailer */

/* 266 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 268 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 270 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter out_mailer */

/* 272 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 274 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 276 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter rtinfo */

/* 278 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 280 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 282 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 284 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 286 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 288 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NewDecryptFile */

/* 290 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 292 */	NdrFcLong( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 298 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x8 ),	/* 8 */
/* 304 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x6,		/* 6 */

	/* Parameter provider_name */

/* 306 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 308 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 310 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter container_name */

/* 312 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 314 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 316 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter mailer */

/* 318 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 320 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 322 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter out_mailer */

/* 324 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 326 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 328 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter rtinfo */

/* 330 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 332 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 334 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 336 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 338 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure HAND_Sign */


	/* Procedure HAND_DecryptFile */

/* 342 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 344 */	NdrFcLong( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0xa ),	/* 10 */
/* 350 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x7,		/* 7 */

	/* Parameter provider_name */


	/* Parameter provider_name */

/* 358 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 360 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 362 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter container_name */


	/* Parameter container_name */

/* 364 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 366 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 368 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szMessage */


	/* Parameter bsPin */

/* 370 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 372 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 374 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szSignature_dat */


	/* Parameter mailer */

/* 376 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 378 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 380 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter cuser */


	/* Parameter out_mailer */

/* 382 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 384 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 386 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szSignature */


	/* Parameter rtinfo */

/* 388 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 390 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 392 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */


	/* Return value */

/* 394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 396 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure P11LogOutFinalize */

/* 400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 406 */	NdrFcShort( 0xb ),	/* 11 */
/* 408 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 414 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 418 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCertByUser */

/* 422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 428 */	NdrFcShort( 0xc ),	/* 12 */
/* 430 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 436 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter provider_name */

/* 438 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 440 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 442 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter cuser */

/* 444 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 446 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 448 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter ccontainer */

/* 450 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 454 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 456 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 458 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Sign */

/* 462 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 464 */	NdrFcLong( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x7 ),	/* 7 */
/* 470 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x8 ),	/* 8 */
/* 476 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter szMessage */

/* 478 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 480 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 482 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szSignature */

/* 484 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 486 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 488 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 490 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 492 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure VerifySignature */

/* 496 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 498 */	NdrFcLong( 0x0 ),	/* 0 */
/* 502 */	NdrFcShort( 0x8 ),	/* 8 */
/* 504 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 506 */	NdrFcShort( 0x0 ),	/* 0 */
/* 508 */	NdrFcShort( 0x22 ),	/* 34 */
/* 510 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter szSignature */

/* 512 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 514 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 516 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szMessage */

/* 518 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 520 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 522 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter blRet */

/* 524 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 526 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 528 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 532 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NewSign */

/* 536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x9 ),	/* 9 */
/* 544 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x8 ),	/* 8 */
/* 550 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x6,		/* 6 */

	/* Parameter provider_name */

/* 552 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 554 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 556 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter container_name */

/* 558 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 560 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 562 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szMessage */

/* 564 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 566 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 568 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szSignature_dat */

/* 570 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 572 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 574 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szSignature */

/* 576 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 578 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 580 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 584 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SignByUser */

/* 588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0xb ),	/* 11 */
/* 596 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 602 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter szMessage */

/* 604 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 606 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 608 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szUser */

/* 610 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 612 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 614 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter szSignature */

/* 616 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 618 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 620 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 622 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 624 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 626 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCertSId */

/* 628 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 630 */	NdrFcLong( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0xc ),	/* 12 */
/* 636 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x8 ),	/* 8 */
/* 642 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter inCertName */

/* 644 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 646 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 648 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter outCertSid */

/* 650 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 652 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 654 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 658 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetCertSubject */

/* 662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0xd ),	/* 13 */
/* 670 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 676 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter inCertName */

/* 678 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 682 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter outSubject */

/* 684 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 688 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 692 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure getCertXML */

/* 696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0xe ),	/* 14 */
/* 704 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 710 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter szXml */

/* 712 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 714 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 716 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 718 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 720 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCerts */

/* 724 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 726 */	NdrFcLong( 0x0 ),	/* 0 */
/* 730 */	NdrFcShort( 0x7 ),	/* 7 */
/* 732 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x8 ),	/* 8 */
/* 738 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 740 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 742 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddNums */

/* 746 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 754 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x8 ),	/* 8 */
/* 760 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter rtnum */

/* 762 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 764 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 766 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 768 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 770 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindCertByUser */

/* 774 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 776 */	NdrFcLong( 0x0 ),	/* 0 */
/* 780 */	NdrFcShort( 0x9 ),	/* 9 */
/* 782 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x8 ),	/* 8 */
/* 788 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter cuser */

/* 790 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 792 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 794 */	NdrFcShort( 0x2c ),	/* Type Offset=44 */

	/* Parameter ccontainer */

/* 796 */	NdrFcShort( 0x2113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=8 */
/* 798 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 800 */	NdrFcShort( 0x1e ),	/* Type Offset=30 */

	/* Return value */

/* 802 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 804 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const util_MIDL_TYPE_FORMAT_STRING util__MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/*  4 */	NdrFcShort( 0x1a ),	/* Offset= 26 (30) */
/*  6 */	
			0x13, 0x0,	/* FC_OP */
/*  8 */	NdrFcShort( 0xc ),	/* Offset= 12 (20) */
/* 10 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 12 */	NdrFcShort( 0x2 ),	/* 2 */
/* 14 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 16 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 18 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 20 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 22 */	NdrFcShort( 0x8 ),	/* 8 */
/* 24 */	NdrFcShort( 0xfff2 ),	/* Offset= -14 (10) */
/* 26 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 28 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 30 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x4 ),	/* 4 */
/* 36 */	NdrFcShort( 0x0 ),	/* 0 */
/* 38 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (6) */
/* 40 */	
			0x12, 0x0,	/* FC_UP */
/* 42 */	NdrFcShort( 0xffea ),	/* Offset= -22 (20) */
/* 44 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x4 ),	/* 4 */
/* 50 */	NdrFcShort( 0x0 ),	/* 0 */
/* 52 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (40) */
/* 54 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 56 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDialog, ver. 0.0,
   GUID={0x68D280CB,0x030B,0x40F9,{0x95,0x56,0xEA,0x61,0x7F,0x39,0xFB,0xC5}} */

#pragma code_seg(".orpc")
static const unsigned short IDialog_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    80
    };

static const MIDL_STUBLESS_PROXY_INFO IDialog_ProxyInfo =
    {
    &Object_StubDesc,
    util__MIDL_ProcFormatString.Format,
    &IDialog_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IDialog_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    util__MIDL_ProcFormatString.Format,
    &IDialog_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IDialogProxyVtbl = 
{
    &IDialog_ProxyInfo,
    &IID_IDialog,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IDialog::SelectFolder */ ,
    (void *) (INT_PTR) -1 /* IDialog::SelectFiles */ ,
    (void *) (INT_PTR) -1 /* IDialog::SaveFile */
};


static const PRPC_STUB_FUNCTION IDialog_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IDialogStubVtbl =
{
    &IID_IDialog,
    &IDialog_ServerInfo,
    10,
    &IDialog_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFileWriter, ver. 0.0,
   GUID={0x6A5D4CDA,0xFAA0,0x452A,{0xB8,0x0C,0x7F,0xC5,0x6B,0x08,0x53,0x9D}} */

#pragma code_seg(".orpc")
static const unsigned short IFileWriter_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    126,
    154,
    182
    };

static const MIDL_STUBLESS_PROXY_INFO IFileWriter_ProxyInfo =
    {
    &Object_StubDesc,
    util__MIDL_ProcFormatString.Format,
    &IFileWriter_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFileWriter_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    util__MIDL_ProcFormatString.Format,
    &IFileWriter_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IFileWriterProxyVtbl = 
{
    &IFileWriter_ProxyInfo,
    &IID_IFileWriter,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFileWriter::CreateFile */ ,
    (void *) (INT_PTR) -1 /* IFileWriter::AppendFileContent */ ,
    (void *) (INT_PTR) -1 /* IFileWriter::WriteFile */
};


static const PRPC_STUB_FUNCTION IFileWriter_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFileWriterStubVtbl =
{
    &IID_IFileWriter,
    &IFileWriter_ServerInfo,
    10,
    &IFileWriter_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFileEncrypter, ver. 0.0,
   GUID={0xC4D88249,0x2999,0x4B51,{0xB6,0x30,0x9F,0xF5,0xAA,0x9A,0x7B,0xFF}} */

#pragma code_seg(".orpc")
static const unsigned short IFileEncrypter_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    210
    };

static const MIDL_STUBLESS_PROXY_INFO IFileEncrypter_ProxyInfo =
    {
    &Object_StubDesc,
    util__MIDL_ProcFormatString.Format,
    &IFileEncrypter_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFileEncrypter_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    util__MIDL_ProcFormatString.Format,
    &IFileEncrypter_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IFileEncrypterProxyVtbl = 
{
    &IFileEncrypter_ProxyInfo,
    &IID_IFileEncrypter,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFileEncrypter::EncryptFile */
};


static const PRPC_STUB_FUNCTION IFileEncrypter_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IFileEncrypterStubVtbl =
{
    &IID_IFileEncrypter,
    &IFileEncrypter_ServerInfo,
    8,
    &IFileEncrypter_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IFileDecrypter, ver. 0.0,
   GUID={0x4F8525D5,0x20B7,0x4EF3,{0x91,0xAE,0x36,0x22,0xEA,0x10,0x43,0xA5}} */

#pragma code_seg(".orpc")
static const unsigned short IFileDecrypter_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    250,
    290,
    80,
    342,
    400,
    422
    };

static const MIDL_STUBLESS_PROXY_INFO IFileDecrypter_ProxyInfo =
    {
    &Object_StubDesc,
    util__MIDL_ProcFormatString.Format,
    &IFileDecrypter_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IFileDecrypter_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    util__MIDL_ProcFormatString.Format,
    &IFileDecrypter_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IFileDecrypterProxyVtbl = 
{
    &IFileDecrypter_ProxyInfo,
    &IID_IFileDecrypter,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IFileDecrypter::DecryptFile */ ,
    (void *) (INT_PTR) -1 /* IFileDecrypter::NewDecryptFile */ ,
    (void *) (INT_PTR) -1 /* IFileDecrypter::PIN_DecryptFile */ ,
    (void *) (INT_PTR) -1 /* IFileDecrypter::HAND_DecryptFile */ ,
    (void *) (INT_PTR) -1 /* IFileDecrypter::P11LogOutFinalize */ ,
    (void *) (INT_PTR) -1 /* IFileDecrypter::FindCertByUser */
};


static const PRPC_STUB_FUNCTION IFileDecrypter_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IFileDecrypterStubVtbl =
{
    &IID_IFileDecrypter,
    &IFileDecrypter_ServerInfo,
    13,
    &IFileDecrypter_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IUKEYSignature, ver. 0.0,
   GUID={0xED770C81,0x946B,0x47BC,{0xA2,0x5F,0x5C,0x72,0x90,0x23,0x82,0xA1}} */

#pragma code_seg(".orpc")
static const unsigned short IUKEYSignature_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    462,
    496,
    536,
    342,
    588,
    628,
    662,
    696
    };

static const MIDL_STUBLESS_PROXY_INFO IUKEYSignature_ProxyInfo =
    {
    &Object_StubDesc,
    util__MIDL_ProcFormatString.Format,
    &IUKEYSignature_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IUKEYSignature_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    util__MIDL_ProcFormatString.Format,
    &IUKEYSignature_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(15) _IUKEYSignatureProxyVtbl = 
{
    &IUKEYSignature_ProxyInfo,
    &IID_IUKEYSignature,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IUKEYSignature::Sign */ ,
    (void *) (INT_PTR) -1 /* IUKEYSignature::VerifySignature */ ,
    (void *) (INT_PTR) -1 /* IUKEYSignature::NewSign */ ,
    (void *) (INT_PTR) -1 /* IUKEYSignature::HAND_Sign */ ,
    (void *) (INT_PTR) -1 /* IUKEYSignature::SignByUser */ ,
    (void *) (INT_PTR) -1 /* IUKEYSignature::GetCertSId */ ,
    (void *) (INT_PTR) -1 /* IUKEYSignature::GetCertSubject */ ,
    (void *) (INT_PTR) -1 /* IUKEYSignature::getCertXML */
};


static const PRPC_STUB_FUNCTION IUKEYSignature_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IUKEYSignatureStubVtbl =
{
    &IID_IUKEYSignature,
    &IUKEYSignature_ServerInfo,
    15,
    &IUKEYSignature_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ITestSample, ver. 0.0,
   GUID={0x8E27D2FA,0xDF40,0x45E4,{0xBB,0x2B,0xB1,0x0E,0x83,0x3B,0x8F,0x45}} */

#pragma code_seg(".orpc")
static const unsigned short ITestSample_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    724,
    746,
    774
    };

static const MIDL_STUBLESS_PROXY_INFO ITestSample_ProxyInfo =
    {
    &Object_StubDesc,
    util__MIDL_ProcFormatString.Format,
    &ITestSample_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO ITestSample_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    util__MIDL_ProcFormatString.Format,
    &ITestSample_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _ITestSampleProxyVtbl = 
{
    &ITestSample_ProxyInfo,
    &IID_ITestSample,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* ITestSample::FindCerts */ ,
    (void *) (INT_PTR) -1 /* ITestSample::AddNums */ ,
    (void *) (INT_PTR) -1 /* ITestSample::FindCertByUser */
};


static const PRPC_STUB_FUNCTION ITestSample_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ITestSampleStubVtbl =
{
    &IID_ITestSample,
    &ITestSample_ServerInfo,
    10,
    &ITestSample_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    util__MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x70001f4, /* MIDL Version 7.0.500 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0
    };

const CInterfaceProxyVtbl * _util_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IFileEncrypterProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IUKEYSignatureProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IDialogProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFileDecrypterProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IFileWriterProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ITestSampleProxyVtbl,
    0
};

const CInterfaceStubVtbl * _util_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IFileEncrypterStubVtbl,
    ( CInterfaceStubVtbl *) &_IUKEYSignatureStubVtbl,
    ( CInterfaceStubVtbl *) &_IDialogStubVtbl,
    ( CInterfaceStubVtbl *) &_IFileDecrypterStubVtbl,
    ( CInterfaceStubVtbl *) &_IFileWriterStubVtbl,
    ( CInterfaceStubVtbl *) &_ITestSampleStubVtbl,
    0
};

PCInterfaceName const _util_InterfaceNamesList[] = 
{
    "IFileEncrypter",
    "IUKEYSignature",
    "IDialog",
    "IFileDecrypter",
    "IFileWriter",
    "ITestSample",
    0
};

const IID *  _util_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _util_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _util, pIID, n)

int __stdcall _util_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _util, 6, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _util, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _util, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _util, 6, *pIndex )
    
}

const ExtendedProxyFileInfo util_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _util_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _util_StubVtblList,
    (const PCInterfaceName * ) & _util_InterfaceNamesList,
    (const IID ** ) & _util_BaseIIDList,
    & _util_IID_Lookup, 
    6,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

