#include<stdio.h>
int main()
{

 int m;
 printf("����m");
 scanf("%d",&m);
 printf("���%d",sign(m));

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

