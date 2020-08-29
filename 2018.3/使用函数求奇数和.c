#include<stdio.h>
#define max 3
int main()
{
    int even (int n);
    int sum(int arr[],int N);
    int a[max],i;
 printf("输入数组的值");
 for(i=0;i<max;i++)
 scanf("%d",&a[i]);

 printf("奇数和%d",sum(a,max));

 return 0;

}

int even (int n)
{
  if((n%2)!=0)
  return 0;
  else return 1;

}

int sum(int arr[],int N)
{
int i ,sum=0;
   for(i=0;i<N;i++)

   if(even(arr[i])==0)
   sum+=arr[i];
   return sum;

}
