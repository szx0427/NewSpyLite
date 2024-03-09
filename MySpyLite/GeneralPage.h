#pragma once
#include "TabPage.h"

// CGeneralPage 对话框

class CGeneralPage : public CTabPage
{
	DECLARE_DYNAMIC(CGeneralPage)

public:
	CGeneralPage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CGeneralPage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_GENERAL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	HBRUSH m_hBkBrush;
	CString m_clsName;
	CString m_cltRc;
	int m_ctrlId;
	CString m_path;
	DWORD m_pid;
	CString m_wndRc;
	DWORD m_tid;
	CString m_title;
	afx_msg void OnNMClickOpenDir(NMHDR *pNMHDR, LRESULT *pResult);
};
