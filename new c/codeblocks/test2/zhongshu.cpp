#include"stdafx.h"
#include<iostream>
using namespace std;
int num=0;//�洢����
int sum=0;//�洢����

 //ͳ�������м������ֵ�������a�Ǵ�ͳ�����飬p�������һ����������Ϊ0��qΪ�������һ������������sizeof(a)/sizeof(a[0])

int count(int a[],int p,int q)
{
    int n=a[(p+q)/2];
    int counts=0;//��¼����
    for(int i=p;i<q;i++)//�������һ������������ʼ�����������һ����������
    {
         if(a[i]==n)
             {
        counts++;
       }
    }
   return counts;
}

//begin����,����������м�ֵ��һ�γ���λ�õ�����, p�������һ������������qΪ�������һ����������

int begin(int a[],int p,int q)
{
     int x=0;
      //������ĵ�һ������ʼ����һ���ҵ���������м�����ȵ���ʱ������ѭ����������i
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

//ͳ����������������
void mode( int a[],int p,int q)
{
     int  mid=(p+q)/2;//midΪ��ǰ�����м���������
     int  tsum=count(a,p,q);//ͳ���м���������
     int left=begin(a,p,q);//����begin����,�ҳ������м�����һ�γ��ֵ�λ��
     if(tsum>sum)//����м�������������sum�����м�������num
     {
          sum=tsum;
          num=a[tnum];
     }
    if(q-(left+tsum)>sum)//�����ǰ�����ұ�Ԫ�صĸ�����������sum,��ô�ұ߿��ܳ������������ҵݹ�Ѱ��
    {
          mode(a,left+tsum,q);
    }
   if(left>sum)//�����ǰ�������Ԫ�صĸ�����������sum����ô��߿��ܳ�������������ݹ�Ѱ��
   {
          mode(a,0,left);
   }
}
//������
int  main()
{
    int a[]={1,2,2,2,2,2,3,4,4,4,4,5,5,5,6,6,6,77,7,7,7,7,7,7,7,7,7,7,7,7};
    mode(a,0,31);
   cout<<"����="<<num<<"      "<<"����="<<sum;
}

