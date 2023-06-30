#include<stdio.h>

int main()
{
    int a=234,b;
    int* p = &b;//this is called pointer variable.

    p = &a;

    printf("%d\n",&a);//this will show decimal memory address.
    printf("%p\n",&a);//this will show hexadecimal memory address.
    printf("%p\n",p);
    printf("%d\n",*p);



    return 0;
}
