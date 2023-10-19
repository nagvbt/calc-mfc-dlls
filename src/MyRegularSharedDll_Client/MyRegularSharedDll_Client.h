
// MyRegularSharedDll_Client.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMyRegularSharedDll_ClientApp:
// See MyRegularSharedDll_Client.cpp for the implementation of this class
//

class CMyRegularSharedDll_ClientApp : public CWinAppEx
{
public:
	CMyRegularSharedDll_ClientApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMyRegularSharedDll_ClientApp theApp;