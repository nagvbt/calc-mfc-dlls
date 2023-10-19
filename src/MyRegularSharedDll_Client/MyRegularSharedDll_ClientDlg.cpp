
// MyRegularSharedDll_ClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyRegularSharedDll_Client.h"
#include "MyRegularSharedDll_ClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMyRegularSharedDll_ClientDlg dialog




CMyRegularSharedDll_ClientDlg::CMyRegularSharedDll_ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyRegularSharedDll_ClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyRegularSharedDll_ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyRegularSharedDll_ClientDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUT_ADD, &CMyRegularSharedDll_ClientDlg::OnBnClickedButAdd)
	ON_BN_CLICKED(IDC_BUT_SUB, &CMyRegularSharedDll_ClientDlg::OnBnClickedButSub)
	ON_BN_CLICKED(IDC_BUT_MUL, &CMyRegularSharedDll_ClientDlg::OnBnClickedButMul)
	ON_BN_CLICKED(IDOK2, &CMyRegularSharedDll_ClientDlg::OnBnClickedOk2)
END_MESSAGE_MAP()


// CMyRegularSharedDll_ClientDlg message handlers

BOOL CMyRegularSharedDll_ClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyRegularSharedDll_ClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyRegularSharedDll_ClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyRegularSharedDll_ClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Balaji Code
extern "C" __declspec(dllimport) long Add( long val1, long val2);
extern "C" __declspec(dllimport) long Sub( long val1, long val2);
extern "C" __declspec(dllimport) long Mul( long val1, long val2); 

void CMyRegularSharedDll_ClientDlg::OnBnClickedButAdd()
{
	m_lVal1 = GetDlgItemInt( IDC_EDIT_VALUE_1);
    m_lVal2 = GetDlgItemInt( IDC_EDIT_VALUE_2);
    m_lResult = Add(m_lVal1, m_lVal2);
    SetDlgItemInt( IDC_EDIT_RESULT, m_lResult, TRUE );
}

void CMyRegularSharedDll_ClientDlg::OnBnClickedButSub()
{
	m_lVal1 = GetDlgItemInt( IDC_EDIT_VALUE_1);
    m_lVal2 = GetDlgItemInt( IDC_EDIT_VALUE_2);
    m_lResult = Sub(m_lVal1, m_lVal2);
    SetDlgItemInt( IDC_EDIT_RESULT, m_lResult, TRUE );
}

void CMyRegularSharedDll_ClientDlg::OnBnClickedButMul()
{
	m_lVal1 = GetDlgItemInt( IDC_EDIT_VALUE_1);
    m_lVal2 = GetDlgItemInt( IDC_EDIT_VALUE_2);
    m_lResult = Mul(m_lVal1, m_lVal2);
    SetDlgItemInt( IDC_EDIT_RESULT, m_lResult, TRUE );
}

void CMyRegularSharedDll_ClientDlg::OnBnClickedOk2()
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}

