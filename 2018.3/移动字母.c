//��ϰ8-8 �ƶ���ĸ��10 �֣�
//����Ҫ���д�������������ַ�����ǰ3���ַ��Ƶ����
//
//�����ӿڶ��壺
//void Shift( char s[] );
//����char s[]���û�������ַ�������Ŀ��֤�䳤�Ȳ�С��3������Shift�뽫����Ҫ��任����ַ�����Ȼ����s[]�
//
//���в��Գ���������
//#include <stdio.h>
//#include <string.h>
//
//#define MAXS 10
//
//void Shift( char s[] );
//
//void GetString( char s[] ); /* ʵ��ϸ���ڴ˲��� */
//
//int main()
//{
//    char s[MAXS];
//
//    GetString(s);
//    Shift(s);
//    printf("%s\n", s);
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//����������
//abcdef
//���������
//defabc


#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift( char s[] );

void GetString( char s[] ); /* ʵ��ϸ���ڴ˲��� */

int main()
{
    char s[MAXS];

    GetString(s);
    Shift(s);
    printf("%s\n", s);

    return 0;
}



//void Shift( char s[] )
//{
//
//  int i=0,j=0,m=0,n=0,count;
//  for(;n<MAXS;n++)
//  {
//      if(s[i]!='\n')
//        count++;
//  }
//  char c1[3],c2[3];//��Ҳ֪�������������
//  for(;i<3;i++)
//    c1[j++]=s[i];
//  c2[m++]=s[count-2+i]
//
//
//}
//
//void GetString( char s[] )
//{
//    char c;
//
//    int i=0,j=0;
//    while(c!='\n')
//    {
//
//        c=getchar();
//        s[i++]=c;
//
//    }
////    for(;j<=i;j++)
////        printf("%c",s[j]);
//
//
//
//}
//
//
////�������� ��ô�벻������


void GetString(char s[])
{
    scanf("%s", s);
    return;//voidҲд��return�ȽϺ�
}

void Shift(char s[])
{
    int i, t, d = 0, e;
    char a[100], b[100];
    memset(a, 0, sizeof(a));//abc���鶼û�г�ʼ������������ݲ��ܱ�֤��������
    memset(b, 0, sizeof(b));//��������ĵ�������������������������Ͼʹ���

    e = strlen(s);
    for (i = 0; i<e; i++) {
        if (i <= 2) {
            a[i] = s[i];
        }
        if (i>2) {
            b[d++] = s[i];

        }
    }
    d = 0;
    t = strlen(b);
    for (i = 0; i<e; i++) {
        if (i<t) {
            s[i] = b[i];

        }
        if (i >= t) {
            s[i] = a[d];

            d++;
        }
    }

    return;//voidҲд��return�ȽϺ�
}










