// OEService.cpp : Implementation of WinMain


#include "stdafx.h"
#include "resource.h"
#include "OEService_i.h"

#include <stdio.h>

class COEServiceModule : public CAtlServiceModuleT< COEServiceModule, IDS_SERVICENAME >
{
public :
	DECLARE_LIBID(LIBID_OEServiceLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OESERVICE, "{B8CCBC5E-146E-439F-A5F9-3B1AD5F18D9C}")
	HRESULT InitializeSecurity() throw()
	{
		// TODO : Call CoInitializeSecurity and provide the appropriate security settings for 
		// your service
		// Suggested - PKT Level Authentication, 
		// Impersonation Level of RPC_C_IMP_LEVEL_IDENTIFY 
		// and an appropiate Non NULL Security Descriptor.

		return S_OK;
	}
};

COEServiceModule _AtlModule;



//
extern "C" int WINAPI _tWinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, 
                                LPTSTR /*lpCmdLine*/, int nShowCmd)
{
    return _AtlModule.WinMain(nShowCmd);
}

