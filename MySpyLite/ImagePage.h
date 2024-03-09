#pragma once
#include "TabPage.h"

// CImagePage 对话框

class CImagePage : public CTabPage
{
	DECLARE_DYNAMIC(CImagePage)

public:
	CImagePage(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CImagePage();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAGE_IMAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_stc_image;
	CImage m_img;
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar m_vscroll;
	CScrollBar m_hscroll;
	CDC *m_pStcDc;
	int m_imgCx, m_imgCy;
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedSaveImage();
};
