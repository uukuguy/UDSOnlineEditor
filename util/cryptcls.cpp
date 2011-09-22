//加解密文本的实现
#include "stdafx.h"
#include "cryptcls.h"
#include <Wincrypt.h>
#include "base64util.h"

BOOL Encrypt(const TCHAR* szRaw,TCHAR* szOut,int iOutSize,TCHAR* szKey){
	BOOL ret=FALSE;
	if (szRaw==NULL || _tcslen(szRaw)==0 || szOut==NULL || iOutSize<=0) return FALSE;
	char* strRaw=NULL;
	char* utf8Key=NULL;
	DWORD rawByteslen=FromUTF16(szRaw,NULL,0);
	if (rawByteslen>0) rawByteslen+=1;
	strRaw=new char[rawByteslen];
	FromUTF16(szRaw,strRaw,rawByteslen);
	rawByteslen=strlen(strRaw);
	DWORD dwLen=rawByteslen;

	BOOL fResult = FALSE;
  HCRYPTPROV hProv = NULL;
  HCRYPTHASH hHash = NULL;
  HCRYPTKEY hSessionKey = NULL;
	char* szBuffer=NULL;
	DWORD encByteslen=rawByteslen;
  BYTE* pbBuffer=NULL;
	fResult = CryptAcquireContext(&hProv, NULL,MS_DEF_PROV,PROV_RSA_FULL,CRYPT_VERIFYCONTEXT);
  if (fResult)
  {
		int keyLen=FromUTF16(szKey,NULL,0);
		if (keyLen>0) keyLen+=1;
		utf8Key=new char[keyLen];
		FromUTF16(szKey,utf8Key,keyLen);
		struct {
			BLOBHEADER header;
			DWORD cbKeySize;
			BYTE rgbKeyData [8];
		} keyBlob;
		keyBlob.header.bType = PLAINTEXTKEYBLOB;
		keyBlob.header.bVersion = CUR_BLOB_VERSION;
		keyBlob.header.reserved = 0;
		keyBlob.header.aiKeyAlg = CALG_DES;
		keyBlob.cbKeySize = 8;
		memcpy(keyBlob.rgbKeyData, utf8Key, 8);
		fResult=CryptImportKey(hProv, (BYTE*)&keyBlob, sizeof(keyBlob), 0, 0, &hSessionKey);
		if (fResult){
			static BYTE KEY_IV[] = {  0xEF, 0x34, 0xCD, 0x78, 0x90, 0xAB, 0x56, 0x12 };
			fResult=CryptSetKeyParam(hSessionKey,KP_IV,KEY_IV,0);
			if (fResult){
				fResult = CryptEncrypt(hSessionKey, 0, TRUE, 0, NULL,&dwLen,encByteslen);
				if (fResult) encByteslen=dwLen+1;
				pbBuffer=new BYTE[encByteslen];
				ZeroMemory(pbBuffer,encByteslen);
				memcpy(pbBuffer,strRaw,rawByteslen);
				fResult = CryptEncrypt(hSessionKey, 0, TRUE, 0, pbBuffer,&rawByteslen,encByteslen);
				if (fResult){
					int outLen=rawByteslen / 3 * 4 + 1;
					if (rawByteslen % 3!=0) outLen+=4;
					szBuffer=new char[outLen];
					ZeroMemory(szBuffer,outLen);
					base64util::b64encode((const char*)pbBuffer,szBuffer,rawByteslen,0);
					BSTR bstr=A2BSTR(szBuffer);
					_tcsncpy_s(szOut,iOutSize,bstr,iOutSize);
					if (bstr)SysFreeString(bstr);
					ret=TRUE;
				}//if end
			}//if end
		}//if end
  }//if end
	if (strRaw) delete[] strRaw;
	if (utf8Key) delete[] utf8Key;
	if (szBuffer) delete[] szBuffer;
	if (pbBuffer) delete[] pbBuffer;
	if (hSessionKey != NULL) CryptDestroyKey(hSessionKey);
	if (hHash != NULL) CryptDestroyHash(hHash);
	if (hProv != NULL) CryptReleaseContext(hProv, 0);
	return ret;
}
BOOL Decrypt(TCHAR* szRaw,TCHAR* szOut,int iOutSize,TCHAR* szKey){
	USES_CONVERSION;
	BOOL ret=FALSE;
	char *utf8Key=NULL;
	if (szRaw==NULL || _tcslen(szRaw)==0 || szOut==NULL || iOutSize<=0) return FALSE;
	int len=strlen(CT2A(szRaw).m_psz);
	int outLen=len / 4 * 3 + 1;
	char* szOutBuffer=new char[outLen];
	ZeroMemory(szOutBuffer,outLen);
	DWORD rawByteslen=base64util::b64decode(CT2A(szRaw).m_psz,szOutBuffer,len);
	if (rawByteslen<=0) goto end;
	BOOL fResult = FALSE;
  HCRYPTPROV hProv = NULL;
  HCRYPTHASH hHash = NULL;
  HCRYPTKEY hSessionKey = NULL;
	char* szBuffer=NULL;
  BYTE* pbBuffer=new BYTE[rawByteslen];
	ZeroMemory(pbBuffer,rawByteslen);
	memcpy(pbBuffer,szOutBuffer,rawByteslen);
	fResult = CryptAcquireContext(&hProv, NULL,MS_DEF_PROV,PROV_RSA_FULL,CRYPT_VERIFYCONTEXT);
  if (fResult)
  {
		int keyLen=FromUTF16(szKey,NULL,0);
		if (keyLen>0) keyLen+=1;
		utf8Key=new char[keyLen];
		FromUTF16(szKey,utf8Key,keyLen);
		struct {
			BLOBHEADER header;
			DWORD cbKeySize;
			BYTE rgbKeyData [8];
		} keyBlob;
		keyBlob.header.bType = PLAINTEXTKEYBLOB;
		keyBlob.header.bVersion = CUR_BLOB_VERSION;
		keyBlob.header.reserved = 0;
		keyBlob.header.aiKeyAlg = CALG_DES;
		keyBlob.cbKeySize = 8;
		memcpy(keyBlob.rgbKeyData, utf8Key, 8);
		fResult=CryptImportKey(hProv, (BYTE*)&keyBlob, sizeof(keyBlob), 0, 0, &hSessionKey);
		if (fResult){
			static BYTE KEY_IV[] = {  0xEF, 0x34, 0xCD, 0x78, 0x90, 0xAB, 0x56, 0x12 };
			fResult=CryptSetKeyParam(hSessionKey,KP_IV,KEY_IV,0);
			if (fResult){
				fResult = CryptDecrypt(hSessionKey, 0, TRUE, 0, pbBuffer,&rawByteslen);
				if (fResult && rawByteslen>0){
					szBuffer=new char[rawByteslen+1];
					ZeroMemory(szBuffer,rawByteslen+1);
					memcpy(szBuffer,pbBuffer,rawByteslen);
					wchar_t * utf16=NULL;
					int wlen=ToUTF16(szBuffer,NULL,0);
					if (wlen>0) wlen+=1;
					utf16=new wchar_t[wlen];
					ZeroMemory(utf16,wlen*sizeof(wchar_t));
					ToUTF16(szBuffer,utf16,wlen);
					_tcsncpy_s(szOut,iOutSize,utf16,iOutSize);
					ret=TRUE;
				}//if end
			}//if end
		}//if end
  }//if end
end:
	if (utf8Key) delete[] utf8Key;
	if (szOutBuffer) delete[] szOutBuffer;
	if (szBuffer) delete[] szBuffer;
	if (pbBuffer) delete[] pbBuffer;
	if (hSessionKey != NULL) CryptDestroyKey(hSessionKey);
	if (hHash != NULL) CryptDestroyHash(hHash);
	if (hProv != NULL) CryptReleaseContext(hProv, 0);
	return ret;
}

BOOL FromUTF16( IN const wchar_t * utf16,char* dst,size_t dstSize)
{
	if (utf16 == NULL || *utf16 == L'\0') return FALSE;
	const int utf16Length = wcslen( utf16 ) + 1;
	//先计算转换后大小
	int utf8Size = ::WideCharToMultiByte(
		CP_UTF8,			//转 UTF-8
		0,						//缺省标记
		utf16,				//数据源，其格式为UTF-16（windows默认unicode）编码
		utf16Length,	//数据源包含字符长度（包括结尾的\0部分）
		NULL,					//不使用，只计算长度
		0,						//不使用
		NULL, NULL		//不使用
		);
	
	if (utf8Size==0) return FALSE;
	if (dstSize==0) return utf8Size;
	ZeroMemory(dst,dstSize);
	int result = ::WideCharToMultiByte(
		CP_UTF8,			//转 UTF-8
		0,						//缺省标记
		utf16,				//数据源，其格式为UTF-16（windows默认unicode）编码
		utf16Length,	//数据源包含字符长度（包括结尾的\0部分）
		dst,					//转换结果
		dstSize>=utf8Size?utf8Size:dstSize,			//结果长度
		NULL, NULL		//不使用
		);
	if ( result == 0)	return FALSE;
	return utf8Size;
}
BOOL ToUTF16(IN const char * utf8 ,wchar_t * dst,size_t dstSize){
	if (utf8 == NULL || *utf8 == L'\0') return FALSE;
	const int utf8ByteCount = strlen( utf8 ) + 1;

	//先计算转换后大小
	int utf16Size = ::MultiByteToWideChar(
		CP_UTF8,
		MB_ERR_INVALID_CHARS,
		utf8,
		utf8ByteCount,
		NULL,
		0
		);
	if ( utf16Size == 0 )return FALSE;
	if (dstSize==0) return utf16Size;
	ZeroMemory(dst,dstSize);
	int result = ::MultiByteToWideChar(
		CP_UTF8,
		MB_ERR_INVALID_CHARS,
		utf8,
		utf8ByteCount,
		dst,
		dstSize>=utf16Size?utf16Size:dstSize
		);

	if ( result == 0 )return FALSE;
	return utf16Size;
}