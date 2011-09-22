#define _MFC_OVERRIDES_NEW
#define _CRTDBG_MAP_ALLOC
#ifdef _WIN32
	#include <windows.h>
#else
	#include <dlfcn.h>
#endif
#include "pkcs11.h"
#include "testp11.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#ifndef Crypto_Enum_Pair_Def
	#define Crypto_Enum_Pair_Def
	typedef struct {
		unsigned	type;
		char		*name;
	} Crypto_Enum_Pair;
#endif

#ifdef __cplusplus
extern "C" {
#endif

CK_FUNCTION_LIST_PTR P11_FuncList = 0;
#ifdef _WIN32
	HMODULE p11Module;
#else
	void *p11Module;
#endif
unsigned expectCkr = 0;
extern Crypto_Enum_Pair Ckr_Errors[], ckm_pairs[];

int Load_Pkcs11_Lib( char *dllName )
{
	CK_RV (*dll_get_function_list)(CK_FUNCTION_LIST_PTR_PTR);
#ifdef _WIN32

	DWORD dwNum = MultiByteToWideChar (CP_ACP, 0, dllName, -1, NULL, 0);
	wchar_t *pwText;
	pwText = new wchar_t[dwNum];
	if(!pwText)
	{
		delete []pwText;
	}
	MultiByteToWideChar (CP_ACP, 0, dllName, -1, pwText, dwNum);

	p11Module = LoadLibrary( pwText );

	delete []pwText;

	dll_get_function_list = (CK_RV (*)(CK_FUNCTION_LIST_PTR_PTR))GetProcAddress( p11Module, "C_GetFunctionList" );
	if ( dll_get_function_list )
		dll_get_function_list( &P11_FuncList );
	if ( ! P11_FuncList )
	{
		MessageBox( 0, L"Can't Load Pkcs11 Library.", L"Error", 0 );
		exit( 1 );
	}
#else
	p11Module = dlopen( dllName, RTLD_LAZY );
	if ( p11Module )
	{
		dll_get_function_list = (CK_RV (*)(CK_FUNCTION_LIST_PTR_PTR))dlsym( p11Module, "C_GetFunctionList" );
		if ( dll_get_function_list )
			dll_get_function_list( &P11_FuncList );
		if ( ! P11_FuncList )
		{
			printf( "Can't Load Pkcs11 Library: %s\n", dllName );
			exit( 1 );
		}
	} else
	{
		fprintf( stderr, "%s\n", dlerror() );
		exit( 1 );
	}
#endif
	return 0;
}

int Free_Pkcs11_Lib()
{
	if ( p11Module )
	{
#ifdef _WIN32
		FreeLibrary( p11Module );
#else
		dlclose( p11Module );
#endif
		p11Module = 0;
		return 1;
	}
	return 0;
}

char *Ckm_NameSpace( unsigned ckm )
{
	static char buffer[ 48 ];
	for ( int i = 0; ckm_pairs[ i ].name; i ++ )
		if ( ckm_pairs[ i ].type == ckm )
		{
			sprintf( buffer, "%s ", ckm_pairs[ i ].name + 4 );
			return buffer;
		}
	return 0;
}

int Template_Int( CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, int attrType, int defaultValue )
{
	unsigned i;
	for ( i = 0; i < ulCount; i ++ )
	{
		if ( pTemplate[ i ].type == (CK_ATTRIBUTE_TYPE)attrType )
		{
			if ( 4 == pTemplate[ i ].ulValueLen )
				return *(int *)pTemplate[ i ].pValue;
		}
	}
	return defaultValue;
}

CK_RV P11_Ret( char *prefix, char *func, CK_RV rv )
{
	if ( ! prefix )
		prefix = "";
	if ( rv != CKR_OK )
	{
		char buffer[ 128 ];
		int i;
		for ( i = 0; CKR_OK != Ckr_Errors[ i ].type; i ++ )
			if ( rv == (unsigned)Ckr_Errors[ i ].type )
				break;
		if ( CKR_OK == Ckr_Errors[ i ].type )
			sprintf( buffer, "%s return 0x%x\n.", func, rv );
		else
			sprintf( buffer, "%s return %s.\n", func, Ckr_Errors[ i ].name );
		printf( buffer );
#ifdef _WIN32
		if ( expectCkr != rv )
		{
			if ( CKR_OK == Ckr_Errors[ i ].type )
				sprintf( buffer, "%s%s return 0x%x, Continue?", prefix, func, rv );
			else
				sprintf( buffer, "%s%s return %s, Continue?", prefix, func, Ckr_Errors[ i ].name );

			DWORD dwNum = MultiByteToWideChar (CP_ACP, 0, buffer, -1, NULL, 0);
			wchar_t *pwText;
			pwText = new wchar_t[dwNum];
			if(!pwText)
			{
				delete []pwText;
			}
			MultiByteToWideChar (CP_ACP, 0, buffer, -1, pwText, dwNum);

			//if ( IDCANCEL == MessageBox( 0, buffer, L"Pkcs11 Error", MB_OKCANCEL ) )
				//exit( 1 );
			int rt = MB_OK;//MessageBox( 0, pwText, L"Pkcs11 Error", MB_OK );
			delete []pwText;
			if ( IDCANCEL ==  rt)
				exit( 1 );
		}
#else
		exit( 1 );
#endif
	} else
		printf( "%s%s return CKR_OK.\n", prefix, func );
	expectCkr = CKR_OK;
	return rv;
}

CK_RV C_GetFunctionList(CK_FUNCTION_LIST_PTR_PTR ppFunctionList)
{
	if ( ! P11_FuncList )
		return CKR_FUNCTION_FAILED;
	*ppFunctionList = P11_FuncList;
	return CKR_OK;
}

CK_RV C_Initialize(CK_VOID_PTR pInitArgs)
{
	if ( P11_FuncList && P11_FuncList->C_Initialize )
		return P11_Ret( 0, "C_Initialize", P11_FuncList->C_Initialize(pInitArgs) );
	return P11_Ret( 0, "C_Initialize", CKR_FUNCTION_FAILED );
}

CK_RV C_GetMechanismList(CK_SLOT_ID slotID, CK_MECHANISM_TYPE_PTR pMechanismList, CK_ULONG_PTR pulCount)
{
	if ( P11_FuncList && P11_FuncList->C_GetMechanismList )
		return P11_Ret( 0, "C_GetMechanismList", P11_FuncList->C_GetMechanismList(slotID, pMechanismList, pulCount) );
	return P11_Ret( 0, "C_GetMechanismList", CKR_FUNCTION_FAILED );
}

CK_RV C_GetMechanismInfo(CK_SLOT_ID slotID, CK_MECHANISM_TYPE type, CK_MECHANISM_INFO_PTR pInfo)
{
	if ( P11_FuncList && P11_FuncList->C_GetMechanismInfo )
		return P11_Ret( 0, "C_GetMechanismInfo", P11_FuncList->C_GetMechanismInfo(slotID, type, pInfo) );
	return P11_Ret( 0, "C_GetMechanismInfo", CKR_FUNCTION_FAILED );
}

CK_RV C_InitToken(CK_SLOT_ID slotID, CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen, CK_UTF8CHAR_PTR pLabel)
{
	if ( P11_FuncList && P11_FuncList->C_InitToken )
		return P11_Ret( 0, "C_InitToken", P11_FuncList->C_InitToken (slotID, pPin, ulPinLen, pLabel) );
	return P11_Ret( 0, "C_InitToken", CKR_FUNCTION_FAILED );
}

CK_RV C_InitPIN(CK_SESSION_HANDLE hSession, CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen)
{
	if ( P11_FuncList && P11_FuncList->C_InitPIN )
		return P11_Ret( 0, "C_InitPIN", P11_FuncList->C_InitPIN(hSession, pPin, ulPinLen) );
	return P11_Ret( 0, "C_InitPIN", CKR_FUNCTION_FAILED );
}

CK_RV C_SetPIN(CK_SESSION_HANDLE hSession, CK_UTF8CHAR_PTR pOldPin, CK_ULONG ulOldLen, CK_UTF8CHAR_PTR pNewPin, CK_ULONG ulNewLen)
{
	if ( P11_FuncList && P11_FuncList->C_SetPIN )
		return P11_Ret( 0, "C_SetPIN", P11_FuncList->C_SetPIN(hSession, pOldPin, ulOldLen, pNewPin, ulNewLen) );
	return P11_Ret( 0, "C_SetPIN", CKR_FUNCTION_FAILED );
}

CK_RV C_Login(CK_SESSION_HANDLE hSession, CK_USER_TYPE userType, CK_UTF8CHAR_PTR pPin, CK_ULONG ulPinLen)
{
	if ( P11_FuncList && P11_FuncList->C_Login )
		return P11_Ret( 0, "C_Login", P11_FuncList->C_Login(hSession, userType, pPin, ulPinLen) );
	return P11_Ret( 0, "C_Login", CKR_FUNCTION_FAILED );
}

CK_RV C_CreateObject(CK_SESSION_HANDLE hSession, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, CK_OBJECT_HANDLE_PTR phObject)
{
	if ( P11_FuncList && P11_FuncList->C_CreateObject )
	{
		char *name = "C_CreateObject";
		int cko = Template_Int( pTemplate, ulCount, CKA_CLASS, -1 );
		if ( CKO_CERTIFICATE == cko )
			name = "C_CreateCertificate";
		if ( CKO_PUBLIC_KEY == cko )
			name = "C_CreatePublicKey";
		if ( CKO_PRIVATE_KEY == cko )
			name = "C_CreatePrivateKey";
		return P11_Ret( 0, name, P11_FuncList->C_CreateObject(hSession, pTemplate, ulCount, phObject) );
	}
	return P11_Ret( 0, "C_CreateObject", CKR_FUNCTION_FAILED );
}

CK_RV C_GetAttributeValue(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount)
{
	if ( P11_FuncList && P11_FuncList->C_GetAttributeValue )
		return P11_Ret( 0, "C_GetAttributeValue", P11_FuncList->C_GetAttributeValue(hSession, hObject, pTemplate, ulCount) );
	return P11_Ret( 0, "C_GetAttributeValue", CKR_FUNCTION_FAILED );
}

CK_RV C_SetAttributeValue(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount)
{
	if ( P11_FuncList && P11_FuncList->C_SetAttributeValue )
		return P11_Ret( 0, "C_SetAttributeValue", P11_FuncList->C_SetAttributeValue(hSession, hObject, pTemplate, ulCount) );
	return P11_Ret( 0, "C_SetAttributeValue", CKR_FUNCTION_FAILED );
}

CK_RV C_FindObjects(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE_PTR phObject, CK_ULONG ulMaxObjectCount, CK_ULONG_PTR pulObjectCount)
{
	if ( P11_FuncList && P11_FuncList->C_FindObjects )
		return P11_Ret( 0, "C_FindObjects", P11_FuncList->C_FindObjects(hSession, phObject, ulMaxObjectCount, pulObjectCount) );
	return P11_Ret( 0, "C_FindObjects", CKR_FUNCTION_FAILED );
}

CK_RV C_Encrypt(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pData, CK_ULONG ulDataLen, CK_BYTE_PTR pEncryptedData, CK_ULONG_PTR pulEncryptedDataLen)
{
	if ( P11_FuncList && P11_FuncList->C_Encrypt )
		return P11_Ret( 0, "C_Encrypt", P11_FuncList->C_Encrypt(hSession, pData, ulDataLen, pEncryptedData, pulEncryptedDataLen) );
	return P11_Ret( 0, "C_Encrypt", CKR_FUNCTION_FAILED );
}

CK_RV C_Decrypt(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pEncryptedData, CK_ULONG ulEncryptedDataLen, CK_BYTE_PTR pData, CK_ULONG_PTR pulDataLen)
{
	if ( P11_FuncList && P11_FuncList->C_Decrypt )
		return P11_Ret( 0, "C_Decrypt", P11_FuncList->C_Decrypt(hSession, pEncryptedData, ulEncryptedDataLen, pData, pulDataLen) );
	return P11_Ret( 0, "C_Decrypt", CKR_FUNCTION_FAILED );
}

CK_RV C_Sign(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pData, CK_ULONG ulDataLen, CK_BYTE_PTR pSignature, CK_ULONG_PTR pulSignatureLen)
{
	if ( P11_FuncList && P11_FuncList->C_Sign )
		return P11_Ret( 0, "C_Sign", P11_FuncList->C_Sign(hSession, pData, ulDataLen, pSignature, pulSignatureLen) );
	return P11_Ret( 0, "C_Sign", CKR_FUNCTION_FAILED );
}

CK_RV C_Verify(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pData, CK_ULONG ulDataLen, CK_BYTE_PTR pSignature, CK_ULONG ulSignatureLen)
{
	if ( P11_FuncList && P11_FuncList->C_Verify )
		return P11_Ret( 0, "C_Verify", P11_FuncList->C_Verify(hSession, pData, ulDataLen, pSignature, ulSignatureLen) );
	return P11_Ret( 0, "C_Verify", CKR_FUNCTION_FAILED );
}

CK_RV C_GenerateKeyPair(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_ATTRIBUTE_PTR pPublicKeyTemplate, CK_ULONG ulPublicKeyAttributeCount, CK_ATTRIBUTE_PTR pPrivateKeyTemplate, CK_ULONG ulPrivateKeyAttributeCount, CK_OBJECT_HANDLE_PTR phPublicKey, CK_OBJECT_HANDLE_PTR phPrivateKey)
{
	if ( P11_FuncList && P11_FuncList->C_GenerateKeyPair )
		return P11_Ret( 0, "C_GenerateKeyPair", P11_FuncList->C_GenerateKeyPair(hSession, pMechanism, pPublicKeyTemplate, ulPublicKeyAttributeCount, pPrivateKeyTemplate, ulPrivateKeyAttributeCount, phPublicKey, phPrivateKey) );
	return P11_Ret( 0, "C_GenerateKeyPair", CKR_FUNCTION_FAILED );
}

CK_RV C_Finalize(CK_VOID_PTR pReserved)
{
	if ( P11_FuncList && P11_FuncList->C_Finalize )
		return P11_Ret( 0, "C_Finalize", P11_FuncList->C_Finalize(pReserved) );
	return P11_Ret( 0, "C_Finalize", CKR_FUNCTION_FAILED );
}

CK_RV C_GetInfo(CK_INFO_PTR pInfo)
{
	if ( P11_FuncList && P11_FuncList->C_GetInfo )
		return P11_Ret( 0, "C_GetInfo", P11_FuncList->C_GetInfo(pInfo) );
	return P11_Ret( 0, "C_Finalize", CKR_FUNCTION_FAILED );
}

CK_RV C_GetSlotList(CK_BBOOL tokenPresent, CK_SLOT_ID_PTR pSlotList, CK_ULONG_PTR pulCount)
{
	if ( P11_FuncList && P11_FuncList->C_GetSlotList )
		return P11_Ret( 0, "C_GetSlotList", P11_FuncList->C_GetSlotList(tokenPresent, pSlotList, pulCount) );
	return P11_Ret( 0, "C_GetSlotList", CKR_FUNCTION_FAILED );
}

CK_RV C_GetSlotInfo(CK_SLOT_ID slotID, CK_SLOT_INFO_PTR pInfo)
{
	if ( P11_FuncList && P11_FuncList->C_GetSlotInfo )
		return P11_Ret( 0, "C_GetSlotInfo", P11_FuncList->C_GetSlotInfo(slotID, pInfo) );
	return P11_Ret( 0, "C_GetSlotInfo", CKR_FUNCTION_FAILED );
}

CK_RV C_GetTokenInfo(CK_SLOT_ID slotID, CK_TOKEN_INFO_PTR pInfo)
{
	if ( P11_FuncList && P11_FuncList->C_GetTokenInfo )
		return P11_Ret( 0, "C_GetTokenInfo", P11_FuncList->C_GetTokenInfo(slotID, pInfo) );
	return P11_Ret( 0, "C_GetTokenInfo", CKR_FUNCTION_FAILED );
}

CK_RV C_OpenSession(CK_SLOT_ID slotID, CK_FLAGS flags, CK_VOID_PTR pApplication, CK_NOTIFY Notify, CK_SESSION_HANDLE_PTR phSession)
{
	if ( P11_FuncList && P11_FuncList->C_OpenSession )
		return P11_Ret( 0, "C_OpenSession", P11_FuncList->C_OpenSession(slotID, flags, pApplication, Notify, phSession) );
	return P11_Ret( 0, "C_OpenSession", CKR_FUNCTION_FAILED );
}

CK_RV C_CloseSession(CK_SESSION_HANDLE hSession)
{
	if ( P11_FuncList && P11_FuncList->C_CloseSession )
		return P11_Ret( 0, "C_CloseSession", P11_FuncList->C_CloseSession(hSession) );
	return P11_Ret( 0, "C_CloseSession", CKR_FUNCTION_FAILED );
}

CK_RV C_CloseAllSessions(CK_SLOT_ID slotID)
{
	if ( P11_FuncList && P11_FuncList->C_CloseAllSessions )
		return P11_Ret( 0, "C_CloseAllSessions", P11_FuncList->C_CloseAllSessions(slotID) );
	return P11_Ret( 0, "C_CloseAllSessions", CKR_FUNCTION_FAILED );
}

CK_RV C_GetSessionInfo(CK_SESSION_HANDLE hSession, CK_SESSION_INFO_PTR pInfo)
{
	if ( P11_FuncList && P11_FuncList->C_GetSessionInfo )
		return P11_Ret( 0, "C_GetSessionInfo", P11_FuncList->C_GetSessionInfo(hSession, pInfo) );
	return P11_Ret( 0, "C_GetSessionInfo", CKR_FUNCTION_FAILED );
}

CK_RV C_GetOperationState(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pOperationState, CK_ULONG_PTR pulOperationStateLen)
{
	if ( P11_FuncList && P11_FuncList->C_GetOperationState )
		return P11_Ret( 0, "C_GetOperationState", P11_FuncList->C_GetOperationState(hSession, pOperationState, pulOperationStateLen) );
	return P11_Ret( 0, "C_GetOperationState", CKR_FUNCTION_FAILED );
}

CK_RV C_SetOperationState(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pOperationState, CK_ULONG ulOperationStateLen, CK_OBJECT_HANDLE hEncryptionKey, CK_OBJECT_HANDLE hAuthenticationKey)
{
	if ( P11_FuncList && P11_FuncList->C_SetOperationState )
		return P11_Ret( 0, "C_SetOperationState", P11_FuncList->C_SetOperationState(hSession, pOperationState, ulOperationStateLen, hEncryptionKey, hAuthenticationKey) );
	return P11_Ret( 0, "C_SetOperationState", CKR_FUNCTION_FAILED );
}

CK_RV C_Logout(CK_SESSION_HANDLE hSession)
{
	if ( P11_FuncList && P11_FuncList->C_Logout )
		return P11_Ret( 0, "C_Logout", P11_FuncList->C_Logout(hSession) );
	return P11_Ret( 0, "C_Logout", CKR_FUNCTION_FAILED );
}

CK_RV C_CopyObject(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, CK_OBJECT_HANDLE_PTR phNewObject)
{
	if ( P11_FuncList && P11_FuncList->C_CopyObject )
		return P11_Ret( 0, "C_CopyObject", P11_FuncList->C_CopyObject(hSession, hObject, pTemplate, ulCount, phNewObject) );
	return P11_Ret( 0, "C_CopyObject", CKR_FUNCTION_FAILED );
}

CK_RV C_DestroyObject(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject)
{
	if ( P11_FuncList && P11_FuncList->C_DestroyObject )
		return P11_Ret( 0, "C_DestroyObject", P11_FuncList->C_DestroyObject(hSession, hObject) );
	return P11_Ret( 0, "C_DestroyObject", CKR_FUNCTION_FAILED );
}

CK_RV C_GetObjectSize(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject, CK_ULONG_PTR pulSize)
{
	if ( P11_FuncList && P11_FuncList->C_GetObjectSize )
		return P11_Ret( 0, "C_GetObjectSize", P11_FuncList->C_GetObjectSize(hSession, hObject, pulSize) );
	return P11_Ret( 0, "C_GetObjectSize", CKR_FUNCTION_FAILED );
}

CK_RV C_FindObjectsInit(CK_SESSION_HANDLE hSession, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount)
{
	if ( P11_FuncList && P11_FuncList->C_FindObjectsInit )
		return P11_Ret( 0, "C_FindObjectsInit", P11_FuncList->C_FindObjectsInit(hSession, pTemplate, ulCount) );
	return P11_Ret( 0, "C_FindObjectsInit", CKR_FUNCTION_FAILED );
}

CK_RV C_FindObjectsFinal(CK_SESSION_HANDLE hSession)
{
	if ( P11_FuncList && P11_FuncList->C_FindObjectsFinal )
		return P11_Ret( 0, "C_FindObjectsFinal", P11_FuncList->C_FindObjectsFinal(hSession) );
	return P11_Ret( 0, "C_FindObjectsFinal", CKR_FUNCTION_FAILED );
}

CK_RV C_EncryptInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hKey)
{
	if ( P11_FuncList && P11_FuncList->C_EncryptInit )
		return P11_Ret( Ckm_NameSpace( pMechanism->mechanism ), "C_EncryptInit", P11_FuncList->C_EncryptInit(hSession, pMechanism, hKey) );
	return P11_Ret( 0, "C_EncryptInit", CKR_FUNCTION_FAILED );
}

CK_RV C_EncryptUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pPart, CK_ULONG ulPartLen, CK_BYTE_PTR pEncryptedPart, CK_ULONG_PTR pulEncryptedPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_EncryptUpdate )
		return P11_Ret( 0, "C_EncryptUpdate", P11_FuncList->C_EncryptUpdate(hSession, pPart, ulPartLen, pEncryptedPart, pulEncryptedPartLen) );
	return P11_Ret( 0, "C_EncryptUpdate", CKR_FUNCTION_FAILED );
}

CK_RV C_EncryptFinal(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pLastEncryptedPart, CK_ULONG_PTR pulLastEncryptedPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_EncryptFinal )
		return P11_Ret( 0, "C_EncryptFinal", P11_FuncList->C_EncryptFinal(hSession, pLastEncryptedPart, pulLastEncryptedPartLen) );
	return P11_Ret( 0, "C_EncryptFinal", CKR_FUNCTION_FAILED );
}

CK_RV C_DecryptInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hKey)
{
	if ( P11_FuncList && P11_FuncList->C_DecryptInit )
		return P11_Ret( Ckm_NameSpace( pMechanism->mechanism ), "C_DecryptInit", P11_FuncList->C_DecryptInit(hSession, pMechanism, hKey) );
	return P11_Ret( 0, "C_DecryptInit", CKR_FUNCTION_FAILED );
}

CK_RV C_DecryptUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pEncryptedPart, CK_ULONG ulEncryptedPartLen, CK_BYTE_PTR pPart, CK_ULONG_PTR pulPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_DecryptUpdate )
		return P11_Ret( 0, "C_DecryptUpdate", P11_FuncList->C_DecryptUpdate(hSession, pEncryptedPart, ulEncryptedPartLen, pPart, pulPartLen) );
	return P11_Ret( 0, "C_DecryptUpdate", CKR_FUNCTION_FAILED );
}

CK_RV C_DecryptFinal(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pLastPart, CK_ULONG_PTR pulLastPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_DecryptFinal )
		return P11_Ret( 0, "C_DecryptFinal", P11_FuncList->C_DecryptFinal(hSession, pLastPart, pulLastPartLen) );
	return P11_Ret( 0, "C_DecryptFinal", CKR_FUNCTION_FAILED );
}

CK_RV C_DigestInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism)
{
	if ( P11_FuncList && P11_FuncList->C_DigestInit )
		return P11_Ret( 0, "C_DigestInit", P11_FuncList->C_DigestInit(hSession, pMechanism) );
	return P11_Ret( 0, "C_DigestInit", CKR_FUNCTION_FAILED );
}

CK_RV C_Digest(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pData, CK_ULONG ulDataLen, CK_BYTE_PTR pDigest, CK_ULONG_PTR pulDigestLen)
{
	if ( P11_FuncList && P11_FuncList->C_Digest )
		return P11_Ret( 0, "C_Digest", P11_FuncList->C_Digest(hSession, pData, ulDataLen, pDigest, pulDigestLen) );
	return P11_Ret( 0, "C_Digest", CKR_FUNCTION_FAILED );
}

CK_RV C_DigestUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pPart, CK_ULONG ulPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_DigestUpdate )
		return P11_Ret( 0, "C_DigestUpdate", P11_FuncList->C_DigestUpdate(hSession, pPart, ulPartLen) );
	return P11_Ret( 0, "C_DigestUpdate", CKR_FUNCTION_FAILED );
}

CK_RV C_DigestKey(CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hKey)
{
	if ( P11_FuncList && P11_FuncList->C_DigestKey )
		return P11_Ret( 0, "C_DigestKey", P11_FuncList->C_DigestKey(hSession, hKey) );
	return P11_Ret( 0, "C_DigestKey", CKR_FUNCTION_FAILED );
}

CK_RV C_DigestFinal(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pDigest, CK_ULONG_PTR pulDigestLen)
{
	if ( P11_FuncList && P11_FuncList->C_DigestFinal )
		return P11_Ret( 0, "C_DigestFinal", P11_FuncList->C_DigestFinal(hSession, pDigest, pulDigestLen) );
	return P11_Ret( 0, "C_DigestFinal", CKR_FUNCTION_FAILED );
}

CK_RV C_SignInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hKey)
{
	if ( P11_FuncList && P11_FuncList->C_SignInit )
		return P11_Ret( 0, "C_SignInit", P11_FuncList->C_SignInit(hSession, pMechanism, hKey) );
	return P11_Ret( 0, "C_SignInit", CKR_FUNCTION_FAILED );
}

CK_RV C_SignUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pPart, CK_ULONG ulPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_SignUpdate )
		return P11_Ret( 0, "C_SignUpdate", P11_FuncList->C_SignUpdate(hSession, pPart, ulPartLen) );
	return P11_Ret( 0, "C_SignUpdate", CKR_FUNCTION_FAILED );
}

CK_RV C_SignFinal(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pSignature, CK_ULONG_PTR pulSignatureLen)
{
	if ( P11_FuncList && P11_FuncList->C_SignFinal )
		return P11_Ret( 0, "C_SignFinal", P11_FuncList->C_SignFinal(hSession, pSignature, pulSignatureLen) );
	return P11_Ret( 0, "C_SignFinal", CKR_FUNCTION_FAILED );
}

CK_RV C_SignRecoverInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hKey)
{
	if ( P11_FuncList && P11_FuncList->C_SignRecoverInit )
		return P11_Ret( 0, "C_SignRecoverInit", P11_FuncList->C_SignRecoverInit(hSession, pMechanism, hKey) );
	return P11_Ret( 0, "C_SignRecoverInit", CKR_FUNCTION_FAILED );
}

CK_RV C_SignRecover(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pData, CK_ULONG ulDataLen, CK_BYTE_PTR pSignature, CK_ULONG_PTR pulSignatureLen)
{
	if ( P11_FuncList && P11_FuncList->C_SignRecover )
		return P11_Ret( 0, "C_SignRecover", P11_FuncList->C_SignRecover(hSession, pData, ulDataLen, pSignature, pulSignatureLen) );
	return P11_Ret( 0, "C_SignRecover", CKR_FUNCTION_FAILED );
}

CK_RV C_VerifyInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hKey)
{
	if ( P11_FuncList && P11_FuncList->C_VerifyInit )
		return P11_Ret( 0, "C_VerifyInit", P11_FuncList->C_VerifyInit(hSession, pMechanism, hKey) );
	return P11_Ret( 0, "C_VerifyInit", CKR_FUNCTION_FAILED );
}

CK_RV C_VerifyUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pPart, CK_ULONG ulPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_VerifyUpdate )
		return P11_Ret( 0, "C_VerifyUpdate", P11_FuncList->C_VerifyUpdate(hSession, pPart, ulPartLen) );
	return P11_Ret( 0, "C_VerifyUpdate", CKR_FUNCTION_FAILED );
}

CK_RV C_VerifyFinal(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pSignature, CK_ULONG ulSignatureLen)
{
	if ( P11_FuncList && P11_FuncList->C_VerifyFinal )
		return P11_Ret( 0, "C_VerifyFinal", P11_FuncList->C_VerifyFinal(hSession, pSignature, ulSignatureLen) );
	return P11_Ret( 0, "C_VerifyFinal", CKR_FUNCTION_FAILED );
}

CK_RV C_VerifyRecoverInit(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hKey)
{
	if ( P11_FuncList && P11_FuncList->C_VerifyRecoverInit )
		return P11_Ret( 0, "C_VerifyRecoverInit", P11_FuncList->C_VerifyRecoverInit(hSession, pMechanism, hKey) );
	return P11_Ret( 0, "C_VerifyRecoverInit", CKR_FUNCTION_FAILED );
}

CK_RV C_VerifyRecover(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pSignature, CK_ULONG ulSignatureLen, CK_BYTE_PTR pData, CK_ULONG_PTR pulDataLen)
{
	if ( P11_FuncList && P11_FuncList->C_VerifyRecover )
		return P11_Ret( 0, "C_VerifyRecover", P11_FuncList->C_VerifyRecover(hSession, pSignature, ulSignatureLen, pData, pulDataLen) );
	return P11_Ret( 0, "C_VerifyRecover", CKR_FUNCTION_FAILED );
}

CK_RV C_DigestEncryptUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pPart, CK_ULONG ulPartLen, CK_BYTE_PTR pEncryptedPart, CK_ULONG_PTR pulEncryptedPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_DigestEncryptUpdate )
		return P11_Ret( 0, "C_DigestEncryptUpdate", P11_FuncList->C_DigestEncryptUpdate(hSession, pPart, ulPartLen, pEncryptedPart, pulEncryptedPartLen) );
	return P11_Ret( 0, "C_DigestEncryptUpdate", CKR_FUNCTION_FAILED );
}

CK_RV C_DecryptDigestUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pEncryptedPart, CK_ULONG ulEncryptedPartLen, CK_BYTE_PTR pPart, CK_ULONG_PTR pulPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_DecryptDigestUpdate )
		return P11_Ret( 0, "C_DecryptDigestUpdate", P11_FuncList->C_DecryptDigestUpdate(hSession, pEncryptedPart, ulEncryptedPartLen, pPart, pulPartLen) );
	return P11_Ret( 0, "C_DecryptDigestUpdate", CKR_FUNCTION_FAILED );
}

CK_RV C_SignEncryptUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pPart, CK_ULONG ulPartLen, CK_BYTE_PTR pEncryptedPart, CK_ULONG_PTR pulEncryptedPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_SignEncryptUpdate )
		return P11_Ret( 0, "C_SignEncryptUpdate", P11_FuncList->C_SignEncryptUpdate(hSession, pPart, ulPartLen, pEncryptedPart, pulEncryptedPartLen) );
	return P11_Ret( 0, "C_SignEncryptUpdate", CKR_FUNCTION_FAILED );
}

CK_RV C_DecryptVerifyUpdate(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pEncryptedPart, CK_ULONG ulEncryptedPartLen, CK_BYTE_PTR pPart, CK_ULONG_PTR pulPartLen)
{
	if ( P11_FuncList && P11_FuncList->C_DecryptVerifyUpdate )
		return P11_Ret( 0, "C_DecryptVerifyUpdate", P11_FuncList->C_DecryptVerifyUpdate(hSession, pEncryptedPart, ulEncryptedPartLen, pPart, pulPartLen) );
	return P11_Ret( 0, "C_DecryptVerifyUpdate", CKR_FUNCTION_FAILED );
}

CK_RV C_GenerateKey(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, CK_OBJECT_HANDLE_PTR phKey)
{
	if ( P11_FuncList && P11_FuncList->C_GenerateKey )
		return P11_Ret( 0, "C_GenerateKey", P11_FuncList->C_GenerateKey(hSession, pMechanism, pTemplate, ulCount, phKey) );
	return P11_Ret( 0, "C_GenerateKey", CKR_FUNCTION_FAILED );
}

CK_RV C_WrapKey(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hWrappingKey, CK_OBJECT_HANDLE hKey, CK_BYTE_PTR pWrappedKey, CK_ULONG_PTR pulWrappedKeyLen)
{
	if ( P11_FuncList && P11_FuncList->C_WrapKey )
		return P11_Ret( 0, "C_WrapKey", P11_FuncList->C_WrapKey(hSession, pMechanism, hWrappingKey, hKey, pWrappedKey, pulWrappedKeyLen) );
	return P11_Ret( 0, "C_WrapKey", CKR_FUNCTION_FAILED );
}

CK_RV C_UnwrapKey(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hUnwrappingKey, CK_BYTE_PTR pWrappedKey, CK_ULONG ulWrappedKeyLen, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulAttributeCount, CK_OBJECT_HANDLE_PTR phKey)
{
	if ( P11_FuncList && P11_FuncList->C_UnwrapKey )
		return P11_Ret( 0, "C_UnwrapKey", P11_FuncList->C_UnwrapKey(hSession, pMechanism, hUnwrappingKey, pWrappedKey, ulWrappedKeyLen, pTemplate, ulAttributeCount, phKey) );
	return P11_Ret( 0, "C_UnwrapKey", CKR_FUNCTION_FAILED );
}

CK_RV C_DeriveKey(CK_SESSION_HANDLE hSession, CK_MECHANISM_PTR pMechanism, CK_OBJECT_HANDLE hBaseKey, CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulAttributeCount, CK_OBJECT_HANDLE_PTR phKey)
{
	if ( P11_FuncList && P11_FuncList->C_DeriveKey )
		return P11_Ret( 0, "C_DeriveKey", P11_FuncList->C_DeriveKey(hSession, pMechanism, hBaseKey, pTemplate, ulAttributeCount, phKey) );
	return P11_Ret( 0, "C_DeriveKey", CKR_FUNCTION_FAILED );
}

CK_RV C_SeedRandom(CK_SESSION_HANDLE hSession, CK_BYTE_PTR pSeed, CK_ULONG ulSeedLen)
{
	if ( P11_FuncList && P11_FuncList->C_SeedRandom )
		return P11_Ret( 0, "C_SeedRandom", P11_FuncList->C_SeedRandom(hSession, pSeed, ulSeedLen) );
	return P11_Ret( 0, "C_SeedRandom", CKR_FUNCTION_FAILED );
}

CK_RV C_GenerateRandom(CK_SESSION_HANDLE hSession, CK_BYTE_PTR RandomData, CK_ULONG ulRandomLen)
{
	if ( P11_FuncList && P11_FuncList->C_GenerateRandom )
		return P11_Ret( 0, "C_GenerateRandom", P11_FuncList->C_GenerateRandom(hSession, RandomData, ulRandomLen) );
	return P11_Ret( 0, "C_GenerateRandom", CKR_FUNCTION_FAILED );
}

CK_RV C_GetFunctionStatus(CK_SESSION_HANDLE hSession)
{
	if ( P11_FuncList && P11_FuncList->C_GetFunctionStatus )
		return P11_Ret( 0, "C_GetFunctionStatus", P11_FuncList->C_GetFunctionStatus(hSession) );
	return P11_Ret( 0, "C_GetFunctionStatus", CKR_FUNCTION_FAILED );
}

CK_RV C_CancelFunction(CK_SESSION_HANDLE hSession)
{
	if ( P11_FuncList && P11_FuncList->C_CancelFunction )
		return P11_Ret( 0, "C_CancelFunction", P11_FuncList->C_CancelFunction(hSession) );
	return P11_Ret( 0, "C_CancelFunction", CKR_FUNCTION_FAILED );
}

CK_RV C_WaitForSlotEvent(CK_FLAGS flags, CK_SLOT_ID_PTR pSlot, CK_VOID_PTR pRserved)
{
	if ( P11_FuncList && P11_FuncList->C_WaitForSlotEvent )
		return P11_Ret( 0, "C_WaitForSlotEvent", P11_FuncList->C_WaitForSlotEvent(flags, pSlot, pRserved) );
	return P11_Ret( 0, "C_WaitForSlotEvent", CKR_FUNCTION_FAILED );
}

int Crypto_MessageBox( char *lpText, char *lpCaption, unsigned uType)
{
#ifdef _WIN32
	static HMODULE kernelModule = 0;
	static HWND (WINAPI *GetConsoleWindowPtr)() = 0;
	HWND hWnd = GetActiveWindow();
	if ( ! hWnd )
	{
		if ( ! kernelModule )
		{
			kernelModule = LoadLibrary( L"Kernel32.dll" );
			if ( kernelModule )
				*(void **)&GetConsoleWindowPtr = (void *)GetProcAddress( kernelModule, "GetConsoleWindow" );
		}
		if ( GetConsoleWindowPtr )
			hWnd = (*GetConsoleWindowPtr)();
	}
	
	DWORD dwNum = MultiByteToWideChar (CP_ACP, 0, lpText, -1, NULL, 0);
	wchar_t *pwText;
	pwText = new wchar_t[dwNum];
	if(!pwText)
	{
		delete []pwText;
	}
	MultiByteToWideChar (CP_ACP, 0, lpText, -1, pwText, dwNum);

	dwNum = MultiByteToWideChar (CP_ACP, 0, lpCaption, -1, NULL, 0);
	wchar_t *pwCaption;
	pwCaption = new wchar_t[dwNum];
	if(!pwCaption)
	{
		delete []pwCaption;
	}
	MultiByteToWideChar (CP_ACP, 0, lpText, -1, pwCaption, dwNum);

	int rt = MessageBox( hWnd, pwText, pwCaption, uType );

	delete []pwText;
	delete []pwCaption;
	return rt;
#else
	return 0;
#endif
}

Crypto_Enum_Pair Ckr_Errors[] = {
	{ CKR_CANCEL,							"CKR_CANCEL" },
	{ CKR_HOST_MEMORY,						"CKR_HOST_MEMORY" },
	{ CKR_SLOT_ID_INVALID,					"CKR_SLOT_ID_INVALID" },
	{ CKR_GENERAL_ERROR,					"CKR_GENERAL_ERROR" },
	{ CKR_FUNCTION_FAILED,					"CKR_FUNCTION_FAILED" },
	{ CKR_ARGUMENTS_BAD,					"CKR_ARGUMENTS_BAD" },
	{ CKR_NO_EVENT,							"CKR_NO_EVENT" },
	{ CKR_NEED_TO_CREATE_THREADS,			"CKR_NEED_TO_CREATE_THREADS" },
	{ CKR_CANT_LOCK,						"CKR_CANT_LOCK" },
	{ CKR_ATTRIBUTE_READ_ONLY,				"CKR_ATTRIBUTE_READ_ONLY" },
	{ CKR_ATTRIBUTE_SENSITIVE,				"CKR_ATTRIBUTE_SENSITIVE" },
	{ CKR_ATTRIBUTE_TYPE_INVALID,			"CKR_ATTRIBUTE_TYPE_INVALID" },
	{ CKR_ATTRIBUTE_VALUE_INVALID,			"CKR_ATTRIBUTE_VALUE_INVALID" },
	{ CKR_DATA_INVALID,						"CKR_DATA_INVALID" },
	{ CKR_DATA_LEN_RANGE,					"CKR_DATA_LEN_RANGE" },
	{ CKR_DEVICE_ERROR,						"CKR_DEVICE_ERROR" },
	{ CKR_DEVICE_MEMORY,					"CKR_DEVICE_MEMORY" },
	{ CKR_DEVICE_REMOVED,					"CKR_DEVICE_REMOVED" },
	{ CKR_ENCRYPTED_DATA_INVALID,			"CKR_ENCRYPTED_DATA_INVALID" },
	{ CKR_ENCRYPTED_DATA_LEN_RANGE,			"CKR_ENCRYPTED_DATA_LEN_RANGE" },
	{ CKR_FUNCTION_CANCELED,				"CKR_FUNCTION_CANCELED" },
	{ CKR_FUNCTION_NOT_PARALLEL,			"CKR_FUNCTION_NOT_PARALLEL" },
	{ CKR_FUNCTION_NOT_SUPPORTED,			"CKR_FUNCTION_NOT_SUPPORTED" },
	{ CKR_KEY_HANDLE_INVALID,				"CKR_KEY_HANDLE_INVALID" },
	{ CKR_KEY_SIZE_RANGE,					"CKR_KEY_SIZE_RANGE" },
	{ CKR_KEY_TYPE_INCONSISTENT,			"CKR_KEY_TYPE_INCONSISTENT" },
	{ CKR_KEY_NOT_NEEDED,					"CKR_KEY_NOT_NEEDED" },
	{ CKR_KEY_CHANGED,						"CKR_KEY_CHANGED" },
	{ CKR_KEY_NEEDED,						"CKR_KEY_NEEDED" },
	{ CKR_KEY_INDIGESTIBLE,					"CKR_KEY_INDIGESTIBLE" },
	{ CKR_KEY_FUNCTION_NOT_PERMITTED,		"CKR_KEY_FUNCTION_NOT_PERMITTED" },
	{ CKR_KEY_NOT_WRAPPABLE,				"CKR_KEY_NOT_WRAPPABLE" },
	{ CKR_KEY_UNEXTRACTABLE,				"CKR_KEY_UNEXTRACTABLE" },
	{ CKR_MECHANISM_INVALID,				"CKR_MECHANISM_INVALID" },
	{ CKR_MECHANISM_PARAM_INVALID,			"CKR_MECHANISM_PARAM_INVALID" },
	{ CKR_OBJECT_HANDLE_INVALID,			"CKR_OBJECT_HANDLE_INVALID" },
	{ CKR_OPERATION_ACTIVE,					"CKR_OPERATION_ACTIVE" },
	{ CKR_OPERATION_NOT_INITIALIZED,		"CKR_OPERATION_NOT_INITIALIZED" },
	{ CKR_PIN_INCORRECT,					"CKR_PIN_INCORRECT" },
	{ CKR_PIN_INVALID,						"CKR_PIN_INVALID" },
	{ CKR_PIN_LEN_RANGE,					"CKR_PIN_LEN_RANGE" },
	{ CKR_PIN_EXPIRED,						"CKR_PIN_EXPIRED" },
	{ CKR_PIN_LOCKED,						"CKR_PIN_LOCKED" },
	{ CKR_SESSION_CLOSED,					"CKR_SESSION_CLOSED" },
	{ CKR_SESSION_COUNT,					"CKR_SESSION_COUNT" },
	{ CKR_SESSION_HANDLE_INVALID,			"CKR_SESSION_HANDLE_INVALID" },
	{ CKR_SESSION_PARALLEL_NOT_SUPPORTED,	"CKR_SESSION_PARALLEL_NOT_SUPPORTED" },
	{ CKR_SESSION_READ_ONLY,				"CKR_SESSION_READ_ONLY" },
	{ CKR_SESSION_EXISTS,					"CKR_SESSION_EXISTS" },
	{ CKR_SESSION_READ_ONLY_EXISTS,			"CKR_SESSION_READ_ONLY_EXISTS" },
	{ CKR_SESSION_READ_WRITE_SO_EXISTS,		"CKR_SESSION_READ_WRITE_SO_EXISTS" },
	{ CKR_SIGNATURE_INVALID,				"CKR_SIGNATURE_INVALID" },
	{ CKR_SIGNATURE_LEN_RANGE,				"CKR_SIGNATURE_LEN_RANGE" },
	{ CKR_TEMPLATE_INCOMPLETE,				"CKR_TEMPLATE_INCOMPLETE" },
	{ CKR_TEMPLATE_INCONSISTENT,			"CKR_TEMPLATE_INCONSISTENT" },
	{ CKR_TOKEN_NOT_PRESENT,				"CKR_TOKEN_NOT_PRESENT" },
	{ CKR_TOKEN_NOT_RECOGNIZED,				"CKR_TOKEN_NOT_RECOGNIZED" },
	{ CKR_TOKEN_WRITE_PROTECTED,			"CKR_TOKEN_WRITE_PROTECTED" },
	{ CKR_UNWRAPPING_KEY_HANDLE_INVALID,	"CKR_UNWRAPPING_KEY_HANDLE_INVALID" },
	{ CKR_UNWRAPPING_KEY_SIZE_RANGE,		"CKR_UNWRAPPING_KEY_SIZE_RANGE" },
	{ CKR_UNWRAPPING_KEY_TYPE_INCONSISTENT, "CKR_UNWRAPPING_KEY_TYPE_INCONSISTENT" },
	{ CKR_USER_ALREADY_LOGGED_IN,			"CKR_USER_ALREADY_LOGGED_IN" },
	{ CKR_USER_NOT_LOGGED_IN,				"CKR_USER_NOT_LOGGED_IN" },
	{ CKR_USER_PIN_NOT_INITIALIZED,			"CKR_USER_PIN_NOT_INITIALIZED" },
	{ CKR_USER_TYPE_INVALID,				"CKR_USER_TYPE_INVALID" },
	{ CKR_USER_ANOTHER_ALREADY_LOGGED_IN,	"CKR_USER_ANOTHER_ALREADY_LOGGED_IN" },
	{ CKR_USER_TOO_MANY_TYPES,				"CKR_USER_TOO_MANY_TYPES" },
	{ CKR_WRAPPED_KEY_INVALID,				"CKR_WRAPPED_KEY_INVALID" },
	{ CKR_WRAPPED_KEY_LEN_RANGE,			"CKR_WRAPPED_KEY_LEN_RANGE" },
	{ CKR_WRAPPING_KEY_HANDLE_INVALID,		"CKR_WRAPPING_KEY_HANDLE_INVALID" },
	{ CKR_WRAPPING_KEY_SIZE_RANGE,			"CKR_WRAPPING_KEY_SIZE_RANGE" },
	{ CKR_WRAPPING_KEY_TYPE_INCONSISTENT,	"CKR_WRAPPING_KEY_TYPE_INCONSISTENT" },
	{ CKR_RANDOM_SEED_NOT_SUPPORTED,		"CKR_RANDOM_SEED_NOT_SUPPORTED" },
	{ CKR_RANDOM_NO_RNG,					"CKR_RANDOM_NO_RNG" },
	{ CKR_DOMAIN_PARAMS_INVALID,			"CKR_DOMAIN_PARAMS_INVALID" },
	{ CKR_BUFFER_TOO_SMALL,					"CKR_BUFFER_TOO_SMALL" },
	{ CKR_SAVED_STATE_INVALID,				"CKR_SAVED_STATE_INVALID" },
	{ CKR_INFORMATION_SENSITIVE,			"CKR_INFORMATION_SENSITIVE" },
	{ CKR_STATE_UNSAVEABLE,					"CKR_STATE_UNSAVEABLE" },
	{ CKR_CRYPTOKI_NOT_INITIALIZED,			"CKR_CRYPTOKI_NOT_INITIALIZED" },
	{ CKR_CRYPTOKI_ALREADY_INITIALIZED,		"CKR_CRYPTOKI_ALREADY_INITIALIZED" },
	{ CKR_MUTEX_BAD,						"CKR_MUTEX_BAD" },
	{ CKR_MUTEX_NOT_LOCKED,					"CKR_MUTEX_NOT_LOCKED" },
	{ CKR_FUNCTION_REJECTED,				"CKR_FUNCTION_REJECTED" },
	{ CKR_VENDOR_DEFINED,					"CKR_VENDOR_DEFINED" },
	{ 0x6581,								"COS内存错误" },
	{ 0x6700,								"COS数据长度错误" },
	{ 0x6901,								"COS无效的状态" },
	{ 0x6954,								"COS按扭" },
	{ 0x6955,								"COS按扭延时" },
	{ 0x6981,								"COS文件类型不匹配" },
	{ 0x6982,								"COS安全状态不满足" },
	{ 0x6983,								"COS密钥已经被锁住" },
	{ 0x6985,								"COS使用条件不满足" },
	{ 0x6988,								"COS安全报文数据项不正确" },
	{ 0x6A80,								"COS数据域参数不正确" },
	{ 0x6A81,								"COS功能不支持" },
	{ 0x6A82,								"COS没有找到文件" },
	{ 0x6A83,								"COS没有找到记录" },
	{ 0x6A84,								"COS没有足够的空间" },
	{ 0x6A86,								"COS参数P1，P2不正确" },
	{ 0x6B00,								"COS参数错误（偏移地址超出了EF文件长度）" },
	{ 0x6D00,								"COS不正确的INS" },
	{ 0x6E00,								"COS不正确的CLA" },
	{ 0x6F00,								"COS无响应数据可取" },
	{ 0x9302,								"COS命令MAC无效" },
	{ 0x9303,								"COS应用永久锁定" },
	{ 0x9401,								"COS金额不足" },
	{ 0x9403,								"COS没有找到密钥" },
	{ 0x9406,								"COS所需MAC不可用" },
	{ CKR_OK,								"Ckr_OK" }
};

Crypto_Enum_Pair ckm_pairs[] = {
	{ CKM_SSF33_KEY_GEN,					"CKM_SSF33_KEY_GEN" },
	{ CKM_SSF33_ECB,						"CKM_SSF33_ECB" },
	{ CKM_SSF33_CBC,						"CKM_SSF33_CBC" },
	{ CKM_SSF33_ECB_PAD,					"CKM_SSF33_ECB_PAD" },
	{ CKM_SSF33_CBC_PAD,					"CKM_SSF33_CBC_PAD" },
	{ CKM_SCB2_KEY_GEN,						"CKM_SCB2_KEY_GEN" },
	{ CKM_SCB2_ECB,							"CKM_SCB2_ECB" },
	{ CKM_SCB2_CBC,							"CKM_SCB2_CBC" },
	{ CKM_SCB2_ECB_PAD,						"CKM_SCB2_ECB_PAD" },
	{ CKM_SCB2_CBC_PAD,						"CKM_SCB2_CBC_PAD" },
	{ CKM_RSA_PKCS_KEY_PAIR_GEN,			"CKM_RSA_PKCS_KEY_PAIR_GEN" },
	{ CKM_RSA_PKCS,							"CKM_RSA_PKCS" },
	{ CKM_RSA_9796,							"CKM_RSA_9796" },
	{ CKM_RSA_X_509,						"CKM_RSA_X_509" },
	{ CKM_MD5_RSA_PKCS,						"CKM_MD5_RSA_PKCS" },
	{ CKM_SHA1_RSA_PKCS,					"CKM_SHA1_RSA_PKCS" },
	{ CKM_SHA256_RSA_PKCS,					"CKM_SHA256_RSA_PKCS" },
	{ CKM_SHA384_RSA_PKCS,					"CKM_SHA384_RSA_PKCS" },
	{ CKM_SHA512_RSA_PKCS,					"CKM_SHA512_RSA_PKCS" },
	{ CKM_RSA_PKCS_OAEP,					"CKM_RSA_PKCS_OAEP" },
	{ CKM_RSA_X9_31_KEY_PAIR_GEN,			"CKM_RSA_X9_31_KEY_PAIR_GEN" },
	{ CKM_RSA_X9_31,						"CKM_RSA_X9_31" },
	{ CKM_SHA1_RSA_X9_31,					"CKM_SHA1_RSA_X9_31" },
	{ CKM_RSA_PKCS_PSS,						"CKM_RSA_PKCS_PSS" },
	{ CKM_SHA1_RSA_PKCS_PSS,				"CKM_SHA1_RSA_PKCS_PSS" },
	{ CKM_RC2_KEY_GEN,						"CKM_RC2_KEY_GEN" },
	{ CKM_RC2_ECB,							"CKM_RC2_ECB" },
	{ CKM_RC2_CBC,							"CKM_RC2_CBC" },
	{ CKM_RC2_MAC,							"CKM_RC2_MAC" },
	{ CKM_RC2_MAC_GENERAL,					"CKM_RC2_MAC_GENERAL" },
	{ CKM_RC2_CBC_PAD,						"CKM_RC2_CBC_PAD" },
	{ CKM_RC4_KEY_GEN,						"CKM_RC4_KEY_GEN" },
	{ CKM_RC4,								"CKM_RC4" },
	{ CKM_DES_KEY_GEN,						"CKM_DES_KEY_GEN" },
	{ CKM_DES_ECB,							"CKM_DES_ECB" },
	{ CKM_DES_CBC,							"CKM_DES_CBC" },
	{ CKM_DES_MAC,							"CKM_DES_MAC" },
	{ CKM_DES_MAC_GENERAL,					"CKM_DES_MAC_GENERAL" },
	{ CKM_DES_CBC_PAD,						"CKM_DES_CBC_PAD" },
	{ CKM_DES2_KEY_GEN,						"CKM_DES2_KEY_GEN" },
	{ CKM_DES3_KEY_GEN,						"CKM_DES3_KEY_GEN" },
	{ CKM_DES3_ECB,							"CKM_DES3_ECB" },
	{ CKM_DES3_CBC,							"CKM_DES3_CBC" },
	{ CKM_DES3_MAC,							"CKM_DES3_MAC" },
	{ CKM_DES3_MAC_GENERAL,					"CKM_DES3_MAC_GENERAL" },
	{ CKM_DES3_CBC_PAD,						"CKM_DES3_CBC_PAD" },
	{ CKM_MD5,								"CKM_MD5" },
	{ CKM_MD5_HMAC,							"CKM_MD5_HMAC" },
	{ CKM_MD5_HMAC_GENERAL,					"CKM_MD5_HMAC_GENERAL" },
	{ CKM_SHA_1,							"CKM_SHA_1" },
	{ CKM_SHA_1_HMAC,						"CKM_SHA_1_HMAC" },
	{ CKM_SHA_1_HMAC_GENERAL,				"CKM_SHA_1_HMAC_GENERAL" },
	{ CKM_SHA256,							"CKM_SHA256" },
	{ CKM_SHA256_HMAC,						"CKM_SHA256_HMAC" },
	{ CKM_SHA256_HMAC_GENERAL,				"CKM_SHA256_HMAC_GENERAL" },
	{ CKM_SHA384,							"CKM_SHA384" },
	{ CKM_SHA384_HMAC,						"CKM_SHA384_HMAC" },
	{ CKM_SHA384_HMAC_GENERAL,				"CKM_SHA384_HMAC_GENERAL" },
	{ CKM_SHA512,							"CKM_SHA512" },
	{ CKM_SHA512_HMAC,						"CKM_SHA512_HMAC" },
	{ CKM_SHA512_HMAC_GENERAL,				"CKM_SHA512_HMAC_GENERAL" },
	{ CKM_AES_KEY_GEN,						"CKM_AES_KEY_GEN" },
	{ CKM_AES_ECB,							"CKM_AES_ECB" },
	{ CKM_AES_CBC,							"CKM_AES_CBC" },
	{ CKM_AES_MAC,							"CKM_AES_MAC" },
	{ CKM_AES_MAC_GENERAL,					"CKM_AES_MAC_GENERAL" },
	{ CKM_AES_CBC_PAD,						"CKM_AES_CBC_PAD" },
	{ 0, 0 }
};

#ifdef __cplusplus
};
#endif
