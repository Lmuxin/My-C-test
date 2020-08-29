//习题10-2 递归求阶乘和（15 分）
//本题要求实现一个计算非负整数阶乘的简单函数，并利用该函数求 1!+2!+3!+...+n! 的值。
//函数接口定义：
//double fact( int n );
//double factsum( int n );
//函数fact应返回n的阶乘，建议用递归实现。函数factsum应返回 1!+2!+...+n! 的值。题目保证输入输出在双精度范围内。
//裁判测试程序样例：
//#include <stdio.h>
//
//double fact( int n );
//double factsum( int n );
//
//int main()
//{
//    int n;
//
//    scanf("%d",&n);
//    printf("fact(%d) = %.0f\n", n, fact(n));
//    printf("sum = %.0f\n", factsum(n));
//
//    return 0;
//}
//
///* 你的代码将被嵌在这里 */
//输入样例1：
//10
//输出样例1：
//fact(10) = 3628800
//sum = 4037913
//输入样例2：
//0
//输出样例2：
//fact(0) = 1
//sum = 0



#include <stdio.h>

double fact( int n );
double factsum( int n );

int main()
{
    int n;

    scanf("%d",&n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));

    return 0;
}

double fact( int n )
{
    double s=0;
    int i=2;
    if(n==1)
      {

      s=1;
}
    else {
     for(;i<=n;i++)
        s=fact(i-1)*i;
    }
    return s;


}
double factsum( int n )
{
double sum=0;
int i=1;
for(;i<=n;i++)
    sum+=fact(i);
return sum;

}
