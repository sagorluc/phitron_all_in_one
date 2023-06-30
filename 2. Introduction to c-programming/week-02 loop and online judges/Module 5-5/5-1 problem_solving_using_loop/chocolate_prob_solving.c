#include<stdio.h>

int main  ()
{
    int n ;

    scanf("%d",&n);

    int choco = n;
    int pack = n;


    while (pack >= 4)
    {
      choco = choco + (pack / 4);
      pack = (pack / 4) + (pack % 4);
    }

    printf(" %d ",choco);




    return 0;
}
