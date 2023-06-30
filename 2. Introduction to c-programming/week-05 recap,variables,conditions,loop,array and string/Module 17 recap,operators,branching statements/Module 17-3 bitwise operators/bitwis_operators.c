#include<stdio.h>
int main()
{
    int a,b,c,d,e,g,h,i;
    int f;

    a = 22;
    b = 5;

    f = a&b; //this is bitwise AND.
    printf("%d\n",f);

    c = 22;
    d = 5;

    e = c|d; //this is bitwise OR.
    printf("%d\n ",e);

    g = 5;

    i = ~g;//this is bitwise NOT.
    printf("%d\n",i);

    int aa,bb,cc,dd;

    aa=5;


    bb=aa<<30; //left shift.
    printf("%d\n",bb);

    cc=5;

    dd=cc>>3;//right shift.
    printf("%d",dd);












    return 0;
}
