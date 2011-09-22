// TestSample.cpp : CTestSample 的实现

#include "stdafx.h"
#include "TestSample.h"
#include <stdio.h>
#include <windows.h>
#include <wincrypt.h>
#include <atlstr.h>
#include "PKIDtManager.h"
#include "P11PinInputDlg.h"
#include "comutil.h"

#define MY_ENCODING_TYPE  (PKCS_7_ASN_ENCODING | X509_ASN_ENCODING)
#define PROVIDER_NAME _T("HaiTai Cryptographic Service Provider")	//"Rainbow iKey 1000 RSA Cryptographic Service Provider"
void MyHandleError(char *s);


// CTestSample


STDMETHODIMP CTestSample::FindCerts(void)
{
	/*
	
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
		InfoMsgBox(_T("CryptAcquireContext"));
	}
	else 
	{
		DWORD err = GetLastError();
		
		InfoMsgBox(_T("CryptAcquireContext error"));
	}
	
	cbData = 0;
	memset(pbData, 0, sizeof(pbData));
	
	CryptGetProvParam(
		hCryptProv, 
		PP_ENUMCONTAINERS, 
		pbData, 
		&cbData, 
		CRYPT_FIRST);
	
	memset(pbData, 0, sizeof(pbData));
	if(CryptGetProvParam(
		hCryptProv, 
		PP_ENUMCONTAINERS, 
		pbData, 
		&cbData, 
		0))
	{
		memset(crContainer, 0, sizeof(crContainer));
		MultiByteToWideChar(CP_ACP,0,(char *)pbData,strlen((char *)pbData),crContainer,1024); 
		//wsprintf(crContainer, _T("count %s"), pbData);
		InfoMsgBox(crContainer);
	}
	else
		InfoMsgBox(_T("CryptGetProvParam error1"));

	CryptReleaseContext(hCryptProv, 0);
	*/
	/*
	CP11PinInputDlg pinDlg;
	if (pinDlg.DoModal() == IDOK)
	{

		//CString pin;
		//BSTR pin;
		//pinDlg.GetDlgControl();
		//pinDlg.GetDlgItem(IDC_EDIT_PIN);
		//CT2A(pin.AllocSysString());
		//InfoMsgBox(pin.AllocSysString());

		InfoMsgBox(pinDlg.m_sz);
	}
	else
	{
		InfoMsgBox(_T("IDCANCEL"));
	}*/
	PKIDtManager pkiDtManager;
	BYTE btContainer[1000];
	char *pCertName = "admin";
	char *pProvName = "HaiTai Cryptographic Service Provider";
	if (pkiDtManager.GetContainers(btContainer, pCertName, pProvName))
	{
		TCHAR containerName[1000];
		MultiByteToWideChar(CP_ACP, 0, (char*)btContainer, 1000, containerName, 500);
		InfoMsgBox(containerName);
	}
	else
	{
		InfoMsgBox(_T("error"));
	}
	return S_OK;
}

void CTestSample::InfoMsgBox(TCHAR* szTip){
	MessageBox(GetForegroundWindow(),szTip,_T("亿榕公文交换平台提示"),MB_OK|MB_ICONINFORMATION);
}

//-------------------------------------------------------------------
//  This example uses the function MyHandleError, a simple error
//  handling function, to print an error message to the  
//  standard error (stderr) file and exit the program. 
//  For most applications, replace this function with one 
//  that does more extensive error reporting.

void MyHandleError(char *s)
{
    fprintf(stderr,"An error occurred in running the program. \n");
    fprintf(stderr,"%s\n",s);
    fprintf(stderr, "Error number %x.\n", GetLastError());
    fprintf(stderr, "Program terminating. \n");
    exit(1);
} // End of MyHandleError
STDMETHODIMP CTestSample::AddNums(BSTR* rtnum)
{
	// TODO: 在此添加实现代码
	num++;
	CString strNumber;
	strNumber.Format(_T("%d"), num);
	*rtnum = strNumber.AllocSysString();
	return S_OK;
}

STDMETHODIMP CTestSample::FindCertByUser(BSTR cuser,BSTR* ccontainer)
{
	// TODO: 在此添加实现代码
	PKIDtManager pkiDtManager;
	char btContainer[1000];
	char *pCertName = (char*)_com_util::ConvertBSTRToString(cuser);
	char *pProvName = "HaiTai Cryptographic Service Provider";
	if (pkiDtManager.GetContainers((BYTE*)btContainer, pCertName, pProvName))
	{
		//char containerName[1000];
		//MultiByteToWideChar(CP_ACP, 0, (char*)btContainer, 1000, containerName, 500);
		//InfoMsgBox(containerName);
		*ccontainer = A2BSTR(btContainer);
	}
	else
	{
		InfoMsgBox(_T("error"));
	}
	if (pCertName)
		delete(pCertName);
	return S_OK;
}
