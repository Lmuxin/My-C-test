//ϰ��10-8 �ݹ�ʵ��˳�����������15 �֣�
//����Ҫ��ʵ��һ����������һ���������а�λ˳�������
//�����ӿڶ��壺
//void printdigits( int n );
//����printdigitsӦ��n��ÿһλ���ִӸ�λ����λ˳���ӡ������ÿλ����ռһ�С�
//���в��Գ���������
//#include <stdio.h>
//
//void printdigits( int n );
//
//int main()
//{
//    int n;
//
//    scanf("%d", &n);
//    printdigits(n);
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//����������
//12345
//���������
//1
//2
//3
//4
//5


#include <stdio.h>

void printdigits( int n );

int main()
{
    int n;

    scanf("%d", &n);
    printdigits(n);

    return 0;
}

void printdigits( int n )
{  int a[20];
    int i=0;
    while(n!=0)
    {  a[i++]=n%10;
        n/=10;
    }
    int j=i-1;

  for(;j>=0;j--)
    printf("%d\n",a[j]);
}
