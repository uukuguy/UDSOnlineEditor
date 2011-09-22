#ifndef TestP11_H

#ifdef __cplusplus
extern "C" {
#endif

#include "pkcs11.h"

#define Crypto_Ck_Base			0x3b6d0000
#define Crypto_Cos_Base			0x5d6b0000
#define Crypto_Skip_Base		0x5d6c0000

#define CKK_SSF33				( Crypto_Ck_Base + 0x100 )
#define CKK_SCB2				( Crypto_Ck_Base + 0x101 )

#define CKM_SSF33_KEY_GEN		( Crypto_Ck_Base + 0x200 )
#define CKM_SSF33_ECB			( Crypto_Ck_Base + 0x201 )
#define CKM_SSF33_CBC			( Crypto_Ck_Base + 0x202 )
#define CKM_SSF33_CBC_PAD		( Crypto_Ck_Base + 0x205 )
#define CKM_SSF33_ECB_PAD		( Crypto_Ck_Base + 0x206 )
#define CKM_SCB2_KEY_GEN		( Crypto_Ck_Base + 0x210 )
#define CKM_SCB2_ECB			( Crypto_Ck_Base + 0x211 )
#define CKM_SCB2_CBC			( Crypto_Ck_Base + 0x212 )
#define CKM_SCB2_CBC_PAD		( Crypto_Ck_Base + 0x215 )
#define CKM_SCB2_ECB_PAD		( Crypto_Ck_Base + 0x216 )

#define CKA_COS_CONTAINER		( Crypto_Skip_Base + 1 )
#define CKA_COS_PASSWORD		( Crypto_Skip_Base + 2 )

typedef struct {
	int		Rsa_Bits;
	unsigned char *Hash;
	unsigned char *Serial;
	int		SerialLength;
	unsigned char *Subject;
	int		SubjectLength;
	unsigned char *Cert;
	int		CertLength;
	unsigned char *Rsa_n, *Rsa_p, *Rsa_q, *Rsa_d, *Rsa_mdp1, *Rsa_mdq1, *Rsa_iqmp;
} Rsa_Cert;

extern CK_MECHANISM mechRsaPkcs, mechRsaOaep, mechRsaX509, mechRsaX931, mechMd5RsaPkcs, mechSha1RsaPkcs;
extern unsigned char trueValue, falseValue, Rsa_e_f4[3], zeroIv[], testP12[2386];
extern unsigned expectCkr, ckoPubKey, ckoPrivKey, ckoCertificate, ckoSecretKey, ckcX509, ckkRsa;
extern Rsa_Cert ShijRsaCert, TestRsaCert, TestExchRsaCert, TestSignRsaCert, CheckRsaCert, CheckExchRsaCert, CheckSignRsaCert, ExtRsaCert, ExtExchRsaCert, ExtSignRsaCert, VmRsaCert, VmExchRsaCert, VmSignRsaCert ;

int Load_Pkcs11_Lib( char *dllName );
int Free_Pkcs11_Lib();
void T11_DumpBinary( void *data, int size, char *name );
int T11_Ckk_Ckm( int ckk, int mode );
int Template_Int( CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, int attrType, int defaultValue );
void T11_CopyTemplate( CK_ATTRIBUTE_PTR pTemplate, CK_ULONG ulCount, CK_ATTRIBUTE_PTR pTarget, CK_ULONG maxCount );
CK_RV T11_GenKeyPair( CK_SESSION_HANDLE hSession, char *id, char inToken, char isExch, CK_OBJECT_HANDLE *phPubKey, CK_OBJECT_HANDLE *phPrivKey );
CK_RV T11_GenerateKey( CK_SESSION_HANDLE hSession, int ckk, char inToken, CK_OBJECT_HANDLE *phKey );
unsigned long T11_FindKey( CK_SESSION_HANDLE hSession, char isPrivate, int ckaType, unsigned char *data, int size );
unsigned long T11_FindCert( CK_SESSION_HANDLE hSession, int ckaType, unsigned char *data, int size );
unsigned long T11_ImportKey( CK_SESSION_HANDLE hSession, int ckk, char inToken, unsigned char *value, int size );
unsigned long T11_ImportPubKey( CK_SESSION_HANDLE hSession, char *id, Rsa_Cert *rsaCert, char isToken, char isExchange );
unsigned long T11_ImportPrivKey( CK_SESSION_HANDLE hSession, char *id, Rsa_Cert *rsaCert, char isToken, char isExchange, char extractable );
unsigned long T11_ImportCert( CK_SESSION_HANDLE hSession, char *id, Rsa_Cert *rsaCert, char isToken, char isExchange );
unsigned long T11_GetAttribute( CK_SESSION_HANDLE hSession, CK_OBJECT_HANDLE hObject, int ckaType );
void T11_ImportPrivValue( CK_SESSION_HANDLE hSession, unsigned char *value, int size );
void T11_ImportP12( CK_SESSION_HANDLE hSession, unsigned char *value, int size, char *password, bool deleteObj );
void T11_Haitai_TokenInfo( int slot, unsigned long *pCkk );
unsigned TestFindKeyHash( CK_SESSION_HANDLE hSession, unsigned char *hash, char isPrivate );
unsigned long TestFindIssuerHash( CK_SESSION_HANDLE hSession, unsigned char *hash );
unsigned long TestFindCertHash( CK_SESSION_HANDLE hSession, unsigned char *hash );
unsigned TestFindKey( CK_SESSION_HANDLE hSession, char *id, char isPrivate );
unsigned long TestFindCert( CK_SESSION_HANDLE hSession, char *id );
void TestGenPair( CK_SESSION_HANDLE hSession, char *id );
int TestImport( CK_SESSION_HANDLE hSession, char *id, Rsa_Cert *rsaCert, bool isExch );

//登录初始化
CK_SESSION_HANDLE WT11_LoginInit(unsigned char * pin, unsigned char * ccontainer);
//初始化
void WT11_Initialize();
//得到解密会话KEY
//pbufSessionKeyEncrypt 已经加密的会话KEY
//ckk 算法
unsigned long WT11_SessionKeyRsa(CK_SESSION_HANDLE hSession, 
								 unsigned char *wrappedKey, unsigned long wrappedKeyLen);
//删除对象，删除会话KEY
void WT11_DestroyObject(CK_SESSION_HANDLE hSession, unsigned long hSymKey );
//解密
int WT11_SCB2_Decrypt(CK_SESSION_HANDLE hSession, unsigned long hSymKey, unsigned char *pbufCipher, 
					  unsigned long cipherSize, unsigned char *pbufplain, unsigned long *plainSize);
//退出
int WT11_LogOutFinalize(CK_SESSION_HANDLE hSession);

#ifdef __cplusplus
};
#endif

#endif
