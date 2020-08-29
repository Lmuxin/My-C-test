#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "DIALOG1.h"
#include  <sql.h>
#include  <sqlext.h>
#include <sqltypes.h>
#include<stdlib.h>


void SaveToDataBaseAdmin(HWND hwnd);//管理员注册函数
void SaveToDataBaseStudent(HWND hwnd);//学生注册函数

//首先定义三个宏
#define LOGIN_TIMEOUT 30 //没有这句下面会报错result=SQLSetConnectAttr(hdbc,SQL_LOGIN_TIMEOUT,(void*)LOGIN_TIMEOUT,0);//设置连接属性  ：error C2065: 'LOGIN_TIMEOUT' : undeclared identifier
/*#define LOCAL_TIMEOUT 30 *///原来是我这句写错了，才会有上面设置属性的错误，我爸LOGIN 写成LOCAL 了  ，这个小错误困扰了好几天
#define MAXBUFLEN 255
#define CHECKDBSTMTERROR(hwnd,result,hstmt)\
 if(SQL_ERROR==result)\
{\
DIALOG1ShowDBStmtError(hwnd,hstmt);\
return ;\
}//这么长也是定义的一个宏可以用\换行



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

			if(BST_CHECKED==checkState1 )//第一个复选框被选中

				
				  SaveToDataBaseAdmin(hwnd);//管理员注册函数
				
           /*HWND hwndcheck2=GetDlgItem(hwnd,IDC_RADIO2);
              int checkState2=Button_GetCheck(hwndcheck2);
			  if(BST_CHECKED==checkState2 )*/
			else
			
			
				
				 SaveToDataBaseStudent(hwnd);//学生注册函数
				
		}

        break;
		
    case IDCANCEL:
		{
		MessageBox(hwnd,TEXT("用户取消注册"),TEXT(""),MB_OK);
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



void DIALOG1ShowDBError(HWND hwnd,SQLSMALLINT type,SQLHANDLE sqlHandle)//显示数据库连接错误函数
{
	char pStatus[10],pMsg[101];
	SQLSMALLINT SQLmsglen;
	char error[200]={0};
	SQLINTEGER SQLerr;
	long erg2=SQLGetDiagRec(type,sqlHandle,1,(SQLCHAR *)pStatus,&SQLerr,(SQLCHAR *)pMsg,100,&SQLmsglen);
	wsprintf(error,"%s (%d)\n",pMsg,(int)SQLerr);
	MessageBox(hwnd,error,TEXT("数据库执行错误"),MB_ICONERROR|MB_OK);
}


void DIALOG1ShowDBConnError(HWND hwnd,SQLHDBC hdbc)

{

DIALOG1ShowDBError(hwnd,SQL_HANDLE_DBC,hdbc);

}



void DIALOG1ShowDBStmtError(HWND hwnd,SQLHSTMT hstmt)

{

DIALOG1ShowDBError(hwnd,SQL_HANDLE_STMT,hstmt);

}



 void SaveToDataBaseAdmin(HWND hwnd)//管理员注册函数
{

SQLHENV henv=NULL;
SQLHDBC hdbc=NULL;//代表一个数据库连接，要操作数据库，首先要链接到数据库 H (句柄） DB(DateBase) C(Connection)
SQLHSTMT hstmt=NULL;//代表一个SQL语句，STMT(Statement）
SQLRETURN result;//执行结果
SQLCHAR ConnStrIn[MAXBUFLEN]="DRIVER={SQL Server};SERVER=我爱你在心里;UID=sa;PWD=sa;DATABASE=JXGL;CharSet=gbk;";
//SERVER=我爱你在心里/*（这个就是添加数据源时候写的服务器名字，也是我的电脑的名字）*/
//若SERVER=我爱你在心里或者SERVER=127.0.0.1 报错无法使用sa登陆。若SERVER=local 则又报错[MIicrosoft][ODBC SQL Server Driver][DBNETLIB]SQL Server不存在或访问被拒绝
//其实呢。最终错误很简单，错了已字母，PWD='sa',而不是PWN='sa',一个字母，耽误了好几天时间。
SQLCHAR ConnStrOut[MAXBUFLEN];

result =SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&henv);//分配环境句柄

result=SQLSetEnvAttr(henv,SQL_ATTR_ODBC_VERSION,(void *)SQL_OV_ODBC3,0);//设置管理环境属性

result=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);//分配连接句柄

result=SQLSetConnectAttr(hdbc,SQL_LOGIN_TIMEOUT,(void*)LOGIN_TIMEOUT,0);//设置连接属性

result=SQLDriverConnect(hdbc,NULL,
						ConnStrIn,SQL_NTS,
						ConnStrOut,MAXBUFLEN,
						(SQLSMALLINT *)0,SQL_DRIVER_NOPROMPT);//创建到连接数据库，使用ConnStrIn连接。result表示连接结果，连接失败还是成功
if(SQL_ERROR==result)
{
DIALOG1ShowDBConnError(hwnd,hdbc);
return;
}

result=SQLAllocHandle(SQL_HANDLE_STMT,hdbc,&hstmt);//初始化语句句柄



TCHAR userName[20];
GetDlgItemText(hwnd,IDC_EDIT1,userName,sizeof(userName)/sizeof(TCHAR));

TCHAR password[20];
GetDlgItemText(hwnd,IDC_EDIT2,password,sizeof(password)/sizeof(TCHAR));


TCHAR password2[20];//确认密码编辑框
GetDlgItemText(hwnd,IDC_EDIT3,password2,sizeof(password)/sizeof(TCHAR));
if(0==lstrcmp(password,password2))

	{
			TCHAR sql[255];
		wsprintf(sql,"insert into Aadmin(username,password) values('%s','%s')",userName,password);//数据插入表中


		result=SQLPrepare(hstmt,(SQLCHAR*)sql,SQL_NTS);

CHECKDBSTMTERROR(hwnd,result,hstmt);
result=SQLExecute(hstmt);//执行SQL 语句
CHECKDBSTMTERROR(hwnd,result,hstmt);


		MessageBox(hwnd,TEXT("注册成功啦，快去登陆吧"),TEXT(""),MB_OK);//可以设置保存成功后清空文本框
	}
if(0!=lstrcmp(password,password2))
{

MessageBox(hwnd,TEXT("两次输入密码不相同，请重新确认输入一致"),TEXT(""),MB_OK|MB_ICONERROR);

}




SQLFreeStmt(hstmt,SQL_CLOSE);//释放SQL语句
SQLDisconnect(hdbc);//断开数据库连接
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}






 void SaveToDataBaseStudent(HWND hwnd)//学生注册函数
{

SQLHENV henv=NULL;
SQLHDBC hdbc=NULL;//代表一个数据库连接，要操作数据库，首先要链接到数据库 H (句柄） DB(DateBase) C(Connection)
SQLHSTMT hstmt=NULL;//代表一个SQL语句，STMT(Statement）
SQLRETURN result;//执行结果
SQLCHAR ConnStrIn[MAXBUFLEN]="DRIVER={SQL Server};SERVER=我爱你在心里;UID=sa;PWD=sa;DATABASE=JXGL;CharSet=gbk;";
//SERVER=我爱你在心里/*（这个就是添加数据源时候写的服务器名字，也是我的电脑的名字）*/
//若SERVER=我爱你在心里或者SERVER=127.0.0.1 报错无法使用sa登陆。若SERVER=local 则又报错[MIicrosoft][ODBC SQL Server Driver][DBNETLIB]SQL Server不存在或访问被拒绝
//其实呢。最终错误很简单，错了已字母，PWD='sa',而不是PWN='sa',一个字母，耽误了好几天时间。
SQLCHAR ConnStrOut[MAXBUFLEN];

result =SQLAllocHandle(SQL_HANDLE_ENV,SQL_NULL_HANDLE,&henv);//分配环境句柄

result=SQLSetEnvAttr(henv,SQL_ATTR_ODBC_VERSION,(void *)SQL_OV_ODBC3,0);//设置管理环境属性

result=SQLAllocHandle(SQL_HANDLE_DBC,henv,&hdbc);//分配连接句柄

result=SQLSetConnectAttr(hdbc,SQL_LOGIN_TIMEOUT,(void*)LOGIN_TIMEOUT,0);//设置连接属性

result=SQLDriverConnect(hdbc,NULL,
						ConnStrIn,SQL_NTS,
						ConnStrOut,MAXBUFLEN,
						(SQLSMALLINT *)0,SQL_DRIVER_NOPROMPT);//创建到连接数据库，使用ConnStrIn连接。result表示连接结果，连接失败还是成功
if(SQL_ERROR==result)
{
DIALOG1ShowDBConnError(hwnd,hdbc);
return;
}
result=SQLAllocHandle(SQL_HANDLE_STMT,hdbc,&hstmt);//初始化语句句柄




TCHAR userName[20];
GetDlgItemText(hwnd,IDC_EDIT1,userName,sizeof(userName)/sizeof(TCHAR));

TCHAR password[20];
GetDlgItemText(hwnd,IDC_EDIT2,password,sizeof(password)/sizeof(TCHAR));


TCHAR password2[20];//确认密码编辑框
GetDlgItemText(hwnd,IDC_EDIT3,password2,sizeof(password)/sizeof(TCHAR));
if(0==lstrcmp(password,password2))

	{
			TCHAR sql[255];
		wsprintf(sql,"insert into stuser(username,password) values('%s','%s')",userName,password);//数据插入表中


		result=SQLPrepare(hstmt,(SQLCHAR*)sql,SQL_NTS);


		CHECKDBSTMTERROR(hwnd,result,hstmt);
result=SQLExecute(hstmt);//执行SQL 语句
CHECKDBSTMTERROR(hwnd,result,hstmt);

MessageBox(hwnd,TEXT("注册成功啦，快去登陆吧"),TEXT("结果"),MB_OK);//可以设置保存成功后清空文本框

	}
if(0!=lstrcmp(password,password2))
{

MessageBox(hwnd,TEXT("两次输入密码不相同，请重新确认输入一致"),TEXT(""),MB_OK|MB_ICONERROR);

}


SQLFreeStmt(hstmt,SQL_CLOSE);//释放SQL语句
SQLDisconnect(hdbc);//断开数据库连接
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}



