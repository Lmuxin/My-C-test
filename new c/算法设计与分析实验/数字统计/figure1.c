#include<stdio.h>
#include<stdlib.h>
void countNumber(int n);
int a[10]={0};
int main()
{
  FILE *in,   *out;
   int  n,i;

   in=fopen("input.txt","r");
   out=fopen("output.txt","w");
   fscanf(in,"%d\n",&n);
   countNumber(n);
   for(i=0;i<10;i++)

   fprintf(out,"%d\n",a[i]);
   fclose(in);

   fclose(out);
   return 0;

}
 void countNumber(int n)
 {

   int i,m;
   for(i=1;i<=n;i++)
   {
      m=i;
      while(m)
      {
        a[m%10]++;
        m=m/10;

      }
   }

 }
