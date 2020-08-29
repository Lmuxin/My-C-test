; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CListDialogDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ListDialog.h"

ClassCount=3
Class1=CListDialogApp
Class2=CListDialogDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_LISTDIALOG_DIALOG

[CLS:CListDialogApp]
Type=0
HeaderFile=ListDialog.h
ImplementationFile=ListDialog.cpp
Filter=N

[CLS:CListDialogDlg]
Type=0
HeaderFile=ListDialogDlg.h
ImplementationFile=ListDialogDlg.cpp
Filter=D
LastObject=IDC_LIST1
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=ListDialogDlg.h
ImplementationFile=ListDialogDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_LISTDIALOG_DIALOG]
Type=1
Class=CListDialogDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_LIST1,SysListView32,1350631425

