// ToolsPage.cpp: 实现文件
//

#include "pch.h"
#include "MySpyLite.h"
#include "ToolsPage.h"
#include "afxdialogex.h"
#include "SendMsgDlg.h"


// CToolsPage 对话框

IMPLEMENT_DYNAMIC(CToolsPage, CTabPage)

CToolsPage::CToolsPage(CWnd* pParent /*=nullptr*/)
	: CTabPage(IDD_PAGE_TOOLS, pParent)
	, m_chkVisible(FALSE)
	, m_chkEnabled(FALSE)
	, m_chkReadonly(FALSE)
	, m_chkTopmost(FALSE)
	, m_chkMaximized(FALSE)
	, m_chkMinimized(FALSE)
	, m_xpos(0)
	, m_ypos(0)
	, m_cxpos(0)
	, m_cypos(0)
	, m_title(_T(""))
	, m_hCurWnd(NULL)
{

}

CToolsPage::~CToolsPage()
{
}

void CToolsPage::DoDataExchange(CDataExchange* pDX)
{
	CTabPage::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_VISIBLE, m_chkVisible);
	DDX_Check(pDX, IDC_ENABLED, m_chkEnabled);
	DDX_Check(pDX, IDC_READONLY, m_chkReadonly);
	DDX_Check(pDX, IDC_TOPMOST, m_chkTopmost);
	DDX_Check(pDX, IDC_MAXIMIZED, m_chkMaximized);
	DDX_Check(pDX, IDC_MINIMIZED, m_chkMinimized);
	DDX_Text(pDX, IDC_X_POS, m_xpos);
	DDX_Text(pDX, IDC_Y_POS, m_ypos);
	DDX_Text(pDX, IDC_CX_POS, m_cxpos);
	DDX_Text(pDX, IDC_CY_POS, m_cypos);
	DDX_Text(pDX, IDC_NEW_TITLE, m_title);
}


BEGIN_MESSAGE_MAP(CToolsPage, CTabPage)
	ON_BN_CLICKED(IDC_VISIBLE, &CToolsPage::OnBnClickedVisible)
	ON_BN_CLICKED(IDC_ENABLED, &CToolsPage::OnBnClickedEnabled)
	ON_BN_CLICKED(IDC_READONLY, &CToolsPage::OnBnClickedReadonly)
	ON_BN_CLICKED(IDC_TOPMOST, &CToolsPage::OnBnClickedTopmost)
	ON_BN_CLICKED(IDC_MAXIMIZED, &CToolsPage::OnBnClickedMaximized)
	ON_BN_CLICKED(IDC_MINIMIZED, &CToolsPage::OnBnClickedMinimized)
	ON_BN_CLICKED(IDC_KILL_NORMAL, &CToolsPage::OnBnClickedKillNormal)
	ON_BN_CLICKED(IDC_KILL_SETPARENT, &CToolsPage::OnBnClickedKillSetparent)
	ON_BN_CLICKED(IDC_KILL_SENDMSG, &CToolsPage::OnBnClickedKillSendmsg)
	ON_BN_CLICKED(IDC_WAIT_AND_QUERY, &CToolsPage::OnBnClickedWaitAndQuery)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_GET_FONT_INFO, &CToolsPage::OnBnClickedGetFontInfo)
	ON_BN_CLICKED(IDC_APPLY_POS, &CToolsPage::OnBnClickedApplyPos)
	ON_BN_CLICKED(IDC_APPLY_TITLE, &CToolsPage::OnBnClickedApplyTitle)
	ON_BN_CLICKED(IDC_SEND_MESSAGE, &CToolsPage::OnBnClickedSendMessage)
END_MESSAGE_MAP()


// CToolsPage 消息处理程序


#define MyInit() UpdateData(); if (!::IsWindow(m_hCurWnd)) { MessageBoxA("窗口句柄无效。"); return; }

void CToolsPage::OnBnClickedVisible()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	::ShowWindow(m_hCurWnd, m_chkVisible ? SW_SHOW : SW_HIDE);
}


void CToolsPage::OnBnClickedEnabled()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	::EnableWindow(m_hCurWnd, m_chkEnabled);
}


void CToolsPage::OnBnClickedReadonly()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	::SendMessage(m_hCurWnd, EM_SETREADONLY, (WPARAM)m_chkReadonly, 0);
}


void CToolsPage::OnBnClickedTopmost()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	::SetWindowPos(m_hCurWnd, m_chkTopmost ? HWND_TOPMOST : HWND_NOTOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
}


void CToolsPage::OnBnClickedMaximized()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	::ShowWindow(m_hCurWnd, m_chkMaximized ? SW_SHOWMAXIMIZED : SW_RESTORE);
}


void CToolsPage::OnBnClickedMinimized()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	::ShowWindow(m_hCurWnd, m_chkMinimized ? SW_SHOWMINIMIZED : SW_RESTORE);
}


void CToolsPage::OnBnClickedKillNormal()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	::PostMessage(m_hCurWnd, WM_CLOSE, 0, 0);
}


void CToolsPage::OnBnClickedKillSetparent()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	CStatic stc;
	stc.Create("", 0, { 0,0,0,0 }, this, IDC_STATIC);
	::SetParent(m_hCurWnd, stc.GetSafeHwnd());
	stc.SendMessage(WM_CLOSE);
}


void CToolsPage::OnBnClickedKillSendmsg()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	int ret = MessageBoxA("在硬件配置较低的计算机上执行此操作可能导致系统运行速度降低，或使本程序崩溃。\n您确定要执行吗？", 
		"警告", MB_ICONWARNING | MB_YESNO | MB_DEFBUTTON2);
	if (ret != IDYES)
		return;

	GetDlgItem(IDC_KILL_SENDMSG)->SetWindowTextA("执行中 请稍候");
	GetDlgItem(IDC_KILL_SENDMSG)->EnableWindow(FALSE);
	for (UINT msg = 0; msg < 0xffff; msg++)
		::PostMessage(m_hCurWnd, msg, 0, 0);
	GetDlgItem(IDC_KILL_SENDMSG)->SetWindowTextA("强力关闭 (方式2) (不推荐)");
	GetDlgItem(IDC_KILL_SENDMSG)->EnableWindow(TRUE);
}


void CToolsPage::OnBnClickedWaitAndQuery()
{
	// TODO: 在此添加控件通知处理程序代码
	SetTimer(1, 1000, NULL);
}


void CToolsPage::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (nIDEvent == 1)
	{
		static int n = 0;
		static CString str;

		POINT pt;
		GetCursorPos(&pt);
		HWND hwnd = ::WindowFromPoint(pt);
		if (n == 10)
		{
			n = 0;
			KillTimer(1);
			str.Format("%X", hwnd);
			GetParent()->GetParent()->SendMessage(WM_QUERYRESULT, 0, (LPARAM)(LPCSTR)str);
			GetParent()->GetParent()->SetWindowTextA("New SpyLite v1.5 by szx0427");
			MessageBeep(MB_OK);
			CTabPage::OnTimer(nIDEvent);
			return;
		}
		
		str.Format("当前窗口：0x%X，剩余时间：%d秒", hwnd, 10 - (n++));
		GetParent()->GetParent()->SetWindowTextA(str);
	}

	CTabPage::OnTimer(nIDEvent);
}


void CToolsPage::OnBnClickedGetFontInfo()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	LOGFONTA lf;
	
	CFont *pFont = CWnd::FromHandle(m_hCurWnd)->GetFont();
	if (pFont != nullptr)
		pFont->GetLogFont(&lf);
	else
	{
		lf.lfHeight = 16;
		lf.lfWidth = 7;
		lf.lfEscapement = 0;
		lf.lfOrientation = 0;
		lf.lfWeight = 700;
		lf.lfItalic = 0;
		lf.lfUnderline = 0;
		lf.lfStrikeOut = 0;
		lf.lfCharSet = 134;
		lf.lfOutPrecision = 1;
		lf.lfClipPrecision = 2;
		lf.lfQuality = 2;
		lf.lfPitchAndFamily = 34;
		strcpy(lf.lfFaceName, "System");
	}

	CString str;
	str.Format(
		"LOGFONT 结构体：\n"
		"lfHeight = %d,\n"
		"lfWidth = %d, \n"
		"lfEscapement = %d,\n"
		"lfOrientation = %d,\n"
		"lfWeight = %d,\n"
		"lfItalic = %u,\n"
		"lfUnderline = %u,\n"
		"lfStrikeOut = %u,\n"
		"lfCharset = %u,\n"
		"lfOutPrecision = %u,\n"
		"lfClipPrecision = %u,\n"
		"lfQuality = %u,\n"
		"lfPitchAndFamily = %u,\n"
		"lfFaceName = %s.",
		lf.lfHeight,
		lf.lfWidth,
		lf.lfEscapement,
		lf.lfOrientation,
		lf.lfWeight,
		lf.lfItalic,
		lf.lfUnderline,
		lf.lfStrikeOut,
		lf.lfCharSet,
		lf.lfOutPrecision,
		lf.lfClipPrecision,
		lf.lfQuality,
		lf.lfPitchAndFamily,
		lf.lfFaceName
	);
	MessageBoxA(str, "读取结果", MB_ICONINFORMATION);
}


void CToolsPage::OnBnClickedApplyPos()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	int x = 0, y = 0;
	auto hParent = ::GetParent(m_hCurWnd);
	if (hParent)
	{
		RECT rc;
		::GetClientRect(hParent, &rc);
		POINT pt = { rc.left,rc.top };
		::ClientToScreen(hParent, &pt);
		x = pt.x;
		y = pt.y;
	}
	::SetWindowPos(m_hCurWnd, NULL, m_xpos - x, m_ypos - y, m_cxpos, m_cypos, SWP_NOZORDER);
}


void CToolsPage::OnBnClickedApplyTitle()
{
	// TODO: 在此添加控件通知处理程序代码
	MyInit();
	::SetWindowTextA(m_hCurWnd, m_title);
}


void CToolsPage::OnBnClickedSendMessage()
{
	// TODO: 在此添加控件通知处理程序代码
	CSendMsgDlg dlg(m_hCurWnd);
	dlg.DoModal();
}
