#ifndef _DIALOG3_H
#define _DIALOG3_H

#include <windows.h>


struct  LoginData//学生信息结构体

{

TCHAR   *sno;
TCHAR   *name;
TCHAR   *sex;
TCHAR   *age;
TCHAR   *sdept;

};


struct  LoginData2//选课信息结构体

{

TCHAR   *sno;
TCHAR   *cno;
TCHAR   *grade;

};



struct  LoginData3//课程信息结构体

{

TCHAR   *cno;
TCHAR   *cname;
TCHAR   *cpro;
TCHAR   *ccredit;

};


BOOL WINAPI DIALOG3_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
BOOL DIALOG3_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
void DIALOG3_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
void DIALOG3_OnClose(HWND hwnd);

#endif