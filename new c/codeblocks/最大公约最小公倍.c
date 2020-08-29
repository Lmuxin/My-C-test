# include<stdio.h>
int main()
{
int p,r,n,m,temp;
printf("请输入两个正整数：");
scanf("n=%d,m=%d",&n,&m);
if(n<m)
{
temp=n;
n=m;
m=temp;
}
p=n*m;

while(m!=0)
{
r=n%m;
n=m;
m=r;
}
printf("最大公约数是%d\n",n);
printf("最小公倍数是%d\n",p/n);
return 0;
}
