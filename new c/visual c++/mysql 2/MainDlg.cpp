#include "stdafx.h"
#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include "MainDlg.h"
#include  <sql.h>
#include  <sqlext.h>
#include <sqltypes.h>
#include <stdlib.h>
#include "DIALOG1.h"
#include "DIALOG2.h"
#include "DIALOG3.h"
//void SaveToDataBaseAdmin(HWND hwnd);//管理员注册函数
//void SaveToDataBaseStudent(HWND hwnd);//学生注册函数
void AdminLogin(HWND hwnd);//管理员登陆函数
void StudentLogin(HWND hwnd);//学生登陆函数
void studentSEARCH(HWND hwnd);

//int GetCheckedRadioButton( int nIDFirstButton, int nIDLastButton );

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
    switch(id)
	{

	case IDC_BUTTONZC:
		   {
			   HINSTANCE hInstance=(HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE);
			  // DialogBoxParam(hIntance,MAKEINTRESOURCE(IDD_DIALOG1),NULL,DIALOG1_Proc,);//给新弹出多窗口传参数
			   DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DIALOG1_Proc);//弹出注册窗口，一开始写的是MAIN_Proc,然后弹出的窗口，点击按钮没反应，又耽误了几个小时。。。。。
			   
		   } 
		   break;


	   case IDC_BUTTONLOGIN:
		   {

			   HWND hwndcheck1=GetDlgItem(hwnd,IDC_RADIO1);
              int checkState1=Button_GetCheck(hwndcheck1);
		if(BST_CHECKED==checkState1)
				
			 AdminLogin(hwnd);//管理员登陆函数


		else
	
		
			 StudentLogin(hwnd);//学生登陆函数
			
		   }
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





void AdminLogin(HWND hwnd)//管理员登陆函数
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


TCHAR inputUserName[20];
GetDlgItemText(hwnd,IDC_EDITUSERNAME,inputUserName,sizeof(inputUserName)/sizeof(TCHAR));

TCHAR inputPassword[20];
GetDlgItemText(hwnd,IDC_EDITPASSWORD,inputPassword,sizeof(inputPassword)/sizeof(TCHAR));

 TCHAR sql[255];
 ZeroMemory(sql,sizeof(sql)/sizeof(TCHAR));
 wsprintf(sql,"SELECT password FROM Aadmin where username='%s'",inputUserName);

result=SQLPrepare(hstmt,(SQLCHAR*)sql,SQL_NTS);



CHECKDBSTMTERROR(hwnd,result,hstmt);

result=SQLExecute(hstmt);//执行SQL 语句

CHECKDBSTMTERROR(hwnd,result,hstmt);


SQLINTEGER cbsatid=SQL_NTS;




//MessageBox(hwnd,inputUserName,TEXT("输入的用户名"),MB_OK);

//MessageBox(hwnd,inputPassword,TEXT("输入的密码"),MB_OK);

BOOL found=FALSE;

while(SQLFetch(hstmt)!=SQL_NO_DATA_FOUND)
{
	//TCHAR userName[20];

//SQLGetData(hstmt,1,SQL_C_CHAR,userName,sizeof(userName)/sizeof(TCHAR),&cbsatid);
//MessageBox(hwnd,userName,TEXT("表中的用户名"),MB_OK);
	
	TCHAR password[20];

	SQLGetData(hstmt,1,SQL_C_CHAR,password,sizeof(password)/sizeof(TCHAR),&cbsatid);
	//MessageBox(hwnd,password,TEXT("表中的的密码"),MB_OK);

	//int a=lstrcmp(inputUserName,userName);
     //TCHAR B[20];//这几句是看看他们比较最后的返回值，哇靠返回是-1，不相等
//	wsprintf(B,"%d",a);
	//	MessageBox(hwnd,B,TEXT("用户名比较返回什么值"),MB_OK);

		
	
	/*if(0==lstrcmp(inputUserName,userName))//因为不相等所以从这一句开始总是一下跳到最下面
			{
				//MessageBox(hwnd,TEXT("用户名相等吗"),TEXT("用户名比较"),MB_OK);*/


				if(0==lstrcmp(inputPassword,password))
					{
      //MessageBox(hwnd,TEXT("密码相等吗"),TEXT("密码比较"),MB_OK);

//MessageBox(hwnd,TEXT("输入正确，登陆成功！"),TEXT("提示"),MB_OK);//////bug终于找到了，通过调试找到的，为什么输入的密码和表中保存的密码不想等呢？因为表中的用户名和密码指定是char(20)位的，而输入的只是简单的几位，通过调试，发现两者差很多
		found=true;	

            HINSTANCE hInstance=(HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE);	 
			DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG2), NULL, DIALOG2_Proc);//注意DIALOG2_Proc是在DIALOG2.CPP中的函数名，而不是第二个对话框的名字IDD_DIALOG2，所以不要加IDD_


	break;
					}
				else 
				
				{
					MessageBox(hwnd,TEXT("密码不正确,请重更新输入"),TEXT(""),MB_OK|MB_ICONERROR);
			break;
				}

}

			if(FALSE==found)
			{

				
							MessageBox(hwnd,TEXT("用户名不存在，请确认后重新输入"),TEXT(""),MB_OK|MB_ICONERROR);
						
			}
SQLFreeStmt(hstmt,SQL_CLOSE);//释放SQL语句
SQLDisconnect(hdbc);//断开数据库连接
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);

}

	

void StudentLogin(HWND hwnd)//学生登陆函数
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


TCHAR inputUserName[20];
GetDlgItemText(hwnd,IDC_EDITUSERNAME,inputUserName,sizeof(inputUserName)/sizeof(TCHAR));

TCHAR inputPassword[20];
GetDlgItemText(hwnd,IDC_EDITPASSWORD,inputPassword,sizeof(inputPassword)/sizeof(TCHAR));


 TCHAR sql[255];
 ZeroMemory(sql,sizeof(sql)/sizeof(TCHAR));
 wsprintf(sql,"SELECT password FROM Stuser where username='%s'",inputUserName);
 

result=SQLPrepare(hstmt,(SQLCHAR*)sql,SQL_NTS);

CHECKDBSTMTERROR(hwnd,result,hstmt);

result=SQLExecute(hstmt);//执行SQL 语句

CHECKDBSTMTERROR(hwnd,result,hstmt);

SQLINTEGER cbsatid=SQL_NTS;



/*TCHAR inputUserName[20];
GetDlgItemText(hwnd,IDC_EDITUSERNAME,inputUserName,sizeof(inputUserName)/sizeof(TCHAR));

TCHAR inputPassword[20];
GetDlgItemText(hwnd,IDC_EDITPASSWORD,inputPassword,sizeof(inputPassword)/sizeof(TCHAR));*/

//MessageBox(hwnd,inputUserName,TEXT("输入的用户名"),MB_OK);

//MessageBox(hwnd,inputPassword,TEXT("输入的密码"),MB_OK);

BOOL found=FALSE;

while(SQLFetch(hstmt)!=SQL_NO_DATA_FOUND)
{
	//TCHAR userName[20];

//SQLGetData(hstmt,1,SQL_C_CHAR,userName,sizeof(userName)/sizeof(TCHAR),&cbsatid);
//MessageBox(hwnd,userName,TEXT("表中的用户名"),MB_OK);
	
	TCHAR password[20];

	SQLGetData(hstmt,1,SQL_C_CHAR,password,sizeof(password)/sizeof(TCHAR),&cbsatid);
	//MessageBox(hwnd,password,TEXT("表中的的密码"),MB_OK);

	//int a=lstrcmp(inputUserName,userName);
     //TCHAR B[20];//这几句是看看他们比较最后的返回值，哇靠返回是-1，不相等
//	wsprintf(B,"%d",a);
	//	MessageBox(hwnd,B,TEXT("用户名比较返回什么值"),MB_OK);

		
	
	//if(0==lstrcmp(inputUserName,userName))//因为不相等所以从这一句开始总是一下跳到最下面
		//	{
				//MessageBox(hwnd,TEXT("用户名相等吗"),TEXT("用户名比较"),MB_OK);


				if(0==lstrcmp(inputPassword,password))
					{
      //MessageBox(hwnd,TEXT("密码相等吗"),TEXT("密码比较"),MB_OK);

//MessageBox(hwnd,TEXT("输入正确，登陆成功！"),TEXT("提示"),MB_OK);//////bug终于找到了，通过调试找到的，为什么输入的密码和表中保存的密码不想等呢？因为表中的用户名和密码指定是char(20)位的，而输入的只是简单的几位，通过调试，发现两者差很多
                   found=true;	

				HINSTANCE hInstance=(HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE);	 
		      	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG3), NULL, DIALOG3_Proc);//注意DIALOG2_Proc是在DIALOG2.CPP中的函数名，而不是第二个对话框的名字IDD_DIALOG2，所以不要加IDD_
		     //	studentSEARCH(hwnd);
                      break;

					}

				else 
				
				{
					MessageBox(hwnd,TEXT("密码不正确,请重更新输入"),TEXT(""),MB_OK|MB_ICONERROR);
					break;
				}

	
}

if(FALSE==found)
{

	
				MessageBox(hwnd,TEXT("用户名不存在，请确认后重新输入"),TEXT(""),MB_OK|MB_ICONERROR);
			
}

SQLFreeStmt(hstmt,SQL_CLOSE);//释放SQL语句
SQLDisconnect(hdbc);//断开数据库连接
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}








































void studentSEARCH1(HWND hwnd)//学生登陆进去后的界面
{

SQLHENV henv=NULL;
SQLHDBC hdbc=NULL;//代表一个数据库连接，要操作数据库，首先要链接到数据库 H (句柄） DB(DateBase) C(Connection)
SQLHSTMT hstmt=NULL;//代表一个SQL语句，STMT(Statement）
SQLRETURN result;//执行结果
SQLCHAR ConnStrIn[MAXBUFLEN]="DRIVER={SQL Server};SERVER=我爱你在心里;UID=sa;PWD=sa;DATABASE=JXGL;CharSet=gbk;";

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


result=SQLPrepare(hstmt,(SQLCHAR*)"SELECT * FROM STUDENT",SQL_NTS);


CHECKDBSTMTERROR(hwnd,result,hstmt);

result=SQLExecute(hstmt);//执行SQL 语句

CHECKDBSTMTERROR(hwnd,result,hstmt);

SQLINTEGER cbsatid=SQL_NTS;

TCHAR sno[20];
TCHAR sname[20];
TCHAR ssex[20];
TCHAR sage[20];
TCHAR sdept[20];
SQLGetData(hstmt,1,SQL_C_CHAR,sno,sizeof(sno)/sizeof(TCHAR),&cbsatid);
SQLGetData(hstmt,2,SQL_C_CHAR,sname,sizeof(sname)/sizeof(TCHAR),&cbsatid);
SQLGetData(hstmt,3,SQL_C_CHAR,ssex,sizeof(ssex)/sizeof(TCHAR),&cbsatid);
SQLGetData(hstmt,4,SQL_C_CHAR,sage,sizeof(sage)/sizeof(TCHAR),&cbsatid);
SQLGetData(hstmt,5,SQL_C_CHAR,sdept,sizeof(sdept)/sizeof(TCHAR),&cbsatid);



LoginData  ld;

ld.sno=sno;
ld.name=sname;
ld.sex=ssex;
ld.age=sage;
ld.sdept=sdept;
HINSTANCE hInstance=(HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE);
DialogBoxParam(hInstance,MAKEINTRESOURCE(IDD_DIALOG3),NULL,DIALOG3_Proc,(LPARAM)&ld);

// hwndCombo1=GetDlgItem(hwnd,IDC_COMBO2);
//ComboBox_AddString(hwndCombo1,sno);


		

SQLFreeStmt(hstmt,SQL_CLOSE);//释放SQL语句
SQLDisconnect(hdbc);//断开数据库连接
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}






void studentSEARCH2(HWND hwnd)//学生登陆进去后的界面
{

SQLHENV henv=NULL;
SQLHDBC hdbc=NULL;//代表一个数据库连接，要操作数据库，首先要链接到数据库 H (句柄） DB(DateBase) C(Connection)
SQLHSTMT hstmt=NULL;//代表一个SQL语句，STMT(Statement）
SQLRETURN result;//执行结果
SQLCHAR ConnStrIn[MAXBUFLEN]="DRIVER={SQL Server};SERVER=我爱你在心里;UID=sa;PWD=sa;DATABASE=JXGL;CharSet=gbk;";

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


result=SQLPrepare(hstmt,(SQLCHAR*)"SELECT * FROM SC",SQL_NTS);


CHECKDBSTMTERROR(hwnd,result,hstmt);

result=SQLExecute(hstmt);//执行SQL 语句

CHECKDBSTMTERROR(hwnd,result,hstmt);

SQLINTEGER cbsatid=SQL_NTS;

TCHAR sno[20];
TCHAR cno[20];
TCHAR grade[20];

SQLGetData(hstmt,1,SQL_C_CHAR,sno,sizeof(sno)/sizeof(TCHAR),&cbsatid);
SQLGetData(hstmt,2,SQL_C_CHAR,cno,sizeof(cno)/sizeof(TCHAR),&cbsatid);
SQLGetData(hstmt,3,SQL_C_CHAR,grade,sizeof(grade)/sizeof(TCHAR),&cbsatid);

LoginData2  ld2;
ld2.sno=sno;
ld2.cno=cno;
ld2.grade=grade;

HINSTANCE hInstance=(HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE);
DialogBoxParam(hInstance,MAKEINTRESOURCE(IDD_DIALOG3),NULL,DIALOG3_Proc,(LPARAM)&ld2);

// hwndCombo1=GetDlgItem(hwnd,IDC_COMBO2);
//ComboBox_AddString(hwndCombo1,sno);


		

SQLFreeStmt(hstmt,SQL_CLOSE);//释放SQL语句
SQLDisconnect(hdbc);//断开数据库连接
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}












void studentSEARCH3(HWND hwnd)//学生登陆进去后的界面
{

SQLHENV henv=NULL;
SQLHDBC hdbc=NULL;//代表一个数据库连接，要操作数据库，首先要链接到数据库 H (句柄） DB(DateBase) C(Connection)
SQLHSTMT hstmt=NULL;//代表一个SQL语句，STMT(Statement）
SQLRETURN result;//执行结果
SQLCHAR ConnStrIn[MAXBUFLEN]="DRIVER={SQL Server};SERVER=我爱你在心里;UID=sa;PWD=sa;DATABASE=JXGL;CharSet=gbk;";

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


result=SQLPrepare(hstmt,(SQLCHAR*)"SELECT * FROM course",SQL_NTS);


CHECKDBSTMTERROR(hwnd,result,hstmt);

result=SQLExecute(hstmt);//执行SQL 语句

CHECKDBSTMTERROR(hwnd,result,hstmt);

SQLINTEGER cbsatid=SQL_NTS;


TCHAR cno[20];
TCHAR cname[20];
TCHAR cpro[20];
TCHAR ccredit[20];//学分吧*/

SQLGetData(hstmt,1,SQL_C_CHAR,cno,sizeof(cno)/sizeof(TCHAR),&cbsatid);
SQLGetData(hstmt,2,SQL_C_CHAR,cname,sizeof(cname)/sizeof(TCHAR),&cbsatid);
SQLGetData(hstmt,3,SQL_C_CHAR,cpro,sizeof(cpro)/sizeof(TCHAR),&cbsatid);
SQLGetData(hstmt,4,SQL_C_CHAR,ccredit,sizeof(ccredit)/sizeof(TCHAR),&cbsatid);

LoginData3  ld3;

ld3.cno=cno;
ld3.cname=cname;
ld3.cpro=cpro;
ld3.ccredit=ccredit;
HINSTANCE hInstance=(HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE);
DialogBoxParam(hInstance,MAKEINTRESOURCE(IDD_DIALOG3),NULL,DIALOG3_Proc,(LPARAM)&ld3);

// hwndCombo1=GetDlgItem(hwnd,IDC_COMBO2);
//ComboBox_AddString(hwndCombo1,sno);


		

SQLFreeStmt(hstmt,SQL_CLOSE);//释放SQL语句
SQLDisconnect(hdbc);//断开数据库连接
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}



