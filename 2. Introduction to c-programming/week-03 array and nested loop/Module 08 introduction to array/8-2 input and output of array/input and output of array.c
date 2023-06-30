#include<stdio.h>

int main()
{
   int i,N=10, ara[N];

   for (i=0; i<N; i++)
   {
      scanf("%d",&ara[i]);
   }

    for (i=0; i<N; i++)
    {
      printf("%d-th position value = %d\n",i,ara[i]);
    }

    return 0;
}
