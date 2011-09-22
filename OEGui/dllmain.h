// dllmain.h : Declaration of module class.

class COEGuiModule : public CAtlDllModuleT< COEGuiModule >
{
public :
	DECLARE_LIBID(LIBID_OEGuiLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_OEGUI, "{6903B2B9-0E5A-411C-A5E5-B04A5EF257BD}")
};

extern class COEGuiModule _AtlModule;
