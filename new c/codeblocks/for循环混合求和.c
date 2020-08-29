# include <stdio.h>
int main()
{

double s=0;
int a,b;
float c;
for(a=1;a<=100;a++)
{
s=s+a;
}
for(a=1;a<=50;a++)
{
b=a*a;
s=s+b;

}

for(a=1;a<=10;a++)
{
c=1/a;
s=s+c;
}
printf("s=%f",s);
return 0;


}
