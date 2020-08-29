//习题10-8 递归实现顺序输出整数（15 分）
//本题要求实现一个函数，对一个整数进行按位顺序输出。
//函数接口定义：
//void printdigits( int n );
//函数printdigits应将n的每一位数字从高位到低位顺序打印出来，每位数字占一行。
//裁判测试程序样例：
//#include <stdio.h>
//
//void printdigits( int n );
//
//int main()
//{
//    int n;
//
//    scanf("%d", &n);
//    printdigits(n);
//
//    return 0;
//}
//
///* 你的代码将被嵌在这里 */
//输入样例：
//12345
//输出样例：
//1
//2
//3
//4
//5


#include <stdio.h>

void printdigits( int n );

int main()
{
    int n;

    scanf("%d", &n);
    printdigits(n);

    return 0;
}

void printdigits( int n )
{  int a[20];
    int i=0;
    while(n!=0)
    {  a[i++]=n%10;
        n/=10;
    }
    int j=i-1;

  for(;j>=0;j--)
    printf("%d\n",a[j]);
}
