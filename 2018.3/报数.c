//ϰ��8-4 ������20 �֣�
//������Ϸ�������ģ���n����Χ��һȦ����˳���1��n��úš��ӵ�һ���˿�ʼ����������m��<n�������˳�Ȧ�ӣ���һ���˴�1��ʼ����������m�����˳�Ȧ�ӡ������ȥ��ֱ���������һ���ˡ�
//
//����Ҫ���д����������ÿ���˵��˳�˳���š�
//
//�����ӿڶ��壺
//
//void CountOff( int n, int m, int out[] );
//����n�ǳ�ʼ������m����Ϸ�涨���˳�λ�Σ���֤ΪС��n����������������CountOff��ÿ���˵��˳�˳���Ŵ�������out[]�С���ΪC���������±��Ǵ�0��ʼ�ģ����Ե�i��λ���ϵ����ǵ�out[i-1]���˳��ġ�
//
//���в��Գ���������
//
//#include <stdio.h>
//#define MAXN 20
//
//void CountOff( int n, int m, int out[] );
//
//int main()
//{
//    int out[MAXN], n, m;
//    int i;
//
//    scanf("%d %d", &n, &m);
//    CountOff( n, m, out );
//    for ( i = 0; i < n; i++ )
//        printf("%d ", out[i]);
//    printf("\n");
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//����������
//
//11 3
//���������
//
//4 10 1 7 5 2 11 9 3 6 8


#include <stdio.h>
#define MAXN 20

void CountOff( int n, int m, int out[] );

int main()
{
    int out[MAXN], n, m;
    int i;

    scanf("%d %d", &n, &m);
    CountOff( n, m, out );
    for ( i = 0; i < n; i++ )
        printf("%d ", out[i]);
    printf("\n");

    return 0;
}

//void CountOff( int n, int m, int out[] )
//{
//    int i=0,j=0,count=n;
//    while(count)
//    {
//            for(;i<count;i++)
//        {
//           if(i==m)
//            {
//                out[j++]=i+1;
//                count--;
//                i+1=0;
//            }
//        }
//
//    }
//
//}

//��������
void CountOff( int n, int m, int out[] ){
    int i=0,j=0,k=0,cnt=0,a[MAXN];

    for(i=0;i<n;i++)
        a[i] = i+1;

    i=0;
    while(cnt < n){
        if(a[i]!=0)
            k++;
        if(k==m){
            j++;
            out[i]=j;
            k=0;
            cnt++;
            a[i]=0;
        }

        i++;
        if(i==n)
            i=0;
    }
}

