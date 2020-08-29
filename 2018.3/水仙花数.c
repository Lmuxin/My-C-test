#include <stdio.h>
#include <math.h>
int narcissistic( int number );
void PrintN( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}


int narcissistic( int number )
{
     int n=0,i,count=0,sum=0;
    n=number;
  while (n)
  {
     count++;
     n=n/10;
  }
    n=number;
    while(n)
    {
      i=n%10;
      sum+=(int)pow(i,count);
      n/=10;

    }

    if(sum==number)
    return 1;
    else return 0;
}
void PrintN( int m, int n )
{
  int i;
  for(i=m;i<=n;i++)


  if (narcissistic(i))
    printf("Ë®ÏÉ»¨Êı%d",i);

}
/*

int narcissistic( int number ){
    int i,n=0,sum=0,cnt=0;
    n = number;
    while(n){
        cnt++;
        n/=10;
    }

    n = number;
    while(n){
        i=n%10;
        sum += (int)pow(i, cnt);
        n/=10;
    }

    if(sum == number)
        return 1;
    else
        return 0;

}

void PrintN( int m, int n ){

    int i;

    for(i=m+1;i<n;i++)
        if(narcissistic(i))
            printf("%d\n", i);
}

*/
