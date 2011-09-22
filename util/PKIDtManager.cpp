#include "StdAfx.h"
#include "PKIDtManager.h"
#include "base64util.h"
#define PROVIDER_NAME _T("HaiTai Cryptographic Service Provider")
#define MY_STRING_TYPE (CERT_X500_NAME_STR | CERT_NAME_STR_REVERSE_FLAG)

PKIDtManager::PKIDtManager(void)
{
}

PKIDtManager::~PKIDtManager(void)
{
}

BOOL PKIDtManager::GetContainers(BYTE *btFirstContainer)
{
	BOOL rt = false;
	HCRYPTPROV hCryptProv;
	BYTE pbData[1000];       // 1000 will hold the longest 
                         // key container name.
	DWORD cbData;
	WCHAR crContainer[1000];

	if(CryptAcquireContext(
		&hCryptProv, 
		NULL, 
		PROVIDER_NAME, 
		PROV_RSA_FULL, 
		CRYPT_VERIFYCONTEXT)) 
	{
		//InfoMsgBox(_T("CryptAcquireContext"));
	}
	else 
	{
		DWORD err = GetLastError();
		
		//InfoMsgBox(_T("CryptAcquireContext error"));
		MessageBox(GetForegroundWindow(),_T("CryptAcquireContext error"),_T("亿榕公文交换平台提示"),MB_OK|MB_ICONINFORMATION);
		goto clean;
	}
	
	cbData = 0;
	memset(pbData, 0, sizeof(pbData));
	
	CryptGetProvParam(
		hCryptProv, 
		PP_ENUMCONTAINERS, 
		btFirstContainer, 
		&cbData, 
		CRYPT_FIRST);
	
	memset(pbData, 0, sizeof(pbData));
	if(CryptGetProvParam(
		hCryptProv, 
		PP_ENUMCONTAINERS, 
		btFirstContainer, 
		&cbData, 
		0))
	{
		//memset(crContainer, 0, sizeof(crContainer));
		//MultiByteToWideChar(CP_ACP,0,(char *)btFirstContainer,strlen((char *)btFirstContainer),crContainer,1024); 
		//wsprintf(crContainer, _T("count %s"), pbData);
		//InfoMsgBox(crContainer);
	}
	else
	{
		//InfoMsgBox(_T("CryptGetProvParam error"));
		MessageBox(GetForegroundWindow(),_T("枚举UKey容器错误，请确认UKey是否插入电脑且工作正常，并安装了正确的驱动程序"),_T("亿榕公文交换平台提示"),MB_OK|MB_ICONINFORMATION);
		goto clean;
	}
	rt = true;
clean:
	if (hCryptProv) CryptReleaseContext(hCryptProv, 0);

	return rt;
}

BOOL PKIDtManager::GetContainers(BYTE *btContainer/*大小必须大于1000*/, char *pCertName, char *pProvName)
{
	BOOL rt = false;
	HCERTSTORE hCertStore;					//证书存储区句柄
	PCCERT_CONTEXT pCertContext = NULL;		//证书句柄
	TCHAR pszNameString[1000];				//保存证书名称的数组
	PCRYPT_KEY_PROV_INFO pKeyProvInfo=NULL;	//保存密码服务提供者信息的结构体指针
	DWORD dwLen;
	char ptmp[1000];	
	
	//打开MY证书库（个人证书存储区）
	hCertStore = CertOpenStore(CERT_STORE_PROV_SYSTEM_W, 0, 0,
		CERT_STORE_OPEN_EXISTING_FLAG |
		CERT_SYSTEM_STORE_CURRENT_USER,
		L"MY");
	if(hCertStore == NULL)
	{
		//HandleError("调用 CertOpenStore 失败。");
	}
	else
	{
		//printf("当前证书库MY区的证书有：\n\n");
		//枚举证书库中证书
		while(pCertContext= CertEnumCertificatesInStore(
			hCertStore,
			pCertContext)) 
		{
			//int serlen = pCertContext->pCertInfo->SerialNumber.cbData;
			//char *crOutByteChar = new char[serlen * 2 + 1];
			//ZeroMemory(crOutByteChar, serlen*2+1);
			//crOutByteChar[serlen*2] = '\0';
			//base64util::ToHexString(crOutByteChar, pCertContext->pCertInfo->SerialNumber.pbData, serlen);
			//delete[] crOutByteChar;

			//获得证书的名称
			CertGetNameString(pCertContext,CERT_NAME_SIMPLE_DISPLAY_TYPE,0,NULL,pszNameString,500);	
			
			WideCharToMultiByte (CP_ACP, 0,pszNameString, -1, ptmp, 1000, NULL,NULL);
			int r = strcmp(ptmp,pCertName);

			if (r != 0)
				continue;
			//打印信息
			//printf("\n证书名称：%s\n",pszNameString);
			//获得证书颁发者的名称，第三个参数为CERT_NAME_ISSUER_FLAG
			CertGetNameString(pCertContext,CERT_NAME_SIMPLE_DISPLAY_TYPE,CERT_NAME_ISSUER_FLAG,NULL,pszNameString,500);	
			//打印信息
			//printf("\n证书颁发者名称：%s\n",pszNameString);
			
			//获得证书句柄属性，CERT_KEY_PROV_INFO_PROP_ID：获得证书对应密码服务提供者信息
			//第一次调用获得输出数据长度
			
			if(!CertGetCertificateContextProperty(pCertContext,CERT_KEY_PROV_INFO_PROP_ID,NULL,&dwLen))
			{
				//HandleError("调用 CertGetCertificateContextProperty1 失败。");
				continue;
			}
			//为pKeyProvInfo申请内存
			pKeyProvInfo = (PCRYPT_KEY_PROV_INFO)malloc(dwLen);
			//第二次调用，获得数据
			if(!CertGetCertificateContextProperty(pCertContext,CERT_KEY_PROV_INFO_PROP_ID,pKeyProvInfo,&dwLen))
			{
				//HandleError("调用 CertGetCertificateContextProperty 失败。");
			}
			else
			{				
				WideCharToMultiByte(CP_ACP,0,pKeyProvInfo->pwszProvName,-1,ptmp,1000,NULL,NULL); 
				int r = strcmp(ptmp,pProvName);
				if (r == 0)
					rt = true;

				//printf("\tCSP名称:%s\n",ptmp);
				WideCharToMultiByte(CP_ACP,0,pKeyProvInfo->pwszContainerName,-1,(char*)btContainer,1000,NULL,NULL); 
				
				//printf("\t容器名:%s\n",ptmp);
				//if(pKeyProvInfo->dwKeySpec == AT_SIGNATURE)
				//	printf("\t密钥用途：AT_SIGNATURE(签名)\n");
				//else
				//	printf("\t密钥用途：AT_KEYEXCHANGE(加密)\n");
			}
			free(pKeyProvInfo);
			pKeyProvInfo = NULL;
			if (rt)
				break;
		}
	}
	CertCloseStore(hCertStore,0);
	return rt;
}

BOOL PKIDtManager::GetCertInfoProp(WD_CERT_INFO_PROP enProp, void *btCertProp/*大小必须大于1000 sid 数据*/, int btCertPropLen/*参数btCertPropLen 长度*/, int &propLen/*propLen 长度*/, char *pCertName, char *pProvName)
{
	BOOL rt = false;
	HCERTSTORE hCertStore;					//证书存储区句柄
	PCCERT_CONTEXT pCertContext = NULL;		//证书句柄
	TCHAR pszNameString[1000];				//保存证书名称的数组
	PCRYPT_KEY_PROV_INFO pKeyProvInfo=NULL;	//保存密码服务提供者信息的结构体指针
	DWORD dwLen;
	char ptmp[1000];	
	
	//打开MY证书库（个人证书存储区）
	hCertStore = CertOpenStore(CERT_STORE_PROV_SYSTEM_W, 0, 0,
		CERT_STORE_OPEN_EXISTING_FLAG |
		CERT_SYSTEM_STORE_CURRENT_USER,
		L"MY");
	if(hCertStore == NULL)
	{
		//HandleError("调用 CertOpenStore 失败。");
	}
	else
	{
		//printf("当前证书库MY区的证书有：\n\n");
		//枚举证书库中证书
		while(pCertContext= CertEnumCertificatesInStore(
			hCertStore,
			pCertContext)) 
		{
			

			//获得证书的名称
			CertGetNameString(pCertContext,CERT_NAME_SIMPLE_DISPLAY_TYPE,0,NULL,pszNameString,500);	
			
			WideCharToMultiByte (CP_ACP, 0,pszNameString, -1, ptmp, 1000, NULL,NULL);
			int r = strcmp(ptmp,pCertName);

			//if (r != 0)
			//	continue;
			//打印信息
			//printf("\n证书名称：%s\n",pszNameString);
			//获得证书颁发者的名称，第三个参数为CERT_NAME_ISSUER_FLAG
			CertGetNameString(pCertContext,CERT_NAME_SIMPLE_DISPLAY_TYPE,CERT_NAME_ISSUER_FLAG,NULL,pszNameString,500);	
			//打印信息
			//printf("\n证书颁发者名称：%s\n",pszNameString);
			
			//获得证书句柄属性，CERT_KEY_PROV_INFO_PROP_ID：获得证书对应密码服务提供者信息
			//第一次调用获得输出数据长度
			
			if(!CertGetCertificateContextProperty(pCertContext,CERT_KEY_PROV_INFO_PROP_ID,NULL,&dwLen))
			{
				//HandleError("调用 CertGetCertificateContextProperty1 失败。");
				continue;
			}
			//为pKeyProvInfo申请内存
			pKeyProvInfo = (PCRYPT_KEY_PROV_INFO)malloc(dwLen);
			//第二次调用，获得数据
			if(!CertGetCertificateContextProperty(pCertContext,CERT_KEY_PROV_INFO_PROP_ID,pKeyProvInfo,&dwLen))
			{
				//HandleError("调用 CertGetCertificateContextProperty 失败。");
			}
			else
			{				
				WideCharToMultiByte(CP_ACP,0,pKeyProvInfo->pwszProvName,-1,ptmp,1000,NULL,NULL); 
				int r = strcmp(ptmp,pProvName);
				if (r == 0)
					rt = true;

				//printf("\tCSP名称:%s\n",ptmp);
				//WideCharToMultiByte(CP_ACP,0,pKeyProvInfo->pwszContainerName,-1,(char*)btContainer,1000,NULL,NULL); 
				
				//printf("\t容器名:%s\n",ptmp);
				//if(pKeyProvInfo->dwKeySpec == AT_SIGNATURE)
				//	printf("\t密钥用途：AT_SIGNATURE(签名)\n");
				//else
				//	printf("\t密钥用途：AT_KEYEXCHANGE(加密)\n");
			}
			if (rt)
			{
				//int serlen = pCertContext->pCertInfo->SerialNumber.cbData;
				if (enProp == serialNumber)//读证书序列号
				{
					propLen = pCertContext->pCertInfo->SerialNumber.cbData;
					if (btCertPropLen < propLen)
					{
						rt = false;
					}
					else
					{
						strcpy((char*)btCertProp, (char*)pCertContext->pCertInfo->SerialNumber.pbData);
					}
				}
				else if (enProp == subject)//读主题
				{
					DWORD cbSize;
					LPTSTR pszString;
					cbSize = CertNameToStr(
						pCertContext->dwCertEncodingType,
						&(pCertContext->pCertInfo->Subject),
						MY_STRING_TYPE,
						NULL,
						0);
					propLen = cbSize;
					if (1 == cbSize || cbSize > btCertPropLen)
					{
						//MyHandleError(TEXT("Subject name is an empty string."));
						rt = false;
					}
					else
					{
						if((pszString = (LPTSTR)malloc(cbSize * sizeof(TCHAR))))
						{
							
							cbSize = CertNameToStr(
								pCertContext->dwCertEncodingType,
								&(pCertContext->pCertInfo->Subject),
								MY_STRING_TYPE,
								pszString,
								cbSize);

							if (1 == cbSize)
							{
								rt = false;
							}
							else
							{
								USES_CONVERSION;
							
								strcpy((char*)btCertProp, (char*)T2A(pszString));
							}
							free(pszString);
						}
					}
					
				}
			}
			//char *crOutByteChar = new char[serlen * 2 + 1];
			//ZeroMemory(crOutByteChar, serlen*2+1);
			//crOutByteChar[serlen*2] = '\0';
			//base64util::ToHexString(crOutByteChar, pCertContext->pCertInfo->SerialNumber.pbData, serlen);
			//delete[] crOutByteChar;

			free(pKeyProvInfo);
			pKeyProvInfo = NULL;
			if (rt)
				break;
		}
	}
	CertCloseStore(hCertStore,0);
	return rt;
}