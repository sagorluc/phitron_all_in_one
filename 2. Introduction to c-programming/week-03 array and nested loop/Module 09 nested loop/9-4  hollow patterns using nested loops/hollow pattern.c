#include<stdio.h>

int main()
{
   int i,j;
   int n = 7;

   //7 stars frist
   for (j=1; j<=n; j++)
   {
     printf("#");

   }
   printf("\n");

   for(i=1; i<=n-2; i++) // midle 5 hash print hobe (n-2)
   {
     printf("#");

     for(j=1; j<=n-2; j++)
     {
      printf(" ");

     }

      printf("#\n");

   }
   //7 stars last
     for (j=1; j<=n; j++)
   {
     printf("#");

   }
    printf("\n");

    return 0;
}
