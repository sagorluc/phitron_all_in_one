#include<stdio.h>
int main()
{
    int i,j;
    int ara[3][7];
    ara[0][4]=12;
    ara[1][2]=7;

    for(i=0; i<3; i++)
    {
       for(j=0; j<7; j++)
    {
      scanf("%d",&ara[i][j]);
    }

    }

    for(i=0; i<3; i++)
    {
       for(j=0; j<7; j++)
    {
      printf(" %d",ara[i][j]);
    }
    printf("\n");
    }






    return 0;
}
