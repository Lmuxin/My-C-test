/*ϰ��6-5 ʹ�ú�����֤��°ͺղ��루20 �֣�
����Ҫ��ʵ��һ���ж������ļ򵥺����������øú�����֤��°ͺղ��룺�κ�һ����С��6��ż�����ɱ�ʾΪ����������֮�͡���������ֻ�ܱ�1��������������������ע�⣺1����������2��������

�����ӿڶ��壺
int prime( int p );
void Goldbach( int n );
���к���prime���û��������pΪ����ʱ����1�����򷵻�0������Goldbach���ո�ʽ��n=p+q�����n�������ֽ⣬����p��q��Ϊ����������Ϊ�����ķֽⲻΨһ������24���Էֽ�Ϊ5+19�������Էֽ�Ϊ7+17����Ҫ�����������н���p��С�Ľ⡣

���в��Գ���������
#include <stdio.h>
#include <math.h>

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

    return 0;
}*/

/* ��Ĵ��뽫��Ƕ������ */
/*
����������
89 100
���������
89 is a prime number
90=7+83, 92=3+89, 94=5+89, 96=7+89, 98=19+79
100=3+97,
*/

#include <stdio.h>
#include <math.h>
#define N 100

int prime( int p );
void Goldbach( int n );

int main()
{
    int m, n, i, cnt;

    scanf("%d %d", &m, &n);
    if ( prime(m) != 0 ) printf("%d is a prime number\n", m);
    if ( m < 6 ) m = 6;
    if ( m%2 ) m++;
    cnt = 0;
    for( i=m; i<=n; i+=2 ) {
        Goldbach(i);
        cnt++;
        if ( cnt%5 ) printf(", ");
        else printf("\n");
    }

    return 0;
}

//
//int prime( int p )
//{  int i=2;
//    if(p>=2)
//    {
//    for(;i<p;i++)
//       {
//
//       if(p%1!=0)
//        return 1;
//        break;
//       }
//    }
//    else
//    return 0;
//
//
//}
//void Goldbach( int n )
//{
//    int i=1,j=0,a[100];
//    for(;i<n;i++)
//        if(prime(i)==1)
//          a[j==]=i;
//
//
//
//}

int prime( int p ){
	int i;
	for(i=2;i<p;i++){
		if(p%i==0)
			break;
	}
	if(i>=p)
		return 1;
	else
		return 0;

}
void Goldbach( int n ){
	int a[N],i,j=0,k=0,flag=0;
	for(i=2;i<n;i++){
		if(prime(i)==1){
			a[j++]=i;
		}
	}

	for(i=0;i<j;i++){
		for(k=0;k<j;k++){
			if(a[i]+a[k]==n){
				printf("%d = %d + %d", n, a[i], a[k]);
				flag=1;
				break;
			}
		}
		if(flag)
			break;
	}
}
