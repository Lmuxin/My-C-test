#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "DIALOG3.h"
#include"Commctrl.h"
#include  <sql.h>
#include  <sqlext.h>
#include <sqltypes.h>
#include <stdlib.h>

BOOL WINAPI DIALOG3_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG,  DIALOG3_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND,  DIALOG3_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE,  DIALOG3_OnClose);
    }

    return FALSE;
}

BOOL  DIALOG3_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
	LoginData *ld=(LoginData*)lParam;

    return TRUE;
}

void  DIALOG3_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDC_OK:
			 //DialogBoxParam(hIntance,MAKEINTRESOURCE(IDD_DIALOG1),NULL,DIALOG1_Proc,);//给新弹出多窗口传参数
        break;
        default:
		break;
    }
}

void  DIALOG3_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}



int InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat = LVCFMT_LEFT, int nWidth = -1, int nSubItem = -1)；

/*int ItemCount = ListView_GetItemCount(GetDlgItem(hwnd,IDC_LSVRECORD));
lvItem.iItem = ItemCount; 
//输出姓名 
lvItem.iSubItem = 0; 
lvItem.pszText = chName; 
SendDlgItemMessage(hwnd,IDC_LSVRECORD,LVM_INSERTITEM,0,(LPARAM)&lvItem); 
//输出年龄 
lvItem.iSubItem = 1; 
lvItem.pszText = chAge; 
SendDlgItemMessage(hwnd,IDC_LSVRECORD,LVM_SETITEM,0,(LPARAM)&lvItem); 
*/