# include<stdio.h>
int main()
{
  /*int i,a=2,b=1;//a,b�������������ǲ��Եģ���Ϊa/b������������Ѻö�С�������*/
  int i;
    double s=0,t,a=2,b=1;//a,b���붨��Ϊ������
  for(i=1;i<=20;i++)
  {s=s+a/b;
  t=a;
  a=a+b;
  b=t;
  }
  printf("s=%f",s);
  return 0;
  }

















