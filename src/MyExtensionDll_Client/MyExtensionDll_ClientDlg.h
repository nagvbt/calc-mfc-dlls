
// MyExtensionDll_ClientDlg.h : header file
//

#pragma once


// CMyExtensionDll_ClientDlg dialog
class CMyExtensionDll_ClientDlg : public CDialog
{
public:
	CMyMath m_objMath;
	long m_lVal1;
	long m_lVal2;
	long m_lResult;

// Construction
public:
	CMyExtensionDll_ClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MYEXTENSIONDLL_CLIENT_DIALOG };

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
	
	
};
