//习题8-9 分类统计各类字符个数（15 分）
//本题要求实现一个函数，统计给定字符串中的大写字母、小写字母、空格、数字以及其它字符各有多少。
//
//函数接口定义：
//
//void StringCount( char *s );
//其中 char *s 是用户传入的字符串。函数StringCount须在一行内按照
//
//大写字母个数 小写字母个数 空格个数 数字个数 其它字符个数
//的格式输出。
//
//裁判测试程序样例：
//
//#include <stdio.h>
//#define MAXS 15
//
//void StringCount( char *s );
//void ReadString( char *s ); /* 由裁判实现，略去不表 */
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
//输入样例：
//
//aZ&*?
//093 Az
//输出样例：
//
//2 2 1 3 4


#include <stdio.h>
#define MAXS 15

void StringCount( char *s );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

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
printf("大写字母%d,小写字母%d,数字%d,空格%d,其他%d",upl,litl,dig,blank ,other);

}
void ReadString( char *s ) /* 由裁判实现，略去不表 */
{


scanf("%s",s);
}
