#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include<stdlib.h>

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

	/*HWND hwndCombo1=GetDlgItem(hwnd,IDC_COMBOOP);
	ComboBox_AddString(hwndCombo1,TEXT("+"));
	ComboBox_AddString(hwndCombo1,TEXT("-"));
	ComboBox_AddString(hwndCombo1,TEXT("*"));
	ComboBox_AddString(hwndCombo1,TEXT("/"));*/
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_BUTTON1:
			{
		 /*TCHAR str1[256];
		 TCHAR str2[256];
		 GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
		 GetDlgItemText(hwnd,IDC_EDIT2,str2,sizeof(str2));
		 int i1=atoi(str1);
		 int i2=atoi(str2);
		  int i3=0;
		 HWND ComboOp=GetDlgItem(hwnd,IDC_COMBOOP);
		 int curIndex=ComboBox_GetCurSel(ComboOp);
		 switch(curIndex)
		 {
		 case 0:
			 { i3=i1-i2;}
			 break;
		 case 1:
			 {  i3=i1*i2;}
			 break;
			 case 2:
			 {	 i3=i1/i2;}
			 break;
		 case 3:
			 {	 i3=i1+i2;}
			 break;
		 }

		 TCHAR str3[24];
		
		 itoa(i3,str3,10);
		 SetDlgItemText(hwnd,IDC_EDIT3,str3);
*/


HWND cmb=GetDlgItem(hwnd,IDC_COMBOOP);

TCHAR str1[20];
GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
ComboBox_AddString(cmb,str1);
SetDlgItemText(hwnd,IDC_EDIT1,TEXT(""));

	}

        break;
		case IDC_BUTTON2:
			{
			HWND cmb=GetDlgItem(hwnd,IDC_COMBOOP);
				int  in=ComboBox_GetCurSel(cmb);
				if(CB_ERR==in)
				{
					MessageBox(hwnd,TEXT("没有任何项目被选中"),TEXT("删除错误"),MB_OK);
					return ;
				}
				ComboBox_DeleteString(cmb,in);
			
			}
			break;


				case IDC_BUTTON3:
			{
			   TCHAR str3[20];
				GetDlgItemText(hwnd,IDC_EDIT2,str3,sizeof(str3));
				HWND cmb=GetDlgItem(hwnd,IDC_COMBOOP);
int iCount=ComboBox_GetCount(cmb);//得到下拉框共有多少项
int i=0;
BOOL bFound=FALSE;
for(i=0;i<iCount;i++)//遍厉各个字符
{
TCHAR str4[24];
ComboBox_GetLBText(cmb,i,str4);
if(lstrcmp(str3,str4)==0)//windows中两个字符串比较用lstrcmp函数
{
	bFound=TRUE;
	ComboBox_SetCurSel(cmb,i);

}


}

if(bFound)
{
 MessageBox(hwnd,TEXT("找到了"),TEXT("消息"),MB_OK);

}
else
{
MessageBox(hwnd,TEXT("找不到"),TEXT("ei "),MB_OK);

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