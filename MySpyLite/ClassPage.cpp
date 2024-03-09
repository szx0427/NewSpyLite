// ClassPage.cpp: 实现文件
//

#include "pch.h"
#include "MySpyLite.h"
#include "ClassPage.h"
#include "afxdialogex.h"


// CClassPage 对话框

IMPLEMENT_DYNAMIC(CClassPage, CTabPage)

CClassPage::CClassPage(CWnd* pParent /*=nullptr*/)
	: CTabPage(IDD_PAGE_CLASS, pParent)
	, m_clsname(_T(""))
	, m_clsstyles(_T("0x00000000L"))
{

}

CClassPage::~CClassPage()
{
}

void CClassPage::DoDataExchange(CDataExchange* pDX)
{
	CTabPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_CLASS_NAME_2, m_clsname);
	DDX_Text(pDX, IDC_CLASS_STYLE, m_clsstyles);
	DDX_Control(pDX, IDC_LIST_CLASS_STYLES, m_list_clsstyle);
}


BEGIN_MESSAGE_MAP(CClassPage, CTabPage)
	ON_NOTIFY(NM_CLICK, IDC_CLASSSTYLES_MSDN, &CClassPage::OnNMClickClassstylesMsdn)
END_MESSAGE_MAP()


// CClassPage 消息处理程序


BOOL CClassPage::OnInitDialog()
{
	CTabPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_list_clsstyle.SetExtendedStyle(m_list_clsstyle.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	CRect rc; m_list_clsstyle.GetClientRect(&rc);
	int cx = rc.Width() - GetSystemMetrics(SM_CXVSCROLL);
	m_list_clsstyle.InsertColumn(0, "样式名称", LVCFMT_LEFT, cx * 2 / 3);
	m_list_clsstyle.InsertColumn(1, "样式值", LVCFMT_LEFT, cx * 1 / 3);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CClassPage::OnNMClickClassstylesMsdn(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecuteA(NULL, "open", "https://docs.microsoft.com/en-us/windows/win32/winmsg/window-class-styles", NULL, NULL, SW_SHOW);

	*pResult = 0;
}
