//ϰ��10-1 �ж�������������λ����15 �֣�
//����Ҫ��ʵ��һ��������ͳ�Ƹ��������ڵ���λ��������λ������ͬ����ȫƽ��������144��676���ĸ�����
//�����ӿڶ��壺
//int search( int n );
//���д���Ĳ���int n��һ����λ���������������λ���ַ�0��������search����[101, n]�����������������������ĸ�����
//���в��Գ���������
//#include <stdio.h>
//#include <math.h>
//
//int search( int n );
//
//int main()
//{
//    int number;
//
//    scanf("%d",&number);
//    printf("count=%d\n",search(number));
//
//    return 0;
//}
//
//
///* ��Ĵ��뽫��Ƕ������ */
//����������
//500
//���������
//count=6
//\
//


#include <stdio.h>
#include <math.h>

int search( int n );

int main()
{
    int number;

    scanf("%d",&number);
    printf("count=%d\n",search(number));

    return 0;
}

int search( int n )
{

    int shi,ge,bai;
    int i=101;
    int s[100];
    int count=0;

    for(;i<n;i++)
    {
        ge=i%10;
        shi=i/10%10;
        bai=i/100;
        if(ge==shi||ge==bai||shi==bai)
        {  int j=1,k=0;
            for(;j<i;j++)
                if(j*j==i)
          count++;

        }
    }
    return count;
}
