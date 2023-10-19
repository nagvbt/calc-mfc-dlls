// MyRegularSharedDll.h : main header file for the MyRegularSharedDll DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMyRegularSharedDllApp
// See MyRegularSharedDll.cpp for the implementation of this class
//

class CMyRegularSharedDllApp : public CWinApp
{
public:
	CMyRegularSharedDllApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
