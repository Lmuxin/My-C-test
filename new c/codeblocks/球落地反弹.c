# include<stdio.h>
int main()
{
    int i;
    double s=100,h=s/2;
    for(i=2;i<=10;i++)
    { s=s+2*h;
        h=h/2;
    }

    printf("10次共经过%f米\n",s);
  printf("第十次经过%f米\n",h);

    return 0;

}
