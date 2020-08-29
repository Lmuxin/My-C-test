#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
��������http://www.rupeng.com����ѧ�������ѧϰ�������ṩ���������Ƶѧϰ�̳̣��ṩ���Ի�һ��һѧϰָ��
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
			{


				HWND hwndcheck=GetDlgItem(hwnd,IDC_CHECK1);

			int checkState=Button_GetCheck(hwndcheck);
			if(BST_CHECKED==checkState)
			{
			MessageBox(hwnd,TEXT("ѡ����"),TEXT("��Ϣ"),MB_OK);
			
			
			}

	}
        break;

		case IDC_BUTTON1:
			{


			HWND hwndcheck=GetDlgItem(hwnd,IDC_CHECK1);

			int checkState=Button_GetCheck(hwndcheck);
			if(BST_CHECKED==checkState)
			{
			Button_SetCheck(hwndcheck,BST_UNCHECKED);
			
			}
			if(BST_UNCHECKED==checkState)
			{
			Button_SetCheck(hwndcheck,BST_CHECKED);
			
			}

	}
			break;

		case IDC_BUTTON2:
			{
	HWND hwndlist=GetDlgItem(hwnd,IDC_LIST1);
	ListBox_AddString(hwndlist,TEXT(" i love"));
				
			}

			break;
        default:
		break;
    }
}

void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}