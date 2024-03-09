// StylesPage.cpp: 实现文件
//

#include "pch.h"
#include "MySpyLite.h"
#include "StylesPage.h"
#include "afxdialogex.h"


// CStylesPage 对话框

IMPLEMENT_DYNAMIC(CStylesPage, CTabPage)

CStylesPage::CStylesPage(CWnd* pParent /*=nullptr*/)
	: CTabPage(IDD_PAGE_STYLES, pParent)
	, m_stc_styles(_T("基本样式：0x00000000L"))
	, m_stc_exstyles(_T("扩展样式：0x00000000L"))
{

}

CStylesPage::~CStylesPage()
{
}

void CStylesPage::DoDataExchange(CDataExchange* pDX)
{
	CTabPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_STYLES, m_list_styles);
	DDX_Control(pDX, IDC_LIST_EXSTYLES, m_list_exstyles);
	DDX_Text(pDX, IDC_BASIC_STYLES, m_stc_styles);
	DDX_Text(pDX, IDC_EX_STYLES, m_stc_exstyles);
}


BEGIN_MESSAGE_MAP(CStylesPage, CTabPage)
	ON_NOTIFY(NM_CLICK, IDC_STYLES_MSDN, &CStylesPage::OnNMClickStylesMsdn)
	ON_NOTIFY(NM_CLICK, IDC_EXSTYLES_MSDN, &CStylesPage::OnNMClickExstylesMsdn)
END_MESSAGE_MAP()


// CStylesPage 消息处理程序


BOOL CStylesPage::OnInitDialog()
{
	CTabPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CRect rc;
	int cx;

	m_list_styles.SetExtendedStyle(m_list_styles.GetExtendedStyle() | /*LVS_EX_GRIDLINES | */LVS_EX_FULLROWSELECT);
	m_list_styles.GetClientRect(&rc);
	cx = rc.Width() - GetSystemMetrics(SM_CXVSCROLL);
	m_list_styles.InsertColumn(0, "样式名称", LVCFMT_LEFT, cx * 2 / 3);
	m_list_styles.InsertColumn(1, "样式值", LVCFMT_LEFT, cx * 1 / 3);

	m_list_exstyles.SetExtendedStyle(m_list_styles.GetExtendedStyle() | /*LVS_EX_GRIDLINES | */LVS_EX_FULLROWSELECT);
	m_list_exstyles.GetClientRect(&rc);
	cx = rc.Width() - GetSystemMetrics(SM_CXVSCROLL);
	m_list_exstyles.InsertColumn(0, "样式名称", LVCFMT_LEFT, cx * 2 / 3);
	m_list_exstyles.InsertColumn(1, "样式值", LVCFMT_LEFT, cx * 1 / 3);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CStylesPage::OnNMClickStylesMsdn(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecuteA(NULL, "open", "https://docs.microsoft.com/en-us/windows/win32/winmsg/window-styles", NULL, NULL, SW_SHOW);

	*pResult = 0;
}


void CStylesPage::OnNMClickExstylesMsdn(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecuteA(NULL, "open", "https://docs.microsoft.com/en-us/windows/win32/winmsg/extended-window-styles", NULL, NULL, SW_SHOW);

	*pResult = 0;
}
