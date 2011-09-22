// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件

#pragma once

#ifndef STRICT
#define STRICT
#endif

// 如果必须将位于下面指定平台之前的平台作为目标，请修改下列定义。
// 有关不同平台对应值的最新信息，请参考 MSDN。
#ifndef WINVER				// 允许使用特定于 Windows XP 或更高版本的功能。
#define WINVER 0x0501		// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT		// 允许使用特定于 Windows XP 或更高版本的功能。
#define _WIN32_WINNT 0x0501	// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif						

#ifndef _WIN32_WINDOWS		// 允许使用特定于 Windows 98 或更高版本的功能。
#define _WIN32_WINDOWS 0x0410 // 将此值更改为适当的值，以指定将 Windows Me 或更高版本作为目标。
#endif

#ifndef _WIN32_IE			// 允许使用特定于 IE 6.0 或更高版本的功能。
#define _WIN32_IE 0x0600	// 将此值更改为相应的值，以适用于 IE 的其他版本。
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 某些 CString 构造函数将是显式的

//字符串缓冲区常数定义
#define STRLEN_SMALL	64
#define STRLEN_NORMAL	128
#define	STRLEN_DEFAULT	512	
#define	STRLEN_1K	1024
#define	STRLEN_2K	2048
#define	STRLEN_4K	4096
#define	STRLEN_8K	8192

//资源回收宏
#define SAFE_FREE_STRING_PTR(x) {if(x){delete[] (x);(x)=NULL;}}
#define SAFE_RELEASE(x) {if(x){(x)->Release();(x)=NULL;}}
#define SAFE_FREE_STRING(x) {if(x){SysFreeString(x);(x)=NULL;}}

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
using namespace ATL;