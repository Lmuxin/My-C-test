//ϰ��8-6 ɾ���ַ���20 �֣�
//����Ҫ��ʵ��һ��ɾ���ַ����е�ָ���ַ��ļ򵥺�����
//
//�����ӿڶ��壺
//
//void delchar( char *str, char c );
//����char *str�Ǵ�����ַ�����c�Ǵ�ɾ�����ַ�������delchar�Ĺ����ǽ��ַ���str�г��ֵ�����c�ַ�ɾ����
//
//���в��Գ���������
//
//#include <stdio.h>
//#define MAXN 20
//
//void delchar( char *str, char c );
//void ReadString( char s[] ); /* �ɲ���ʵ�֣���ȥ���� */
//
//int main()
//{
//    char str[MAXN], c;
//
//    scanf("%c\n", &c);
//    ReadString(str);
//    delchar(str, c);
//    printf("%s\n", str);
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//����������
//
//a
//happy new year
//���������
//
//hppy new yer


#include <stdio.h>
#include <string.h>
#define MAXN 20

void delchar( char *str, char c );
void ReadString( char s[] ); /* �ɲ���ʵ�֣���ȥ���� */

int main()
{
    char str[MAXN], c;

    scanf("%c\n", &c);
    ReadString(str);
    delchar(str, c);
    printf("%s\n", str);

    return 0;
}
//void delchar( char *str, char c )
//{
//
//
//    char ch;
//    int  len;
//
//    len=strlen(str);
//    int i=0;
//    for(;i<len;i++)
//    {
//      //ch='\n';
//        if(str[i]==c)
//            {
//                ch=str[i];
//                str[i]=str[i+1];
//                ch=NULL;
//                continue;
//
//            }
//
//    }
//
//}
void delchar( char *str, char c ){
    int i,j,len;

    len = strlen(str);
    printf("len = %d\n", len);

    for(i=0;i<len;i++){
        if(str[i]==c){
            for(j=i;j<len;j++)
                str[j]=str[j+1];
        }
    }
    str[j]='\0';
}
void ReadString( char s[] ) /* �ɲ���ʵ�֣���ȥ���� */
{

      scanf("%s",s);
}
