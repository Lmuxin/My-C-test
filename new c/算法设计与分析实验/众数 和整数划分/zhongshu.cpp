//#include"stdafx.h"
#include<iostream>
using namespace std;
int num=0;//�洢����
int sum=0;//�洢����

 /*ͳ�������м������ֵ�������a�Ǵ�ͳ�����飬p�������һ����������Ϊ0��qΪ�������һ������������sizeof(a)/sizeof(a[0])*/

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

/*begin����,����������м�ֵ��һ�γ���λ�õ�����, p�������һ������������qΪ�������һ����������*/

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
     if(tsum>sum)//���м�������������sum�����м�������num
     {
          sum=tsum;
          num=a[mid];
     }
    if(q-(left+tsum)>sum)//��q��ȥ�м�����һ�γ��ֵ�λ���ټ�ȥ�м���������,��ʣ��Ԫ�صĸ�����������sum,��ô�м������һ�γ��ֵ�λ���ұ߿��ܳ������������ҵݹ�Ѱ��
    {
          mode(a,left+tsum,q);
    }
   if(left>sum)//���м�����һ�γ��ֵ�λ�ô�������sum����ô��߿��ܳ�������������ݹ�Ѱ��
   {
          mode(a,0,left);
   }
}
//������
int  main()
{
    int a[5];
    cout<<"����������:"<<endl;
    for(int i=0;i<5;i++)
        cin>>a[i];
    mode(a,0,5);
   cout<<"����="<<num<<'\t'<<"����="<<sum;
   //system("pause");
   return 0;

}
