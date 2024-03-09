#pragma once
#include "TabPage.h"

#ifndef WM_QUERYRESULT
#define WM_QUERYRESULT (WM_USER + 1)
#endif

// CToolsPage 对话框

class CToolsPage : public CTabPage
{
	DECLARE_DYNAMIC(CToolsPage)

public:
	CToolsPage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CToolsPage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_TOOLS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_chkVisible;
	BOOL m_chkEnabled;
	BOOL m_chkReadonly;
	BOOL m_chkTopmost;
	BOOL m_chkMaximized;
	BOOL m_chkMinimized;
	int m_xpos;
	int m_ypos;
	int m_cxpos;
	int m_cypos;
	CString m_title;
	HWND m_hCurWnd;
	afx_msg void OnBnClickedVisible();
	afx_msg void OnBnClickedEnabled();
	afx_msg void OnBnClickedReadonly();
	afx_msg void OnBnClickedTopmost();
	afx_msg void OnBnClickedMaximized();
	afx_msg void OnBnClickedMinimized();
	afx_msg void OnBnClickedKillNormal();
	afx_msg void OnBnClickedKillSetparent();
	afx_msg void OnBnClickedKillSendmsg();
	afx_msg void OnBnClickedWaitAndQuery();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedGetFontInfo();
	afx_msg void OnBnClickedApplyPos();
	afx_msg void OnBnClickedApplyTitle();
	afx_msg void OnBnClickedSendMessage();
};
