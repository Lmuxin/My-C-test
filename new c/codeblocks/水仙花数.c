# include <stdio.h>
int main()
{
int a,b,c,i;
for(i=100;i<=999;i++)
{
a=i/100;//��λ����
b=(i-a*100)/10;//ʮλ����
c=i%10;//��λ����
if(i==a*a*a+b*b*b+c*c*c)
printf("i=%d\n",i);



}

return 0;




}
