//ϰ��11-3 ��������ַ������ȣ�15 �֣�
//����Ҫ��ʵ��һ�����������ڼ�����n��Ԫ�ص�ָ������s������ַ����ĳ��ȡ�
//�����ӿڶ��壺
//int max_len( char *s[], int n );
//����n���ַ����洢��s[]�У�����max_lenӦ����������ַ����ĳ��ȡ�
//���в��Գ���������
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//#define MAXN 10
//#define MAXS 20
//
//int max_len( char *s[], int n );
//
//int main()
//{
//    int i, n;
//    char *string[MAXN] = {NULL};
//
//    scanf("%d", &n);
//    for(i = 0; i < n; i++) {
//        string[i] = (char *)malloc(sizeof(char)*MAXS);
//        scanf("%s", string[i]);
//    }
//    printf("%d\n", max_len(string, n));
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//����������
//4
//blue
//yellow
//red
//green
//���������
//6


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 10
#define MAXS 20

int max_len( char *s[], int n );

int main()
{
    int i, n;
    char *string[MAXN] = {NULL};

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        string[i] = (char *)malloc(sizeof(char)*MAXS);
        scanf("%s", string[i]);
    }
    printf("%d\n", max_len(string, n));

    return 0;
}


int max_len( char *s[], int n )
{
    int i=0,j=0;
    int len[n];
    int slen=0;
     for(;i<n;i++)
     {
         len[j++]=strlen(*(s+i));//һ��Ҫ��*��s+i))

     }

    i=0;
    slen=len[0];
    for(;i<n;i++)
        {
            if(len[i]>slen)
                slen=len[i];
        }
    return slen;
}
