//ϰ��8-9 ����ͳ�Ƹ����ַ�������15 �֣�
//����Ҫ��ʵ��һ��������ͳ�Ƹ����ַ����еĴ�д��ĸ��Сд��ĸ���ո������Լ������ַ����ж��١�
//
//�����ӿڶ��壺
//
//void StringCount( char *s );
//���� char *s ���û�������ַ���������StringCount����һ���ڰ���
//
//��д��ĸ���� Сд��ĸ���� �ո���� ���ָ��� �����ַ�����
//�ĸ�ʽ�����
//
//���в��Գ���������
//
//#include <stdio.h>
//#define MAXS 15
//
//void StringCount( char *s );
//void ReadString( char *s ); /* �ɲ���ʵ�֣���ȥ���� */
//
//int main()
//{
//    char s[MAXS];
//
//    ReadString(s);
//    StringCount(s);
//
//    return 0;
//}
//
///* Your function will be put here */
//����������
//
//aZ&*?
//093 Az
//���������
//
//2 2 1 3 4


#include <stdio.h>
#define MAXS 15

void StringCount( char *s );
void ReadString( char *s ); /* �ɲ���ʵ�֣���ȥ���� */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}


void StringCount( char *s )
{
    int upl=0,litl=0,blank=0,dig=0,other=0;
    int len=strlen(s);
    int i=0;
    for(;i<len;i++)
    {
        if(s[i]>='A'&&s[i]<='Z')
            upl++;
        else if(s[i]>='a'&&s[i]<='z')
            litl++;
        else if(s[i]>='0'&&s[i]<='9')
            dig++;
        else if(s[i]==" ")
            blank++;
        else other++;

    }
printf("��д��ĸ%d,Сд��ĸ%d,����%d,�ո�%d,����%d",upl,litl,dig,blank ,other);

}
void ReadString( char *s ) /* �ɲ���ʵ�֣���ȥ���� */
{


scanf("%s",s);
}
