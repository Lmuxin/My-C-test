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
//char name[256];//����һ���ַ�������,Windows��һ����TCHAR����CHAR,jiejue Unicode�����ı��������
//GetDlgItemText(hwnd,IDC_EDITNAME,name,sizeof(name));//Ϊʲô��sizeof������strlen?
//sprintf�Ǵ�ӡ���ַ����У��൱��java����ַ�����ӡ�sprintf(�ַ���ָ�룬������������a1,a2,......)
//wsprintf,c���Կ���windows����ʱ��wsprintf����sprintf
//TCHAR msg[256];
//wsprintf(msg,"%s���",name);
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

