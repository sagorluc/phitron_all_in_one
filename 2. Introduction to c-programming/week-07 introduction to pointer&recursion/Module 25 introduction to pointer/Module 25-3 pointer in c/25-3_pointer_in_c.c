#include<stdio.h>
int main()
{
    int a=5;
    int* p;
    int* q;

    p=&a;

    *p=7;//change the value of a.
    q = p;
    *q = 13;//change the value of a.use pointer.


    printf("%d\n",a);

    return 0;
}
