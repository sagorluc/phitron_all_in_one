#include<stdio.h>

int main ()
{

    int ara[10];

    ara[0] = 5239;
    ara[1] = 6239;
    ara[2] = ara[0] * ara[1];
    ara[3] = ara[1] + ara[2];

    printf("%d\n", ara[0]);
    printf("%d\n", ara[1]);
    printf("%d\n", ara[2]);
    printf("%d\n", ara[3]);



    return 0;
}
