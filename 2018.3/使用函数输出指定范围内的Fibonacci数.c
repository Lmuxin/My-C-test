/*ϰ��6-4 ʹ�ú������ָ����Χ�ڵ�Fibonacci����20 �֣�
����Ҫ��ʵ��һ������Fibonacci���ļ򵥺�������������ʵ����һ�������������������m��n��0<m��n��10000��֮�������Fibonacci������νFibonacci���о���������һ��������ǰ����ĺͣ��ʼ���������Ϊ1�������С�

�����ӿڶ��壺
int fib( int n );
void PrintFN( int m, int n );
���к���fib�뷵�ص�n��Fibonacci��������PrintFNҪ��һ�������������Χ[m, n]�ڵ�����Fibonacci�����������ּ���һ���ո���ĩ�����ж���ո��������������û��Fibonacci���������һ�С�No Fibonacci number����

���в��Գ���������
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
/* ��Ĵ��뽫��Ƕ������ */
/*��������1��
20 100 7
�������1��
fib(7) = 13
21 34 55 89
��������2��
2000 2500 8
�������2��
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
 ��д��
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
            /*if (index == 1)//index��ȫ���Բ�Ҫ��
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
