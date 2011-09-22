// dllmain.h : Declaration of module class.

class COEProxyModule : public CAtlDllModuleT< COEProxyModule >
{
public :
	DECLARE_LIBID(LIBID_OEProxyLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OEPROXY, "{441C132D-AF8D-4E6B-93DF-4AC1A30D4CA8}")
};

extern class COEProxyModule _AtlModule;
