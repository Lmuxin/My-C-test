# include <stdio.h>
# define SUM 100000
int main ()
{
float total,aver,amount;
int i;
for(i=1,total=0;i<=1000;i++)

{
printf ("please enter amount:");
scanff("%f",&amount);
total=total+amount;
if(total>=SUM )break;
}
aver=total/i;
printf("i=%d,aver=%f",i,aver);
return 0;




}
