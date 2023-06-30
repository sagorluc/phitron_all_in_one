#include<stdio.h>
int main()
{
    int a,b;// a = 7, b = 14;
    scanf("%d %d",&a,&b);

    int i,gcd;
    for(i=1; i<=a; i++)
    {
        if(a%i==0 && b%i==0)
           gcd = i;
    }
    printf("gcd is %d",gcd);



    return 0;
}
//gcd and lcm
