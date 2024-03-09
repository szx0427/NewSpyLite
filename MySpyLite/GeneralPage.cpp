// GeneralPage.cpp: 实现文件
//

#include "pch.h"
#include "MySpyLite.h"
#include "GeneralPage.h"
#include "afxdialogex.h"


// CGeneralPage 对话框

IMPLEMENT_DYNAMIC(CGeneralPage, CTabPage)

CGeneralPage::CGeneralPage(CWnd* pParent /*=nullptr*/)
	: CTabPage(IDD_PAGE_GENERAL, pParent)
	, m_clsName(_T(""))
	, m_cltRc(_T(""))
	, m_ctrlId(0)
	, m_path(_T(""))
	, m_pid(0)
	, m_wndRc(_T(""))
	, m_tid(0)
	, m_title(_T(""))
{
	m_hBkBrush = GetSysColorBrush(COLOR_WINDOW);
}

CGeneralPage::~CGeneralPage()
{
}

void CGeneralPage::DoDataExchange(CDataExchange* pDX)
{
	CTabPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CLASSNAME, m_clsName);
	DDX_Text(pDX, IDC_CLIENT_RECT, m_cltRc);
	DDX_Text(pDX, IDC_CTRL_ID, m_ctrlId);
	DDX_Text(pDX, IDC_PATH, m_path);
	DDX_Text(pDX, IDC_PID, m_pid);
	DDX_Text(pDX, IDC_RECT, m_wndRc);
	DDX_Text(pDX, IDC_TID, m_tid);
	DDX_Text(pDX, IDC_TITLE, m_title);
}


BEGIN_MESSAGE_MAP(CGeneralPage, CTabPage)
	ON_NOTIFY(NM_CLICK, IDC_OPEN_DIR, &CGeneralPage::OnNMClickOpenDir)
END_MESSAGE_MAP()


// CGeneralPage 消息处理程序


void CGeneralPage::OnNMClickOpenDir(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (PathFileExistsA(m_path))
		ShellExecuteA(NULL, "open", "explorer.exe", "/select," + m_path, NULL, SW_SHOWNORMAL);
	else
		MessageBoxA("文件不存在。", "错误", MB_ICONWARNING);

	*pResult = 0;
}
