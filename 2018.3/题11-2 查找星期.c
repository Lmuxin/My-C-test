//��11-2 �������ڣ�15 �֣�
//����Ҫ��ʵ�ֺ��������Ը����±���ҵ����ڣ����ض�Ӧ����š�
//���
//����
//0
//Sunday
//1
//Monday
//2
//Tuesday
//3
//Wednesday
//4
//Thursday
//5
//Friday
//6
//Saturday
//�����ӿڶ��壺
//int getindex( char *s );
//����getindexӦ�����ַ���s��š��������Ĳ���s����һ���������ڵ��ַ������򷵻�-1��
//���в��Գ���������
//#include <stdio.h>
//#include <string.h>
//
//#define MAXS 80
//
//int getindex( char *s );
//
//int main()
//{
//    int n;
//    char s[MAXS];
//
//    scanf("%s", s);
//    n = getindex(s);
//    if ( n==-1 ) printf("wrong input!\n");
//    else printf("%d\n", n);
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//��������1��
//Tuesday
//�������1��
//2
//��������2��
//today
//�������2��
//wrong input!


#include <stdio.h>
#include <string.h>

#define MAXS 80

int getindex( char *s );

int main()
{
    int n;
    char s[MAXS];

    scanf("%s", s);
    n = getindex(s);
    if ( n==-1 ) printf("wrong input!\n");
    else printf("%d\n", n);

    return 0;
}

int getindex( char *s )
{
    int a;
      if(s=="Sunday")
            a=0;
      if(s=="Monday")
            a=1;
        if(s=="Tuesday")
            a=2;
        if(s=="Wednesday")
             a=3;
        if(s=="Thursday")
             a=4;
             a=4;
        if(s=="Friday")
             a=5;
              if(s=="Saturday")
             a=6;
             else a=-1;
    return a;
}
