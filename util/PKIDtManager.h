#pragma once


enum WD_CERT_INFO_PROP 
{
	serialNumber = 0,
	subject
};

class PKIDtManager
{
public:
	PKIDtManager(void);
public:
	~PKIDtManager(void);
public:
	BOOL GetContainers(BYTE *btFirstContainer);
	BOOL GetContainers(BYTE *btContainer/*大小必须大于1000*/, char *pCertName, char *pProvName);
	BOOL GetCertInfoProp(WD_CERT_INFO_PROP enProp, void *btCertProp/*大小必须大于1000 sid 数据*/, int btCertPropLen/*参数btSid 长度*/, int &propLen/*sid 长度*/, char *pCertName, char *pProvName);
};
