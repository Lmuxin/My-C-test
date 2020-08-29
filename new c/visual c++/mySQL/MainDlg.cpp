#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include  <sql.h>
#include  <sqlext.h>
#include <sqltypes.h>

//首先定义三个宏
#define LOGIN_TIMEOUT 30 //没有这句下面会报错result=SQLSetConnectAttr(hdbc,SQL_LOGIN_TIMEOUT,(void*)LOGIN_TIMEOUT,0);//设置连接属性  ：error C2065: 'LOGIN_TIMEOUT' : undeclared identifier
/*#define LOCAL_TIMEOUT 30 *///原来是我这句写错了，才会有上面设置属性的错误，我爸LOGIN 写成LOCAL 了  ，这个小错误困扰了好几天
#define MAXBUFLEN 255
#define CHECKDBSTMTERROR(hwnd,result,hstmt)\
 if(SQL_ERROR==result)\
{\
ShowDBStmtError(hwnd,hstmt);\
return ;\
}//这么长也是定义的一个宏可以用\换行

/*
Template designed by RuPeng.com. Please visit http://www.rupeng.com for more information
如鹏网（http://www.rupeng.com）大学生计算机学习社区，提供大量免费视频学习教程，提供个性化一对一学习指导
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

	void DBTest(HWND hwnd);//虽然下面有定义函数，但是这里要声明一下
    switch(id)
    {
        case IDC_OK:

			DBTest(hwnd);//上面声明后这个才可以调用
			
			break;
        default:
		break;
    }
}


void Main_OnClose(HWND hwnd)
{
    EndDialog(hwnd, 0);
}


void ShowDBError(HWND hwnd,SQLSMALLINT type,SQLHANDLE sqlHandle)//显示数据库连接错误函数
{
	char pStatus[10],pMsg[101];
	SQLSMALLINT SQLmsglen;
	char error[200]={0};
	SQLINTEGER SQLerr;
	long erg2=SQLGetDiagRec(type,sqlHandle,1,(SQLCHAR *)pStatus,&SQLerr,(SQLCHAR *)pMsg,100,&SQLmsglen);
	wsprintf(error,"%s (%d)\n",pMsg,(int)SQLerr);
	MessageBox(hwnd,error,TEXT("数据库执行错误"),MB_ICONERROR|MB_OK);
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
ShowDBConnError(hwnd,hdbc);
return;
}
result=SQLAllocHandle(SQL_HANDLE_STMT,hdbc,&hstmt);//初始化语句句柄
 
//result=SQLPrepare(hstmt,(SQLCHAR*)"insert into student VALUES(96009,'赵刚','F',20,'CS')",SQL_NTS);//创建SQL句柄
result=SQLPrepare(hstmt,(SQLCHAR*)"SELECT Sno,Sname,Sage FROM STUDENT",SQL_NTS);

CHECKDBSTMTERROR(hwnd,result,hstmt);
result=SQLExecute(hstmt);//执行SQL 语句
CHECKDBSTMTERROR(hwnd,result,hstmt);
//处理sql执行后产生的结果的代码

SQLINTEGER cbsatid=SQL_NTS;//需要一行一行读取数据库的内容，叫做游标读取

/*while(SQLFetch(hstmt)!=SQL_NO_DATA_FOUND)//每调用一次SQLFetch函数，就读取一行，直到返回值为SQL_NO_DATA_FOUND时表示读取到最后
{
TCHAR name[20];
	//调用SQLGetData来取得列的内容
SQLGetData(hstmt,2,SQL_C_CHAR,name,sizeof(name)/sizeof(TCHAR),&cbsatid);//第个参数代表SQL语句的hstmt,第二个参数是要读取到列的序号（从1开始），第三个参数是列的类型，在SQLExt,h中所有以为SQL-C_开头的都可以选择。第四个参数是要接受的值的指针。第五个是指针指向缓冲区的大小。第六个。。。不管他
MessageBox(hwnd,name,TEXT(""),MB_OK);
}*/




while(SQLFetch(hstmt)!=SQL_NO_DATA_FOUND)
{

	TCHAR name[20];

SQLGetData(hstmt,2,SQL_C_CHAR,name,sizeof(name)/sizeof(TCHAR),&cbsatid);

SQLINTEGER i;
SQLGetData(hstmt,3,SQL_C_LONG,&i,sizeof(i),&cbsatid);//他们这两个读取数据不是从数据库里表里读取出来的，是从上面select 执行的结果里都出来的。上面select执行结果，Sage是第三列，所以SQLGetData函数中第3个参数是3，而不是JXGL数据库里的第四列


/*TCHAR name[20];
SQLGetData(hstmt,2,SQL_C_CHAR,name,sizeof(name)/sizeof(TCHAR),&cbsatid);*///尼玛这两句和上面那两句有什么区别，为什么放这里运行就出错，放在前面就正常，fuck




TCHAR s[20];
wsprintf(s,TEXT("%s年龄是：%d"),name,i);

MessageBox(hwnd,s,TEXT(""),MB_OK);
}


SQLFreeStmt(hstmt,SQL_CLOSE);//释放SQL语句
SQLDisconnect(hdbc);//断开数据库连接
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);
MessageBox(hwnd,TEXT("执行成功"),TEXT("结果"),MB_OK);

}