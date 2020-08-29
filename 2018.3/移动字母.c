//练习8-8 移动字母（10 分）
//本题要求编写函数，将输入字符串的前3个字符移到最后。
//
//函数接口定义：
//void Shift( char s[] );
//其中char s[]是用户传入的字符串，题目保证其长度不小于3；函数Shift须将按照要求变换后的字符串仍然存在s[]里。
//
//裁判测试程序样例：
//#include <stdio.h>
//#include <string.h>
//
//#define MAXS 10
//
//void Shift( char s[] );
//
//void GetString( char s[] ); /* 实现细节在此不表 */
//
//int main()
//{
//    char s[MAXS];
//
//    GetString(s);
//    Shift(s);
//    printf("%s\n", s);
//
//    return 0;
//}
//
///* 你的代码将被嵌在这里 */
//输入样例：
//abcdef
//输出样例：
//defabc


#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift( char s[] );

void GetString( char s[] ); /* 实现细节在此不表 */

int main()
{
    char s[MAXS];

    GetString(s);
    Shift(s);
    printf("%s\n", s);

    return 0;
}



//void Shift( char s[] )
//{
//
//  int i=0,j=0,m=0,n=0,count;
//  for(;n<MAXS;n++)
//  {
//      if(s[i]!='\n')
//        count++;
//  }
//  char c1[3],c2[3];//你也知道用两个数组存
//  for(;i<3;i++)
//    c1[j++]=s[i];
//  c2[m++]=s[count-2+i]
//
//
//}
//
//void GetString( char s[] )
//{
//    char c;
//
//    int i=0,j=0;
//    while(c!='\n')
//    {
//
//        c=getchar();
//        s[i++]=c;
//
//    }
////    for(;j<=i;j++)
////        printf("%c",s[j]);
//
//
//
//}
//
//
////尼玛尼玛 怎么想不出来呢


void GetString(char s[])
{
    scanf("%s", s);
    return;//void也写上return比较好
}

void Shift(char s[])
{
    int i, t, d = 0, e;
    char a[100], b[100];
    memset(a, 0, sizeof(a));//abc数组都没有初始化，里面的数据不能保证是正常的
    memset(b, 0, sizeof(b));//可能在你的电脑上数据正常，放在评测机上就错了

    e = strlen(s);
    for (i = 0; i<e; i++) {
        if (i <= 2) {
            a[i] = s[i];
        }
        if (i>2) {
            b[d++] = s[i];

        }
    }
    d = 0;
    t = strlen(b);
    for (i = 0; i<e; i++) {
        if (i<t) {
            s[i] = b[i];

        }
        if (i >= t) {
            s[i] = a[d];

            d++;
        }
    }

    return;//void也写上return比较好
}










