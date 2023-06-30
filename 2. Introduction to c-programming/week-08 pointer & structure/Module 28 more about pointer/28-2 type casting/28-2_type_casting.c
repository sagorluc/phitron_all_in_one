#include<stdio.h>
int main()
{
    int a=7;
    double b=7.25;
    //char c='a';
    int* p;
    double* q;

//    b = a;
//    a = c;
//    c = 65;

    //b = 25/4.0;
    //b = (double)25/4;//this is type casting.

    p = &a;
    //q = &b;
    q = (double*)p;//this is type casting.
    //printf("%d\n%lf\n%c"a,b,c);
    printf("%p\n%p",p,q);


    return 0;
}
