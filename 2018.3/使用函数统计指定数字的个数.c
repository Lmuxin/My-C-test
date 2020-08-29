#include <stdio.h>

int CountDigit( int number, int digit );

int main()
{
    int number, digit;

    scanf("%d %d", &number, &digit);
    printf("Number of digit %d in %d: %d\n", digit, number, CountDigit(number, digit));

    return 0;
}



   int CountDigit(int number,int digit)
{
    int cnt=0;
    int num;
    if(number<0)
        number=-number;
    if(number==0&&digit==0)
        cnt++;
    while(number)
    {
        num=number%10;
        if(num==digit)
            cnt++;
        number/=10;
    }

    return cnt;
}


