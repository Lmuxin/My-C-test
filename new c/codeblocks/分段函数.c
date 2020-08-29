# include<stdio.h>
int main()
{

    float y,x;
    printf("please input x:");
    scanf("%f",&x);
    if(x<1)
        y=x;
    else if(x>=10)
        y=3*x-11;
    else  y=2*x-1;
    printf("Êä³öy=%f\n",y);
    return 0;

}
