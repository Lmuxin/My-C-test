/*ϰ��6-1 ����ͳ���ַ�������15 �֣�
����Ҫ��ʵ��һ��������ͳ�Ƹ����ַ�����Ӣ����ĸ���ո��س��������ַ��������ַ��ĸ�����

�����ӿڶ��壺
void StringCount( char s[] );
���� char s[] ���û�������ַ���������StringCount����һ���ڰ���

letter = Ӣ����ĸ����, blank = �ո��س�����, digit = �����ַ�����, other = �����ַ�����
�ĸ�ʽ�����

���в��Գ���������
#include <stdio.h>
#define MAXS 15

void StringCount( char s[] );
void ReadString( char s[] ); /* �ɲ���ʵ�֣���ȥ���� */
/*
int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}
*/
/* Your function will be put here */

#include <stdio.h>
#define MAXS 15

void StringCount( char s[] );


int main()
{
    char s[MAXS];
    printf("�����ַ�:");
     char c;
     int i=0;
for(;i<15;i++){
   c=getchar();
   if(c=='\n')//�س�Ҫ�õ�����
    break;
  else

     s[i]=c;

}

    StringCount(s);


    return 0;
}

void StringCount( char s[] )
{
    int digita=0,letter=0,blank=0,others=0;

    int i;
    for(i=0;i<15;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
            digita++;
        else if(  (   s[i]>= 'a' &&    s[i]<='z')  ||   (s[i]>='A' &&    s[i]<='Z' )  )//��ĸ���ֱ���ӵ�����
                letter++;

            else if(s[i]==' ')//�ո��ǵ�����   ����˫����
                blank++;
            else
                others++;
    }
    printf("����%d:,��ĸ%d,�ո�%d,����%d",digita,letter,blank,others);

}



