#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
如鹏网（http://www.rupeng.com）大学生计算机学习社区，提供大量免费视频学习教程，提供个性化一对一学习指导
*/
BOOL WINAPI Main_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG, Main_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND, Main_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, Main_OnClose);
    }

    return FALSE;
}

BOOL Main_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
//char name[256];//声明一个字符串数组,Windows里一般用TCHAR代替CHAR,jiejue Unicode、中文编码的问题
//GetDlgItemText(hwnd,IDC_EDITNAME,name,sizeof(name));//为什么用sizeof而不用strlen?
//sprintf是打印到字符串中，相当于java里的字符串相加。sprintf(字符串指针，“。。。”，a1,a2,......)
//wsprintf,c语言开发windows程序时用wsprintf代替sprintf
//TCHAR msg[256];
//wsprintf(msg,"%s你好",name);
//MessageBox(hwnd,msg,msg,MB_OK);	
			SetDlgItemText(hwnd,IDC_EDITNAME,"WOAINI ");

	break;
        default:
	break;
}
}
	void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd,0);
}

