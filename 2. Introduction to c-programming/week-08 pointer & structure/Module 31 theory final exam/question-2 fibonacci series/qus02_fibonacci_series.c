#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    int f1,f2,f3;
    f1 = 0, f2 = 1;
    f3 = f1 + f2;


    printf("%d, %d",f1,f2);


    for(int i=3; i<=n; i++)
    {
        f1 = f2;
        f2= f3;

        printf(", %d",f3);


        f3 = f1 + f2;

    }

    return 0;
}
