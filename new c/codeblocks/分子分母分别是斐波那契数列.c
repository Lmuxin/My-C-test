# include<stdio.h>
int main()
{
  /*int i,a=2,b=1;//a,b定义成整数结果是不对的，因为a/b结果是整数，把好多小数舍掉了*/
  int i;
    double s=0,t,a=2,b=1;//a,b必须定义为浮点数
  for(i=1;i<=20;i++)
  {s=s+a/b;
  t=a;
  a=a+b;
  b=t;
  }
  printf("s=%f",s);
  return 0;
  }

















