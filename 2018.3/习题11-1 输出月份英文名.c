//习题11-1 输出月份英文名（15 分）
//本题要求实现函数，可以返回一个给定月份的英文名称。
//函数接口定义：
//char *getmonth( int n );
//函数getmonth应返回存储了n对应的月份英文名称的字符串头指针。如果传入的参数n不是一个代表月份的数字，则返回空指针NULL。
//裁判测试程序样例：
//#include <stdio.h>
//
//char *getmonth( int n );
//
//int main()
//{
//    int n;
//    char *s;
//
//    scanf("%d", &n);
//    s = getmonth(n);
//    if ( s==NULL ) printf("wrong input!\n");
//    else printf("%s\n", s);
//
//    return 0;
//}
//
///* 你的代码将被嵌在这里 */
//输入样例1：
//5
//输出样例1：
//May
//输入样例2：
//15
//输出样例2：
//wrong input!


#include <stdio.h>

char *getmonth( int n );

int main()
{
    int n;
    char *s;

    scanf("%d", &n);
    s = getmonth(n);
    if ( s==NULL ) printf("wrong input!\n");
    else printf("%s\n", s);

    return 0;
}

char *getmonth( int n )
{  char *m;

    if(n<=0||n>12)
        m=NULL;
     else
     {

         switch(n)
         {

             case 1: m="JAN"; break;
             case 2: m="FEB"; break;
             case 3: m="MAR"; break;
             case 4: m="APR"; break;
             case 5: m="MAY";break;
             case 6:  m="JUN";break;
             case 7:  m="jul";break;
             case 8:  m="aug";break;
             case 9: m="sep"; break;
             case 10: m="oct"; break;
             case 11: m="nov"; break;
             case 12:  m="dec";break;
         }

     }

     return m;
}
