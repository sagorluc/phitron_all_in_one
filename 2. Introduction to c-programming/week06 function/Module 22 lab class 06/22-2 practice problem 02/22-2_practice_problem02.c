#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int i;
    int is_prime = 1;
    for(i=2; i<n; i++)
    {
        if(n%i==0)
            is_prime = 0;

    }
    if(is_prime==1)
        printf("prime number \n");
    else
        printf("composit number \n");

    return 0;
}
