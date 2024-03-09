// AboutPage.cpp: 实现文件
//

#include "pch.h"
#include "MySpyLite.h"
#include "AboutPage.h"
#include "afxdialogex.h"


// CAboutPage 对话框

IMPLEMENT_DYNAMIC(CAboutPage, CTabPage)

CAboutPage::CAboutPage(CWnd* pParent /*=nullptr*/)
	: CTabPage(IDD_PAGE_ABOUT, pParent)
{

}

CAboutPage::~CAboutPage()
{
}

void CAboutPage::DoDataExchange(CDataExchange* pDX)
{
	CTabPage::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAboutPage, CTabPage)
END_MESSAGE_MAP()


// CAboutPage 消息处理程序


