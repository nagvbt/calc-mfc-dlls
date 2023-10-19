
// MyRegularSharedDll_Client_ExplicitLinkingDlg.h : header file
//

#pragma once


// CMyRegularSharedDll_Client_ExplicitLinkingDlg dialog
class CMyRegularSharedDll_Client_ExplicitLinkingDlg : public CDialog
{

public:
	long m_lVal1;
	long m_lVal2;
	long m_lResult;
// Construction
public:
	CMyRegularSharedDll_Client_ExplicitLinkingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MYREGULARSHAREDDLL_CLIENT_EXPLICITLINKING_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButAdd();
	afx_msg void OnBnClickedButSub();
	afx_msg void OnBnClickedButMul();
	long GetResult(const char* strOperation, long lVal1, long lVal2);
};
