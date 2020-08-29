#include"stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;


int Select(int a[], int p, int r, int k)
{
	int Partition(int a[], int p, int r, int x);
	void bubblesort(int a[], int first, int end);
	void Swap(int m, int n);
	if ((r - p)<75)
	{
		bubblesort(a, p, r);
			return a[p + k - 1];
	}

	for (int i = 0; i <= (r - p - 4) / 5; i++)
		//将a[p + 5 * i]至a[p + 5 * i + 4]的第3小元素与a[p + i]交换位置；
		//找中位数的中位数，-p-4即上面说的n-5
	{
		bubblesort(a, p + 5 * i, p + 5 * i + 4);
		Swap(a[p + 5 * i + 2], a[p + i]);

	}
	int z= Select(a, p, p + (r - p - 4), (r - p - 4) / 10);
	int i = Partition(a, p, r, z);
	int j = i - p + 1;
	if (k <= j)
	{
		return  Select(a, p, i, k);
	}
	else
	{
      return Select(a, i + 1, r, k - j);
	}
}
//划分函数

int Partition(int a[], int p, int r,int x)
{
	void Swap(int m, int n);
	int i = p, j = r + 1;
	 x = a[p];
	//将小于x的元素交换到左边的区域
	//将大于x的元素交换到右边的区域
	while (true) {
		while (a[++i]<x&&i<r);
		while (a[--j]>x);
		if (i >= j)
		{
			break;
		}
		Swap(a[i], a[j]);
	}
	
	return j;
}
//元素交换函数
void Swap(int m, int n)
{
	int temp;

		temp = m;
	m = n;
	n = temp;
}

//冒泡排序
void bubblesort(int a[],int first, int end) //冒泡排序
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




int Random(int x, int y)
{

	int ran_num = rand() % (y - x) + x;
	return ran_num;


}


int main()
{
	int Select(int a[], int p, int r, int k);
	int Partition(int a[], int p, int r);
	void Swap(int m, int n);
	void bubblesort(int a[], int first, int end);
	int Random(int x, int y);
	int a[10];
	//srand(unsigned)time(0);

	for (int i = 0; i < 10; i++)
	{
		a[i] = Random(0, 100);
		cout << "a[" << i << "]:" << a[i] << " ";


	}
	cout << endl;
	cout << "第3小元素是" << Select(a, 0, 9, 3) << endl;
	bubblesort(a, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		a[i] = Random(0, 100);
		cout << "a[" << i << "]:" << a[i] << " ";


	}
	cout << endl;


}