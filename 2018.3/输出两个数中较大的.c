#include<stdio.h>
int main()
{

   int a,b,ma;

  int max(int a,int b);
  printf("����a,b��ֵ��");
  scanf("%d%d",&a,&b);
  ma=max(a,b);
  printf("����ϴ��%d",ma);
  return 0;


}
int max(int a,int b)//
{

   return (a>b?a:b);//Ҫ������ ��Ȼ������



}
