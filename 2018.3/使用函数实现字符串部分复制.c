//ϰ��8-5 ʹ�ú���ʵ���ַ������ָ��ƣ�20 �֣�
//����Ҫ���д�������������ַ���t�дӵ�m���ַ���ʼ��ȫ���ַ����Ƶ��ַ���s�С�
//
//�����ӿڶ��壺
//
//void strmcpy( char *t, int m, char *s );
//����strmcpy�������ַ���char *t�дӵ�m���ַ���ʼ��ȫ���ַ����Ƶ��ַ���char *s�С���m���������ַ����ĳ��ȣ������ַ���ӦΪ�մ���
//
//���в��Գ���������
//
//#include <stdio.h>
//#define MAXN 20
//
//void strmcpy( char *t, int m, char *s );
//void ReadString( char s[] ); /* �ɲ���ʵ�֣���ȥ���� */
//
//int main()
//{
//    char t[MAXN], s[MAXN];
//    int m;
//
//    scanf("%d\n", &m);
//    ReadString(t);
//    strmcpy( t, m, s );
//    printf("%s\n", s);
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//����������
//
//7
//happy new year
//���������
//
//new year


#include <stdio.h>
#include<string.h>

#define MAXN 20

void strmcpy( char *t, int m, char *s );
void ReadString( char s[] ); /* �ɲ���ʵ�֣���ȥ���� */

int main()
{
    char t[MAXN], s[MAXN];
    int m;

    scanf("%d\n", &m);
    ReadString(t);
    strmcpy( t, m, s );
    printf("%s\n", s);

    return 0;
}


//void strmcpy( char *t, int m, char *s )
//{  int i,j=0;
//           if(m>strlen(*t))
//             *s=NULL;
//           else
//            for(i=m-1;i<MAXN;i++)
//            *s[j++]=*t[i];
//
//
//}
//void ReadString( char s[] )/* �ɲ���ʵ�֣���ȥ���� */
//{
//    scanf("%s",s);
//
//
//
//}
//���Բ���
void strmcpy( char *t, int m,char *s ){
    int i,j,len;

    strcpy(s, t);
    len = strlen(s);
    //printf("s = %s, len = %d\n", s, len);
    for(i=m-1;i>0;i--){
        for(j=i;j<len;j++){
            *(s+j-1)=*(s+j);
        }
    }
    *(s+len-m+1)='\0';
}
void ReadString(  char *s )
{

     scanf("%s",s);
}
