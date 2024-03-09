// WindowsPage.cpp: 实现文件
//

#include "pch.h"
#include "MySpyLite.h"
#include "WindowsPage.h"
#include "afxdialogex.h"


// CWindowsPage 对话框

HWND CWindowsPage::m_hCurrentWnd = NULL;
int CWindowsPage::m_i = 0;

IMPLEMENT_DYNAMIC(CWindowsPage, CTabPage)

CWindowsPage::CWindowsPage(CWnd* pParent /*=nullptr*/)
	: CTabPage(IDD_PAGE_WINDOWS, pParent)
	, m_ownerWnd(_T(""))
	, m_parentWnd(_T(""))
	, m_nextWnd(_T(""))
	, m_prevWnd(_T(""))
{
}

CWindowsPage::~CWindowsPage()
{
}

void CWindowsPage::DoDataExchange(CDataExchange* pDX)
{
	CTabPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHILDREN_LIST, m_list_children);
	DDX_Text(pDX, IDC_OWNER_HWND, m_ownerWnd);
	DDX_Text(pDX, IDC_PARENT_HWND, m_parentWnd);
	DDX_Text(pDX, IDC_NEXT_HWND, m_nextWnd);
	DDX_Text(pDX, IDC_PREV_HWND, m_prevWnd);
}


BEGIN_MESSAGE_MAP(CWindowsPage, CTabPage)
	ON_BN_CLICKED(IDC_ENUM_CHILD_WNDS, &CWindowsPage::OnBnClickedEnumChildWnds)
	ON_BN_CLICKED(IDC_QUERY_SELECTION, &CWindowsPage::OnBnClickedQuerySelection)
	ON_NOTIFY(NM_CLICK, IDC_LNKQUERYPARENT, &CWindowsPage::OnNMClickLnkqueryparent)
	ON_NOTIFY(NM_CLICK, IDC_LNKQUERYOWNER, &CWindowsPage::OnNMClickLnkqueryowner)
	ON_NOTIFY(NM_CLICK, IDC_LNKQUERYPREVHWND, &CWindowsPage::OnNMClickLnkqueryprevhwnd)
	ON_NOTIFY(NM_CLICK, IDC_LNKQUERYNEXTHWND, &CWindowsPage::OnNMClickLnkquerynexthwnd)
END_MESSAGE_MAP()


// CWindowsPage 消息处理程序



BOOL CWindowsPage::OnInitDialog()
{
	CTabPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_list_children.SetExtendedStyle(m_list_children.GetExtendedStyle() | LVS_EX_FULLROWSELECT);
	CRect rc; m_list_children.GetClientRect(&rc);
	int cx = rc.Width() - GetSystemMetrics(SM_CXVSCROLL);
	m_list_children.InsertColumn(0, "窗口句柄", LVCFMT_LEFT, cx * 1 / 5);
	m_list_children.InsertColumn(1, "窗口类名", LVCFMT_LEFT, cx * 2 / 5);
	m_list_children.InsertColumn(2, "窗口标题", LVCFMT_LEFT, cx * 2 / 5);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CWindowsPage::OnBnClickedEnumChildWnds()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!IsWindow(m_hCurrentWnd))
	{
		MessageBoxA("当前窗口句柄无效。");
		return;
	}
	m_list_children.DeleteAllItems();
	m_i = 0;
	EnumChildWindows(m_hCurrentWnd, EnumWindowsProc, (LPARAM)this);
	if (!m_list_children.GetItemCount())
		MessageBoxA("该窗口没有任何子窗口。", "信息", MB_ICONINFORMATION);
}

BOOL CALLBACK CWindowsPage::EnumWindowsProc(HWND hWnd, LPARAM lParam)
{
	CWindowsPage *pThis = (CWindowsPage*)lParam;
	static char szBuf[1024];

	sprintf(szBuf, "0x%X", hWnd);
	pThis->m_list_children.InsertItem(m_i, szBuf);
	::GetClassNameA(hWnd, szBuf, 1024);
	pThis->m_list_children.SetItemText(m_i, 1, szBuf);
	::GetWindowTextA(hWnd, szBuf, 1024);
	pThis->m_list_children.SetItemText(m_i++, 2, szBuf);

	return TRUE;
}


void CWindowsPage::OnBnClickedQuerySelection()
{
	// TODO: 在此添加控件通知处理程序代码
	POSITION pos = m_list_children.GetFirstSelectedItemPosition();
	if (!pos)
	{
		MessageBoxA("请选择一个子窗口。");
		return;
	}
	int sel = m_list_children.GetNextSelectedItem(pos);
	GetParent()->GetParent()->
		SendMessage(WM_QUERYRESULT, 0, 
		(LPARAM)((LPCSTR)m_list_children.GetItemText(sel, 0) + 2));
}


void CWindowsPage::OnNMClickLnkqueryparent(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	GetParent()->GetParent()->SendMessage(WM_QUERYRESULT, 0, (LPARAM)(LPCSTR)m_parentWnd);

	*pResult = 0;
}


void CWindowsPage::OnNMClickLnkqueryowner(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	GetParent()->GetParent()->SendMessage(WM_QUERYRESULT, 0, (LPARAM)(LPCSTR)m_ownerWnd);

	*pResult = 0;
}


void CWindowsPage::OnNMClickLnkqueryprevhwnd(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	GetParent()->GetParent()->SendMessage(WM_QUERYRESULT, 0, (LPARAM)(LPCSTR)m_prevWnd);

	*pResult = 0;
}


void CWindowsPage::OnNMClickLnkquerynexthwnd(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	GetParent()->GetParent()->SendMessage(WM_QUERYRESULT, 0, (LPARAM)(LPCSTR)m_nextWnd);

	*pResult = 0;
}
