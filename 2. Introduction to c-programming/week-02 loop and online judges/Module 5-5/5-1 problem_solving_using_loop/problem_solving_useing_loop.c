#include<stdio.h>

int main ()
{
    int n, i, sum = 0;

    printf("Enter the number of passengers ");
    scanf("%d",&n);

    for (i =1; i <= n; i++ )
    {
      int w ;

      scanf("%d",&w);

      sum = sum + w;

    }
    printf("total weight of passengers is %d\n", sum);


    return 0;
}
