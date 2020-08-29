# include<stdio.h>
int main()
{
	int a,b,c,temp,max;
	printf(" please input a,b,c:");
	scanf("%d,%d,%d\n",&a,&b,&c);
	temp=(a>b)?a:b;
	max=(temp>c)?temp:c;//为什么 不对呢

	printf("the max=%d");
	return 0;
}
