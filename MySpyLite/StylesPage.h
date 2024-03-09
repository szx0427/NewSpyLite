#pragma once
#include "TabPage.h"

// CStylesPage 对话框

class CStylesPage : public CTabPage
{
	DECLARE_DYNAMIC(CStylesPage)

public:
	CStylesPage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CStylesPage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_STYLES };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list_styles;
	CListCtrl m_list_exstyles;
	CString m_stc_styles;
	CString m_stc_exstyles;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMClickStylesMsdn(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickExstylesMsdn(NMHDR *pNMHDR, LRESULT *pResult);
};
