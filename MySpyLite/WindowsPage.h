#pragma once
#include "TabPage.h"

#ifndef WM_QUERYRESULT
#define WM_QUERYRESULT (WM_USER + 1)
#endif

// CWindowsPage 对话框

class CWindowsPage : public CTabPage
{
	DECLARE_DYNAMIC(CWindowsPage)

public:
	CWindowsPage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CWindowsPage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_WINDOWS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list_children;
	CString m_ownerWnd;
	CString m_parentWnd;
	static int m_i;
	static HWND m_hCurrentWnd;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedEnumChildWnds();
	static BOOL CALLBACK EnumWindowsProc(HWND hWnd, LPARAM lParam);
	afx_msg void OnBnClickedQuerySelection();
	afx_msg void OnNMClickLnkqueryparent(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickLnkqueryowner(NMHDR *pNMHDR, LRESULT *pResult);
	CString m_nextWnd;
	CString m_prevWnd;
	afx_msg void OnNMClickLnkqueryprevhwnd(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickLnkquerynexthwnd(NMHDR *pNMHDR, LRESULT *pResult);
};
