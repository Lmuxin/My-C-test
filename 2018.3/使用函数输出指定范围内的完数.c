/*ϰ��6-3 ʹ�ú������ָ����Χ�ڵ�������20 �֣�
����Ҫ��ʵ��һ�������������Ӻ͵ļ򵥺�������������ʵ����һ�������������������m��n��0<m��n��10000��֮���������������ν�������Ǹ���ǡ�õ��ڳ������������֮�͡����磺6=1+2+3������1��2��3Ϊ6�����ӡ�

�����ӿڶ��壺
int factorsum( int number );
void PrintPN( int m, int n );
���к���factorsum�뷵��int number�����Ӻͣ�����PrintPNҪ�������������Χ[m, n]��ÿ�������������ۼ���ʽ�ķֽ�ʽ��ÿ������ռһ�У���ʽΪ������ = ����1 + ����2 + ... + ����k�����������������Ӿ�������˳��������������������û�������������һ�С�No perfect number����

���в��Գ���������
#include <stdio.h>

int factorsum( int number );
void PrintPN( int m, int n );

int main()
{
    int i, m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);

    return 0;
}
*/

/* ��Ĵ��뽫��Ƕ������ */

/*��������1��
1 30
�������1��
1 is a perfect number
1 = 1
6 = 1 + 2 + 3
28 = 1 + 2 + 4 + 7 + 14
��������2��
7 25
�������2��
No perfect number
*/

#define N 100

int factorsum( int number );
void PrintPN( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( factorsum(m) == m ) printf("%d is a perfect number\n", m);
    if ( factorsum(n) == n ) printf("%d is a perfect number\n", n);
    PrintPN(m, n);

    return 0;
}

int factorsum( int number ){
    int a[N],i,j=0,n=0,sum=0;

    if(number == 1)
        return 1;

    for(i=1;i<number;i++)
        if(number%i==0){
            a[j++]=i;
        }

    for(i=0;i<j;i++)
        sum+=a[i];

    if(sum == number)
        return 1;
    return 0;
}
void PrintPN( int m, int n ){
    int i,j,k=0,l,a[N];
    if(m==1){
        printf("%d = %d\n",m , m);
        m+=1;
    }

    for(i=m;i<=n;i++){
        if(factorsum(i)==1){
            for(j=1;j<i;j++){
                if(i%j==0){
                    a[k++]=j;
                }
            }
            printf("%d = ", i);
            for(l=0;l<k-1;l++)
                printf("%d + ", a[l]);
            printf("%d\n", a[l]);
            k=0;
        }
    }
}


