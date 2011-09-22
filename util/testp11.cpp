#define _MFC_OVERRIDES_NEW
#include <malloc.h>
#define _CRTDBG_MAP_ALLOC
#ifdef _WIN32
	#include <windows.h>
	#ifndef __MINGW32__
		#include <crtdbg.h>
	#endif
	#include <conio.h>
#endif
#include <stdio.h>
#include <string.h>
#include "testp11.h"

#ifdef __cplusplus
extern "C" {
#endif

void TestWaitEvent( unsigned long *pSlot )
{
	unsigned long count = 1;
	CK_SLOT_INFO slotInfo;
	C_GetSlotList( true, pSlot, &count );
	if ( count > 0 )
		return;
	do
	{
		slotInfo.flags = 0;
		printf( "\nPlease Insert UsbKey.\n\n" );
		C_WaitForSlotEvent( 0, pSlot, 0 );
		C_GetSlotInfo( *pSlot, &slotInfo );
	} while ( ! ( slotInfo.flags & CKF_TOKEN_PRESENT ) );
}

void T11_Encrypt( CK_SESSION_HANDLE hSession, unsigned long hSymKey, int ckk, unsigned char *plain, unsigned plainSize, unsigned char *cipher, unsigned long *pCipherSize )
{
	CK_MECHANISM mech = { T11_Ckk_Ckm( ckk, 6 ), 0, 0 };
	C_EncryptInit( hSession, &mech, hSymKey );
	C_Encrypt( hSession, plain, plainSize, cipher, pCipherSize );
}

CK_RV T11_Decrypt( CK_SESSION_HANDLE hSession, unsigned long hSymKey, int ckk, unsigned char *cipher, unsigned cipherSize, unsigned char *plain, unsigned long *pPlainSize )
{
	CK_RV rt_decrypt = 0;
	CK_RV rt_init = 0;
	CK_MECHANISM mech = { T11_Ckk_Ckm( ckk, 6 ), 0, 0 };
	rt_init = C_DecryptInit( hSession, &mech, hSymKey );
	rt_decrypt = C_Decrypt( hSession, cipher, cipherSize, plain, pPlainSize );
	return rt_decrypt;
}

CK_RV T11_UnwrapKey(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hUnwrappingKey, CK_BYTE_PTR pWrappedKey, CK_ULONG ulWrappedKeyLen, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulAttributeCount, CK_OBJECT_HANDLE_PTR phKey)
{
	CK_ATTRIBUTE attrs[ 48 ];
	unsigned char keyValue[ 128 ];
	unsigned long ckk, keySize = sizeof( keyValue );
	T11_CopyTemplate( pTemplate, ulAttributeCount, attrs, 48 );
	
	C_DecryptInit( hSession, pMechanism, hUnwrappingKey );
	C_Decrypt( hSession, pWrappedKey, ulWrappedKeyLen, keyValue, &keySize );

	ckk = Template_Int( pTemplate, ulWrappedKeyLen, CKA_KEY_TYPE, 0 );
	attrs[ ulAttributeCount ].type = CKA_VALUE;
	if ( CKM_RSA_X_509 == pMechanism->mechanism && CKK_SCB2 == ckk )
	{
		keySize = 32;
		attrs[ ulAttributeCount ].pValue = keyValue + 128 - keySize;
	} else
		attrs[ ulAttributeCount ].pValue = keyValue;
	attrs[ ulAttributeCount ].ulValueLen = keySize;
	return C_CreateObject( hSession, attrs, ++ ulAttributeCount, phKey );
}

void T11_Envelope( CK_SESSION_HANDLE hSession, unsigned long hPub, int ckk, unsigned char *plain, unsigned long plainSize, unsigned char *warpedKey, unsigned long *pWrappedKeyLen, unsigned char *cipher, unsigned long *pCipherSize )
{
	unsigned long hSymKey;
	CK_MECHANISM rsaMech = { CKM_RSA_X_509, 0, 0 }, wrapMech = { 0, zeroIv, 8 };
//	CK_MECHANISM rsaMech = { CKM_RSA_PKCS, 0, 0 }, wrapMech = { 0, zeroIv, 8 };
	
	T11_GenerateKey( hSession, ckk, true, &hSymKey );
	C_WrapKey( hSession, &rsaMech, hPub, hSymKey, warpedKey, pWrappedKeyLen );
	T11_Encrypt( hSession, hSymKey, ckk, plain, plainSize, cipher, pCipherSize );
	C_DestroyObject( hSession, hSymKey );
}

void T11_Unenvelope( CK_SESSION_HANDLE hSession, unsigned long hPriv, int ckk, unsigned char *wrappedKey, unsigned long wrappedKeyLen, unsigned char *cipher, unsigned long cipherSize, unsigned char *plain, unsigned long *pPlainSize )
{
	unsigned long hSymKey;
	CK_ATTRIBUTE unwrapAttrs[ 6 ] = {
		{ CKA_CLASS, &ckoSecretKey, 4 },
		{ CKA_KEY_TYPE, &ckk, 4 },
		{ CKA_TOKEN, &trueValue, 1 },
		{ CKA_ENCRYPT, &trueValue, 1 },
		{ CKA_DECRYPT, &trueValue, 1 },
		{ CKA_EXTRACTABLE, &trueValue, 1 }
	};
//	CK_MECHANISM rsaMech = { CKM_RSA_X_509, 0, 0 }, wrapMech = { 0, zeroIv, 8 };
	CK_MECHANISM rsaMech = { CKM_RSA_PKCS, 0, 0 }, wrapMech = { 0, zeroIv, 8 };
	T11_UnwrapKey( hSession, &rsaMech, hPriv, wrappedKey, wrappedKeyLen, unwrapAttrs, 6, &hSymKey );
	T11_Decrypt( hSession, hSymKey, ckk, cipher, cipherSize, plain, pPlainSize );
	C_DestroyObject( hSession, hSymKey );
}

void TestEnvelop( CK_SESSION_HANDLE hSession, int ckk, char *string )
{
	unsigned char wrappedKey[ 256 ], cipher[ 256 ], plain[ 256 ];
	unsigned long wrappedKeyLen = sizeof(wrappedKey), cipherSize = sizeof(cipher), plainSize = sizeof(plain);
	Rsa_Cert *pCert = &TestRsaCert;
	unsigned long size, hPriv, hPub;
	size = strlen(string) + 1;
//	hPriv = T11_ImportPrivKey( hSession, "TestLable", pCert, true, 1, 0 );
//	hPub = T11_ImportPubKey( hSession, "TestLable", pCert, true, 1 );

	hPriv = T11_FindKey( hSession, true, 0, 0, 0 );
	hPub = T11_FindKey( hSession, false, 0, 0, 0 );

//	T11_Envelope( hSession, hPub, ckk, (unsigned char *)string, size, wrappedKey, &wrappedKeyLen, cipher, &cipherSize );

    memcpy(wrappedKey, "\x8C\xBF\x98\x5D\x50\x2A\x74\x53\x5D\xAE\xB6\xDF\x16\x81\x0D\x25\x81\xBF\xB4\xD7\x2D\xEE\x05\x62\x3B\xB2\xF8\x6C\x87\x3C\xCB\xB2\xCF\x11\x66\x5C\x09\xEF\x81\xF4\x5B\x84\x76\x3C\x89\xF0\x4D\xD9\xD0\x07\x46\xB6\xE5\x04\x9F\x15\xB7\x4A\x67\x11\x9D\xAA\x4B\xCD\x2E\x11\x25\x30\x31\xA3\xD0\x06\x62\xF3\x3D\xCD\xC0\xC2\x06\x07\x72\x70\xC9\xFB\x27\x2C\x25\x69\xFA\xAA\xDB\x61\xFB\xDE\xE0\x28\xC0\x56\x1E\xAD\x34\x53\xB6\xCE\xA7\x50\xA9\x4A\xB6\xAB\x74\x72\xDB\xFD\xAC\xB0\xC9\x94\x47\x04\xDD\x0A\xCB\xBD\xA0\x7E\x25\x80", 128);


	memcpy(cipher, "\xA8\x71\x7D\xB1\x06\x9D\xE3\xC1\x2C\x47\x22\xF6\x77\xE6\xCE\xBD", 16);
	cipherSize = 16;
	wrappedKeyLen = 128;


	T11_Unenvelope( hSession, hPriv, ckk, wrappedKey, wrappedKeyLen, cipher, cipherSize, plain, &plainSize );

//	C_DestroyObject( hSession, hPriv );
//	C_DestroyObject( hSession, hPub );
	if ( strcmp( (char *)plain, string ) )
		printf( "\n	TestEnvelop Fail.\n\n" );
	else
		printf( "\n	TestEnvelop: %s\n\n", plain );
}

//登录初始化
CK_SESSION_HANDLE WT11_LoginInit(unsigned char * pin, unsigned char * ccontainer)
{
	unsigned long int lenpin = 0;
	lenpin = strlen((char *)pin);
	CK_SESSION_HANDLE hSession;
	unsigned long slot = 0;
	//Load_Pkcs11_Lib( "HtPkcs11.dll" );
	C_Initialize( NULL );
	unsigned long count = 1;
	CK_SLOT_INFO slotInfo;
	C_GetSlotList( true, &slot, &count );
	if ( count <= 0 )
		return 0;
	///////测试
	//unsigned long pCkk;
	//T11_Haitai_TokenInfo(0, &pCkk);

	///////
	C_OpenSession( slot, CKF_RW_SESSION | CKF_SERIAL_SESSION, NULL, NULL, &hSession );
	C_Login( hSession, CKU_USER, (CK_UTF8CHAR_PTR) pin, (CK_ULONG) lenpin );
	//char *cerData = {"加密证书"};
	//T11_FindCert(hSession, 0, NULL, 0);
	return hSession;
}

void WT11_Initialize()
{
	C_Initialize( NULL );
}
//得到解密会话KEY
//pbufSessionKeyEncrypt 已经加密的会话KEY
//ckk 算法
unsigned long WT11_SessionKeyRsa(CK_SESSION_HANDLE hSession,
								 unsigned char *wrappedKey, unsigned long wrappedKeyLen)
{
	int ckk = CKK_SCB2;
	unsigned long hSymKey = 0;
	unsigned long hPriv, hPub;
	CK_ATTRIBUTE unwrapAttrs[ 6 ] = {
		{ CKA_CLASS, &ckoSecretKey, 4 },
		{ CKA_KEY_TYPE, &ckk, 4 },
		{ CKA_TOKEN, &trueValue, 1 },
		{ CKA_ENCRYPT, &trueValue, 1 },
		{ CKA_DECRYPT, &trueValue, 1 },
		{ CKA_EXTRACTABLE, &trueValue, 1 }
	};
	hPriv = T11_FindKey( hSession, true, 0, 0, 0 );
	CK_MECHANISM rsaMech = { CKM_RSA_PKCS, 0, 0 }, wrapMech = { 0, zeroIv, 8 };
	T11_UnwrapKey( hSession, &rsaMech, hPriv, wrappedKey, wrappedKeyLen, unwrapAttrs, 6, &hSymKey );
	return hSymKey;
}
void WT11_DestroyObject(CK_SESSION_HANDLE hSession, unsigned long hSymKey )
{
	C_DestroyObject( hSession, hSymKey );
}
//pbufSessionKeyEncrypt 已经加密的会话KEY
//pbufCipher 已经加密的数据
//pbufplain 解密数据
int WT11_SCB2_Decrypt(CK_SESSION_HANDLE hSession, unsigned long hSymKey, unsigned char *pbufCipher, 
					  unsigned long cipherSize, unsigned char *pbufplain, unsigned long * plainSize)
{
	CK_RV rt = 0;
	int ckk = CKK_SCB2;
	rt = T11_Decrypt( hSession, hSymKey, ckk, pbufCipher, cipherSize, pbufplain, plainSize );
	return (int) rt;
}

int WT11_LogOutFinalize(CK_SESSION_HANDLE hSession)
{
	C_Logout( hSession );
	C_Finalize( 0 );
	return 1;
}
/*
int main(int argc, char **argv)
{
	CK_SESSION_HANDLE hSession;
	unsigned long slot = 0;

	Load_Pkcs11_Lib( "HtPkcs11.dll" );
	C_Initialize( NULL );
	TestWaitEvent( &slot );
	C_OpenSession( slot, CKF_RW_SESSION | CKF_SERIAL_SESSION, NULL, NULL, &hSession );
	C_Login( hSession, CKU_USER, (CK_UTF8CHAR_PTR)"1111", 4 );

	TestEnvelop( hSession, CKK_SCB2, "hello, SCB2 envelope" );

	C_Logout( hSession );
	C_Finalize( 0 );
	return 0;
}*/

#ifdef __cplusplus
};
#endif
