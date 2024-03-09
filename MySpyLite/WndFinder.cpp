#include "pch.h"
#include "MySpyLite.h"
#include "WndFinder.h"
#include "resource.h"


CWndFinder::CWndFinder()
	: m_pEdit(NULL)
	, m_pushed(false)
	, m_hLastFound(NULL)
//	, m_hOldPen(NULL)
//	, m_hOldBrush(NULL)
//	, m_oldROP(0)
{
	m_hCross = LoadCursor(NULL, IDC_CROSS);
	m_hPen = CreatePen(PS_SOLID, 5, RGB(255, 255, 0));
	m_hNullBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
}

CWndFinder::~CWndFinder()
{
	DestroyCursor(m_hCross);
	DeleteObject(m_hPen);
//	DeleteObject(m_hNullBrush); // It's not necessary to delete a stock object
}


BEGIN_MESSAGE_MAP(CWndFinder, CStatic)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()


void CWndFinder::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	CWnd* pParent = GetParent();
//	pParent->SetDlgItemText(IDC_HWND, _T("test"));
	::SetCursor(m_hCross);
	DWORD dw = GetLastError();

	if (!m_pEdit)
		m_pEdit = GetParent()->GetDlgItem(IDC_HWND);

	m_pushed = true;
	SetCapture();

	CStatic::OnLButtonDown(nFlags, point);
}


void CWndFinder::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pushed = false;
	ReleaseCapture();

	if (m_hLastFound)
	{
		ReleaseLastFound();
		m_hLastFound = NULL;
		GetParent()->SendMessage(WM_QUERYRESULT);
	}

	CStatic::OnLButtonUp(nFlags, point);
}

void CWndFinder::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pushed)
	{
		POINT pt;
		GetCursorPos(&pt);
		HWND hwnd = ::WindowFromPoint(pt);
		::ScreenToClient(hwnd, &pt);
		HWND hChild = ::ChildWindowFromPoint(hwnd, pt);
		if (hChild) {
			hwnd = hChild;
		}
		if (hwnd != m_hLastFound)
		{
			CString sWnd;
			sWnd.Format(_T("%X"), hwnd);
			sWnd.ReleaseBuffer();
			m_pEdit->SetWindowText(sWnd);

			HDC hdc;
			RECT rect;

			if (m_hLastFound)
			{
				ReleaseLastFound();
			}

			hdc = ::GetWindowDC(hwnd);
			auto hOldPen = SelectObject(hdc, m_hPen);
			auto hOldBrush = SelectObject(hdc, m_hNullBrush);
			auto oldROP = SetROP2(hdc, R2_NOT);
			::GetWindowRect(hwnd, &rect);
			Rectangle(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top);
			SelectObject(hdc, hOldPen);
			SelectObject(hdc, hOldBrush);
			SetROP2(hdc, oldROP);
			::ReleaseDC(hwnd, hdc);

			m_hLastFound = hwnd;
		}
	}

	CStatic::OnMouseMove(nFlags, point);
}

void CWndFinder::ReleaseLastFound()
{
	HDC hdc = ::GetWindowDC(m_hLastFound);
	RECT rect;
	::GetWindowRect(m_hLastFound, &rect);
	auto hOldPen = SelectObject(hdc, m_hPen);
	auto hOldBrush = SelectObject(hdc, m_hNullBrush);
	auto oldROP = SetROP2(hdc, R2_NOT);
	Rectangle(hdc, 0, 0, rect.right - rect.left, rect.bottom - rect.top);
	SelectObject(hdc, hOldPen);
	SelectObject(hdc, hOldBrush);
	SetROP2(hdc, oldROP);
	//::RedrawWindow(m_hLastFound, NULL, NULL, RDW_ERASE | RDW_INVALIDATE | RDW_FRAME | RDW_ERASENOW | RDW_UPDATENOW | RDW_ALLCHILDREN);
	::ReleaseDC(m_hLastFound, hdc);
}
