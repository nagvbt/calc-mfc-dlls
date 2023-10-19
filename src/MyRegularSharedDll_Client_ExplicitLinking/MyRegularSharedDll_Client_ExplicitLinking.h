
// MyRegularSharedDll_Client_ExplicitLinking.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMyRegularSharedDll_Client_ExplicitLinkingApp:
// See MyRegularSharedDll_Client_ExplicitLinking.cpp for the implementation of this class
//

class CMyRegularSharedDll_Client_ExplicitLinkingApp : public CWinAppEx
{
public:
	CMyRegularSharedDll_Client_ExplicitLinkingApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMyRegularSharedDll_Client_ExplicitLinkingApp theApp;