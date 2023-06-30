#include<stdio.h>

int factorial(int x);//this is function prototypes.

int main()
{
    int n,i,ans=1;

    scanf("%d",&n);

    ans = factorial(n);
    printf("The factorial is = %d",ans);


    return 0;
}

int factorial(int x)
{
 int n,i;
 int res = 1;
 for(i=1; i<=x; i++)
 {
    res *= i;

 }
 return res;

}
