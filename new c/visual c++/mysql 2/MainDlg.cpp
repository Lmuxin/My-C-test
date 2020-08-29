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
//void SaveToDataBaseAdmin(HWND hwnd);//����Աע�ắ��
//void SaveToDataBaseStudent(HWND hwnd);//ѧ��ע�ắ��
void AdminLogin(HWND hwnd);//����Ա��½����
void StudentLogin(HWND hwnd);//ѧ����½����
void studentSEARCH(HWND hwnd);

//int GetCheckedRadioButton( int nIDFirstButton, int nIDLastButton );

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
			  // DialogBoxParam(hIntance,MAKEINTRESOURCE(IDD_DIALOG1),NULL,DIALOG1_Proc,);//���µ����ര�ڴ�����
			   DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DIALOG1_Proc);//����ע�ᴰ�ڣ�һ��ʼд����MAIN_Proc,Ȼ�󵯳��Ĵ��ڣ������ťû��Ӧ���ֵ����˼���Сʱ����������
			   
		   } 
		   break;


	   case IDC_BUTTONLOGIN:
		   {

			   HWND hwndcheck1=GetDlgItem(hwnd,IDC_RADIO1);
              int checkState1=Button_GetCheck(hwndcheck1);
		if(BST_CHECKED==checkState1)
				
			 AdminLogin(hwnd);//����Ա��½����


		else
	
		
			 StudentLogin(hwnd);//ѧ����½����
			
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





void AdminLogin(HWND hwnd)//����Ա��½����
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


TCHAR inputUserName[20];
GetDlgItemText(hwnd,IDC_EDITUSERNAME,inputUserName,sizeof(inputUserName)/sizeof(TCHAR));

TCHAR inputPassword[20];
GetDlgItemText(hwnd,IDC_EDITPASSWORD,inputPassword,sizeof(inputPassword)/sizeof(TCHAR));

 TCHAR sql[255];
 ZeroMemory(sql,sizeof(sql)/sizeof(TCHAR));
 wsprintf(sql,"SELECT password FROM Aadmin where username='%s'",inputUserName);

result=SQLPrepare(hstmt,(SQLCHAR*)sql,SQL_NTS);



CHECKDBSTMTERROR(hwnd,result,hstmt);

result=SQLExecute(hstmt);//ִ��SQL ���

CHECKDBSTMTERROR(hwnd,result,hstmt);


SQLINTEGER cbsatid=SQL_NTS;




//MessageBox(hwnd,inputUserName,TEXT("������û���"),MB_OK);

//MessageBox(hwnd,inputPassword,TEXT("���������"),MB_OK);

BOOL found=FALSE;

while(SQLFetch(hstmt)!=SQL_NO_DATA_FOUND)
{
	//TCHAR userName[20];

//SQLGetData(hstmt,1,SQL_C_CHAR,userName,sizeof(userName)/sizeof(TCHAR),&cbsatid);
//MessageBox(hwnd,userName,TEXT("���е��û���"),MB_OK);
	
	TCHAR password[20];

	SQLGetData(hstmt,1,SQL_C_CHAR,password,sizeof(password)/sizeof(TCHAR),&cbsatid);
	//MessageBox(hwnd,password,TEXT("���еĵ�����"),MB_OK);

	//int a=lstrcmp(inputUserName,userName);
     //TCHAR B[20];//�⼸���ǿ������ǱȽ����ķ���ֵ���ۿ�������-1�������
//	wsprintf(B,"%d",a);
	//	MessageBox(hwnd,B,TEXT("�û����ȽϷ���ʲôֵ"),MB_OK);

		
	
	/*if(0==lstrcmp(inputUserName,userName))//��Ϊ��������Դ���һ�俪ʼ����һ������������
			{
				//MessageBox(hwnd,TEXT("�û��������"),TEXT("�û����Ƚ�"),MB_OK);*/


				if(0==lstrcmp(inputPassword,password))
					{
      //MessageBox(hwnd,TEXT("���������"),TEXT("����Ƚ�"),MB_OK);

//MessageBox(hwnd,TEXT("������ȷ����½�ɹ���"),TEXT("��ʾ"),MB_OK);//////bug�����ҵ��ˣ�ͨ�������ҵ��ģ�Ϊʲô���������ͱ��б�������벻����أ���Ϊ���е��û���������ָ����char(20)λ�ģ��������ֻ�Ǽ򵥵ļ�λ��ͨ�����ԣ��������߲�ܶ�
		found=true;	

            HINSTANCE hInstance=(HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE);	 
			DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG2), NULL, DIALOG2_Proc);//ע��DIALOG2_Proc����DIALOG2.CPP�еĺ������������ǵڶ����Ի��������IDD_DIALOG2�����Բ�Ҫ��IDD_


	break;
					}
				else 
				
				{
					MessageBox(hwnd,TEXT("���벻��ȷ,���ظ�������"),TEXT(""),MB_OK|MB_ICONERROR);
			break;
				}

}

			if(FALSE==found)
			{

				
							MessageBox(hwnd,TEXT("�û��������ڣ���ȷ�Ϻ���������"),TEXT(""),MB_OK|MB_ICONERROR);
						
			}
SQLFreeStmt(hstmt,SQL_CLOSE);//�ͷ�SQL���
SQLDisconnect(hdbc);//�Ͽ����ݿ�����
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);

}

	

void StudentLogin(HWND hwnd)//ѧ����½����
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


TCHAR inputUserName[20];
GetDlgItemText(hwnd,IDC_EDITUSERNAME,inputUserName,sizeof(inputUserName)/sizeof(TCHAR));

TCHAR inputPassword[20];
GetDlgItemText(hwnd,IDC_EDITPASSWORD,inputPassword,sizeof(inputPassword)/sizeof(TCHAR));


 TCHAR sql[255];
 ZeroMemory(sql,sizeof(sql)/sizeof(TCHAR));
 wsprintf(sql,"SELECT password FROM Stuser where username='%s'",inputUserName);
 

result=SQLPrepare(hstmt,(SQLCHAR*)sql,SQL_NTS);

CHECKDBSTMTERROR(hwnd,result,hstmt);

result=SQLExecute(hstmt);//ִ��SQL ���

CHECKDBSTMTERROR(hwnd,result,hstmt);

SQLINTEGER cbsatid=SQL_NTS;



/*TCHAR inputUserName[20];
GetDlgItemText(hwnd,IDC_EDITUSERNAME,inputUserName,sizeof(inputUserName)/sizeof(TCHAR));

TCHAR inputPassword[20];
GetDlgItemText(hwnd,IDC_EDITPASSWORD,inputPassword,sizeof(inputPassword)/sizeof(TCHAR));*/

//MessageBox(hwnd,inputUserName,TEXT("������û���"),MB_OK);

//MessageBox(hwnd,inputPassword,TEXT("���������"),MB_OK);

BOOL found=FALSE;

while(SQLFetch(hstmt)!=SQL_NO_DATA_FOUND)
{
	//TCHAR userName[20];

//SQLGetData(hstmt,1,SQL_C_CHAR,userName,sizeof(userName)/sizeof(TCHAR),&cbsatid);
//MessageBox(hwnd,userName,TEXT("���е��û���"),MB_OK);
	
	TCHAR password[20];

	SQLGetData(hstmt,1,SQL_C_CHAR,password,sizeof(password)/sizeof(TCHAR),&cbsatid);
	//MessageBox(hwnd,password,TEXT("���еĵ�����"),MB_OK);

	//int a=lstrcmp(inputUserName,userName);
     //TCHAR B[20];//�⼸���ǿ������ǱȽ����ķ���ֵ���ۿ�������-1�������
//	wsprintf(B,"%d",a);
	//	MessageBox(hwnd,B,TEXT("�û����ȽϷ���ʲôֵ"),MB_OK);

		
	
	//if(0==lstrcmp(inputUserName,userName))//��Ϊ��������Դ���һ�俪ʼ����һ������������
		//	{
				//MessageBox(hwnd,TEXT("�û��������"),TEXT("�û����Ƚ�"),MB_OK);


				if(0==lstrcmp(inputPassword,password))
					{
      //MessageBox(hwnd,TEXT("���������"),TEXT("����Ƚ�"),MB_OK);

//MessageBox(hwnd,TEXT("������ȷ����½�ɹ���"),TEXT("��ʾ"),MB_OK);//////bug�����ҵ��ˣ�ͨ�������ҵ��ģ�Ϊʲô���������ͱ��б�������벻����أ���Ϊ���е��û���������ָ����char(20)λ�ģ��������ֻ�Ǽ򵥵ļ�λ��ͨ�����ԣ��������߲�ܶ�
                   found=true;	

				HINSTANCE hInstance=(HINSTANCE)GetWindowLong(hwnd,GWL_HINSTANCE);	 
		      	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG3), NULL, DIALOG3_Proc);//ע��DIALOG2_Proc����DIALOG2.CPP�еĺ������������ǵڶ����Ի��������IDD_DIALOG2�����Բ�Ҫ��IDD_
		     //	studentSEARCH(hwnd);
                      break;

					}

				else 
				
				{
					MessageBox(hwnd,TEXT("���벻��ȷ,���ظ�������"),TEXT(""),MB_OK|MB_ICONERROR);
					break;
				}

	
}

if(FALSE==found)
{

	
				MessageBox(hwnd,TEXT("�û��������ڣ���ȷ�Ϻ���������"),TEXT(""),MB_OK|MB_ICONERROR);
			
}

SQLFreeStmt(hstmt,SQL_CLOSE);//�ͷ�SQL���
SQLDisconnect(hdbc);//�Ͽ����ݿ�����
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}








































void studentSEARCH1(HWND hwnd)//ѧ����½��ȥ��Ľ���
{

SQLHENV henv=NULL;
SQLHDBC hdbc=NULL;//����һ�����ݿ����ӣ�Ҫ�������ݿ⣬����Ҫ���ӵ����ݿ� H (����� DB(DateBase) C(Connection)
SQLHSTMT hstmt=NULL;//����һ��SQL��䣬STMT(Statement��
SQLRETURN result;//ִ�н��
SQLCHAR ConnStrIn[MAXBUFLEN]="DRIVER={SQL Server};SERVER=�Ұ���������;UID=sa;PWD=sa;DATABASE=JXGL;CharSet=gbk;";

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


result=SQLPrepare(hstmt,(SQLCHAR*)"SELECT * FROM STUDENT",SQL_NTS);


CHECKDBSTMTERROR(hwnd,result,hstmt);

result=SQLExecute(hstmt);//ִ��SQL ���

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


		

SQLFreeStmt(hstmt,SQL_CLOSE);//�ͷ�SQL���
SQLDisconnect(hdbc);//�Ͽ����ݿ�����
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}






void studentSEARCH2(HWND hwnd)//ѧ����½��ȥ��Ľ���
{

SQLHENV henv=NULL;
SQLHDBC hdbc=NULL;//����һ�����ݿ����ӣ�Ҫ�������ݿ⣬����Ҫ���ӵ����ݿ� H (����� DB(DateBase) C(Connection)
SQLHSTMT hstmt=NULL;//����һ��SQL��䣬STMT(Statement��
SQLRETURN result;//ִ�н��
SQLCHAR ConnStrIn[MAXBUFLEN]="DRIVER={SQL Server};SERVER=�Ұ���������;UID=sa;PWD=sa;DATABASE=JXGL;CharSet=gbk;";

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


result=SQLPrepare(hstmt,(SQLCHAR*)"SELECT * FROM SC",SQL_NTS);


CHECKDBSTMTERROR(hwnd,result,hstmt);

result=SQLExecute(hstmt);//ִ��SQL ���

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


		

SQLFreeStmt(hstmt,SQL_CLOSE);//�ͷ�SQL���
SQLDisconnect(hdbc);//�Ͽ����ݿ�����
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}












void studentSEARCH3(HWND hwnd)//ѧ����½��ȥ��Ľ���
{

SQLHENV henv=NULL;
SQLHDBC hdbc=NULL;//����һ�����ݿ����ӣ�Ҫ�������ݿ⣬����Ҫ���ӵ����ݿ� H (����� DB(DateBase) C(Connection)
SQLHSTMT hstmt=NULL;//����һ��SQL��䣬STMT(Statement��
SQLRETURN result;//ִ�н��
SQLCHAR ConnStrIn[MAXBUFLEN]="DRIVER={SQL Server};SERVER=�Ұ���������;UID=sa;PWD=sa;DATABASE=JXGL;CharSet=gbk;";

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


result=SQLPrepare(hstmt,(SQLCHAR*)"SELECT * FROM course",SQL_NTS);


CHECKDBSTMTERROR(hwnd,result,hstmt);

result=SQLExecute(hstmt);//ִ��SQL ���

CHECKDBSTMTERROR(hwnd,result,hstmt);

SQLINTEGER cbsatid=SQL_NTS;


TCHAR cno[20];
TCHAR cname[20];
TCHAR cpro[20];
TCHAR ccredit[20];//ѧ�ְ�*/

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


		

SQLFreeStmt(hstmt,SQL_CLOSE);//�ͷ�SQL���
SQLDisconnect(hdbc);//�Ͽ����ݿ�����
SQLFreeHandle(SQL_HANDLE_DBC,hdbc);
SQLFreeHandle(SQL_HANDLE_ENV,henv);


}



