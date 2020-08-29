# include <stdio.h>
int main()
{
    int m,n;
    scanf("%d",&m);
    scanf("%d",&n);
int i,a[20];
for(i=0;i<m;i++)
scanf("%d",&a[i]);

int b[20];
for(i=0;i<n;i++)
scanf("%d",&b[i]);

int k=0,c[40];
for(i=0;i<m;i++)
for(j=0;j<n;j++)
if( a[i]£¡=b[j])
   {c[k]=a[i];
   printf("%d",c[k]);
   k++;}
   else break;




   for£¨i=0;i<n;i++)
   for(j=0;j<m;j++)
   {
       if(b[i]!=a[j])
        c[k]=b[];
        printf("%d",c[k]);
        k++;
       else
        break;
   }


   return 0;
}
