
#include <stdio.h>
# define N 20

int main()
{
   int i,j,k=0,m,n,x,y=m+n;

   scanf("%d",&m);
   int a[N];
   for(i=0;i<m;i++)
    {
        scanf(" %d",&a[i]);
    }

   for(i=0;i<m;i++)
   {
       for(j=i+1;j<m;j++)
       {
           if(a[i]==a[j])
           {
               for(k=j+1;k<m;k++)
              {
               a[k-1]=a[k];
              }
               m--;
           }
       }
   }

   scanf("%d",&n);
   int b[N];
   for(j=0;j<n;j++)
    {
        scanf("%d",&b[j]);
    }



    for(j=0;j<n;j++)
   {
       for(i=j+1;i<n;i++)
       {
           if(b[j]==b[i])
           {
               for(x=i+1;x<n;x++)
              {
               b[x-1]=b[x];
              }
               n--;
           }
       }
   }



   int c[N],d=0;



  for(i=0;i<m;i++)
    {

        for(j=0;j<n;j++)
        {
            if(a[i]==b[j])
          {
            break;
          }
        }
       if(j>=n)
       {
        c[d]=a[i];
        d++;
       }
    }


 printf("%d",c[0]);
    for(i=1;i<d;i++)
    {
        printf(" %d",c[i]);
    }


  for(j=0;j<n;j++)
    {
        for(i=0;i<m;i++)
        {
            if(b[j]==a[i])
          {
             break;
          }
        }
        if(i>=m)
          printf(" %d",b[j]);
    }

return 0;
}
