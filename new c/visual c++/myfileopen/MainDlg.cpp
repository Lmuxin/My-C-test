#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include<commdlg.h>
#include "resource.h"
#include "MainDlg.h"
#include<fstream>

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
	case IDC_OK:{

			OPENFILENAME ofn;
			char szFile[MAX_PATH];
			ZeroMemory(&ofn,sizeof(ofn));
			ofn.lStructSize=sizeof(ofn);
			ofn.lpstrFile=szFile;
			ofn.lpstrFile[0]=TEXT('\0');
			ofn.nMaxFile=sizeof(szFile);
			ofn.lpstrFilter=TEXT("ALL\0*.*\0Text\0*.TXT\0");
			ofn.nFilterIndex=1;
			ofn.lpstrFileTitle=NULL;
			ofn.nMaxFileTitle=0;
		    ofn.lpstrInitialDir=NULL;
			ofn.Flags=OFN_EXPLORER |OFN_PATHMUSTEXIST|OFN_FILEMUSTEXIST|OFN_ALLOWMULTISELECT;//OFN_ALLOWMULTISELECT允许选择多个文件
			if(GetOpenFileName(&ofn))//需要在头文件里加入#include<commdlg.h>
			{
			//MessageBox(hwnd,szFile,"",MB_OK);
				FILE *fp=fopen(szFile,"r");
				char line[256];
				fgets(line,sizeof(line),fp);
				SetDlgItemText(hwnd,IDC_EDIT1,line);
			
			}

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