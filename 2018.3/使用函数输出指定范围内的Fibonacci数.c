/*习题6-4 使用函数输出指定范围内的Fibonacci数（20 分）
本题要求实现一个计算Fibonacci数的简单函数，并利用其实现另一个函数，输出两正整数m和n（0<m≤n≤10000）之间的所有Fibonacci数。所谓Fibonacci数列就是满足任一项数字是前两项的和（最开始两项均定义为1）的数列。

函数接口定义：
int fib( int n );
void PrintFN( int m, int n );
其中函数fib须返回第n项Fibonacci数；函数PrintFN要在一行中输出给定范围[m, n]内的所有Fibonacci数，相邻数字间有一个空格，行末不得有多余空格。如果给定区间内没有Fibonacci数，则输出一行“No Fibonacci number”。

裁判测试程序样例：
#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );

int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}
*/
/* 你的代码将被嵌在这里 */
/*输入样例1：
20 100 7
输出样例1：
fib(7) = 13
21 34 55 89
输入样例2：
2000 2500 8
输出样例2：
fib(8) = 21
No Fibonacci number
*/

#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );

int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}

/*
 我写的
int fib( int n )
{int f1=1,f2=1,fn,i;
if(n<=2)
    return 1;
else
    fn=fib(n-1)+fib(n-2);
    return fn;

}
void PrintFN( int m, int n )
{
     int i=m;
     int a=i+i+1;
     int b=i+2;

     for(;i<=n;i++)

          if(a==b)
            printf("%d %d %d",i,a,b);
            else
             printf("No Fibonacci number");



}
*/

int fib(int n)
{
    int i, x1, x2, x;
    x=0;
    x1=1;
    x2=1;
    for (i=3; i<=n; i++)
    {
        x=x1+x2;
        x1=x2;
        x2=x;
    }
    if (n==1 || n==2)
        x=1;
    return x;
}


void PrintFN(int m, int n)
{
    int i, count, index, flag;
    index=0;
    flag=0;
    i=1;
    while (fib(i) < 10000)
        i++;
    count = i;
    for (i = 1; i < count; i++)
    {
        if (fib(i) >= m && fib(i) <= n)
        {
            flag = 1;
            //index++;
            /*if (index == 1)//index完全可以不要嘛
            {
                printf("%d", fib(i));
                continue;
            }*/
            printf(" %d", fib(i));
        }
    }
    if (!flag)
        printf("No Fibonacci number");
    putchar('\n');
}
