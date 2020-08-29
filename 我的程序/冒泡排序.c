# include <stdio.h>
int main()
{
int i,j,t;
int a[10];
printf("please enter  numbers:");
for(i=0;i<=9;i++)
scanf("%d88",&a[i]);
for(j=0;j<9;j++)
for(i=0;i<9-j;i++)

if(a[i]>a[i+1])
{
t=a[i];
a[i]=a[i+1];
a[i+1]=t;
}

printf("the sorted numbers is:");
for(i=0;i<10;i++)
printf("%d",a[i]);
return 0;



}
