# include <stdio.h>
int main ()
{
int n,i,k;
printf("please enter a integer number n=?");
sacnf("%d",&n);
k=sqrt(n);
for(i=2;i<=k;i++)
if (n%i==0)break;

if(i<=k)
printf("%d is not a ",n);
else
printf("%d is a ",n);
return 0;








}
