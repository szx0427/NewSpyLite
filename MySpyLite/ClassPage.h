#pragma once
#include "TabPage.h"

// CClassPage 对话框

class CClassPage : public CTabPage
{
	DECLARE_DYNAMIC(CClassPage)

public:
	CClassPage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CClassPage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_CLASS };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_clsname;
	CString m_clsstyles;
	CListCtrl m_list_clsstyle;
	afx_msg void OnNMClickClassstylesMsdn(NMHDR *pNMHDR, LRESULT *pResult);
};
