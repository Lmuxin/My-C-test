#include<iostream>
using namespace std;
const int MAX = 9999;
int main()
{
   int i,j,k;
   int n,c,d;
   int w[MAX] = {0};   //����
   int b[MAX] = {0};   //���
   int v[MAX] = {0};   //��ֵ
   cout<<"��������Ʒ����:";
   cin>>n;
   cout<<"�����뱳�����������ݻ�:";
   cin>>c>>d;
   cout<<"���������������Ʒ������,���,��ֵ:(��"<<n<<"��)"<<endl;
   for(i =1;i<n+1;i++)
   {
       cin>>w[i]>>b[i]>>v[i];
   }

   int dp[50][50][50]={0};        //dp[i][j][k] i�����ŵ�1����i����Ʒ��j�������������k��������ݻ���dpΪ���ż�ֵ

   for(i=1;i<n+1;i++)
       for(j =1;j <=c;j++)
           for(k = 1 ;k <= d ; k++)
           {
               if(w[i]<=j&&b[i]<=k)  //��ǰ��Ʒ����С�ڵ�ǰ�����������С���ݻ�ʱ ���ſ��Կ���װ����Ʒ������
                   dp[i][j][k] = max(dp[i-1][j][k] , dp[i-1][j-w[i]][k-b[i]] + v[i]);
               else dp[i][j][k] = dp[i-1][j][k];
           }
   cout<<"�����ܷ���Ʒ������ֵΪ:"<<dp[n][c][d]<<endl;
  int x[MAX] ={0};   //��¼�Ƿ�ѡ��
  for(i =n;i>1;i--)
       if(dp[i][c][d]==dp[i-1][c][d])x[i] =0;
      else {x[i]=1;c -= w[i];d -= b[i];}
   x[1]=(dp[1][c][d])?1:0;
   cout<<"��ѡ�뱳������Ʒ�ı��,���������,��ֵ�ֱ���:"<<endl;
   for(i=1;i<n+1;i++)
       if(x[i]==1)
           cout<<"��"<<i<<"����Ʒ: "<<w[i]<<"  "<<b[i]<<"  "<<v[i]<<endl;

}
