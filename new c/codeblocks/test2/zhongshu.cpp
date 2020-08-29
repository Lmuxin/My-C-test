#include"stdafx.h"
#include<iostream>
using namespace std;
int num=0;//存储众数
int sum=0;//存储重数

 //统计数组中间数出现的重数，a是待统计数组，p是数组第一个数的索引为0，q为数组最后一个数的索引是sizeof(a)/sizeof(a[0])

int count(int a[],int p,int q)
{
    int n=a[(p+q)/2];
    int counts=0;//记录重数
    for(int i=p;i<q;i++)//从数组第一个数的索引开始，遍历到最后一个数的索引
    {
         if(a[i]==n)
             {
        counts++;
       }
    }
   return counts;
}

//begin函数,返回数组的中间值第一次出现位置的索引, p是数组第一个数的索引，q为数组最后一个数的索引

int begin(int a[],int p,int q)
{
     int x=0;
      //从数组的第一个数开始，第一次找到与数组的中间数相等的数时，跳出循环，并返回i
     for(int i=p;i<q;i++)
     {
       if(a[i]==a[(p+q)/2])
       {
            x=i;
            break;
       }
     }
return x;
}

//统计重数和众数函数
void mode( int a[],int p,int q)
{
     int  mid=(p+q)/2;//mid为当前数组中间数的索引
     int  tsum=count(a,p,q);//统计中间数的重数
     int left=begin(a,p,q);//调用begin函数,找出数组中间数第一次出现的位置
     if(tsum>sum)//如果中间数的重数大于sum，将中间数赋给num
     {
          sum=tsum;
          num=a[tnum];
     }
    if(q-(left+tsum)>sum)//如果当前数组右边元素的个数大于重数sum,那么右边可能出现众数，向右递归寻找
    {
          mode(a,left+tsum,q);
    }
   if(left>sum)//如果当前数组左边元素的个数大于重数sum，那么左边可能出现众数，向左递归寻找
   {
          mode(a,0,left);
   }
}
//主函数
int  main()
{
    int a[]={1,2,2,2,2,2,3,4,4,4,4,5,5,5,6,6,6,77,7,7,7,7,7,7,7,7,7,7,7,7};
    mode(a,0,31);
   cout<<"众数="<<num<<"      "<<"重数="<<sum;
}

