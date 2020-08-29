//#include"stdafx.h"
#include<iostream>
using namespace std;
int q (int n, int m)
{
	if ((n<1) || (m<1))
		return 0;
	if ((n == 1) || (m == 1))
		return 1;
	if (n < m)
		return q(n, n);
	if (n == m)
		return q(n, m - 1) + 1;
	return q(n, m - 1) + q(n - m, m);
}
int main()
{   int m,n;//要划分的正整数n
  cout<<"请输入要划分的整数n:"<<endl;
  cin>>n;
  cout<<endl;
   cout<<"请输入最大加数不超过:"<<endl;
   cin>>m;
   if(m<1)


   {

   cout<<"输入m有错,请重新输入:"<<endl;
   cin>>m;
   cout<<endl;
   }

   cout<<endl;
	cout << q(n, m) << endl;
//	system("pause");
	return 0;
}
