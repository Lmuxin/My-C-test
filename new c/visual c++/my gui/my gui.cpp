// my gui.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
int a=MessageBox(NULL,TEXT("���Ǻ�����?"),TEXT("ѯ��"),MB_YESNO|MB_ICONQUESTION);
if(a==IDYES)
{

int b=MessageBox(NULL,TEXT("һ����Ͳ��Ǻ���"),TEXT("�ظ�"),MB_OK|MB_ICONEXCLAMATION);


if(b==IDOK)
{
	MessageBox(NULL,TEXT("��ʽ��c��"),TEXT("����"),MB_OK);

}

}

else
{

	MessageBox(NULL,TEXT("���԰����ɺ���"),TEXT("Ӧ��"),MB_RETRYCANCEL);
}

return 0;
}



