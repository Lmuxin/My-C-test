# include <stdio.h>
int main(){
int i,a[20];
for(i=0;i<20;i++)
{scanf("%d",&a[i]);}

int j,b[20];
for(j=0;j<20;j++)
{scanf("%d",&b[j]);
}
int k=0,c[40];
for(i=0;i<20;i++)
for(j=0;j<20;j++)
{if( a[i]£¡=b[j])
   c[k++]=a[i++];
   else break;
   }


   for£¨i=0;i<20;i++)
   for(j=0;j<20;j++)
   {
       if(b[j]!=a[i])
        c[k++]=b[j];
       else
        break;
   }

   for(k=0;k<40;k++)
   printf("%d",c[k]);
   return 0;





}
