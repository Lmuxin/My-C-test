#include<iostream>
using namespace std;
const int MAX = 9999;
int main()
{
   int i,j,k;
   int n,c,d;
   int w[MAX] = {0};   //重量
   int b[MAX] = {0};   //体积
   int v[MAX] = {0};   //价值
   cout<<"请输入物品个数:";
   cin>>n;
   cout<<"请输入背包的容量及容积:";
   cin>>c>>d;
   cout<<"请依次输入各个物品的重量,体积,价值:(共"<<n<<"个)"<<endl;
   for(i =1;i<n+1;i++)
   {
       cin>>w[i]>>b[i]>>v[i];
   }

   int dp[50][50][50]={0};        //dp[i][j][k] i代表着第1到第i个物品，j代表的是重量，k代表的是容积，dp为最优价值

   for(i=1;i<n+1;i++)
       for(j =1;j <=c;j++)
           for(k = 1 ;k <= d ; k++)
           {
               if(w[i]<=j&&b[i]<=k)  //当前物品重量小于当前容量，且体积小于容积时 ，才可以考虑装入物品的问题
                   dp[i][j][k] = max(dp[i-1][j][k] , dp[i-1][j-w[i]][k-b[i]] + v[i]);
               else dp[i][j][k] = dp[i-1][j][k];
           }
   cout<<"背包能放物品的最大价值为:"<<dp[n][c][d]<<endl;
  int x[MAX] ={0};   //记录是否被选中
  for(i =n;i>1;i--)
       if(dp[i][c][d]==dp[i-1][c][d])x[i] =0;
      else {x[i]=1;c -= w[i];d -= b[i];}
   x[1]=(dp[1][c][d])?1:0;
   cout<<"被选入背包的物品的编号,质量和体积,价值分别是:"<<endl;
   for(i=1;i<n+1;i++)
       if(x[i]==1)
           cout<<"第"<<i<<"个物品: "<<w[i]<<"  "<<b[i]<<"  "<<v[i]<<endl;

}
