//ϰ��11-4 �ַ��������ӣ�15 �֣�
//����Ҫ��ʵ��һ���������������ַ�������������
//�����ӿڶ��壺
//char *str_cat( char *s, char *t );
//����str_catӦ���ַ���t���Ƶ��ַ���s��ĩ�ˣ����ҷ����ַ���s���׵�ַ��
//���в��Գ���������
//#include <stdio.h>
//#include <string.h>
//
//#define MAXS 10
//
//char *str_cat( char *s, char *t );
//
//int main()
//{
//    char *p;
//    char str1[MAXS+MAXS] = {'\0'}, str2[MAXS] = {'\0'};
//
//    scanf("%s%s", str1, str2);
//    p = str_cat(str1, str2);
//    printf("%s\n%s\n", p, str1);
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//����������
//abc
//def
//���������
//abcdef
//abcdef


#include <stdio.h>
#include <string.h>

#define MAXS 10

char *str_cat( char *s, char *t );

int main()
{
    char *p;
    char str1[MAXS+MAXS] = {'\0'}, str2[MAXS] = {'\0'};

    scanf("%s%s", str1, str2);
    p = str_cat(str1, str2);
    printf("%s\n%s\n", p, str1);

    return 0;
}

char *str_cat( char *s, char *t )
{
    int i=0;
    int len;
    len=strlen(s);
    for(;i<strlen(t);i++)
       *(s+len+i)=*(t+i);

    return s;

}
