
// Report_Doc.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CReport_DocApp:
// See Report_Doc.cpp for the implementation of this class
//

class CReport_DocApp : public CWinApp
{
public:
	CReport_DocApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CReport_DocApp theApp;