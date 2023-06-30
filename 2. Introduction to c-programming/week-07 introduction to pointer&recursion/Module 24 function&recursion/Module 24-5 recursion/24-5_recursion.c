#include<stdio.h>

int factorial(int x);
    //basic recursion rules.
    //factorial(n) = n * factorial(n-1);
    //factorial(0) = 1;


int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",factorial(n));

    return 0;
}
//basic recursion rules.
//factorial(5) = 5 * factorial(5-1);
//factorial(5) = 5 * factorial(4);
//factorial(n) = n * factorial(n-1);
//factorial(0) = 1;
//factorial(1) = 1;
//factorial(-ve) = invalid;

int factorial(int x)
{
    if(x==0) //(x>0)

        return 1;//return x * factorial(x-1);

    else

        return x * factorial(x-1);//return 1; it's a same things.


}
