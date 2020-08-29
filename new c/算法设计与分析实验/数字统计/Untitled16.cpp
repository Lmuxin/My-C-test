#include<iostream>
using namespace std;
int main()

{

    void count_num(int n);
    int n;
     cout<<"请输入书的页码：";
     cin>>n;

	count_num(n);

	return 0;
}

void count_num(int n)
{
	int count[10]={0};
	for (int i=0;i<=n;i++)
	{
		int t=i;
		if(0==t)
		{
			count[0]++;//计算第一个0的个数
		}

		while(t)
		{
			count[t%10]++;//计算高位出现次数
			t/=10;//依次向低位
		}
	}
	for(  int i=0;i<10;i++)
	{

		cout<<i;
		cout<<"出现的次数是:";
		cout<<count[i]<<'\n';
	}

}
