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
    return TRUE;
}

void Main_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
			{

				/*******简单的两数相加******/
		/*TCHAR str1[256];
		TCHAR str2[256];//声明两个字符串变量用来取得输入带两个数字
		GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
		GetDlgItemText(hwnd,IDC_EDIT2,str2,sizeof(str2));
		//两个字符串不能直接相加，需要先转换成整形，需要用到C语言的标准库函数：atoi(意思是ASCALL to int ）
		int i1=atoi(str1);                                                
		int i2=atoi(str2);
		int i3=i1+i2;
		TCHAR str3[256];
		//wsprintf(str3,"%d",i3);
		//或者不要上面那个wsprintf(...）
		//而用itoa函数
		itoa(i3,str3,10);
	SetDlgItemText(hwnd,IDC_EDIT3,str3);*/


			/**************输入一个数是半径，求其面积********/
			TCHAR str1[256];
				GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
				int i=atoi(str1);
				double f1=i*i*3.14;
				TCHAR str2[256];      //现在问题来了，求面积结果是个double，不能用itoa函数了
			wsprintf(str2,"%d",f1);    //   f是double,那% 后面应该是什么呢
				SetDlgItemText(hwnd,IDC_EDIT3,str2);




/**************十进制和二进制转换**************/

			/*	TCHAR  str1[20];
				GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
				int i1=atoi(str1);
				TCHAR str2[20];              //这个没啥问题就是，输入为1 时，输出也为1，不是应该为01吗？
				itoa(i1,str2,2);
					SetDlgItemText(hwnd,IDC_EDIT3,str2);*/



				/***************计算两个数字之差*************/
				/*TCHAR str1[20];
				TCHAR str2[20];
				GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
				GetDlgItemText(hwnd,IDC_EDIT2,str2,sizeof(str2));
				int i1=atoi(str1);
				int i2=atoi(str2);
				int i3=i1-i2;
				TCHAR str3[20];
				wsprintf(str3,"%d",i3);
				SetDlgItemText(hwnd,IDC_EDIT3,str3);*/




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