//ϰ��6-6 ʹ�ú������һ����������������20 �֣�
//����Ҫ��ʵ��һ�����������������ļ򵥺�����
//
//�����ӿڶ��壺
//int reverse( int number );
//���к���reverse�뷵���û����������number����������
//
//���в��Գ���������
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
///* ��Ĵ��뽫��Ƕ������ */
//����������
//-12340
//���������
//-4321
//����: C�γ���
//��λ: �㽭��ѧ
//ʱ������: 400ms
//�ڴ�����: 64MB


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

//��ô���㶼����д ����������

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
