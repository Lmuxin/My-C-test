//ϰ��10-5 �ݹ����Ackermenn������15 �֣�
//����Ҫ��ʵ��Ackermenn�����ļ��㣬�亯���������£�
//
//�����ӿڶ��壺
//int Ack( int m, int n );
//����m��n���û�����ķǸ�����������Ack����Ackermenn��������Ӧֵ����Ŀ��֤����������ڳ�����
//��Χ�ڡ�
//���в��Գ���������
//#include <stdio.h>
//
//int Ack( int m, int n );
//
//int main()
//{
//    int m, n;
//
//    scanf("%d %d", &m, &n);
//    printf("%d\n", Ack(m, n));
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//����������
//2 3
//���������
//9


#include <stdio.h>

int Ack( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    printf("%d\n", Ack(m, n));

    return 0;
}

int Ack( int m, int n )
{
    int sum;
    if(m==0)
    {
        sum=n+1;
    }

    else if(n==0&&m>0)
        sum=Ack(m-1,1);
    else  if(m>0&&n>0)
     {

      sum=Ack(m-1,Ack(m,n-1));
      }

        return sum;


}
