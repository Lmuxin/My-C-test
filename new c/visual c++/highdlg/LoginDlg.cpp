#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "LoginDlg.h"
#include<stdlib.h>

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
��������http://www.rupeng.com����ѧ�������ѧϰ�������ṩ���������Ƶѧϰ�̳̣��ṩ���Ի�һ��һѧϰָ��
*/
BOOL WINAPI LoginDlg_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG,LoginDlg_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND, LoginDlg_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, LoginDlg_OnClose);
    }

    return FALSE;
}

BOOL LoginDlg_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	LoginDate* id=(LoginDate*)lParam;
SetDlgItemText(hwnd,IDC_EDITUSERNAME,id->username);
SetDlgItemText(hwnd,IDC_EDITPASSWORD,id->password);
	

	MessageBox(hwnd,id->username,TEXT(""),MB_OK);
    return TRUE;
}

void LoginDlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
			MessageBox(hwnd,TEXT("��ӭ���������� www.RuPeng.com ��ѧ�������ѧϰ����"),TEXT("�ʺ�"),MB_OK);
        break;
        default:
		break;
    }
}

void LoginDlg_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}