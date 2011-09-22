// P11PinInputDlg.h : CP11PinInputDlg 的声明

#pragma once

#include "resource.h"       // 主符号

#include <atlhost.h>


// CP11PinInputDlg

class CP11PinInputDlg : 
	public CAxDialogImpl<CP11PinInputDlg>
{
public:
	CP11PinInputDlg()
		: pin_len(0)
	{
		*m_sz = 0;
	}

	~CP11PinInputDlg()
	{
	}

	enum { IDD = IDD_P11PININPUTDLG };

BEGIN_MSG_MAP(CP11PinInputDlg)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_HANDLER(IDOK, BN_CLICKED, OnClickedOK)
	COMMAND_HANDLER(IDCANCEL, BN_CLICKED, OnClickedCancel)
	COMMAND_HANDLER(IDC_EDIT_PIN, EN_MAXTEXT, OnEnMaxtextEditPin)
	MESSAGE_HANDLER(WM_SHOWWINDOW, OnShowWindow)
	COMMAND_HANDLER(IDC_BUTTON1, BN_CLICKED, OnBnClickedButton1)
	CHAIN_MSG_MAP(CAxDialogImpl<CP11PinInputDlg>)
END_MSG_MAP()

// 处理程序原型:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		CAxDialogImpl<CP11PinInputDlg>::OnInitDialog(uMsg, wParam, lParam, bHandled);
		bHandled = TRUE;

		HWND   hList   =   GetDlgItem(IDC_LIST1);
		//char   str[12]   =   "list1";  
		LV_COLUMN lvc;
		lvc.mask = LVCF_TEXT | LVCF_WIDTH;
		lvc.pszText = _T("读卡器");
		lvc.cx = 120;
		if(hList)  
		{  
			SendMessage(hList,LVM_INSERTCOLUMN,TRUE,(long)&lvc);  
		}   

		lvc.pszText = _T("HaiKey名字");
		lvc.cx = 120;
		if(hList)  
		{  
			SendMessage(hList,LVM_INSERTCOLUMN,TRUE,(long)&lvc);  
		}

		LVITEM   lvi; 
		lvi.iItem = 0;
		lvi.iSubItem = 0;
		lvi.mask = LVIF_TEXT; 
		lvi.pszText = _T("Haitai HaiKey 0");
		if(hList)  
		{ 
			SendMessage(hList, LVM_INSERTITEM, 0, (LPARAM)&lvi);   
		}
		//LVITEM   lvi1; 
		//lvi.iItem = 1;
		lvi.iSubItem = 1;	
		//lvi1.mask = LVIF_TEXT;
		lvi.pszText = _T("HaiKey");
		if(hList)  
		{ 
			SendMessage(hList, LVM_SETITEM, 0, (LPARAM)&lvi);   
		}
		return 1;  // 使系统设置焦点
	}

	LRESULT OnClickedOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		//GetDlgItemTextW(IDC_EDIT_PIN, pin);
		//CWindow   edit(GetDlgItem(IDC_EDIT_PIN));
		//edit.GetWndClassName();
		//TCHAR m_sz[64];
		*m_sz = 0;
		pin_len = 0;
		int cchString = ::GetWindowTextLength(GetDlgItem(IDC_EDIT_PIN));
		if (cchString > 60)
			cchString = 60;
		GetDlgItemText(IDC_EDIT_PIN, m_sz, cchString + 1);
		pin_len = cchString;
		EndDialog(wID);
		return 0;
	}

	LRESULT OnClickedCancel(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		EndDialog(wID);
		return 0;
	}

public:
	TCHAR m_sz[64];
public:
	LRESULT OnEnMaxtextEditPin(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
public:
	// 密码长度
	int pin_len;
public:
	LRESULT OnShowWindow(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
public:
	LRESULT OnBnClickedButton1(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};


