#ifndef __APPLE__
	#include <malloc.h>
#endif
#define _CRTDBG_MAP_ALLOC
#ifdef _WIN32
	#include <windows.h>
	#ifndef __MINGW32__
		#include <crtdbg.h>
	#endif
#endif
#include <stdio.h>
#include <string.h>
#include "testp11.h"

#ifdef __cplusplus
extern "C" {
#endif

#define CKA_HT_COS_CONTAINER	0x5d6c0001
unsigned char trueValue = 1;
unsigned char falseValue = 0;
unsigned ckoPubKey = CKO_PUBLIC_KEY, ckoPrivKey = CKO_PRIVATE_KEY;
unsigned ckoCertificate = CKO_CERTIFICATE, ckoSecretKey = CKO_SECRET_KEY;
unsigned ckcX509 = CKC_X_509, ckkRsa = CKK_RSA;
CK_MECHANISM mechRsaPkcs = { CKM_RSA_PKCS, 0, 0 };
CK_MECHANISM mechRsaOaep = { CKM_RSA_PKCS_OAEP, 0, 0 };
CK_MECHANISM mechRsaX509 = { CKM_RSA_X_509, 0, 0 };
CK_MECHANISM mechRsaX931 = { CKM_RSA_X9_31, 0, 0 };
CK_MECHANISM mechMd5RsaPkcs = { CKM_MD5_RSA_PKCS, 0, 0 };
CK_MECHANISM mechSha1RsaPkcs = { CKM_SHA1_RSA_PKCS, 0, 0 };
unsigned char zeroIv[ 16 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void T11_DumpBinary( void *data, int size, char *name )
{
	FILE *fp = fopen( name, "wb" );
	if ( fp )
	{
		fwrite( data, 1, size, fp );
		fclose( fp );
	}
}

int T11_Ckk_Ckm( int ckk, int mode )
{
	int ckm = 0;
	if ( CKK_RSA == ckk )
		ckm = CKM_RSA_PKCS_KEY_PAIR_GEN;
	if ( CKK_DSA == ckk )
		ckm = CKM_DSA_KEY_PAIR_GEN;
	if ( CKK_DH == ckk )
		ckm = CKM_DH_PKCS_KEY_PAIR_GEN;
	if ( CKK_EC == ckk )
		ckm = CKM_EC_KEY_PAIR_GEN;
	if ( CKK_RC2 == ckk )
		ckm = CKM_RC2_KEY_GEN;
	if ( CKK_RC4 == ckk )
		ckm = CKM_RC4_KEY_GEN;
	if ( CKK_DES == ckk )
		ckm = CKM_DES_KEY_GEN;
	if ( CKK_DES2 == ckk )
		if ( mode )
			ckm = CKM_DES3_KEY_GEN;
		else
			ckm = CKM_DES2_KEY_GEN;
	if ( CKK_DES3 == ckk )
		ckm = CKM_DES3_KEY_GEN;
	if ( CKK_AES == ckk )
		ckm = CKM_AES_KEY_GEN;
	if ( CKK_SSF33 == ckk )
		ckm = CKM_SSF33_KEY_GEN;
	if ( CKK_SCB2 == ckk )
		ckm = CKM_SCB2_KEY_GEN;
	return ckm + mode;
}

void T11_CopyTemplate( CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, CK_ATTRIBUTE_PTR pTarget, CK_ULONG maxCount )
{
	if ( ulCount > maxCount )
		ulCount = maxCount;
	for ( unsigned i = 0; i < ulCount; i ++ )
	{
		pTarget[ i ].type =			pTemplate[ i ].type;
		pTarget[ i ].pValue =		pTemplate[ i ].pValue;
		pTarget[ i ].ulValueLen =	pTemplate[ i ].ulValueLen;
	}
}

CK_RV T11_GenKeyPair( CK_SESSION_HANDLE hSession, char *id, char inToken, char isExch, CK_OBJECT_HANDLE *phPubKey, CK_OBJECT_HANDLE *phPrivKey )
{
	CK_MECHANISM mech = { CKM_RSA_PKCS_KEY_PAIR_GEN, 0, 0 };
	unsigned char pubExponent[ 3 ] = { 0x01, 0x00, 0x01 };
	unsigned modulusBits = 1024;
	CK_ATTRIBUTE pubAttrs[ 5 ] = {
			{ CKA_PRIVATE, &falseValue, 1 },
			{ CKA_ENCRYPT, isExch ? &trueValue : &falseValue, 1 },
			{ CKA_PUBLIC_EXPONENT, &pubExponent, 3 },
			{ CKA_MODULUS_BITS, &modulusBits, 4 },
			{ CKA_LABEL, id, strlen(id) } };
	CK_ATTRIBUTE privAttrs[ 5 ] = {
			{ CKA_KEY_TYPE, &ckkRsa, 4 },
			{ CKA_TOKEN, inToken ? &trueValue : &falseValue, 1 },
			{ CKA_PRIVATE, &trueValue, 1 },
			{ CKA_DECRYPT, isExch ? &trueValue : &falseValue, 1 },
			{ CKA_LABEL, id, strlen(id) } };
	return C_GenerateKeyPair( hSession, &mech, pubAttrs, 5, privAttrs, 5, phPubKey, phPrivKey );
}

CK_RV T11_GenerateKey( CK_SESSION_HANDLE hSession, int ckk, char inToken, CK_OBJECT_HANDLE *phKey )
{
	int valueLen = 16;
	CK_MECHANISM mech = { T11_Ckk_Ckm( ckk, 0 ), 0, 0 };
	CK_ATTRIBUTE attrs[ 9 ] = {
			{ CKA_CLASS, &ckoSecretKey, 4 },
			{ CKA_KEY_TYPE, &ckk, 4 },
			{ CKA_TOKEN, inToken ? &trueValue : &falseValue, 1 },
			{ CKA_ENCRYPT, &trueValue, 1 },
			{ CKA_DECRYPT, &trueValue, 1 },
			{ CKA_UNWRAP, &trueValue, 1 },
			{ CKA_WRAP, &trueValue, 1 },
			{ CKA_EXTRACTABLE, &trueValue, 1 },
			{ CKA_VALUE_LEN, &valueLen, 4 } };
	return C_GenerateKey( hSession, &mech, attrs, CKK_SCB2 == ckk ? 9 : 8, phKey );
}

unsigned long T11_FindKey( CK_SESSION_HANDLE hSession, char isPrivate, int ckaType, unsigned char *data, int size )
{
	unsigned long count = 2, findCount = 0;
	CK_OBJECT_HANDLE hKey = 0;
	CK_ATTRIBUTE attrs[ 4 ] = {
		{ CKA_CLASS, isPrivate ? &ckoPrivKey : &ckoPubKey, 4 },
		{ CKA_TOKEN, &trueValue, 1 }
	};
	if ( (char)-1 != isPrivate )
	{
		attrs[ count ].type = CKA_PRIVATE;
		attrs[ count ].pValue = isPrivate ? &trueValue : &falseValue;
		attrs[ count ++ ].ulValueLen = 1;
	};
	if ( data )
	{
		attrs[ count ].type = ckaType;
		attrs[ count ].pValue = data;
		attrs[ count ++ ].ulValueLen = size;
	}
	C_FindObjectsInit( hSession, attrs, count );
	C_FindObjects( hSession, &hKey, 1, &findCount );
	C_FindObjectsFinal( hSession );
	return hKey;
}


unsigned long T11_FindPub( CK_SESSION_HANDLE hSession, Rsa_Cert *rsaCert )
{
	unsigned char buffer[ 512 ];
	unsigned long findCount = 0, hPub = 0;
	CK_ATTRIBUTE attrs[ 3 ] = {
		{ CKA_MODULUS, rsaCert->Rsa_n, rsaCert->Rsa_Bits == 2048 ? 256 : 128 },
		{ CKA_CLASS, &ckoPubKey, 4 }
	};
	C_FindObjectsInit( hSession, attrs, 2 );
	C_FindObjects( hSession, &hPub, 1, &findCount );
	C_FindObjectsFinal( hSession );
	if ( hPub )
	{
		attrs[ 0 ].pValue = buffer;
		attrs[ 0 ].ulValueLen = sizeof(buffer);
		C_GetAttributeValue( hSession, hPub, attrs, 1 );
	}
	return hPub;
}

unsigned long T11_FindCert( CK_SESSION_HANDLE hSession, int ckaType, unsigned char *data, int size )
{
	unsigned long findCount = 0, hCert = 0;
	CK_RV rv;
	CK_ATTRIBUTE attrs[ 3 ] = {
		{ CKA_CLASS, &ckoCertificate, 4 },
		{ CKA_TOKEN, &trueValue, 1 },
		{ ckaType, data, size },
	};
	C_FindObjectsInit( hSession, attrs, data ? 3 : 2 );
	//int i = 0;
	//while (1)
	//{
		rv = C_FindObjects( hSession, &hCert, 1, &findCount );
		/*
		if (rv != CKR_OK || findCount == 0)
			break;
		//T11_GetAttribute(hSession, hCert, CKA_SUBJECT);
		//T11_GetAttribute(hSession, hCert, CKA_VALUE);
		//T11_GetAttribute(hSession, hCert, CKA_LABEL);
		//T11_GetAttribute(hSession, hCert, CKA_OWNER);
		//T11_GetAttribute(hSession, hCert, CKA_CERTIFICATE_CATEGORY);
		//T11_GetAttribute(hSession, hCert, CKA_START_DATE);
		//T11_GetAttribute(hSession, hCert, CKA_CERTIFICATE_TYPE);
		CK_RV attrrv;
		unsigned char buffer[ 4096 ];
		CK_DATE start_date;
		CK_ATTRIBUTE attrs[ 1 ] = 
			{CKA_SUBJECT, buffer, sizeof(buffer)};
		attrrv = C_GetAttributeValue( hSession, hCert, attrs, 1 );

		CK_ATTRIBUTE attrs1[ 1 ] = 
		{CKA_START_DATE, &start_date, sizeof(start_date)};
		attrrv = C_GetAttributeValue( hSession, hCert, attrs1, 1 );

		CK_ATTRIBUTE attrs2[ 1 ] = 
		{CKA_LABEL, buffer, sizeof(buffer)};
		attrrv = C_GetAttributeValue( hSession, hCert, attrs2, 1 );

		CK_ATTRIBUTE attrs3[ 1 ] = 
		{CKA_CHECK_VALUE, buffer, sizeof(buffer)};
		attrrv = C_GetAttributeValue( hSession, hCert, attrs3, 1 );

		CK_CERTIFICATE_TYPE cert_type = CKC_X_509;
		CK_ATTRIBUTE attrs4[ 1 ] = 
		{CKA_CERTIFICATE_TYPE, &cert_type, sizeof(cert_type)};
		attrrv = C_GetAttributeValue( hSession, hCert, attrs4, 1 );

		CK_ATTRIBUTE attrs5[ 1 ] = 
			{CKA_VALUE, buffer, sizeof(buffer)};
		attrrv = C_GetAttributeValue( hSession, hCert, attrs5, 1 );

		CK_ULONG cert_category;
		CK_ATTRIBUTE attrs6[ 1 ] = 
			{CKA_CERTIFICATE_CATEGORY, &cert_category, sizeof(cert_category)};
		attrrv = C_GetAttributeValue( hSession, hCert, attrs6, 1 );

		CK_BYTE id[] = {123};
		CK_ATTRIBUTE attrs7[ 1 ] = 
			{CKA_ID, id, sizeof(id)};
		attrrv = C_GetAttributeValue( hSession, hCert, attrs7, 1 );

		CK_ATTRIBUTE attrs8[ 1 ] = 
		{CKA_OWNER, buffer, sizeof(buffer)};
		attrrv = C_GetAttributeValue( hSession, hCert, attrs8, 1 );

		i++;
		
	}*/
	C_FindObjectsFinal( hSession );
	return hCert;
}

unsigned long T11_ImportKey( CK_SESSION_HANDLE hSession, int ckk, char inToken, unsigned char *value, int size )
{
	unsigned long hObject = 0;
	CK_MECHANISM mech = { ckk, 0, 0 };
	CK_ATTRIBUTE attrs[ 8 ] = {
			{ CKA_CLASS, &ckoSecretKey, 4 },
			{ CKA_KEY_TYPE, &ckk, 4 },
			{ CKA_TOKEN, inToken ? &trueValue : &falseValue, 1 },
			{ CKA_ENCRYPT, &trueValue, 1 },
			{ CKA_DECRYPT, &trueValue, 1 },
			{ CKA_UNWRAP, &trueValue, 1 },
			{ CKA_WRAP, &trueValue, 1 },
			{ CKA_VALUE, value, size }
	};
	C_CreateObject( hSession, attrs, 8, &hObject );
	return hObject;
}

void T11_DelCert( CK_SESSION_HANDLE hSession, int ckaType, const void *data, int size )
{
	unsigned long findCount = 0, hCert = 0;
	CK_ATTRIBUTE attrs[ 3 ] = {
		{ CKA_CLASS, &ckoCertificate, 4 },
		{ CKA_TOKEN, &trueValue, 1 },
		{ ckaType, (void *)data, size }
	};
	C_FindObjectsInit( hSession, attrs, data ? 3 : 2 );
	C_FindObjects( hSession, &hCert, 1, &findCount );
	C_FindObjectsFinal( hSession );
	if ( findCount > 0 )
		C_DestroyObject( hSession, hCert );
}

unsigned long T11_ImportCert( CK_SESSION_HANDLE hSession, char *id, Rsa_Cert *rsaCert, char isToken, char isExchange )
{
	unsigned long hObject = 0;
	CK_ATTRIBUTE attrs[ 10 ] = {
		{ CKA_CLASS, &ckoCertificate, 4 },
		{ CKA_CERTIFICATE_TYPE, &ckcX509, 4 },
		{ CKA_TOKEN, isToken ? &trueValue : &falseValue, 1 },
		{ CKA_DECRYPT, isExchange ? &trueValue : &falseValue, 1 },
		{ CKA_PRIVATE, &falseValue, 1 },
		{ CKA_LABEL, id, strlen(id) },
		{ CKA_HT_COS_CONTAINER, id, strlen(id) },
		{ CKA_SUBJECT, rsaCert->Subject, rsaCert->SubjectLength },
		{ CKA_VALUE, rsaCert->Cert, rsaCert->CertLength }
	};
	C_CreateObject( hSession, attrs, 9, &hObject );
	return hObject;
}

unsigned long T11_ImportPubKey( CK_SESSION_HANDLE hSession, char *id, Rsa_Cert *rsaCert, char isToken, char isExchange )
{
	unsigned long hObject = 0;
	CK_ATTRIBUTE attrs[ 12 ] = {
		{ CKA_CLASS, &ckoPubKey, 4 },
		{ CKA_KEY_TYPE, &ckkRsa, 4 },
		{ CKA_TOKEN, isToken ? &trueValue : &falseValue, 1 },
		{ CKA_PRIVATE, &falseValue, 1 },
		{ CKA_VERIFY, &trueValue, 1 },
		{ CKA_WRAP, isExchange ? &trueValue : &falseValue, 1 },
		{ CKA_DECRYPT, isExchange ? &trueValue : &falseValue, 1 },
		{ CKA_EXTRACTABLE, &trueValue, 1 },
		{ CKA_LABEL, id, strlen(id) },
		{ CKA_HT_COS_CONTAINER, id, strlen(id) },
		{ CKA_MODULUS, rsaCert->Rsa_n, rsaCert->Rsa_Bits == 2048 ? 256 : 128 },
		{ CKA_PUBLIC_EXPONENT, Rsa_e_f4, 3 }
	};
	C_CreateObject( hSession, attrs, 12, &hObject );
	return hObject;
}

unsigned long T11_ImportPrivKey( CK_SESSION_HANDLE hSession, char *id, Rsa_Cert *rsaCert, char isToken, char isExchange, char extractable )
{
	unsigned long hObject = 0;
	int bytes = rsaCert->Rsa_Bits == 2048 ? 128 : 64;
	CK_ATTRIBUTE attrs[ 16 ] = {
		{ CKA_CLASS, &ckoPrivKey, 4 },
		{ CKA_KEY_TYPE, &ckkRsa, 4 },
		{ CKA_TOKEN, isToken ? &trueValue : &falseValue, 1 },
		{ CKA_PRIVATE, &trueValue, 1 },
		{ CKA_SIGN, &trueValue, 1 },
		{ CKA_ENCRYPT, isExchange ? &trueValue : &falseValue, 1 },
		{ CKA_DECRYPT, isExchange ? &trueValue : &falseValue, 1 },
		{ CKA_LABEL, id, strlen(id) },
		{ CKA_MODULUS, rsaCert->Rsa_n, bytes * 2 },
		{ CKA_PUBLIC_EXPONENT, Rsa_e_f4, 3 },
		{ CKA_PRIME_1, rsaCert->Rsa_p, bytes },
		{ CKA_PRIME_2, rsaCert->Rsa_q, bytes },
		{ CKA_PRIVATE_EXPONENT, rsaCert->Rsa_d, bytes * 2 },
		{ CKA_EXPONENT_1, rsaCert->Rsa_mdp1, bytes },
		{ CKA_EXPONENT_2, rsaCert->Rsa_mdq1, bytes },
		{ CKA_COEFFICIENT, rsaCert->Rsa_iqmp, bytes }
	};
	C_CreateObject( hSession, attrs, 8 + 8, &hObject );
	return hObject;
}

unsigned long T11_GetAttribute( CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject, int ckaType )
{
	CK_RV rt;
	unsigned char buffer[ 4096 ];
	CK_ATTRIBUTE attrs[ 1 ] = { ckaType, buffer, sizeof(buffer) };
	rt = C_GetAttributeValue( hSession, hObject, attrs, 1 );
	return rt;
}

void T11_DestroyObject( CK_SESSION_HANDLE hSession, unsigned cko, unsigned cka, void *value, unsigned size )
{
	unsigned long i, count, objArray[ 10 ];
	CK_ATTRIBUTE findAttrs[ 2 ] = {
		{ CKA_CLASS, &cko, 4 },
		{ cka, value, size }
	};
	C_FindObjectsInit( hSession, findAttrs, 2 );
	C_FindObjects( hSession, objArray, 10, &count );
	C_FindObjectsFinal( hSession );
	for ( i = 0; i < count; i ++ )
		C_DestroyObject( hSession, objArray[ i ] );
}

void T11_ImportPrivValue( CK_SESSION_HANDLE hSession, unsigned char *value, int size )
{
	unsigned long hObject = 0;
	CK_ATTRIBUTE attrs[ 4 ] = {
		{ CKA_CLASS, &ckoPrivKey, 4 },
		{ CKA_KEY_TYPE, &ckkRsa, 4 },
		{ CKA_TOKEN, &trueValue, 1 },
		{ CKA_VALUE, value, size }
	};
	C_CreateObject( hSession, attrs, 4, &hObject );
	C_DestroyObject( hSession, hObject );
}

void T11_ImportP12( CK_SESSION_HANDLE hSession, unsigned char *value, int size, char *password, bool deleteObj )
{
	unsigned long hCert, hPub, hPriv;
	CK_ATTRIBUTE attrs[ 5 ] = {
		{ CKA_CLASS, &ckoCertificate, 4 },
		{ CKA_PRIVATE, &falseValue, 1 },
		{ CKA_TOKEN, &trueValue, 1 },
		{ CKA_COS_PASSWORD, password, password ? strlen(password) : 0 },
		{ CKA_VALUE, value, size }
	};
	C_CreateObject( hSession, attrs, 5, &hCert );
	if ( deleteObj )
		C_DestroyObject( hSession, hCert );
	attrs[ 0 ].pValue = &ckoPubKey;
	C_CreateObject( hSession, attrs, 5, &hPub );
	if ( deleteObj )
		C_DestroyObject( hSession, hPub );
	attrs[ 0 ].pValue = &ckoPrivKey;
	C_CreateObject( hSession, attrs, 5, &hPriv );
	if ( deleteObj )
		C_DestroyObject( hSession, hPriv );
}

void T11_Haitai_TokenInfo( int slot, unsigned long *pCkk )
{
	CK_TOKEN_INFO info;
	C_GetTokenInfo( slot, &info );
	if ( info.hardwareVersion.minor & 8 )
		*pCkk = CKK_SCB2;
	else if ( info.hardwareVersion.minor & 4 )
		*pCkk = CKK_SSF33;
	else
		*pCkk = CKK_DES2;
}

unsigned TestFindKeyHash( CK_SESSION_HANDLE hSession, unsigned char *hash, char isPrivate )
{
	CK_OBJECT_HANDLE hKey = T11_FindKey( hSession, isPrivate, CKA_HASH_OF_SUBJECT_PUBLIC_KEY, hash, 20 );
	if ( 0 == hKey )
		printf( "Can't find %s Key by Hash.\n", isPrivate ? "Priv" : "Pub" );
	else
		printf( "Find %s Key by Hash.\n", isPrivate ? "Priv" : "Pub" );
	return hKey;
}

unsigned long TestFindIssuerHash( CK_SESSION_HANDLE hSession, unsigned char *hash )
{
	CK_OBJECT_HANDLE hKey = T11_FindCert( hSession, CKA_HASH_OF_ISSUER_PUBLIC_KEY, hash, 20 );
	if ( hKey )
		printf( "Find Cert by Id.\n" );
	else
		printf( "Can't find Cert by Id.\n" );
	return hKey;
}

unsigned long TestFindCertHash( CK_SESSION_HANDLE hSession, unsigned char *hash )
{
	CK_OBJECT_HANDLE hKey = T11_FindCert( hSession, CKA_HASH_OF_SUBJECT_PUBLIC_KEY, hash, 20 );
	if ( hKey )
		printf( "Find Cert by Hash.\n" );
	else
		printf( "Can't find Cert by Hash.\n" );
	return hKey;
}

unsigned TestFindKey( CK_SESSION_HANDLE hSession, char *id, char isPrivate )
{
	CK_OBJECT_HANDLE hKey = T11_FindKey( hSession, isPrivate, CKA_LABEL, (unsigned char *)id, strlen(id) );
	if ( 0 == hKey )
		printf( "Can't find %s Key by id = \"%s\".\n", isPrivate ? "Priv" : "Pub", id );
	else
		printf( "Find %s Key by Id.\n", isPrivate ? "Priv" : "Pub" );
	return hKey;
}

unsigned long TestFindCert( CK_SESSION_HANDLE hSession, char *id )
{
	CK_OBJECT_HANDLE hKey = T11_FindCert( hSession, CKA_LABEL, (unsigned char *)id, strlen(id) );
	if ( hKey )
		printf( "Find Cert.\n" );
	else
		printf( "Can't find Cert.\n" );
	return hKey;
}

void TestGenPair( CK_SESSION_HANDLE hSession, char *id )
{
	unsigned long hPriv = 0, hPub = 0;
	T11_GenKeyPair( hSession, id, 1, 0, &hPub, &hPriv );
	if ( hPriv )
	{
		C_DestroyObject( hSession, hPub );
		C_DestroyObject( hSession, hPriv );
	}
}

int TestImport( CK_SESSION_HANDLE hSession, char *id, Rsa_Cert *rsaCert, bool isExch )
{
	if ( ! T11_ImportPubKey( hSession, id, rsaCert, true, isExch ) )
		return 0;
	if ( ! T11_ImportPrivKey( hSession, id, rsaCert, true, isExch, 0 ) )
		return 0;
	T11_ImportCert( hSession, id, rsaCert, true, isExch );
	return 0;
}

#ifdef __cplusplus
};
#endif
