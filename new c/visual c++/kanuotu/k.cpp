#include <stdafx.h>
#include <iostream>
#include <cmath>
#include "vector.h"
int   a[16];//�������16����
int   visited[16];//����������Ƿ��ù�

void  init_zero()//��ʼ��Ϊ0
{
for(int i=0;i<16;i++)
{a[i]=0;//û������ʱȫΪ0
visited[i]=0;//û�л���û�б�����
}
}

void   print()//��ӡ��ŵͼ������4x4��ŵͼ�Ĺ������
{
cout<<"\t\t**************************************\n";
cout<<"\t\t\t"<<a[0]<<"   "<<a[1]<<"   "<<a[3]<<"   "<<a[2]<<"\n";
cout<<"\t\t\t"<<a[4]<<"   "<<a[5]<<"   "<<a[7]<<"   "<<a[6]<<"\n";
cout<<"\t\t\t"<<a[12]<<"   "<<a[13]<<"   "<<a[15]<<"   "<<a[14]<<"\n";
cout<<"\t\t\t"<<a[8]<<"   "<<a[9]<<"   "<<a[11]<<"   "<<a[10]<<"\n";
cout<<"\t\t**************************************\n";
}

void   sigle_set(int  bit,int  TRUE)
//bitΪ�����ַ���Ӧ�����ִ��ţ�TRUEΪ�����Ǽ٣���a����a��
//���������һ����־��һ����������һЩ��Ϊ1��
{int  position=0;
for(int  j=0;j<=1;j++)
  for(int  k=0;k<=1;k++)
	  for(int m=0;m<=1;m++)
//һ���ַ�Ҫ��8����Ϊ1��ʹ��3��ѭ��
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
//���������һ����־��һ�����ţ����ݷ����ҵ���Ӧ�����֣��ٵ���sigle_set��������
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
//����bit1��bit2��ֵ�����bit3��bit4��ֵ
{if(bit1==3&&bit2==2){bit3=1;bit4=0;}
if(bit1==3&&bit2==1){bit3=2;bit4=0;}
if(bit1==3&&bit2==0){bit3=2;bit4=1;}
if(bit1==2&&bit2==1){bit3=3;bit4=0;}
if(bit1==2&&bit2==0){bit3=3;bit4=1;}
if(bit1==1&&bit2==0){bit3=3;bit4=2;}
}

int  char_bit(char  C)
//���ַ���Ϊ��Ӧ�����ִ���
{if(C=='a')return  3;
else if(C=='b')return  2;
else if(C=='c')return  1;
else if(C=='d')return  0;
}

void   two_set(char  c1,int true1, char   c2,int  true2)

//���������2����־��2����������һЩ��Ϊ1��
//c1Ϊ��һ�������ַ���true1�ǵ�һ�������ַ�����٣�
//c2Ϊ��2�������ַ���true2�ǵ�2�������ַ������
{int  bit1=char_bit(c1);
 int   bit2=char_bit(c2);
//�ҵ���1�͵�2���ַ���Ӧ�����ִ���

 int   bit3=0,bit4=0;
 int  position=0;
delete_twobit(bit1,bit2,bit3,bit4);
//�õ�û��������ַ������ִ���
for(int  j=0;j<=1;j++)
   for(int  k=0;k<=1;k++)
//2���ַ���2����־��4����Ϊһ
   {position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*j+pow(2,bit4)*k;
    a[position]=1;
   }
}

void   delete_three_bit(int bit1,int  bit2, int  bit3,int  &bit4)
//����bit1��bit2��bit3��ֵ�����bit4��ֵ

{if(bit1==3&&bit2==2&&bit3==1)bit4=0;
if(bit1==3&&bit2==2&&bit3==0)bit4=1;
if(bit1==3&&bit2==1&&bit3==0)bit4=2;
if(bit1==2&&bit2==1&&bit3==0)bit4=3;
}


void  three_set(char  c1,int  true1,char  c2,int true2, char c3,int  true3)
//���������3����־��3����������һЩ��Ϊ1��
//c1Ϊ��һ�������ַ���true1�ǵ�һ�������ַ�����٣�
//c2Ϊ��2�������ַ���true2�ǵ�2�������ַ������
//c3Ϊ��3�������ַ���true3�ǵ�3�������ַ������

{int  bit1=char_bit(c1), bit2=char_bit(c2), bit3=char_bit(c3);
//�ҵ���1��2��3���ַ���Ӧ�����ִ���

int  bit4=0,posotion=0;
delete_three_bit(bit1,bit2,bit3,bit4);
//�õ�û��������ַ������ִ���


for(int  i=0;i<=1;i++)
//3���ַ���3����־��4����Ϊһ
{posotion=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*true3+pow(2,bit4)*i;
 a[posotion]=1;
}
}


void  four_set(int  true1,int  true2,int true3,int  true4)
//���������4����־����һ����Ϊ1��
//true1�ǵ�һ�������ַ�����٣�true2�ǵ�2�������ַ�����٣�true3�ǵ�3�������ַ������
//true4�ǵ�4�������ַ������
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


void  input_one()//����һ����־��һ���ַ�
{  int  ture;
   char   c;
char  flag='y';
cout<<"����1����־��1���ַ�\n";
while(flag!='n')
  {cin>>ture;//����һ����־
   cin>>c;//����һ���ַ�
   if (corret_input(c,ture))
         single(c,ture);
   else
      cout<<"�����д���!\n";

   //������������Ӧ��һЩ��Ϊ1
  cout<<"continue?y/n\n";//�Ƿ�������
  cin>>flag;
 }
}




void  input_two()
{  int  ture1,ture2;
   char   c1,c2;
   char  flag='y';
   cout<<"����2����־��2���ַ�\n";
  while(flag!='n')
  {cin>>ture1;//�����һ����־
   cin>>c1;//�����1���ַ�
   cin>>ture2;//�����2����־
   cin>>c2;//�����2���ַ�
   if (corret_input(c1,ture1)&&corret_input(c2,ture2))
   two_set( c1, ture1, c2, ture2);
     else
      cout<<"�����д���!\n";
   //������������Ӧ��һЩ��Ϊ1
 cout<<"continue?y/n\n";
 //�Ƿ�������
   cin>>flag;
  }
}



void  input_three()
{  int  ture1,ture2,ture3;
   char   c1,c2,c3;
   cout<<"����3����־��3���ַ�\n";
  char  flag='y';
while(flag!='n')
  {cin>>ture1;//�����һ����־
   cin>>c1;//�����1���ַ�
   cin>>ture2;//�����2����־
   cin>>c2;//�����2���ַ�
   cin>>ture3;//�����3����־
   cin>>c3;//�����3���ַ�
     if (corret_input(c1,ture1)&&corret_input(c2,ture2)&&corret_input(c3,ture3))
   three_set(c1,ture1,c2,ture2, c3,ture3);
      else
      cout<<"�����д���!\n";

  //������������Ӧ��һЩ��Ϊ1
   cout<<"continue?y/n\n";
 //�Ƿ�������
   cin>>flag;
  }
}



void  input_four()
{  int  ture1,ture2,ture3,ture4;
   char   c1,c2,c3,c4;
   cout<<"����4����־��4���ַ�\n";
    char  flag='y';

	while(flag!='n')
  {

   cin>>ture1;//�����һ����־
   cin>>c1;
   cin>>ture2;//�����2����־
   cin>>c2;
   cin>>ture3;//�����3����־
   cin>>c3;
    cin>>ture4;//�����4����־
   cin>>c4;
   if(corret_input_ture(ture1)&&corret_input_ture(ture2)&&corret_input_ture(ture3)&&corret_input_ture(ture4))
   four_set(ture1,ture2,ture3,ture4);
    else
      cout<<"�����д���!\n";
 //������������Ӧ��һЩ��Ϊ1
    cout<<"continue?y/n\n";
   cin>>flag;
  }
}




void   display_main_message()//������˵�
{cout<<"\t\t*************************************\n";
 cout<<"\t\t\t1:   ��ʼ����������\n";
 cout<<"\t\t\t2:   ����ó����\n";
 cout<<"\t\t\t3:   ���¿�ʼ\n";
 cout<<"\t\t\t4:   ��ʾ��ŵͼ�е�����\n";
 cout<<"\t\t\t5:   �˳�\n";
 cout<<"\t\t*************************************\n";
}



void  display_input_message()//�������Ĳ˵�
{cout<<"\t\t*************************************\n";
cout<<"\t\t1:����1���ַ�    \t2:����2���ַ�\n";
cout<<"\t\t3:����3���ַ�    \t4:����4���ַ�\n";
cout<<"\t\t5:�˳�\n";
cout<<"\t\t*************************************\n";
}




void  init()//��������
{  display_input_message();//
  int  flag;
  cin>>flag;
  //�ж������뼸���ַ�
  while(flag!=5)//Ϊ5�˳�
  {
if(flag==1)  input_one();//����һ���ַ�
else  if(flag==2)input_two(); //����2���ַ�
else  if(flag==3) input_three();//����3���ַ�
else  if(flag==4)input_four(); //����4���ַ�
else  cout<<"error!";
 display_input_message();
cin>>flag;
}
}




int  one()
//�ж�16�����Ƿ�ȫ��Ϊ1
{int  flag=1;
for(int  i=0;i<16;i++)
   if(a[i]==0)
   {flag=0;break;}
   return  flag;
}





char   bit_to_char(int  bit)
//�����ִ���תΪ��Ӧ���ַ�
{if(bit==3)return 'a';
if(bit==2)return 'b';
if(bit==1)return 'c';
if(bit==0)return 'd';
}

void   delete_threes_bit(int  bit,int  &bit1,int  &bit2,int  &bit3)
//��֪һ���ַ��Ĵ��ţ��õ�3�������ִ���
{if(bit==3){bit1=2;bit2=1;bit3=0;}
if(bit==2){bit1=3;bit2=1;bit3=0;}
if(bit==1){bit1=3;bit2=2;bit3=0;}
if(bit==0){bit1=3;bit2=2;bit3=1;}
}



int  judge_8bit(int   bit,int  trues)
//�ж��Ƿ���8��1����1����������Ի���
{int  flag=1,bit1,bit2,bit3,position,i,j,k;
delete_threes_bit(bit,bit1,bit2,bit3);
//��֪һ���ַ��Ĵ��ţ��õ�3�������ִ���




for(i=0;i<=1;i++)
  for(j=0;j<=1;j++)
	  for(k=0;k<=1;k++)
//8������3��ѭ��
	  {position=pow(2,bit)*trues+pow(2,bit1)*i+pow(2,bit2)*j+pow(2,bit3)*k;
	  if(a[position]==0)
		  //�����һ������1�����˳�
	  {flag=0;
	  break;
	  }
	 }

if(flag==1)
//������8����Ϊ1��������ͷ�������
{
for(  i=0;i<=1;i++)
  for(   j=0;j<=1;j++)
	  for(   k=0;k<=1;k++)
	  {position=pow(2,bit)*trues+pow(2,bit1)*i+pow(2,bit2)*j+pow(2,bit3)*k;
	   visited[position]=1;
	   //������8����
	 }
}
return  flag;
}







void  all_8bit()
//�����е�8����Ϊ1����������жϣ���������
{for(int bit=0;bit<=3;bit++)
for(int  ture=0;ture<=1;ture++)
		if(judge_8bit(bit,ture))
                 cout<<"\t\t"<<ture<<bit_to_char(bit)<<endl;
}








int judge_4bit(int   bit1,int  true1,int   bit2,int  true2)
//�ж��Ƿ���4��1����1����������Ի���
{int  bit3,bit4;int  flag=1,position,i,j;

delete_twobit(bit1, bit2,bit3,bit4);
//��֪2���ַ��Ĵ��ţ��õ�2�������ִ���


for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
//4������2��ѭ��

	 {position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*i+pow(2,bit4)*j;
	  if(a[position]==0)
		    //�����һ������1�����˳�
	  {flag=0;
	  break;
	  }
	 }
if(flag==1)
//���ж�������ǰ���Ƿ�ȫ�����ʹ�
{int  flgg=1;
	for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
	 {position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*i+pow(2,bit4)*j;
	  if(visited[position]==0)
      //�����һ������0��˵��û�б����ʣ����Ի���
	  {flgg=0;break;}
	 }

if(flgg==1)flag=0;

}

if(flag==1)
//û��ȫ�����ʹ����ͷ���4����
{
	for(i=0;i<=1;i++)
     for(j=0;j<=1;j++)
	 {position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*i+pow(2,bit4)*j;
	 visited[position]=1;
	 //����4����
	 }
}
return  flag;
}


void  all_4bit()
//�����е�4����Ϊ1����������жϣ���������
{for(int  bit1=3;bit1>=0;bit1--)
    for(int  bit2=0;bit2<bit1;bit2++)
		for(int  true1=0; true1<=1;true1++)
			for(int  true2=0; true2<=1;true2++)
 if(judge_4bit(bit1,true1,bit2,true2))
      cout<<"\t\t"<<true1<<bit_to_char(bit1)<<true2<<bit_to_char(bit2)<<endl;
}



int judge_2bit(int   bit1,int  true1,int   bit2,int  true2,int   bit3,int  true3)
//�ж��Ƿ���2��1����1����������Ի���
{int  bit4,flag=1,position=0,i;
delete_three_bit(bit1,bit2,bit3,bit4);
//��֪3���ַ��Ĵ��ţ��õ�1�������ִ���
for(i=0;i<=1;i++)
{position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*true3+pow(2,bit4)*i;
  if(a[position]==0)
	  {flag=0;//�����һ������1�����˳�
	  break;
	  }
}

//���ж�������ǰ���Ƿ�ȫ�����ʹ�
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
{//û��ȫ�����ʹ����ͷ�����2����
for(i=0;i<=1;i++)
{position=pow(2,bit1)*true1+pow(2,bit2)*true2+pow(2,bit3)*true3+pow(2,bit4)*i;
  visited[position]=1;
}
}
return  flag;
}



//�����е�2����Ϊ1����������жϣ���������
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
//�ж��Ƿ���1��1��1�����
{int  flag=1,position;
position=8*true1+4*true2+2*true3+true4;
if(a[position]==0)flag=0;
if(flag==1)
{
if(visited[position]==1)//û�б�����
flag=0;
}
if(flag==1)//����
visited[position]=1;
return  flag;
}

//�����е�1��1����������жϣ���������
void   all_1bit()
{for(int  ture1=0;ture1<=1;ture1++)
   for(int  ture2=0;ture2<=1;ture2++)
      for(int  ture3=0;ture3<=1;ture3++)
            for(int  ture4=0;ture4<=1;ture4++)
   if(judge_1bit(ture1,ture2,ture3,ture4))
		 cout<<"\t\t"<<ture1<<'a'<<ture2<<'b'<<ture3<<'c'<<ture4<<'d'<<endl;

}





void  compress()//����
{cout<<"\t\t�����:\n";
if(one())//���ȫ��1�������1
cout<<"\t\t1\n";
 else
 {   all_8bit();//8������1�Ļ���
	 all_4bit();//4������1�Ļ���
	 all_2bit();//2������1�Ļ���
	 all_1bit();//1��1�Ļ���
 }
}




void  main()
{init_zero();
//��ʼ��Ϊ0
display_main_message();
int  flag;
cin>>flag;
while(flag!=5)
{
if(flag==1) init();//��������
else  if(flag==2)compress(); //����ó����
else  if(flag==3) {init_zero();init();}//������������
else  if(flag==4) print();//��ӡ����ͼ�е�����
else  cout<<"error!";
display_main_message();
cin>>flag;
}
}