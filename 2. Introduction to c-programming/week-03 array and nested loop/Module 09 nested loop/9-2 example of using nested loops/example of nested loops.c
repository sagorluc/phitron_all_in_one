#include<stdio.h>

int main()
{
  int i,j;

    i=0;

    while (i<13)
    {
        //print 5 star.if we need to print 50k star.then what should we do.
        j=0;
        while (j<15)
        {
          printf("*");

          j++;

        }

        printf("\n");
        i++;

    }

    return 0;
}
