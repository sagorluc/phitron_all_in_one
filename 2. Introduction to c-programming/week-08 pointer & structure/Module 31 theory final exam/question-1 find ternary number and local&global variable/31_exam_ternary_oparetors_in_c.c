#include<stdio.h>
int main()
{
    int a,b,maxx;

    a = 87;
    b = 89;

    if(a>=b)
        maxx = a;
    else
        maxx = b;

        //maxx = a>=b ? a : b; //short way.

    printf("The maximum number is = %d\n",maxx);

    return 0;
}
