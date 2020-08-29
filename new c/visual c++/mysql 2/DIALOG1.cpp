#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "DIALOG1.h"
#include  <sql.h>
#include  <sqlext.h>
#include <sqltypes.h>
#include<stdlib.h>


void SaveToDataBaseAdmin(HWND hwnd);//����Աע�ắ��
void SaveToDataBaseStudent(HWND hwnd);//ѧ��ע�ắ��

//���ȶ���������
#define LOGIN_TIMEOUT 30 //û���������ᱨ��result=SQLSetConnectAttr(hdbc,SQL_LOGIN_TIMEOUT,(void*)LOGIN_TIMEOUT,0);//������������  ��error C2065: 'LOGIN_TIMEOUT' : undeclared identifier
/*#define LOCAL_TIMEOUT 30 *///ԭ���������д���ˣ��Ż��������������ԵĴ����Ұ�LOGIN д��LOCAL ��  �����С���������˺ü���
#define MAXBUFLEN 255
#define CHECKDBSTMTERROR(hwnd,result,hstmt)\
 if(SQL_ERROR==result)\
{\
DIALOG1ShowDBStmtError(hwnd,hstmt);\
return ;\
}//��ô��Ҳ�Ƕ����һ���������\����



BOOL WINAPI DIALOG1_Proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
        HANDLE_MSG(hWnd, WM_INITDIALOG, DIALOG1_OnInitDialog);
        HANDLE_MSG(hWnd, WM_COMMAND, DIALOG1_OnCommand);
		HANDLE_MSG(hWnd,WM_CLOSE, DIALOG1_OnClose);
    }

    return FALSE;
}

BOOL DIALOG1_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{
    return TRUE;
}

void DIALOG1_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{
    switch(id)
    {
        case IDZC:
		{
			HWND hwndcheck1=GetDlgItem(hwnd,IDC_RADIO2);
              int checkState1=Button_GetCheck(hwndcheck1);

			if(BST_CHECKED==checkState1 )//��һ����ѡ��ѡ��

				
				  SaveToDataBaseAdmin(hwnd);//����Աע�ắ��
				
           /*HWND hwndcheck2=GetDlgItem(hwnd,IDC_RADIO2);
              int checkState2=Button_GetCheck(hwndcheck2);
			  if(BST_CHECKED==checkState2 )*/
			else
			
			
				
				 SaveToDataBaseStudent(hwnd);//ѧ��ע�ắ��
				
		}

        break;
		
    case IDCANCEL:
		{
		MessageBox(hwnd,TEXT("�û�ȡ��ע��"),TEXT(""),MB_OK);
          EndDialog(hwnd, 0);
		}
		break;
	case	IDC_BUTTON1:
		{
			 EndDialog(hwnd, 0);
		}
		break;
        default:
		break;
    }
}

void DIALOG1_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}



void DIALOG1ShowDBError(HWND hwnd,SQLSMALLINT type,SQLHANDLE sqlHandle)//��ʾ���ݿ����Ӵ�����
{
	char pStatus[10],pMsg[101];
	SQLSMALLINT SQLmsglen;
	char error[200]={0};
	SQLINTEGER SQLerr;
	long erg2=SQLGetDiagRec(type,sqlHandle,1,(SQLCHAR *)pStatus,&SQLerr,(SQLCHAR *)pMsg,100,&SQLmsglen);
	wsprintf(error,"%s (%d)\n",pMsg,(int)SQLerr);
	MessageBox(hwnd,error,TEXT("���ݿ�ִ�д���"),MB_ICONERROR|MB_OK);
}


void DIALOG1ShowDBConnError(HWND hwnd,SQLHDBC hdbc)

{

DIALOG1ShowDBError(hwnd,SQL_HANDLE_DBC,hdbc);

}



void DIALOG1ShowDBStmtError(HWND hwnd,SQLHSTMT hstmt)

{

DIALOG1ShowDBError(hwnd,SQL_HANDLE_STMT,hstmt);

}



 void SaveToDataBaseAdmin(HWND hwnd)//����Աע�ắ��
{

SQLHENV henv=NULL;
SQLHDBC hdbc=NULL;//����һ�����ݿ����ӣ�Ҫ�������ݿ⣬����Ҫ���ӵ����ݿ� H (����� DB(DateBase) C(Connection)
SQLHSTMT hstmt=NULL;//����һ��SQL��䣬STMT(Statement��
SQLRETURN result;//ִ�н��
SQLCHAR ConnStrIn[MAXBUFLEN]="DRIVER={SQL Server};SERVER=�Ұ���������;UID=sa;PWD=sa;DATABASE=JXGL;CharSet=gbk;";
//SERVER=�Ұ���������/*����������������Դʱ��д�ķ��������֣�Ҳ���ҵĵ��Ե����֣�*/
//��SERVER=�Ұ������������SERVER=127.0.0.1 �����޷�ʹ��sa��½����SERVER=local ���ֱ���[MIicrosoft][ODBC SQL Server Driver][DBNETLIB]SQL Server�����ڻ���ʱ��ܾ�
//��ʵ�ء����մ���ܼ򵥣���������ĸ��PWD='sa',������PWN='sa',һ����ĸ�������˺ü���ʱ�䡣
SQLCHAR ConnStrOut[MAXBUFLEN];

result =SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&henv);//���价�����

result=SQLSetEnvAttr(henv,SQL_ATTR_ODBC_VERSION,(void *)SQL_OV_ODBC3,0);//���ù���������

result=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);//�������Ӿ��

result=SQLSetConnectAttr(hdbc,SQL_LOGIN_TIMEOUT,(void*)LOGIN_TIMEOUT,0);//������������

result=SQLDriverConnect(hdbc,NULL,
						ConnStrIn,SQL_NTS,
						ConnStrOut,MAXBUFLEN,
						(SQLSMALLINT *)0,SQL_DRIVER_NOPROMPT);//�������������ݿ⣬ʹ��ConnStrIn���ӡ�result��ʾ���ӽ��������ʧ�ܻ��ǳɹ�
if(SQL_ERROR==result)
{
DIALOG1ShowDBConnError(hwnd,hdbc);
return;
}

result=SQLAllocHandle(SQL_HANDLE_STMT,hdbc,&hstmt);//��ʼ�������



TCHAR userName[20];
GetDlgItemText(hwnd,IDC_EDIT1,userName,sizeof(userName)/sizeof(TCHAR));

TCHAR password[20];
GetDlgItemText(hwnd,IDC_EDIT2,password,sizeof(password)/sizeof(TCHAR));


TCHAR password2[20];//ȷ������༭��
GetDlgItemText(hwnd,IDC_EDIT3,password2,sizeof(password)/sizeof(TCHAR));
if(0==lstrcmp(password,password2))

	{
			TCHAR sql[255];
		wsprintf(sql,"insert into Aadmin(username,password) values('%s','%s')",userName,password);//���ݲ������


		result=SQLPrepare(hstmt,(SQLCHAR*)sql,SQL_NTS);

CHECKDBSTMTERROR(hwnd,result,hstmt);
result=SQLExecute(hstmt);//ִ��SQL ���
CHECKDBSTMTERROR(hwnd,result,hstmt);


		MessageBox(hwnd,TEXT("ע��ɹ�������ȥ��½��"),TEXT(""),MB_OK);//�������ñ���ɹ�������ı���
	}
if(0!=lstrcmp(password,password2))
{

MessageBox(hwnd,TEXT("�����������벻��ͬ��������ȷ������һ��"),TEXT(""),MB_OK|MB_ICONERROR);

}




SQLFreeStmt(hstmt,SQL_CLOSE);//�ͷ�SQL���
SQLDisconnect(hdbc);//�Ͽ����ݿ�����
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}






 void SaveToDataBaseStudent(HWND hwnd)//ѧ��ע�ắ��
{

SQLHENV henv=NULL;
SQLHDBC hdbc=NULL;//����һ�����ݿ����ӣ�Ҫ�������ݿ⣬����Ҫ���ӵ����ݿ� H (����� DB(DateBase) C(Connection)
SQLHSTMT hstmt=NULL;//����һ��SQL��䣬STMT(Statement��
SQLRETURN result;//ִ�н��
SQLCHAR ConnStrIn[MAXBUFLEN]="DRIVER={SQL Server};SERVER=�Ұ���������;UID=sa;PWD=sa;DATABASE=JXGL;CharSet=gbk;";
//SERVER=�Ұ���������/*����������������Դʱ��д�ķ��������֣�Ҳ���ҵĵ��Ե����֣�*/
//��SERVER=�Ұ������������SERVER=127.0.0.1 �����޷�ʹ��sa��½����SERVER=local ���ֱ���[MIicrosoft][ODBC SQL Server Driver][DBNETLIB]SQL Server�����ڻ���ʱ��ܾ�
//��ʵ�ء����մ���ܼ򵥣���������ĸ��PWD='sa',������PWN='sa',һ����ĸ�������˺ü���ʱ�䡣
SQLCHAR ConnStrOut[MAXBUFLEN];

result =SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&henv);//���价�����

result=SQLSetEnvAttr(henv,SQL_ATTR_ODBC_VERSION,(void *)SQL_OV_ODBC3,0);//���ù���������

result=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);//�������Ӿ��

result=SQLSetConnectAttr(hdbc,SQL_LOGIN_TIMEOUT,(void*)LOGIN_TIMEOUT,0);//������������

result=SQLDriverConnect(hdbc,NULL,
						ConnStrIn,SQL_NTS,
						ConnStrOut,MAXBUFLEN,
						(SQLSMALLINT *)0,SQL_DRIVER_NOPROMPT);//�������������ݿ⣬ʹ��ConnStrIn���ӡ�result��ʾ���ӽ��������ʧ�ܻ��ǳɹ�
if(SQL_ERROR==result)
{
DIALOG1ShowDBConnError(hwnd,hdbc);
return;
}
result=SQLAllocHandle(SQL_HANDLE_STMT,hdbc,&hstmt);//��ʼ�������




TCHAR userName[20];
GetDlgItemText(hwnd,IDC_EDIT1,userName,sizeof(userName)/sizeof(TCHAR));

TCHAR password[20];
GetDlgItemText(hwnd,IDC_EDIT2,password,sizeof(password)/sizeof(TCHAR));


TCHAR password2[20];//ȷ������༭��
GetDlgItemText(hwnd,IDC_EDIT3,password2,sizeof(password)/sizeof(TCHAR));
if(0==lstrcmp(password,password2))

	{
			TCHAR sql[255];
		wsprintf(sql,"insert into stuser(username,password) values('%s','%s')",userName,password);//���ݲ������


		result=SQLPrepare(hstmt,(SQLCHAR*)sql,SQL_NTS);


		CHECKDBSTMTERROR(hwnd,result,hstmt);
result=SQLExecute(hstmt);//ִ��SQL ���
CHECKDBSTMTERROR(hwnd,result,hstmt);

MessageBox(hwnd,TEXT("ע��ɹ�������ȥ��½��"),TEXT("���"),MB_OK);//�������ñ���ɹ�������ı���

	}
if(0!=lstrcmp(password,password2))
{

MessageBox(hwnd,TEXT("�����������벻��ͬ��������ȷ������һ��"),TEXT(""),MB_OK|MB_ICONERROR);

}


SQLFreeStmt(hstmt,SQL_CLOSE);//�ͷ�SQL���
SQLDisconnect(hdbc);//�Ͽ����ݿ�����
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}



