#include<stdio.h>
int main()
{

   int a,b,ma;

  int max(int a,int b);
  printf("输入a,b的值：");
  scanf("%d%d",&a,&b);
  ma=max(a,b);
  printf("输出较大的%d",ma);
  return 0;


}
int max(int a,int b)//
{

   return (a>b?a:b);//要加括号 不然不对了



}
