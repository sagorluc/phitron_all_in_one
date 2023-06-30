#include<stdio.h>

int main()
{

   int n , s;
   scanf("%d",&n);

   s = n/5 + (n % 5 != 0);
   printf("%d", s);

    return 0;
}
