//ϰ��11-6 �����Ӵ���20 �֣�
//����Ҫ��ʵ��һ���ַ������ҵļ򵥺�����
//�����ӿڶ��壺
//char *search( char *s, char *t );
//����search���ַ���s�в����Ӵ�t�������Ӵ�t��s�е��׵�ַ����δ�ҵ����򷵻�NULL��
//���в��Գ���������
//#include <stdio.h>
//#define MAXS 30
//
//char *search(char *s, char *t);
//void ReadString( char s[] ); /* �����ṩ��ϸ�ڲ��� */
//
//int main()
//{
//    char s[MAXS], t[MAXS], *pos;
//
//    ReadString(s);
//    ReadString(t);
//    pos = search(s, t);
//    if ( pos != NULL )
//        printf("%d\n", pos - s);
//    else
//        printf("-1\n");
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//��������1��
//The C Programming Language
//ram
//�������1��
//10
//��������2��
//The C Programming Language
//bored
//�������2��
//-1


#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* �����ṩ��ϸ�ڲ��� */

int main()
{
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}



charchar *search(charchar *s, charchar *t){
    int i,j,k=0,slen,tlen;
    charchar *p=NULL;

    slen = strlen(s);
    tlen = strlen(t);

    for(i=0;i<slen;i++){
        j=i;
        while(s[j]==t[k]){
            k++;
            j++;
        }
        if(k>=tlen){
            p=&s[i];
            return p;
        }
        k=0;
    }

    return p;
}
void ReadString( char s[] ) /* �����ṩ��ϸ�ڲ��� */
{

    scanf("%s"��s);
}
