// 线性时间选择问题.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<time.h>
#define MAX_VALUE 10000
#define random() rand()%MAX_VALUE
#define N 10000
int a[N];
using namespace  std;
class Find
{
public:
	void bubble(int first, int end) //冒泡排序
	{
		for (int flag = first; flag<end; flag++)
			for (int i = end; i>flag; i--)
				if (a[i]<a[i - 1])
				{
					int t = a[i];
					a[i] = a[i - 1];
					a[i - 1] = t;
				}
	}
	int partition(int p, int r, int x) //数组a中从a[p]到a[r]的元素按照x划分,大于x的在左边,小于x的在右边
	{
		int i, j;
		for (i = p, j = r; i<j; i++)
		{
			if (a[i]>x)
			{
				while (i<j&&a[j]>x)
					j--;
				if (i != j) {
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
					j--;
				}
			}
		}
		return i - 1;
	}
	int select(int p, int r, int k)   //寻找中位数
	{
		if (r - p<5) {
			bubble(p, r);
			return a[p + k - 1];
		}
		for (int i = 0; i<(r - p - 4) / 5; i++)
		{
			int s = p + 5 * i, t = s + 4;
			bubble(s, t);
			int temp = a[p + i];
			a[p + i] = a[s + 2];
			a[s + 2] = temp;
		}
		int x = select(p, p + (r - p - 4) / 5, (r - p + 6) / 10);
		int i = partition(p, r, x);
		int j = i - p + 1;
		if (k <= j)
			return select(p, i, k);
		else
			return select(i + 1, r, k - j);
	}
};
void main()
{
	clock_t   start, end;
	double   elapsed;
	srand((int)time(NULL));
	for (int k = 0; k<N; k++)
	{
		a[k] = random();
		cout << a[k] << "\t";
	}
	cout << endl;
	start = clock();
	Find f;
	int n = 5000;
	cout << "The No." << n << " is :" << f.select(0, N - 1, n) << endl;
	end = clock();
	elapsed = ((double)(end - start));///CLOCKS_PER_SEC;
	cout << "Time: " << elapsed << endl;
	system("pause");
}
