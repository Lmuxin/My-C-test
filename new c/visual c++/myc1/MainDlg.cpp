#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include<stdlib.h>

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

				/*******�򵥵��������******/
		/*TCHAR str1[256];
		TCHAR str2[256];//���������ַ�����������ȡ���������������
		GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
		GetDlgItemText(hwnd,IDC_EDIT2,str2,sizeof(str2));
		//�����ַ�������ֱ����ӣ���Ҫ��ת�������Σ���Ҫ�õ�C���Եı�׼�⺯����atoi(��˼��ASCALL to int ��
		int i1=atoi(str1);                                                
		int i2=atoi(str2);
		int i3=i1+i2;
		TCHAR str3[256];
		//wsprintf(str3,"%d",i3);
		//���߲�Ҫ�����Ǹ�wsprintf(...��
		//����itoa����
		itoa(i3,str3,10);
	SetDlgItemText(hwnd,IDC_EDIT3,str3);*/


			/**************����һ�����ǰ뾶���������********/
			TCHAR str1[256];
				GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
				int i=atoi(str1);
				double f1=i*i*3.14;
				TCHAR str2[256];      //�����������ˣ����������Ǹ�double��������itoa������
			wsprintf(str2,"%d",f1);    //   f��double,��% ����Ӧ����ʲô��
				SetDlgItemText(hwnd,IDC_EDIT3,str2);




/**************ʮ���ƺͶ�����ת��**************/

			/*	TCHAR  str1[20];
				GetDlgItemText(hwnd,IDC_EDIT1,str1,sizeof(str1));
				int i1=atoi(str1);
				TCHAR str2[20];              //���ûɶ������ǣ�����Ϊ1 ʱ�����ҲΪ1������Ӧ��Ϊ01��
				itoa(i1,str2,2);
					SetDlgItemText(hwnd,IDC_EDIT3,str2);*/



				/***************������������֮��*************/
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