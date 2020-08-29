#ifndef _DIALOG2_H
#define _DIALOG2_H

#include <windows.h>

BOOL WINAPI DIALOG2_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL DIALOG2_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void DIALOG2_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void DIALOG2_OnClose(HWND hwnd);

#endif