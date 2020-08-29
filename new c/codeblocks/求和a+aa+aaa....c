# include <stdio.h>
int main()
{

int a,n,t=0,s=0,i=1;
printf("input a,n:");
scanf("a=%d,n=%d",&a,&n);
while(i<=n)
{
t=t+a;
s=s+t;
a=a*10;
i++;
}
printf("s=%d",s);
return 0;


}
