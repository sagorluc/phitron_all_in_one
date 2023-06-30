#include<stdio.h>

int main()
{
    int row,col,a,b;
    int ara[5][5];

    for(row=0; row<5; row++)
    {
        for(col=0; col<5; col++)
        {
           scanf("%d",&ara[row][col]);

           if(ara[row][col]==1)
           {
              a = row;
              b = col;
           }
        }
    }

    int ans,row_change,col_change;

    if (a>2)
        row_change = (a-2);
    else
        row_change = (2-a);
    if(b>2)
        col_change = (b-2);
    else
        col_change = (2-b);

    ans = row_change + col_change;

    printf("%d",ans);



    return 0;
}
