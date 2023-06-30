#include<stdio.h>

void find_even_odd(x)
{
    if(x%2==0)
        printf("even\n");
    else
        printf("odd\n");
}



int main()
{
    int n;
    scanf("%d",&n);

    find_even_odd(n);




    return 0;
}

