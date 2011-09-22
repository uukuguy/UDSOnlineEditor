// dllmain.cpp : Implementation of DllMain.

#include "stdafx.h"
#include "resource.h"
#include "OEGui_i.h"
#include "dllmain.h"
#include "dlldatax.h"

COEGuiModule _AtlModule;
extern HANDLE v_hPrivateHeap;

// DLL Entry Point
extern "C" BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
#ifdef _MERGE_PROXYSTUB
	if (!PrxDllMain(hInstance, dwReason, lpReserved))
		return FALSE;
#endif
	hInstance;
	v_hPrivateHeap = HeapCreate(0, 0x1000, 0);

	return _AtlModule.DllMain(dwReason, lpReserved); 
}
