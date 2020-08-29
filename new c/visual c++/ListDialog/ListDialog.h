// ListDialog.h : main header file for the LISTDIALOG application
//

#if !defined(AFX_LISTDIALOG_H__6AFC9EAE_C005_45F0_99AB_9FCBB4DEE192__INCLUDED_)
#define AFX_LISTDIALOG_H__6AFC9EAE_C005_45F0_99AB_9FCBB4DEE192__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CListDialogApp:
// See ListDialog.cpp for the implementation of this class
//

class CListDialogApp : public CWinApp
{
public:
	CListDialogApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListDialogApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CListDialogApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTDIALOG_H__6AFC9EAE_C005_45F0_99AB_9FCBB4DEE192__INCLUDED_)
