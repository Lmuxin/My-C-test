//ϰ��11-1 ����·�Ӣ������15 �֣�
//����Ҫ��ʵ�ֺ��������Է���һ�������·ݵ�Ӣ�����ơ�
//�����ӿڶ��壺
//char *getmonth( int n );
//����getmonthӦ���ش洢��n��Ӧ���·�Ӣ�����Ƶ��ַ���ͷָ�롣�������Ĳ���n����һ�������·ݵ����֣��򷵻ؿ�ָ��NULL��
//���в��Գ���������
//#include <stdio.h>
//
//char *getmonth( int n );
//
//int main()
//{
//    int n;
//    char *s;
//
//    scanf("%d", &n);
//    s = getmonth(n);
//    if ( s==NULL ) printf("wrong input!\n");
//    else printf("%s\n", s);
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//��������1��
//5
//�������1��
//May
//��������2��
//15
//�������2��
//wrong input!


#include <stdio.h>

char *getmonth( int n );

int main()
{
    int n;
    char *s;

    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);

    return 0;
}

char *getmonth( int n )
{  char *m;

    if(n<=0||n>12)
        m=NULL;
     else
     {

         switch(n)
         {

             case 1: m="JAN"; break;
             case 2: m="FEB"; break;
             case 3: m="MAR"; break;
             case 4: m="APR"; break;
             case 5: m="MAY";break;
             case 6:  m="JUN";break;
             case 7:  m="jul";break;
             case 8:  m="aug";break;
             case 9: m="sep"; break;
             case 10: m="oct"; break;
             case 11: m="nov"; break;
             case 12:  m="dec";break;
         }

     }

     return m;
}
