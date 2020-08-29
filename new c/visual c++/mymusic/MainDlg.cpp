#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"

#include<Mmsystem.h>
#pragma comment(lib,"Winmm.lib")








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
			{   TCHAR path[MAX_PATH];

			GetShortPathName("F:\\网易音乐\\music\\李荣浩-老街",path,sizeof(path));//得到 文件名的路径
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