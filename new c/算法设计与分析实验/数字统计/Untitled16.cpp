#include<iostream>
using namespace std;
int main()

{

    void count_num(int n);
    int n;
     cout<<"���������ҳ�룺";
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
			count[0]++;//�����һ��0�ĸ���
		}

		while(t)
		{
			count[t%10]++;//�����λ���ִ���
			t/=10;//�������λ
		}
	}
	for(  int i=0;i<10;i++)
	{

		cout<<i;
		cout<<"���ֵĴ�����:";
		cout<<count[i]<<'\n';
	}

}
