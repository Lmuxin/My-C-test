#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

void count_num(int,int);
int count[10]= {0};

int main()
{
    ifstream infile;
infile.open("input.txt");
 if(!infile)
 {
 cout << "�봴��һ���ļ���д��ҳ��" << endl;
 }
 int n,m,o=0;
 double a;
 infile >> n;
 infile.close();
 m = log10(n) + 1;//n��λ��
 count_num(n,m);
 for(int i=0; i<m; i++)
 {
 a = pow(10,i);
 o += int(a);//������0
 }
 count[0] -= o;
 ofstream outfile;
 outfile.open("output.txt",ios::trunc);
 for(int i=0; i<10; i++)
 {
 outfile << count[i] << endl;
 }
 outfile.close();
}

void count_num(int n,int m)
{
 double len = pow(10,m-1);//����ĳ���
 int high = n/int(len);//���λ�����Ǽ�
 double num = high*(m-1)*pow(10,m-2);//high��������ÿ�����ֵĸ���
 for(int i=0; i<10; i++)
 {
 count[i] += int(num);
 }
 for(int i=0; i<high; i++)
 {
 count[i] += int(len);//�������λ�ϵ����ֵĴ���
 }
 int l = n%int(len);//ȥ�����λ����
 count[high] += (l+1);//���λ���ֵĴ���
 if(m > 1) return count_num(l,m-1);//�ݹ�ѭ����һλ��ʱ����
}
