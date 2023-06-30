#include<stdio.h>
#include<math.h>
int factorial(int x);//this is function prototypes.

int main()
{
     int n,r;

    scanf("%d%d",&n,&r);

    int permutation;
    int combination;

    permutation = factorial(n) / factorial(n-r);
    combination = factorial(n) / (factorial(n-r)*factorial(r));

    printf("permutation is nPr = %d\n",permutation);
    printf("combination is nCr = %d",combination);


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
