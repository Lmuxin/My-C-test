#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include  <sql.h>
#include  <sqlext.h>
#include <sqltypes.h>

//���ȶ���������
#define LOGIN_TIMEOUT 30 //û���������ᱨ��result=SQLSetConnectAttr(hdbc,SQL_LOGIN_TIMEOUT,(void*)LOGIN_TIMEOUT,0);//������������  ��error C2065: 'LOGIN_TIMEOUT' : undeclared identifier
/*#define LOCAL_TIMEOUT 30 *///ԭ���������д���ˣ��Ż��������������ԵĴ����Ұ�LOGIN д��LOCAL ��  �����С���������˺ü���
#define MAXBUFLEN 255
#define CHECKDBSTMTERROR(hwnd,result,hstmt)\
 if(SQL_ERROR==result)\
{\
ShowDBStmtError(hwnd,hstmt);\
return ;\
}//��ô��Ҳ�Ƕ����һ���������\����

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

	void DBTest(HWND hwnd);//��Ȼ�����ж��庯������������Ҫ����һ��
    switch(id)
    {
        case IDC_OK:

			DBTest(hwnd);//��������������ſ��Ե���
			
			break;
        default:
		break;
    }
}


void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}


void ShowDBError(HWND hwnd,SQLSMALLINT type,SQLHANDLE sqlHandle)//��ʾ���ݿ����Ӵ�����
{
	char pStatus[10],pMsg[101];
	SQLSMALLINT SQLmsglen;
	char error[200]={0};
	SQLINTEGER SQLerr;
	long erg2=SQLGetDiagRec(type,sqlHandle,1,(SQLCHAR *)pStatus,&SQLerr,(SQLCHAR *)pMsg,100,&SQLmsglen);
	wsprintf(error,"%s (%d)\n",pMsg,(int)SQLerr);
	MessageBox(hwnd,error,TEXT("���ݿ�ִ�д���"),MB_ICONERROR|MB_OK);
}



void ShowDBConnError(HWND hwnd,SQLHDBC hdbc)

{

ShowDBError(hwnd,SQL_HANDLE_DBC,hdbc);

}


void ShowDBStmtError(HWND hwnd,SQLHSTMT hstmt)

{

ShowDBError(hwnd,SQL_HANDLE_STMT,hstmt);

}

void DBTest(HWND hwnd)
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
ShowDBConnError(hwnd,hdbc);
return;
}
result=SQLAllocHandle(SQL_HANDLE_STMT,hdbc,&hstmt);//��ʼ�������
 
//result=SQLPrepare(hstmt,(SQLCHAR*)"insert into student VALUES(96009,'�Ը�','F',20,'CS')",SQL_NTS);//����SQL���
result=SQLPrepare(hstmt,(SQLCHAR*)"SELECT Sno,Sname,Sage FROM STUDENT",SQL_NTS);

CHECKDBSTMTERROR(hwnd,result,hstmt);
result=SQLExecute(hstmt);//ִ��SQL ���
CHECKDBSTMTERROR(hwnd,result,hstmt);
//����sqlִ�к�����Ľ���Ĵ���

SQLINTEGER cbsatid=SQL_NTS;//��Ҫһ��һ�ж�ȡ���ݿ�����ݣ������α��ȡ

/*while(SQLFetch(hstmt)!=SQL_NO_DATA_FOUND)//ÿ����һ��SQLFetch�������Ͷ�ȡһ�У�ֱ������ֵΪSQL_NO_DATA_FOUNDʱ��ʾ��ȡ�����
{
TCHAR name[20];
	//����SQLGetData��ȡ���е�����
SQLGetData(hstmt,2,SQL_C_CHAR,name,sizeof(name)/sizeof(TCHAR),&cbsatid);//�ڸ���������SQL����hstmt,�ڶ���������Ҫ��ȡ���е���ţ���1��ʼ�����������������е����ͣ���SQLExt,h��������ΪSQL-C_��ͷ�Ķ�����ѡ�񡣵��ĸ�������Ҫ���ܵ�ֵ��ָ�롣�������ָ��ָ�򻺳����Ĵ�С��������������������
MessageBox(hwnd,name,TEXT(""),MB_OK);
}*/




while(SQLFetch(hstmt)!=SQL_NO_DATA_FOUND)
{

	TCHAR name[20];

SQLGetData(hstmt,2,SQL_C_CHAR,name,sizeof(name)/sizeof(TCHAR),&cbsatid);

SQLINTEGER i;
SQLGetData(hstmt,3,SQL_C_LONG,&i,sizeof(i),&cbsatid);//������������ȡ���ݲ��Ǵ����ݿ�������ȡ�����ģ��Ǵ�����select ִ�еĽ���ﶼ�����ġ�����selectִ�н����Sage�ǵ����У�����SQLGetData�����е�3��������3��������JXGL���ݿ���ĵ�����


/*TCHAR name[20];
SQLGetData(hstmt,2,SQL_C_CHAR,name,sizeof(name)/sizeof(TCHAR),&cbsatid);*///�����������������������ʲô����Ϊʲô���������оͳ�������ǰ���������fuck




TCHAR s[20];
wsprintf(s,TEXT("%s�����ǣ�%d"),name,i);

MessageBox(hwnd,s,TEXT(""),MB_OK);
}


SQLFreeStmt(hstmt,SQL_CLOSE);//�ͷ�SQL���
SQLDisconnect(hdbc);//�Ͽ����ݿ�����
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);
MessageBox(hwnd,TEXT("ִ�гɹ�"),TEXT("���"),MB_OK);

}