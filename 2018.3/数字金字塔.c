#include<stdio.h>
int main()
{
    void p(int m);
 int m;
 printf("����m");
 scanf("%d",&m);
 p(m);

 return 0;



}

//����ⷨ6666������  ����û����
void p( int n ){
    int i,j,k,m;

    m = n;
    for(i=1;i<=n;i++,m--){
        j=m;
        for(;j>0;j--)
            printf(" ");
        for(k=i;k>0;k--)
            printf("%d ", i);
        printf("\n");
    }

/*void p(int m)
{
int i,j;
 for(i=1;i<=m;i++)
   {

    for(j=i;j<=m;j++)
      {

     printf("%d\t",i);

      }
      printf("\n");
   }
*/
}
