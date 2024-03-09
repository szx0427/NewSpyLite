// ImagePage.cpp: 实现文件
//

#include "pch.h"
#include "MySpyLite.h"
#include "ImagePage.h"
#include "afxdialogex.h"


// CImagePage 对话框

IMPLEMENT_DYNAMIC(CImagePage, CTabPage)

CImagePage::CImagePage(CWnd* pParent /*=nullptr*/)
	: CTabPage(IDD_PAGE_IMAGE, pParent)
	, m_pStcDc(NULL)
	, m_imgCx(0)
	, m_imgCy(0)
{

}

CImagePage::~CImagePage()
{
}

void CImagePage::DoDataExchange(CDataExchange* pDX)
{
	CTabPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IMAGE, m_stc_image);
	DDX_Control(pDX, IDC_VSCROLL, m_vscroll);
	DDX_Control(pDX, IDC_HSCROLL, m_hscroll);
}


BEGIN_MESSAGE_MAP(CImagePage, CTabPage)
	ON_WM_ERASEBKGND()
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_SAVE_IMAGE, &CImagePage::OnBnClickedSaveImage)
END_MESSAGE_MAP()


// CImagePage 消息处理程序



BOOL CImagePage::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	BOOL b = CTabPage::OnEraseBkgnd(pDC);

	if (!m_img.IsNull())
	{
		m_img.BitBlt(m_pStcDc->m_hDC, 1, 1, m_imgCx, m_imgCy, 
			m_hscroll.GetScrollPos(), m_vscroll.GetScrollPos(), SRCCOPY);
	}

	return b;
}


void CImagePage::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nSBCode)
	{
	case SB_THUMBTRACK:
		m_img.BitBlt(m_pStcDc->m_hDC, 1, 1, m_imgCx, m_imgCy,
			nPos, m_vscroll.GetScrollPos(), SRCCOPY);
		break;
	case SB_THUMBPOSITION:
		m_hscroll.SetScrollPos(nPos);
		break;
	case SB_LINELEFT:
		m_img.BitBlt(m_pStcDc->m_hDC, 1, 1, m_imgCx, m_imgCy,
			m_hscroll.GetScrollPos() - 1, m_vscroll.GetScrollPos(), SRCCOPY);
		m_hscroll.SetScrollPos(m_hscroll.GetScrollPos() - 1);
		break;
	case SB_LINERIGHT:
		m_img.BitBlt(m_pStcDc->m_hDC, 1, 1, m_imgCx, m_imgCy,
			m_hscroll.GetScrollPos() + 1, m_vscroll.GetScrollPos(), SRCCOPY);
		m_hscroll.SetScrollPos(m_hscroll.GetScrollPos() + 1);
		break;
	default:
		break;
	}

	CTabPage::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CImagePage::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	switch (nSBCode)
	{
	case SB_THUMBTRACK:
		m_img.BitBlt(m_pStcDc->m_hDC, 1, 1, m_imgCx, m_imgCy,
			m_hscroll.GetScrollPos(), nPos, SRCCOPY);
		break;
	case SB_THUMBPOSITION:
		m_vscroll.SetScrollPos(nPos);
		break;
	case SB_LINELEFT:
		m_img.BitBlt(m_pStcDc->m_hDC, 1, 1, m_imgCx, m_imgCy,
			m_hscroll.GetScrollPos(), m_vscroll.GetScrollPos() - 1, SRCCOPY);
		m_vscroll.SetScrollPos(m_vscroll.GetScrollPos() - 1);
		break;
	case SB_LINERIGHT:
		m_img.BitBlt(m_pStcDc->m_hDC, 1, 1, m_imgCx, m_imgCy,
			m_hscroll.GetScrollPos(), m_vscroll.GetScrollPos() + 1, SRCCOPY);
		m_vscroll.SetScrollPos(m_vscroll.GetScrollPos() + 1);
		break;
	default:
		break;
	}

	CTabPage::OnVScroll(nSBCode, nPos, pScrollBar);
}


void CImagePage::OnDestroy()
{
	m_stc_image.ReleaseDC(m_pStcDc);

	CTabPage::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}


BOOL CImagePage::OnInitDialog()
{
	CTabPage::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_pStcDc = m_stc_image.GetDC();
	CRect rc;
	m_stc_image.GetClientRect(&rc);
	m_imgCx = rc.Width() - 2;
	m_imgCy = rc.Height() - 2;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CImagePage::OnBnClickedSaveImage()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_img.IsNull())
	{
		MessageBoxA("没有可以保存的图像。");
		return;
	}

	CFileDialog fileDlg(FALSE, "bmp", NULL, OFN_OVERWRITEPROMPT,
		"位图文件(*.bmp)|*.bmp|JPEG格式图片(*.jpg;*.jpeg)|*.jpg;*.jpeg|PNG格式图片(*.png)|*.png|所有文件(*.*)|*.*||",
		this, 0, TRUE);
	if (fileDlg.DoModal() == IDOK)
	{
		HRESULT hr = m_img.Save(fileDlg.GetPathName());
		if (SUCCEEDED(hr))
			MessageBoxA("图片保存成功！", "信息", MB_ICONINFORMATION);
		else
		{
			CString str;
			str.Format("图片保存失败(HRESULT: 0x%08X)。", hr);
			MessageBoxA(str, "错误", MB_ICONHAND);
		}
	}
}
