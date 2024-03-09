#pragma once
#include <afxwin.h>
class CTabPage :
	public CDialog
{
	DECLARE_DYNAMIC(CTabPage)

public:
	CTabPage(int nID, CWnd* pParent);

	virtual void OnOK();
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

