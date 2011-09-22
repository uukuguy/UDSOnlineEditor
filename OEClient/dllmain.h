// dllmain.h : Declaration of module class.

class COEClientModule : public CAtlDllModuleT< COEClientModule >
{
public :
	DECLARE_LIBID(LIBID_OEClientLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OECLIENT, "{8C99661B-B251-4BD6-AEA9-2C8C03E2A22D}")
};

extern class COEClientModule _AtlModule;
