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
 cout << "请创建一个文件并写入页码" << endl;
 }
 int n,m,o=0;
 double a;
 infile >> n;
 infile.close();
 m = log10(n) + 1;//n的位数
 count_num(n,m);
 for(int i=0; i<m; i++)
 {
 a = pow(10,i);
 o += int(a);//多计算的0
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
 double len = pow(10,m-1);//区间的长度
 int high = n/int(len);//最高位数字是几
 double num = high*(m-1)*pow(10,m-2);//high个区间内每个数字的个数
 for(int i=0; i<10; i++)
 {
 count[i] += int(num);
 }
 for(int i=0; i<high; i++)
 {
 count[i] += int(len);//除了最高位上的数字的次数
 }
 int l = n%int(len);//去掉最高位的数
 count[high] += (l+1);//最高位数字的次数
 if(m > 1) return count_num(l,m-1);//递归循环至一位数时跳出
}
