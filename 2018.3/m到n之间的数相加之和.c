#include<stdio.h>
int main()
{

int sum(int m,int n);

int m,n,s;
printf("����m��n��ֵ��");

scanf("%d%d",&m,&n);
s=sum(m,n);

printf("���m��n�ĺ���%d��",s);


}

int sum(int m,int n)
{
  int s=0,i;
  for(i=m+1;i<n;i++)
     s+=i;
  return s;


}
