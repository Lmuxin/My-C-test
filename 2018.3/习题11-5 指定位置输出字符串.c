//ϰ��11-5 ָ��λ������ַ�����20 �֣�
//����Ҫ��ʵ��һ���������Ը�����һ���ַ����������ַ�����ӡ�������ַ����д����һ���ַ�ƥ���λ�ÿ�ʼ����ڶ����ַ�ƥ���λ��֮��������ַ���
//�����ӿڶ��壺
//char *match( char *s, char ch1, char ch2 );
//����matchӦ��ӡs�д�ch1��ch2֮��������ַ������ҷ���ch1�ĵ�ַ��
//���в��Գ���������
//#include <stdio.h>
//
//#define MAXS 10
//
//char *match( char *s, char ch1, char ch2 );
//
//int main()
//{
//    char str[MAXS], ch_start, ch_end, *p;
//
//    scanf("%s\n", str);
//    scanf("%c %c", &ch_start, &ch_end);
//    p = match(str, ch_start, ch_end);
//    printf("%s\n", p);
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//��������1��
//program
//r g
//�������1��
//rog
//rogram
//��������2��
//program
//z o
//�������2��
//(����)
//(����)
//��������3��
//program
//g z
//�������3��
//gram
//gram
//



#include <stdio.h>
#include<string.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

//char *match( char *s, char ch1, char ch2 )
//{
//    int i=0,j=0,a,b;
//    char *c=NULL;;
//    for(;i<strlen(s);i++)
//    {
//        if(s[i]==ch1)
//       {
//
//       a=i;
//        c=&s[a];
//        break;
//       }
//    }
//    j=a+1;
//    for(;j<strlen(s);j++)
//    {
//        if(s[j]==ch2)
//        b=j;
//          break;
//    }
//    int m;
//    i=0;
//   for(m=a+1;m<b;m++)
//    printf("%c",s[m]);
//
//    return c;
//}


char *match( char *s, char ch1, char ch2 ){

    int i=0,j=0,k=0,len=0;
    char *p=NULL;

    len = strlen(s);

    for(i=0;i<len;i++)
        {
            if(s[i]==ch1)
            {
                    p=&s[i];
                    for(j=i;j<len;j++)
                    {
                            if(s[j]!=ch2)
                                {
                                    printf("%c", s[j]);
                                }
                          if(s[j]==ch2)
                              {
                                  printf("%c\n", s[j]);
                                  return p;
                               }
                   }
                   printf("\n");
                   return p;
               }
    }
    printf("\n");
    return p;
}

