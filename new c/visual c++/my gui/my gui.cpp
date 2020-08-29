// my gui.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
int a=MessageBox(NULL,TEXT("你是好人吗?"),TEXT("询问"),MB_YESNO|MB_ICONQUESTION);
if(a==IDYES)
{

int b=MessageBox(NULL,TEXT("一看你就不是好人"),TEXT("回复"),MB_OK|MB_ICONEXCLAMATION);


if(b==IDOK)
{
	MessageBox(NULL,TEXT("格式化c盘"),TEXT("坏蛋"),MB_OK);

}

}

else
{

	MessageBox(NULL,TEXT("尝试把你变成好人"),TEXT("应答"),MB_RETRYCANCEL);
}

return 0;
}



