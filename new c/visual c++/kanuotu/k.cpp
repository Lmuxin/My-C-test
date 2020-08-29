#include <stdafx.h>
#include <iostream>
#include <cmath>
#include "vector.h"
int   a[16];//用来存放16个数
int   visited[16];//化简过程中是否被用过

void  init_zero()//初始化为0
{
for(int i=0;i<16;i++)
{a[i]=0;//没有输入时全为0
visited[i]=0;//没有化简，没有被访问
}
}

void   print()//打印卡诺图，更加4x4卡诺图的规则输出
{
cout<<"\t\t**************************************\n";
cout<<"\t\t\t"<<a[0]<<"   "<<a[1]<<"   "<<a[3]<<"   "<<a[2]<<"\n";
cout<<"\t\t\t"<<a[4]<<"   "<<a[5]<<"   "<<a[7]<<"   "<<a[6]<<"\n";
cout<<"\t\t\t"<<a[12]<<"   "<<a[13]<<"   "<<a[15]<<"   "<<a[14]<<"\n";
cout<<"\t\t\t"<<a[8]<<"   "<<a[9]<<"   "<<a[11]<<"   "<<a[10]<<"\n";
cout<<"\t\t**************************************\n";
}

void   sigle_set(int  bit,int  TRUE)
//bit为输入字符对应的数字代号，TRUE为正还是假，即a还是a非
//根据输入的一个标志和一个符号设置一些数为1；
{int  position=0;
for(int  j=0;j<=1;j++)
  for(int  k=0;k<=1;k++)
	  for(int m=0;m<=1;m++)
//一个字符要置8个数为1，使用3重循环
{switch(bit)
	  {case  3:position=8*TRUE+j*4+k*2+m;
	           a[position]=1;
			   break;

	  case  2:position=8*j+TRUE*4+k*2+m;
	           a[position]=1;
			   break;
	  case  1:position=8*j+k*4+TRUE*2+m;
	           a[position]=1;
			   break;

	  case  0:position=8*j+k*4+m*2+TRUE;
	           a[position]=1;
			   break;
      default:break;
	  }
	  }
}


void  single(char  C,  int  TRUE)
//根据输入的一个标志和一个符号，根据符号找到对应的数字，再调用sigle_set（）函数
{switch(C)
{case 'a':sigle_set(3,TRUE);
          break;
case 'b':sigle_set(2,TRUE);
          break;
case 'c':sigle_set(1,TRUE);
          break;
case 'd':sigle_set(0,TRUE);
          break;
default:break;
}
}

void  delete_twobit(int  bit1,int  bit2,int  &bit3,int &bit4)
//根据bit1和bit2的值，求出bit3和bit4的值
{if(bit1==3&&bit2==2){bit3=1;bit4=0;}
if(bit1==3&&bit2==1){bit3=2;bit4=0;}
if(bit1==3&&bit2==0){bit3=2;bit4=1;}
if(bit1==2&&bit2==1){bit3=3;bit4=0;}
if(bit1==2&&bit2==0){bit3=3;bit4=1;}
if(bit1==1&&bit2==0){bit3=3;bit4=2;}
}

int  char_bit(char  C)
//将字符化为相应的数字代号
{if(C=='a')return  3;
else if(C=='b')return  2;
else if(C=='c')return  1;
else if(C=='d')return  0;
}

void   two_set(char  c1,int true1, char   c2,int  true2)

//根据输入的2个标志和2个符号设置一些数为1；
//c1为第一个输入字符，true1是第一个输入字符的真假，
//c2为第2个输入字符，true2是第2个输入字符的真假
{int  bit1=char_bit(c1);
 int   bit2=char_bit(c2);
//找到第1和第2个字符对应的数字代号

 int   bit3=0,bit4=0;
 int  position=0;
delete_twobit(bit1,bit2,bit3,bit4);
//得到没有输入的字符的数字代号
for(int  j=0;j<=1;j++)
   for(int  k=0;k<=1;k++)
//2个字符和2个标志置4个数为一
   {position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*j+pow(2,bit4)*k;
    a[position]=1;
   }
}

void   delete_three_bit(int bit1,int  bit2, int  bit3,int  &bit4)
//根据bit1和bit2和bit3的值，求出bit4的值

{if(bit1==3&&bit2==2&&bit3==1)bit4=0;
if(bit1==3&&bit2==2&&bit3==0)bit4=1;
if(bit1==3&&bit2==1&&bit3==0)bit4=2;
if(bit1==2&&bit2==1&&bit3==0)bit4=3;
}


void  three_set(char  c1,int  true1,char  c2,int true2, char c3,int  true3)
//根据输入的3个标志和3个符号设置一些数为1；
//c1为第一个输入字符，true1是第一个输入字符的真假，
//c2为第2个输入字符，true2是第2个输入字符的真假
//c3为第3个输入字符，true3是第3个输入字符的真假

{int  bit1=char_bit(c1), bit2=char_bit(c2), bit3=char_bit(c3);
//找到第1，2，3个字符对应的数字代号

int  bit4=0,posotion=0;
delete_three_bit(bit1,bit2,bit3,bit4);
//得到没有输入的字符的数字代号


for(int  i=0;i<=1;i++)
//3个字符和3个标志置4个数为一
{posotion=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*true3+pow(2,bit4)*i;
 a[posotion]=1;
}
}


void  four_set(int  true1,int  true2,int true3,int  true4)
//根据输入的4个标志设置一个数为1；
//true1是第一个输入字符的真假，true2是第2个输入字符的真假，true3是第3个输入字符的真假
//true4是第4个输入字符的真假
{ int  position=0;
position=8*true1+4*true2+2*true3+true4;
a[position]=1;
}


int  corret_input(char  c,int ture)
{ if(c!='a'&&c!='b'&&c!='c'&&c!='d')
	  return 0;
 if(ture!=0&&ture!=1)
       return 0;
   return  1;
}


int  corret_input_ture(int ture)
{ if(ture!=0&&ture!=1)
       return 0;
   return  1;
}


void  input_one()//输入一个标志和一个字符
{  int  ture;
   char   c;
char  flag='y';
cout<<"输入1个标志和1个字符\n";
while(flag!='n')
  {cin>>ture;//输入一个标志
   cin>>c;//输入一个字符
   if (corret_input(c,ture))
         single(c,ture);
   else
      cout<<"输入有错误!\n";

   //根据输入置响应的一些数为1
  cout<<"continue?y/n\n";//是否再输入
  cin>>flag;
 }
}




void  input_two()
{  int  ture1,ture2;
   char   c1,c2;
   char  flag='y';
   cout<<"输入2个标志和2个字符\n";
  while(flag!='n')
  {cin>>ture1;//输入第一个标志
   cin>>c1;//输入第1个字符
   cin>>ture2;//输入第2个标志
   cin>>c2;//输入第2个字符
   if (corret_input(c1,ture1)&&corret_input(c2,ture2))
   two_set( c1, ture1, c2, ture2);
     else
      cout<<"输入有错误!\n";
   //根据输入置响应的一些数为1
 cout<<"continue?y/n\n";
 //是否再输入
   cin>>flag;
  }
}



void  input_three()
{  int  ture1,ture2,ture3;
   char   c1,c2,c3;
   cout<<"输入3个标志和3个字符\n";
  char  flag='y';
while(flag!='n')
  {cin>>ture1;//输入第一个标志
   cin>>c1;//输入第1个字符
   cin>>ture2;//输入第2个标志
   cin>>c2;//输入第2个字符
   cin>>ture3;//输入第3个标志
   cin>>c3;//输入第3个字符
     if (corret_input(c1,ture1)&&corret_input(c2,ture2)&&corret_input(c3,ture3))
   three_set(c1,ture1,c2,ture2, c3,ture3);
      else
      cout<<"输入有错误!\n";

  //根据输入置响应的一些数为1
   cout<<"continue?y/n\n";
 //是否再输入
   cin>>flag;
  }
}



void  input_four()
{  int  ture1,ture2,ture3,ture4;
   char   c1,c2,c3,c4;
   cout<<"输入4个标志和4个字符\n";
    char  flag='y';

	while(flag!='n')
  {

   cin>>ture1;//输入第一个标志
   cin>>c1;
   cin>>ture2;//输入第2个标志
   cin>>c2;
   cin>>ture3;//输入第3个标志
   cin>>c3;
    cin>>ture4;//输入第4个标志
   cin>>c4;
   if(corret_input_ture(ture1)&&corret_input_ture(ture2)&&corret_input_ture(ture3)&&corret_input_ture(ture4))
   four_set(ture1,ture2,ture3,ture4);
    else
      cout<<"输入有错误!\n";
 //根据输入置响应的一些数为1
    cout<<"continue?y/n\n";
   cin>>flag;
  }
}




void   display_main_message()//主界面菜单
{cout<<"\t\t*************************************\n";
 cout<<"\t\t\t1:   初始化输入数据\n";
 cout<<"\t\t\t2:   化简得出结果\n";
 cout<<"\t\t\t3:   重新开始\n";
 cout<<"\t\t\t4:   显示卡诺图中的数据\n";
 cout<<"\t\t\t5:   退出\n";
 cout<<"\t\t*************************************\n";
}



void  display_input_message()//输入界面的菜单
{cout<<"\t\t*************************************\n";
cout<<"\t\t1:输入1个字符    \t2:输入2个字符\n";
cout<<"\t\t3:输入3个字符    \t4:输入4个字符\n";
cout<<"\t\t5:退出\n";
cout<<"\t\t*************************************\n";
}




void  init()//输入数据
{  display_input_message();//
  int  flag;
  cin>>flag;
  //判断是输入几个字符
  while(flag!=5)//为5退出
  {
if(flag==1)  input_one();//输入一个字符
else  if(flag==2)input_two(); //输入2个字符
else  if(flag==3) input_three();//输入3个字符
else  if(flag==4)input_four(); //输入4个字符
else  cout<<"error!";
 display_input_message();
cin>>flag;
}
}




int  one()
//判断16个数是否全部为1
{int  flag=1;
for(int  i=0;i<16;i++)
   if(a[i]==0)
   {flag=0;break;}
   return  flag;
}





char   bit_to_char(int  bit)
//由数字代号转为相应的字符
{if(bit==3)return 'a';
if(bit==2)return 'b';
if(bit==1)return 'c';
if(bit==0)return 'd';
}

void   delete_threes_bit(int  bit,int  &bit1,int  &bit2,int  &bit3)
//已知一个字符的代号，得到3个的数字代号
{if(bit==3){bit1=2;bit2=1;bit3=0;}
if(bit==2){bit1=3;bit2=1;bit3=0;}
if(bit==1){bit1=3;bit2=2;bit3=0;}
if(bit==0){bit1=3;bit2=2;bit3=1;}
}



int  judge_8bit(int   bit,int  trues)
//判断是否有8个1都是1的情况，可以化简
{int  flag=1,bit1,bit2,bit3,position,i,j,k;
delete_threes_bit(bit,bit1,bit2,bit3);
//已知一个字符的代号，得到3个的数字代号




for(i=0;i<=1;i++)
  for(j=0;j<=1;j++)
	  for(k=0;k<=1;k++)
//8个数用3重循环
	  {position=pow(2,bit)*trues+pow(2,bit1)*i+pow(2,bit2)*j+pow(2,bit3)*k;
	  if(a[position]==0)
		  //如果有一个不是1，就退出
	  {flag=0;
	  break;
	  }
	 }

if(flag==1)
//当存在8个都为1的情况，就访问它们
{
for(  i=0;i<=1;i++)
  for(   j=0;j<=1;j++)
	  for(   k=0;k<=1;k++)
	  {position=pow(2,bit)*trues+pow(2,bit1)*i+pow(2,bit2)*j+pow(2,bit3)*k;
	   visited[position]=1;
	   //访问这8个数
	 }
}
return  flag;
}







void  all_8bit()
//对所有的8个都为1的情况进行判断，并输出结果
{for(int bit=0;bit<=3;bit++)
for(int  ture=0;ture<=1;ture++)
		if(judge_8bit(bit,ture))
                 cout<<"\t\t"<<ture<<bit_to_char(bit)<<endl;
}








int judge_4bit(int   bit1,int  true1,int   bit2,int  true2)
//判断是否有4个1都是1的情况，可以化简
{int  bit3,bit4;int  flag=1,position,i,j;

delete_twobit(bit1, bit2,bit3,bit4);
//已知2个字符的代号，得到2个的数字代号


for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
//4个数用2重循环

	 {position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*i+pow(2,bit4)*j;
	  if(a[position]==0)
		    //如果有一个不是1，就退出
	  {flag=0;
	  break;
	  }
	 }
if(flag==1)
//先判断它们在前面是否全被访问过
{int  flgg=1;
	for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
	 {position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*i+pow(2,bit4)*j;
	  if(visited[position]==0)
      //如果有一个不是0，说明没有被访问，可以化简
	  {flgg=0;break;}
	 }

if(flgg==1)flag=0;

}

if(flag==1)
//没有全被访问过，就访问4个数
{
	for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
	 {position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*i+pow(2,bit4)*j;
	 visited[position]=1;
	 //访问4个数
	 }
}
return  flag;
}


void  all_4bit()
//对所有的4个都为1的情况进行判断，并输出结果
{for(int  bit1=3;bit1>=0;bit1--)
    for(int  bit2=0;bit2<bit1;bit2++)
		for(int  true1=0; true1<=1;true1++)
			for(int  true2=0; true2<=1;true2++)
 if(judge_4bit(bit1,true1,bit2,true2))
      cout<<"\t\t"<<true1<<bit_to_char(bit1)<<true2<<bit_to_char(bit2)<<endl;
}



int judge_2bit(int   bit1,int  true1,int   bit2,int  true2,int   bit3,int  true3)
//判断是否有2个1都是1的情况，可以化简
{int  bit4,flag=1,position=0,i;
delete_three_bit(bit1,bit2,bit3,bit4);
//已知3个字符的代号，得到1个的数字代号
for(i=0;i<=1;i++)
{position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*true3+pow(2,bit4)*i;
  if(a[position]==0)
	  {flag=0;//如果有一个不是1，就退出
	  break;
	  }
}

//先判断它们在前面是否全被访问过
if(flag==1)
{int  flagg=1;
	for(i=0;i<=1;i++)
{position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*true3+pow(2,bit4)*i;
  if(visited[position]==0)
        flagg=0;

}
	  if(flagg==1)flag=0;
}


if(flag==1)
{//没有全被访问过，就访问这2个数
for(i=0;i<=1;i++)
{position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*true3+pow(2,bit4)*i;
  visited[position]=1;
}
}
return  flag;
}



//对所有的2个都为1的情况进行判断，并输出结果
void  all_2bit()
{for(int  bit1=3;bit1>=0;bit1--)
        for(int  bit2=0;bit2<bit1;bit2++)
               for(int  bit3=0;bit3<bit2;bit3++)
                       for(int  true1=0; true1<=1; true1++)
						     for(int  true2=0; true2<=1; true2++)
								  for(int  true3=0; true3<=1; true3++)

								  {if(judge_2bit(bit1,true1,bit2,true2,bit3, true3))
								 cout<<"\t\t"<<true1<<bit_to_char(bit1)<<true2<<bit_to_char(bit2)<<true3<<bit_to_char(bit3)<<endl;
								  }
}



int  judge_1bit(int true1,int true2,int true3,int true4)
//判断是否有1个1是1的情况
{int  flag=1,position;
position=8*true1+4*true2+2*true3+true4;
if(a[position]==0)flag=0;
if(flag==1)
{
if(visited[position]==1)//没有被访问
flag=0;
}
if(flag==1)//访问
visited[position]=1;
return  flag;
}

//对所有的1个1的情况进行判断，并输出结果
void   all_1bit()
{for(int  ture1=0;ture1<=1;ture1++)
   for(int  ture2=0;ture2<=1;ture2++)
      for(int  ture3=0;ture3<=1;ture3++)
            for(int  ture4=0;ture4<=1;ture4++)
   if(judge_1bit(ture1,ture2,ture3,ture4))
		 cout<<"\t\t"<<ture1<<'a'<<ture2<<'b'<<ture3<<'c'<<ture4<<'d'<<endl;

}





void  compress()//化简
{cout<<"\t\t结果是:\n";
if(one())//如果全是1，就输出1
cout<<"\t\t1\n";
 else
 {   all_8bit();//8个都是1的化简
	 all_4bit();//4个都是1的化简
	 all_2bit();//2个都是1的化简
	 all_1bit();//1个1的化简
 }
}




void  main()
{init_zero();
//初始化为0
display_main_message();
int  flag;
cin>>flag;
while(flag!=5)
{
if(flag==1) init();//输入数据
else  if(flag==2)compress(); //化简得出结果
else  if(flag==3) {init_zero();init();}//重新输入数据
else  if(flag==4) print();//打印卡洛图中的数据
else  cout<<"error!";
display_main_message();
cin>>flag;
}
}