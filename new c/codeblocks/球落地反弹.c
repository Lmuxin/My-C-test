# include<stdio.h>
int main()
{
    int i;
    double s=100,h=s/2;
    for(i=2;i<=10;i++)
    { s=s+2*h;
        h=h/2;
    }

    printf("10�ι�����%f��\n",s);
  printf("��ʮ�ξ���%f��\n",h);

    return 0;

}
