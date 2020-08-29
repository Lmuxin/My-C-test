#ifndef _LOGINDLG_H
#define _LOGINDLG_H

#include <windows.h>


struct LoginDate
{

TCHAR *username;
TCHAR *password;

};

BOOL WINAPI LoginDlg_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL LoginDlg_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void LoginDlg_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void LoginDlg_OnClose(HWND hwnd);

#endif