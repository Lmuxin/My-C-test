//习题8-3 数组循环右移（20 分）
//本题要求实现一个对数组进行循环右移的简单函数：一个数组a中存有n（>0）个整数，将每个整数循环向右移m（≥0）个位置，即将a中的数据由（a
//​0
//​​ a
//​1
//​​ ⋯a
//​n−1
//​​ ）变换为（a
//​n−m
//​​ ⋯a
//​n−1
//​​ a
//​0
//​​ a
//​1
//​​ ⋯a
//​n−m−1
//​​ ）（最后m个数循环移至最前面的m个位置）。
//
//函数接口定义：
//
//int ArrayShift( int a[], int n, int m );
//其中a[]是用户传入的数组；n是数组的大小；m是右移的位数。函数ArrayShift须将循环右移后的数组仍然存在a[]中。
//
//裁判测试程序样例：
//
//#include <stdio.h>
//#define MAXN 10
//
//int ArrayShift( int a[], int n, int m );
//
//int main()
//{
//    int a[MAXN], n, m;
//    int i;
//
//    scanf("%d %d", &n, &m);
//    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);
//
//    ArrayShift(a, n, m);
//
//    for ( i = 0; i < n; i++ ) {
//        if (i != 0) printf(" ");
//        printf("%d", a[i]);
//    }
//    printf("\n");
//
//    return 0;
//}
//
///* 你的代码将被嵌在这里 */
//输入样例：
//
//6 2
//1 2 3 4 5 6
//输出样例：
//
//5 6 1 2 3 4


#include <stdio.h>
#define MAXN 10

int ArrayShift( int a[], int n, int m );

int main()
{
    int a[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    for ( i = 0; i < n; i++ ) scanf("%d", &a[i]);

    ArrayShift(a, n, m);

    for ( i = 0; i < n; i++ ) {
        if (i != 0) printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");

    return 0;
}

///哈哈哈 尼玛 我写对啦 啦啦啦
int ArrayShift( int a[], int n, int m )
{
    int i=0,j=0,k;
    int b[100]={0};

    for(;i<m;i++)
    {
        b[j++]=a[n-m+i];
    }
    i=0;
    for(;i<m;i++){
    for(k=n-m+i;k>=0;k--)
    {
      a[k]=a[k-1];
        }
    }
    i=0;j=0;

    for(;i<m;i++)
        a[j++]=b[i];
    return a;
}




