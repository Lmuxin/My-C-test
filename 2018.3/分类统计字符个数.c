/*习题6-1 分类统计字符个数（15 分）
本题要求实现一个函数，统计给定字符串中英文字母、空格或回车、数字字符和其他字符的个数。

函数接口定义：
void StringCount( char s[] );
其中 char s[] 是用户传入的字符串。函数StringCount须在一行内按照

letter = 英文字母个数, blank = 空格或回车个数, digit = 数字字符个数, other = 其他字符个数
的格式输出。

裁判测试程序样例：
#include <stdio.h>
#define MAXS 15

void StringCount( char s[] );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */
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
    printf("输入字符:");
     char c;
     int i=0;
for(;i<15;i++){
   c=getchar();
   if(c=='\n')//回车要用单引号
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
        else if(  (   s[i]>= 'a' &&    s[i]<='z')  ||   (s[i]>='A' &&    s[i]<='Z' )  )//字母数字必须加单引号
                letter++;

            else if(s[i]==' ')//空格是单引号   不是双引号
                blank++;
            else
                others++;
    }
    printf("数字%d:,字母%d,空格%d,其他%d",digita,letter,blank,others);

}



