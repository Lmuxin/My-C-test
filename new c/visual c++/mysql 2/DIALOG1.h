#ifndef _DIALOG1_H
#define _DIALOG1_H

#include <windows.h>

BOOL WINAPI DIALOG1_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL DIALOG1_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void DIALOG1_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void DIALOG1_OnClose(HWND hwnd);

#endif