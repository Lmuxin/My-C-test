/*习题5-7 使用函数求余弦函数的近似值（15 分）
本题要求实现一个函数，用下列公式求cos(x)的近似值，精确到最后一项的绝对值小于e：

cos(x)=x
​0
​​ /0!−x
​2
​​ /2!+x
​4
​​ /4!−x
​6
​​ /6!+⋯

函数接口定义：
double funcos( double e, double x );
其中用户传入的参数为误差上限e和自变量x；函数funcos应返回用给定公式计算出来、并且满足误差要求的cos(x)的近似值。输入输出均在双精度范围内。

裁判测试程序样例：
#include <stdio.h>
#include <math.h>

double funcos( double e, double x );

int main()
{
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}
*/
/* 你的代码将被嵌在这里 */

/*
输入样例：
0.01 -3.14
输出样例：
cos(-3.14) = -0.999899

*/


#include <stdio.h>
#include <math.h>

double funcos( double e, double x );

int main()
{
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}

double funcos( double e, double x )
{
    int temp1=1,temp2=1,temp3=1,sum=1;
    int i,k;

    k=-1;
    for(i=2;temp1>e;i+=2){

        temp2=temp2*x*x;
        temp3=temp3*i*(i-1);
        sum=sum+k*temp2/temp3;
        temp1=temp2/temp3;
        k=-k;

    }

    return sum;


}
