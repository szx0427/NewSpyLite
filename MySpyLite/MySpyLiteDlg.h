
// MySpyLiteDlg.h: 头文件
//

#pragma once
#include "WndFinder.h"
#include "GeneralPage.h"
#include "StylesPage.h"
#include "ClassPage.h"
#include "WindowsPage.h"
#include "ImagePage.h"
#include "ToolsPage.h"
#include "AboutPage.h"

// CMySpyLiteDlg 对话框
class CMySpyLiteDlg : public CDialog
{
// 构造
public:
	CMySpyLiteDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYSPYLITE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_tabCursel;
	CWndFinder m_wndFinder;
	CString m_sWnd;
	BOOL m_topmost;
	afx_msg void OnBnClickedTopmost();
	CFont m_font;
	CTabCtrl m_tab;
	CGeneralPage m_page1;
	CStylesPage m_page2;
	CClassPage m_page3;
	CWindowsPage m_page4;
	CImagePage m_page5;
	CToolsPage m_page6;
	CAboutPage m_page7;
	afx_msg void OnBnClickedQuery();
	afx_msg LRESULT OnQueryResult(WPARAM, LPARAM lParam);
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	void UpdateGeneralData(HWND hWnd);
	void UpdateStylesData(HWND hWnd);
	void UpdateClassData(HWND hWnd);
	void UpdateWindowsData(HWND hWnd);
	void UpdateImageData(HWND hWnd);
	void UpdateToolsData(HWND hWnd);
	virtual void OnOK();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	static std::string NTFilePath2DosFilePath(std::string name);
	CEdit m_hexEdit;
};
