//#include"stdafx.h"
#include<iostream>
#include   <stdlib.h>
using namespace std;

int Select(int a[], int p, int r, int k)//ѡ����ڼ�СԪ����ʲô
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
		{//��a[p + 5 * i]��a[p + 5 * i + 4]�ĵ�3СԪ����a[p + i]����λ�ã�
		//����λ������λ����-p-4������˵��n-5
		bubblesort(a,p+5*i,p+5*i+4);//
		Swap(a[p+5*i+2],a[p+i]);
		}
	int x= Select(a, p, p + (r - p - 4), (r - p - 4) / 10);
	int i = Partition(a, p, r, x);
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
//���ֺ���

int Partition(int a[], int p, int r,int x)
{
	void Swap(int m, int n);
	int i = p, j = r + 1;
	 x = a[p];
	//��С��x��Ԫ�ؽ�������ߵ�����
	//������x��Ԫ�ؽ������ұߵ�����
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
//Ԫ�ؽ�������
void Swap(int m, int n)
{
	int temp;

		temp = m;
	m = n;
	n = temp;
}

//ð������
void bubblesort(int a[],int first, int end) //ð������
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
{   //��������
	int Select(int a[], int p, int r, int k);
	int Partition(int a[], int p, int r);
	void Swap(int m, int n);
	void bubblesort(int a[], int first, int end);
	int Random(int x, int y);

	int a[200];


	for (int i = 0; i < 200; i++)
	{
		a[i] = Random(0, 1000);//1000���ڵ������
		cout << "a[" << i << "]:" << a[i] << "\n";
	}
	cout << endl;
	int k;
	cout<<"������ڼ�СԪ��k:"<<endl;
	cin>>k;
	cout<<endl;
	cout << "��";
	cout<<k;
	cout<<"СԪ����" << Select(a, 0, 199, k) << endl;

	//����
	bubblesort(a, 0, 199);
	cout<<endl;
	for (int i = 0; i < 200; i++)
	{
		//a[i] = Random(0, 100);
		cout << "a[" << i << "]:" << a[i] << " ";

	}
	cout << endl;

}
