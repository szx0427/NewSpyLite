#pragma once


// CSendMsgDlg 对话框

class CSendMsgDlg : public CDialog
{
	DECLARE_DYNAMIC(CSendMsgDlg)

public:
	CSendMsgDlg(HWND hCurWnd, CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSendMsgDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SEND_MESSAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int m_type;
	int m_wp;
	int m_lp;
	int m_result;
	HWND m_hCurWnd;
	afx_msg void OnBnClickedSend();
	afx_msg void OnCbnSelchangeSendType();
	CEdit m_resultCtrl;
	UINT m_msg;
	afx_msg void OnNMClickMsgDoc(NMHDR* pNMHDR, LRESULT* pResult);
};
