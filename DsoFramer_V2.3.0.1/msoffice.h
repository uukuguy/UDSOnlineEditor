
#ifndef DSO_MSOFFICE_
#define DSO_MSOFFICE_

//#define SUPPORT_WPS
#import "C:\Program Files\Common Files\DESIGNER\MSADDNDR.DLL" raw_interfaces_only, raw_native_types, no_namespace, named_guids 

// C:\Program Files\Common Files\Microsoft Shared\OFFICE12
#import "C:\Program Files\Common Files\Microsoft Shared\OFFICE12\mso.dll" rename_namespace("Office")
//using namespace Office;

// C:\Program Files\Common Files\Microsoft Shared\VBA\VBA6
#import "C:\Program Files\Common Files\Microsoft Shared\VBA\VBA6\VBE6EXT.olb" rename_namespace("VBE6")
//using namespace VBE6;

// C:\Program Files\Microsoft Office\Office12
#import "C:\Program Files\Microsoft Office\Office12\MSWORD.olb" rename("ExitWindows","ExitWindowsEx"),rename_namespace("MSWord")
//using namespace MSWord;

// C:\Program Files\Microsoft Office\Office12
#import "C:\Program Files\Microsoft Office\Office12\EXCEL.exe" rename("RGB","RGBEx"),rename("DialogBox","DialogBoxEx"),rename_namespace("MSExcel")
//using namespace MSExcel;

// C:\Program Files\Microsoft Office\Office12
#import "C:\Program Files\Microsoft Office\Office12\MSPPT.OLB" named_guids,rename_namespace("MSPPT")
//using namespace MSPPT;


 
#ifdef SUPPORT_WPS
#import "c:\Program Files\Kingsoft\WPS Office 2005 Professional\office6\kso10.dll" rename_namespace("Wps")
using namespace Wps;
#import "c:\Program Files\Kingsoft\WPS Office 2005 Professional\office6\wpscore.dll" rename_namespace("Wps")
using namespace Wps;
#endif


#endif