// ListDialogDlg.h : header file
//

#if !defined(AFX_LISTDIALOGDLG_H__53C97B9D_8503_4DA6_8B98_F9E273029F61__INCLUDED_)
#define AFX_LISTDIALOGDLG_H__53C97B9D_8503_4DA6_8B98_F9E273029F61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListDialogDlg dialog

class CListDialogDlg : public CDialog
{
// Construction
public:
	CListDialogDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListDialogDlg)
	enum { IDD = IDD_LISTDIALOG_DIALOG };
	CListCtrl	m_cListCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListDialogDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListDialogDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTDIALOGDLG_H__53C97B9D_8503_4DA6_8B98_F9E273029F61__INCLUDED_)
