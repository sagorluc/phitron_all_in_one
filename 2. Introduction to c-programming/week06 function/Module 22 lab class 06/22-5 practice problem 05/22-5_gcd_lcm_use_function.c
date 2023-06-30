#include<stdio.h>
int gcd(int x, int y);//gcd function prototypes.
int lcm(int x, int y);//lcm function prototypes.

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);

    int c;
    c = gcd(a,b);

    int d;
    d = lcm(a,b);

    printf("GCD is %d\n",c);

    printf("LCM is %d",d);

    return 0;
}

int gcd(int x, int y)//this is gcd function.
{
    int i,result;
    for(i=1; i<=x; i++)
    {
        if(x%i==0 && y%i==0)
            result = i;
    }
    return result;
}

int lcm(int x, int y)//this is lcm function.
{
    int i;
    for(i=x; ; i++)
    {
        if (i%x==0 && i%y==0)
        {
            return i;
        }
    }
}


//int lcm(int x, int y) //this is short code to find lcm.
//{
    //return (x*y) / gcd(x,y);
//}
