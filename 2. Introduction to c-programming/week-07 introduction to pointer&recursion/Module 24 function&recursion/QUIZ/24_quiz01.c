#include<stdio.h>
void foo();
int value=2;
int main()
{
    printf("%d \n",value);

    return 0;
}
void foo()
{
    value*=2;
}
