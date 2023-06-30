#include<stdio.h>

int main()
{   long long int n,i;
    long long int ara[200003];
    scanf("%lld",&n);
    long long int moves = 0;
    for(i=0; i<n; i++) //taking all the input using by loop.
    scanf("%lld",&ara[i]);

    for(i=1; i<n; i++)//using loop for all calculation.
    {
        if(ara[i]<ara[i-1])//condition
        {
            moves += ara[i-1] - ara[i];
            ara[i] = ara[i-1];
        }

    }

    printf("%lld",moves);
    return 0;
}
