#include<stdio.h>
int is_prime(int x);

int main()
{
    int n;
    scanf("%d",&n);

    if(is_prime(n)==1)
        printf("prime number \n");
    else
        printf("composit number \n");

    return 0;
}

int is_prime(int x)
{
    int i;
    for(i=2; i<x; i++)
    {
        if(x%i==0)
            return 0;

    }
    return 1;
}
