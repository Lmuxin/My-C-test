#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

#include<Mmsystem.h>
#pragma comment(lib,"Winmm.lib")








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
			{   TCHAR path[MAX_PATH];

			GetShortPathName("F:\\��������\\music\\���ٺ�-�Ͻ�",path,sizeof(path));//�õ� �ļ�����·��
			TCHAR cmd[MAX_PATH+10];
			wsprintf(cmd,"play %s",path);
				//MeMessageBox(hwnd,path,path,MB_OK);
				mciSendString("play F:/1.mp3","",0,NULL);
			
			
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