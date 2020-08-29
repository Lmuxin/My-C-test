#include <stdio.h>
#include <math.h>

int prime( int p );
int PrimeSum( int m, int n );

int main()
{
    int m, n, p;

    scanf("%d %d", &m, &n);
    printf("Sum of ( ");
    for( p=m; p<=n; p++ ) {
        if( prime(p) != 0 )
            printf("%d ", p);
    }
    printf(") = %d\n", PrimeSum(m, n));

    return 0;
}

int prime( int p )
{
    int i,n;
    if(p>=2){

    n=sqrt(p);
    for(i=2;i<=n;i++)
    {
    if(p%i==0)
    break;
    }
    if (i>n)
    return 1;
    else return 0;

}
else return 0;

}


/*int prime( int p )
{
	int i,n;
	if(p >= 2){
		n = sqrt(p);
		for (i = 2;i <= n;i++){
			if(p % i == 0)
			break;
		}
		if (i > n)
		return 1;
		else
		return 0;
	}
	else
	return 0;
}

*/
int PrimeSum( int m, int n )
{
	int a,c = 0;
	for(a = m;a <= n;a++)
	if(prime(a) == 1)
	c = c + a;
	return c;
}


