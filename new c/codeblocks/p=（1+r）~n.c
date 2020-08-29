# include<stdio.h>
# include<math.h>
int main()
{

	float p,r;
	int n;
	 printf("please input r= and n=:");
	 scanf("r=%f,n=%d",&r,&n);
	 p=pow(1+r,n);
	 printf("p=%f\n",p);
	 return 0;
}
