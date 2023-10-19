
// MyRegularSharedDll_Client_ExplicitLinkingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyRegularSharedDll_Client_ExplicitLinking.h"
#include "MyRegularSharedDll_Client_ExplicitLinkingDlg.h"

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


// CMyRegularSharedDll_Client_ExplicitLinkingDlg dialog




CMyRegularSharedDll_Client_ExplicitLinkingDlg::CMyRegularSharedDll_Client_ExplicitLinkingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyRegularSharedDll_Client_ExplicitLinkingDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyRegularSharedDll_Client_ExplicitLinkingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyRegularSharedDll_Client_ExplicitLinkingDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUT_ADD, &CMyRegularSharedDll_Client_ExplicitLinkingDlg::OnBnClickedButAdd)
	ON_BN_CLICKED(IDC_BUT_SUB, &CMyRegularSharedDll_Client_ExplicitLinkingDlg::OnBnClickedButSub)
	ON_BN_CLICKED(IDC_BUT_MUL, &CMyRegularSharedDll_Client_ExplicitLinkingDlg::OnBnClickedButMul)
END_MESSAGE_MAP()


// CMyRegularSharedDll_Client_ExplicitLinkingDlg message handlers

BOOL CMyRegularSharedDll_Client_ExplicitLinkingDlg::OnInitDialog()
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

void CMyRegularSharedDll_Client_ExplicitLinkingDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyRegularSharedDll_Client_ExplicitLinkingDlg::OnPaint()
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
HCURSOR CMyRegularSharedDll_Client_ExplicitLinkingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//Balaji code
typedef long (*CALCFUN)(long, long);

void CMyRegularSharedDll_Client_ExplicitLinkingDlg::OnBnClickedButAdd()
{
  m_lVal1 = GetDlgItemInt( IDC_EDIT_VALUE_1);
  m_lVal2 = GetDlgItemInt( IDC_EDIT_VALUE_2);

  m_lResult = GetResult("Add", m_lVal1, m_lVal2);
  SetDlgItemInt( IDC_EDIT_RESULT, m_lResult, TRUE );

}

void CMyRegularSharedDll_Client_ExplicitLinkingDlg::OnBnClickedButSub()
{
  m_lVal1 = GetDlgItemInt( IDC_EDIT_VALUE_1);
  m_lVal2 = GetDlgItemInt( IDC_EDIT_VALUE_2);

  m_lResult = GetResult(("Sub"), m_lVal1, m_lVal2);
  SetDlgItemInt( IDC_EDIT_RESULT, m_lResult, TRUE );
}

void CMyRegularSharedDll_Client_ExplicitLinkingDlg::OnBnClickedButMul()
{
  m_lVal1 = GetDlgItemInt( IDC_EDIT_VALUE_1);
  m_lVal2 = GetDlgItemInt( IDC_EDIT_VALUE_2);

  m_lResult = GetResult(("Mul"), m_lVal1, m_lVal2);
  SetDlgItemInt( IDC_EDIT_RESULT, m_lResult, TRUE );
}

long CMyRegularSharedDll_Client_ExplicitLinkingDlg::GetResult(const char* strOperation, long lVal1, long lVal2)
{
  CALCFUN  pFun;             
  HMODULE hMod;        // handle to loaded library module
  BOOL    bRes;        // BOOL to check if DLL was successfully unloaded 

  // returns a handle to the DLL, otherwise NULL
  hMod = LoadLibrary(_T("MyRegularSharedDll.dll"));
 
  // returns the address of the DLL functions, otherwise NULL
  //const char* op = strOperation;
  pFun = (CALCFUN) GetProcAddress(hMod, strOperation);
 
  // (DLL function address) (function parameters)
  long lResult = (pFun)(lVal1, lVal2);
  
  // returns nonzero if sucussful 
  bRes = FreeLibrary(hMod); 

  return lResult;
}
