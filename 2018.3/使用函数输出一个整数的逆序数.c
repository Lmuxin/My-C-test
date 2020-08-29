//习题6-6 使用函数输出一个整数的逆序数（20 分）
//本题要求实现一个求整数的逆序数的简单函数。
//
//函数接口定义：
//int reverse( int number );
//其中函数reverse须返回用户传入的整型number的逆序数。
//
//裁判测试程序样例：
//#include <stdio.h>
//
//int reverse( int number );
//
//int main()
//{
//    int n;
//
//    scanf("%d", &n);
//    printf("%d\n", reverse(n));
//
//    return 0;
//}
//
///* 你的代码将被嵌在这里 */
//输入样例：
//-12340
//输出样例：
//-4321
//作者: C课程组
//单位: 浙江大学
//时间限制: 400ms
//内存限制: 64MB


#include <stdio.h>
#define N 100

int reverse( int number );

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", reverse(n));

    return 0;
}
//int reverse( int number )
//
//{
//    int i,j=0,m,s=0,n;
//    int a[N];
//    if(number<0)
//    {
//        number=-number;
//        while(number)
//        {   m=number%10;
//             a[j++]=m;
//             number/=10;
//
//        }
//        for(i=j;i>0;i--)
//    {
//         n=i*10^(i-1);
//         s+=n;
//
//
//    }
//     return -s;
//
//    }
//    else
//    {
//
//        while(number)
//        {   m=number%10;
//             a[j++]=m;
//             number/=10;
//
//        }
//        for(i=j;i>0;i--)
//    {   n=i*10^(i-1);
//        s+=n;
//
//
//    }
//    return s;
//    }
//
//
//
//
//
//}

//这么简单你都不会写 你有脑子吗

int reverse( int number ){
  int sum, result;
    if(number<0){
        printf("-");
        number = number * -1;
    }
    sum = 0;
    while(number!=0){
        result = number % 10;
        sum = sum * 10 + result;
        number = number / 10;
    }
    return sum;

}
