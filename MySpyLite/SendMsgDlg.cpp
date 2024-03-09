// SendMsgDlg.cpp: 实现文件
//

#include "pch.h"
#include "MySpyLite.h"
#include "SendMsgDlg.h"
#include "afxdialogex.h"


// CSendMsgDlg 对话框

IMPLEMENT_DYNAMIC(CSendMsgDlg, CDialog)

CSendMsgDlg::CSendMsgDlg(HWND hCurWnd, CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_SEND_MESSAGE, pParent)
	, m_type(0)
	, m_wp(0)
	, m_lp(0)
	, m_result(0)
	, m_hCurWnd(hCurWnd)
	, m_msg(0)
{

}

CSendMsgDlg::~CSendMsgDlg()
{
}

void CSendMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_CBIndex(pDX, IDC_SEND_TYPE, m_type);
	DDX_Text(pDX, IDC_WPARAM, m_wp);
	DDX_Text(pDX, IDC_LPARAM, m_lp);
	DDX_Text(pDX, IDC_RESULT, m_result);
	DDX_Control(pDX, IDC_RESULT, m_resultCtrl);
	DDX_Text(pDX, IDC_MESSAGE, m_msg);
}


BEGIN_MESSAGE_MAP(CSendMsgDlg, CDialog)
	ON_BN_CLICKED(IDC_SEND, &CSendMsgDlg::OnBnClickedSend)
	ON_CBN_SELCHANGE(IDC_SEND_TYPE, &CSendMsgDlg::OnCbnSelchangeSendType)
	ON_NOTIFY(NM_CLICK, IDC_MSG_DOC, &CSendMsgDlg::OnNMClickMsgDoc)
END_MESSAGE_MAP()


// CSendMsgDlg 消息处理程序


void CSendMsgDlg::OnBnClickedSend()
{
	// TODO: 在此添加控件通知处理程序代码
	if (!::IsWindow(m_hCurWnd)) { MessageBoxA("窗口句柄无效。"); return; }
	UpdateData();
	if (m_type == 0)
	{
		m_result = ::SendMessage(m_hCurWnd, m_msg, m_wp, m_lp);
		UpdateData(false);
	}
	else
		::PostMessage(m_hCurWnd, m_msg, m_wp, m_lp);
}


void CSendMsgDlg::OnCbnSelchangeSendType()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	m_result = 0;
	UpdateData(false);
	m_resultCtrl.EnableWindow(m_type == 0);
}


void CSendMsgDlg::OnNMClickMsgDoc(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	ShellExecute(NULL, "open", "https://docs.microsoft.com/en-us/windows/win32/winmsg/about-messages-and-message-queues", NULL, NULL, SW_SHOWDEFAULT);
	*pResult = 0;
}


