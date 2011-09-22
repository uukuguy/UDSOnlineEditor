// P11PinInputDlg.cpp : CP11PinInputDlg 的实现

#include "stdafx.h"
#include "P11PinInputDlg.h"


// CP11PinInputDlg

LRESULT CP11PinInputDlg::OnEnMaxtextEditPin(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("max"),_T("亿榕公文交换平台提示"),MB_OK|MB_ICONINFORMATION);
	return 0;
}

LRESULT CP11PinInputDlg::OnShowWindow(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	return 0;
}

LRESULT CP11PinInputDlg::OnBnClickedButton1(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: 在此添加控件通知处理程序代码
	
	
	return 0;
}
