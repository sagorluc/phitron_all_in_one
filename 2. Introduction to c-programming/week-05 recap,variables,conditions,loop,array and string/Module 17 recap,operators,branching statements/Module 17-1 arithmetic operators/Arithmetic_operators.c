#include<stdio.h>
#include<math.h>
int main()
{
    int a = 12;
    int b = 5;
    int x = 3;
    int c,d,e,f,g,h;

    c = a+b;
    d = a-b;
    e = a*b;
    f = a/b;
    g = a%b;
    printf("add->%d\n",c);
    printf("subtraction->%d\n",d);
    printf("mpltiplication->%d\n",e);
    printf("divided->%d\n",f);
    printf("vagses or remainder->%d\n\n",g);

    int p;
    p=pow(b,x);//b to the power x.we can use pow(,,); this function.

    printf("power ->%d\n",p);

    float s;
    s = sqrt(a);//this is square root function.
    printf("square root ->%0.1f\n\n\n",s);

    char i,j;
    i='x';
    j='y';

    char c;
    c = i+2;
    printf("%c",c);




    return 0;
}
