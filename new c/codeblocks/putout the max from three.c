# include<stdio.h>
int main()
{
	int a,b,c,max;

	printf("please input three numbers:");
scanf("%d,%d,%d",&a,&b,&c);
/*ax=(a>b?a:b)>c?(a>b?a:b):c;*///运行结果不对,
max=a>b?a:b;
max=max>c?max:c;
printf("the max is %d\n",max);
	return 0;
}
