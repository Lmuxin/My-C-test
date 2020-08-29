//习题8-6 删除字符（20 分）
//本题要求实现一个删除字符串中的指定字符的简单函数。
//
//函数接口定义：
//
//void delchar( char *str, char c );
//其中char *str是传入的字符串，c是待删除的字符。函数delchar的功能是将字符串str中出现的所有c字符删除。
//
//裁判测试程序样例：
//
//#include <stdio.h>
//#define MAXN 20
//
//void delchar( char *str, char c );
//void ReadString( char s[] ); /* 由裁判实现，略去不表 */
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
///* 你的代码将被嵌在这里 */
//输入样例：
//
//a
//happy new year
//输出样例：
//
//hppy new yer


#include <stdio.h>
#include <string.h>
#define MAXN 20

void delchar( char *str, char c );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

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
void ReadString( char s[] ) /* 由裁判实现，略去不表 */
{

      scanf("%s",s);
}
