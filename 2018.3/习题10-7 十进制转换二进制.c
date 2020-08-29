//浙大版《C语言程序设计（第3版）》题目集
//
//1810 分
//
//函数题
//共 45 小题，共计 720 分
//
//编程题
//共 71 小题，共计 1090 分
//高等教育出版社教材-浙大版《C语言程序设计（第3版）》题目集
//题目集仅供查看，请输入读者验证码答题。
//
//开始答题
//
//函数题
//编程题
//习题10-7 十进制转换二进制（15 分）
//本题要求实现一个函数，将正整数n转换为二进制后输出。
//函数接口定义：
//void dectobin( int n );
//函数dectobin应在一行中打印出二进制的n。建议用递归实现。
//裁判测试程序样例：
//#include <stdio.h>
//
//void dectobin( int n );
//
//int main()
//{
//    int n;
//
//    scanf("%d", &n);
//    dectobin(n);
//
//    return 0;
//}
//
///* 你的代码将被嵌在这里 */
//输入样例：
//10
//输出样例：
//1010



#include <stdio.h>

void dectobin( int n );

int main()
{
    int n;

    scanf("%d", &n);
    dectobin(n);

    return 0;
}

void dectobin( int n )
{

    int a[20]={0};
    int i=0;

    while(n!=0)
    {
        a[i++]=n%2;
        n/=2;
    }

    int j=i-1;
    for(;j>=0;j--)
        printf("%d",a[j]);

}
