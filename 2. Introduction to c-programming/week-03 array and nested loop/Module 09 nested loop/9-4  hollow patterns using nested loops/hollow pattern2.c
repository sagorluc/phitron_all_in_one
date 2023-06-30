#include<stdio.h>
int main()
{
    int i,j;
    int n=7;

    for(j=1; j<=n*2+1; j++) // frist 15 doller sign print hobe
    {
        printf("%d ",j);
    }

    printf("_\n"); // frist line er new line.

    for(i=1; i<=(n*2-1); i++) // midle left side 13 ta @ print hobe.
    {
        printf("%d ",i);
        for(j=1; j<=(n*4+2); j++) // midle line er gap print hobe.
        {
            printf(" ");
        }
        printf("%d \n",i);
    }

    for (j=1; j<=n*2+1; j++) // last 15 doller sign print hobe.
    {
        printf("%d ",j);
    }


    return 0;

}
