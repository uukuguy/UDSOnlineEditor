// FileEncrypter.cpp : FileEncrypter 的实现

#include "stdafx.h"
#include "FileEncrypter.h"
#include <wincrypt.h>
#include "cryptcls.h"

#define STRLEN_DEFAULT 1024

#define MY_ENCODING_TYPE  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)
#define KEYLENGTH  0x00//0x00800000

#define ALG_SID_SCB2    0xf0
#define CALG_SCB2   (ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|ALG_SID_SCB2)

//#define CALG_SF33	(ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|(ALG_SID_EXAMPLE+1))

//#define CALG_SCB2	(ALG_CLASS_DATA_ENCRYPT|ALG_TYPE_BLOCK|(ALG_SID_EXAMPLE+2))

#define ENCRYPT_ALGORITHM CALG_SCB2
#define ENCRYPT_BLOCK_SIZE 16 

#define PROVIDER_NAME _T("HaiTai Cryptographic Service Provider")
// FileEncrypter

STDMETHODIMP FileEncrypter::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IFileEncrypter
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
STDMETHODIMP FileEncrypter::EncryptFile(BSTR szInFN,BSTR szOutFN,BSTR szPwd){
	if (!szInFN || _tcslen(szInFN)==0) {
		InfoMsgBox(_T("对不起，您必须提供待加密的文件名！"));
		return S_OK;
	}
	if (!szOutFN || _tcslen(szOutFN)==0) {
		InfoMsgBox(_T("对不起，您必须提供加密后的文件名！"));
		return S_OK;
	}
	FILE *hSource=0; 
	FILE *hDestination=0; 

	HCRYPTPROV hCryptProv; 
	HCRYPTKEY hKey; 
	HCRYPTKEY hXchgKey; 
	HCRYPTHASH hHash; 
	
	PBYTE pbKeyBlob; 
	DWORD dwKeyBlobLen; 
	
	PBYTE pbBuffer; 
	DWORD dwBlockLen; 
	DWORD dwBufferLen; 
	DWORD dwCount; 

	char* utf8Pwd=NULL;

	TCHAR msgTip[STRLEN_DEFAULT]={0};
	_tfopen_s(&hSource,szInFN,_T("rb"));
	if(!hSource){
		_stprintf_s(msgTip,_T("对不起，无法打开文件“%s”！"),szInFN);
		InfoMsgBox(msgTip);
		goto clean;
	}
	_tfopen_s(&hDestination,szOutFN,_T("wb"));
	if(!hDestination){
		_stprintf_s(msgTip,_T("对不起，无法打开文件“%s”！"),szOutFN);
		InfoMsgBox(msgTip);
		goto clean;
	}

	TCHAR szContainerName[]=_T("f0d74c20-4a68-47d2-a1d2-7c622399ad48");	//TODO:容器名称为“test”?
	//初始化CSP上下文
	if(CryptAcquireContext(&hCryptProv,szContainerName,PROVIDER_NAME,PROV_RSA_FULL,0))
	{
		//正确初始化CSP
	}
	else
	{
		if(!CryptAcquireContext(&hCryptProv,szContainerName,PROVIDER_NAME,PROV_RSA_FULL,CRYPT_NEWKEYSET)){
			InfoMsgBox(_T("对不起，无法初始化CSP上下文，请确认UKey是否插入电脑且工作正常，并安装了正确的驱动程序！"));
			goto clean;
		}
	}
	//如果没有提供密码
	if(!szPwd || _tcslen(szPwd)==0){
		if(!CryptGenKey(hCryptProv,ENCRYPT_ALGORITHM,CRYPT_EXPORTABLE, /*KEYLENGTH | CRYPT_EXPORTABLE, */&hKey))
		{
			InfoMsgBox(_T("对不起，无法生成密钥，请确认UKey是否插入电脑且工作正常，并安装了正确的驱动程序！"));
			goto clean;
		}
		if(CryptGetUserKey(hCryptProv,AT_KEYEXCHANGE,&hXchgKey)){
			//公钥被成功获取
		}
		else{
			CryptGenKey(hCryptProv,AT_KEYEXCHANGE,0,&hXchgKey);
		}
		if(!CryptExportKey(hKey,hXchgKey,SIMPLEBLOB, 0,NULL, &dwKeyBlobLen)){
			InfoMsgBox(_T("对不起，无法获取密钥块，请确认UKey是否插入电脑且工作正常，并安装了正确的驱动程序！"));
			goto clean;
		}
		if(!(pbKeyBlob =(BYTE *)malloc(dwKeyBlobLen)))
		{ 
			InfoMsgBox(_T("对不起，无法为密钥块分配内存！"));
			goto clean;
		}
		if(!CryptExportKey(hKey,hXchgKey,SIMPLEBLOB,0, pbKeyBlob, &dwKeyBlobLen)){
			InfoMsgBox(_T("对不起，无法为导出密钥！"));
			goto clean;
		}
		CryptDestroyKey(hXchgKey); 
		hXchgKey = 0;
		fwrite(&dwKeyBlobLen, sizeof(DWORD), 1, hDestination); 
		if(ferror(hDestination))
		{
			InfoMsgBox(_T("无法写入输出文件！"));
			goto clean;
		}
		fwrite(pbKeyBlob, 1, dwKeyBlobLen, hDestination); 
		if(ferror(hDestination))
		{ 
			InfoMsgBox(_T("无法写入输出文件！"));
			goto clean;
		}
	}
	else{	//提供了密码
		if(!CryptCreateHash(hCryptProv,CALG_MD5, 0,0,&hHash))
		{
			InfoMsgBox(_T("无法创建哈希！"));
			goto clean;
		}
		int keyLen=FromUTF16(szPwd,NULL,0);
		if (keyLen>0) keyLen+=1;
		utf8Pwd=new char[keyLen];
		FromUTF16(szPwd,utf8Pwd,keyLen);
		if(!CryptHashData( hHash, (BYTE *)utf8Pwd, keyLen-1, 0))
		{
			InfoMsgBox(_T("无法创建密码哈希值！"));
			goto clean;
		}
		if(!CryptDeriveKey( hCryptProv,ENCRYPT_ALGORITHM, hHash, KEYLENGTH, &hKey))
		{
			InfoMsgBox(_T("无法从哈希值创建密钥！"));
			goto clean;
		}
		CryptDestroyHash(hHash); 
		hHash = 0; 
	}
	dwBlockLen = 1024 - 1024 % ENCRYPT_BLOCK_SIZE; 
	if(ENCRYPT_BLOCK_SIZE > 1) 
		dwBufferLen = dwBlockLen + ENCRYPT_BLOCK_SIZE; 
	else 
		dwBufferLen = dwBlockLen; 

	if(!(pbBuffer = (BYTE *)malloc(dwBufferLen)))
	{
		InfoMsgBox(_T("对不起，无法为缓冲区分配内存！"));
		goto clean;
	}
	//循环读取源文件的数据然后加密数据并把结果写入目标文件
	do
	{ 
		dwCount = fread(pbBuffer, 1, dwBlockLen, hSource); 
		if(ferror(hSource))
		{ 
			InfoMsgBox(_T("对不起，无法读取待加密文件数据！"));
			goto clean;
		}
		
		if(!CryptEncrypt(hKey,0,feof(hSource),0,pbBuffer,&dwCount,dwBufferLen))
		{ 
			InfoMsgBox(_T("加密过程出现错误！"));
			goto clean;
		} 
		
		fwrite(pbBuffer, 1, dwCount, hDestination); 
		if(ferror(hDestination))
		{ 
			InfoMsgBox(_T("对不起，无法写入加密后的数据到目标文件！"));
			goto clean;
		}
	} 
	while(!feof(hSource)); 
	InfoMsgBox(_T("加密成功！"));
	//资源释放
clean:
	if(utf8Pwd) delete[] utf8Pwd;
	if(hSource) fclose(hSource); 
	if(hDestination) fclose(hDestination);
	if(pbBuffer) free(pbBuffer); 

	if(hKey) CryptDestroyKey(hKey); 

	if(hXchgKey) CryptDestroyKey(hXchgKey); 

	if(hHash) CryptDestroyHash(hHash); 

	if(hCryptProv) CryptReleaseContext(hCryptProv, 0);
	return S_OK;
}

void FileEncrypter::ErrorMsgBox(DWORD dwErrorCode,TCHAR* szTemplet){
	BOOL hasTemplet=TRUE;

	if (!szTemplet || _tcslen(szTemplet)==0) hasTemplet=FALSE;

	if(dwErrorCode==0 && hasTemplet){
		MessageBox(GetForegroundWindow(),szTemplet,_T("亿榕公文交换平台错误"),MB_OK|MB_ICONERROR);
		return ;
	}

	TCHAR* szPos=NULL;
	if (hasTemplet) szPos=_tcsstr(szTemplet,_T("%s"));
	LPVOID lpMsgBuf;
	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |FORMAT_MESSAGE_FROM_SYSTEM,NULL,dwErrorCode,MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),(LPTSTR) &lpMsgBuf,0, NULL );
	TCHAR szTip[STRLEN_DEFAULT]={0};
	_stprintf_s(szTip,(szPos?szTemplet:_T("%s")),(lpMsgBuf==NULL?_T("未知错误"):lpMsgBuf));
	LocalFree(lpMsgBuf);
	MessageBox(GetForegroundWindow(),szTip,_T("亿榕公文交换平台错误"),MB_OK|MB_ICONERROR);
}

void FileEncrypter::InfoMsgBox(TCHAR* szTip){
	MessageBox(GetForegroundWindow(),szTip,_T("亿榕公文交换平台提示"),MB_OK|MB_ICONINFORMATION);
}