//习题11-5 指定位置输出字符串（20 分）
//本题要求实现一个函数，对给定的一个字符串和两个字符，打印出给定字符串中从与第一个字符匹配的位置开始到与第二个字符匹配的位置之间的所有字符。
//函数接口定义：
//char *match( char *s, char ch1, char ch2 );
//函数match应打印s中从ch1到ch2之间的所有字符，并且返回ch1的地址。
//裁判测试程序样例：
//#include <stdio.h>
//
//#define MAXS 10
//
//char *match( char *s, char ch1, char ch2 );
//
//int main()
//{
//    char str[MAXS], ch_start, ch_end, *p;
//
//    scanf("%s\n", str);
//    scanf("%c %c", &ch_start, &ch_end);
//    p = match(str, ch_start, ch_end);
//    printf("%s\n", p);
//
//    return 0;
//}
//
///* 你的代码将被嵌在这里 */
//输入样例1：
//program
//r g
//输出样例1：
//rog
//rogram
//输入样例2：
//program
//z o
//输出样例2：
//(空行)
//(空行)
//输入样例3：
//program
//g z
//输出样例3：
//gram
//gram
//



#include <stdio.h>
#include<string.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;

    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

//char *match( char *s, char ch1, char ch2 )
//{
//    int i=0,j=0,a,b;
//    char *c=NULL;;
//    for(;i<strlen(s);i++)
//    {
//        if(s[i]==ch1)
//       {
//
//       a=i;
//        c=&s[a];
//        break;
//       }
//    }
//    j=a+1;
//    for(;j<strlen(s);j++)
//    {
//        if(s[j]==ch2)
//        b=j;
//          break;
//    }
//    int m;
//    i=0;
//   for(m=a+1;m<b;m++)
//    printf("%c",s[m]);
//
//    return c;
//}


char *match( char *s, char ch1, char ch2 ){

    int i=0,j=0,k=0,len=0;
    char *p=NULL;

    len = strlen(s);

    for(i=0;i<len;i++)
        {
            if(s[i]==ch1)
            {
                    p=&s[i];
                    for(j=i;j<len;j++)
                    {
                            if(s[j]!=ch2)
                                {
                                    printf("%c", s[j]);
                                }
                          if(s[j]==ch2)
                              {
                                  printf("%c\n", s[j]);
                                  return p;
                               }
                   }
                   printf("\n");
                   return p;
               }
    }
    printf("\n");
    return p;
}

