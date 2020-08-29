#include <bits/stdc++.h>
using namespace std;
int top=0;
double h[40];
int main()
{
    char k[40],c;
    int n,m,i,j;
    while(1)
    {
        scanf("%c",&c);
        if(c=='\n')
        {
            break;
        }
        else if(c!=' ')
        {
           k[top]=c;
           top++;
        }
    }
    int top1=0;
   for(i=top-1;i>=0;i--)
   {
       if(k[i]>='0' && k[i]<='9')
       {
           double t=double(k[i]-'0');
           h[top1]=t;
           top1++;
       }
       if(k[i]=='+')
       {
           h[top1-2]=h[top1-1]+h[top1-2];
           top1--;
       }
       if(k[i]=='-')
       {
           h[top1-2]=h[top1-1]-h[top1-2];
           top1--;
       }
       if(k[i]=='*')
       {
           h[top1-2]=h[top1-1]*h[top1-2];
           top1--;
       }
       if(k[i]=='/')
       {
           h[top1-2]=h[top1-1]/h[top1-2];
           top1--;
       }

   }
   if(top1==1)
   {
      printf("%.1lf\n",h[0]);
   }
   else
   {
       printf("ERROR\n");
   }


    return 0;
}
