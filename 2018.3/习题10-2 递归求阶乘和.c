//ϰ��10-2 �ݹ���׳˺ͣ�15 �֣�
//����Ҫ��ʵ��һ������Ǹ������׳˵ļ򵥺����������øú����� 1!+2!+3!+...+n! ��ֵ��
//�����ӿڶ��壺
//double fact( int n );
//double factsum( int n );
//����factӦ����n�Ľ׳ˣ������õݹ�ʵ�֡�����factsumӦ���� 1!+2!+...+n! ��ֵ����Ŀ��֤���������˫���ȷ�Χ�ڡ�
//���в��Գ���������
//#include <stdio.h>
//
//double fact( int n );
//double factsum( int n );
//
//int main()
//{
//    int n;
//
//    scanf("%d",&n);
//    printf("fact(%d) = %.0f\n", n, fact(n));
//    printf("sum = %.0f\n", factsum(n));
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//��������1��
//10
//�������1��
//fact(10) = 3628800
//sum = 4037913
//��������2��
//0
//�������2��
//fact(0) = 1
//sum = 0



#include <stdio.h>

double fact( int n );
double factsum( int n );

int main()
{
    int n;

    scanf("%d",&n);
    printf("fact(%d) = %.0f\n", n, fact(n));
    printf("sum = %.0f\n", factsum(n));

    return 0;
}

double fact( int n )
{
    double s=0;
    int i=2;
    if(n==1)
      {

      s=1;
}
    else {
     for(;i<=n;i++)
        s=fact(i-1)*i;
    }
    return s;


}
double factsum( int n )
{
double sum=0;
int i=1;
for(;i<=n;i++)
    sum+=fact(i);
return sum;

}
