#include<stdio.h>
int main()
{

int sum(int m,int n);

int m,n,s;
printf("输入m和n的值：");

scanf("%d%d",&m,&n);
s=sum(m,n);

printf("输出m到n的和是%d：",s);


}

int sum(int m,int n)
{
  int s=0,i;
  for(i=m+1;i<n;i++)
     s+=i;
  return s;


}
