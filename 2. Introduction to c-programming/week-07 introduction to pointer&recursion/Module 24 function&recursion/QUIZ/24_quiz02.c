#include<stdio.h>
void foo();

int value=3;
int main()
{
    printf("%d \n",value);
    foo(2);

    return 0;
}

void foo()
{
    value*=2;

}

