#include<stdio.h>
int main()
{

 int m;
 printf("ÊäÈëm");
 scanf("%d",&m);
 printf("Êä³ö%d",sign(m));

 return 0;



}

int sign(int x)
{
  if (x>0)
    return 1;
    else if (x==0)
      return 0;
      return -1;




}

