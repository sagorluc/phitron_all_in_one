#include<stdio.h>

int main()
{
   int n=6;
   int ara[]={26,56,45,8,26,6};
   int i;
   int m = ara[0];

   for (i=0; i<n; i++)
    {

     if (ara[i]>m)
     {
        m=ara[i];

     }
    }
    printf("the maximum value is %d\n",m);

    return 0;
}
