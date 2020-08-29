# include<stdio.h>
int main()
{
int a,b,c;
printf("输入数据：");
/*scanf("%d,%d,%d",&a,&b,&c);//这样输入数据输出结果是不对的 为什么*/
scanf("a=%d,b=%d,c=%d",&a,&b,&c);//这样输入数据，输出结果就是正确的
printf("%d,%d,%d",a,b,c);
return 0;


}

