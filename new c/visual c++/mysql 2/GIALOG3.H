#ifndef _GIALOG3_H
#define _GIALOG3_H

#include <windows.h>

BOOL WINAPI DIALOG3_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL GIALOG3_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void GIALOG3_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void GIALOG3_OnClose(HWND hwnd);

#endif