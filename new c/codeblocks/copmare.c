# include<stdio.h>
int main()
{
	int a,b,c,temp,max;
	printf(" please input a,b,c:");
	scanf("%d,%d,%d\n",&a,&b,&c);
	temp=(a>b)?a:b;
	max=(temp>c)?temp:c;//Ϊʲô ������

	printf("the max=%d");
	return 0;
}
