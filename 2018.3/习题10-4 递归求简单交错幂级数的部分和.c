//习题10-4 递归求简单交错幂级数的部分和（15 分）
//本题要求实现一个函数，计算下列简单交错幂级数的部分和：
//f(x,n)=x−x
//​2
//​​+x
//​3
//​​−x
//​4
//​​+⋯+(−1)
//​n−1
//​​x
//​n
//​​
//函数接口定义：
//double fn( double x, int n );
//其中题目保证传入的n是正整数，并且输入输出都在双精度范围内。函数fn应返回上述级数的部分和。建议尝试用递归实现。
//裁判测试程序样例：
//#include <stdio.h>
//
//double fn( double x, int n );
//
//int main()
//{
//    double x;
//    int n;
//
//    scanf("%lf %d", &x, &n);
//    printf("%.2f\n", fn(x,n));
//
//    return 0;
//}
//
///* 你的代码将被嵌在这里 */
//输入样例：
//0.5 12
//输出样例：
//0.33


#include <stdio.h>
#include <math.h>

double fn( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));

    return 0;
}


//这是老子写的可行的 但是没用递归
//double fn( double x, int n )
//{
//
//    double sum;
//        int k=-1,i=1;
//        double a;
//     for(;i<=n;i++)
//     {    a=pow(x,i);
//         if(i%2==0)
//         {
//             a*=k;
//         }
//          sum+=a;
//     }
// return  sum;
//}

//递归


double fn( double x, int n )
{
    if(n==1)return x;
    else return x*(1-fn(x,n-1));
}

////下面是错的
//double fn( double x, int n )
//{
//
//    int i,k=-1;
//     double sum,a;
//     if(n==0)
//        sum=1;
//        if(n==1)
//            sum=x;
//        if(n>1){
//
//
//                     i=n-1;
//
//                     a=fn(x,i)*x;
//                     if(n%2==0)
//                       {a*=k;}
//                       i--;
//                     sum+=a;
//                 }
//
//
//
//    return sum;
//}
//
