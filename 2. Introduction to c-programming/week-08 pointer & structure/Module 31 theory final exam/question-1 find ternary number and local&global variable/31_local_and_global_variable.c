#include<stdio.h>

int g = 8; //declare global variable.

void variable()
{
    int g = 9; //local variable.
    printf("function variable %d",g);
}

int main()
{
     int L; //local variable.

     L = 12;

     variable();
     printf("\nlocal variable %d\n",L);

     printf("Global variable %d",g);

    return 0;
}
