// ListCtrlDlg.h : header file
//

#if !defined(AFX_LISTCTRLDLG_H__08AFDBDB_AAB6_4E8D_A501_4F114ABE2A48__INCLUDED_)
#define AFX_LISTCTRLDLG_H__08AFDBDB_AAB6_4E8D_A501_4F114ABE2A48__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CListCtrlDlg dialog

class CListCtrlDlg : public CDialog
{
// Construction
public:
	CListCtrlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CListCtrlDlg)
	enum { IDD = IDD_LISTCTRL_DIALOG };
	CListCtrl	m_ListCtrl;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CListCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTCTRLDLG_H__08AFDBDB_AAB6_4E8D_A501_4F114ABE2A48__INCLUDED_)
