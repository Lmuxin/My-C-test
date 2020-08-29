  
#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "GIALOG3.h"

BOOL WINAPI GIALOG3_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG,  GIALOG3_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND,  GIALOG3_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE,  GIALOG3_OnClose);
    }

    return FALSE;
}

BOOL  GIALOG3_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
//	m_ListCtrl.InsertColumn(0, _T("姓名"), LVCFMT_LEFT, 60，-1); 
    return TRUE;
}

void  GIALOG3_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
			MessageBox(hwnd,TEXT("欢迎访问如鹏网 www.RuPeng.com 大学生计算机学习社区"),TEXT("问好"),MB_OK);
        break;
        default:
		break;
    }
}

void  GIALOG3_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}
