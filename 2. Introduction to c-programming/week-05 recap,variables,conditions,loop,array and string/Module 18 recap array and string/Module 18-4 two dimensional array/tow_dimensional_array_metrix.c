#include<stdio.h>
int main()
{
    int marks1[2][2],marks2[2][2];
    int i,j;

    for(i=0; i<2; i++)
        for(j=0; j<2; j++)
            scanf("%d",&marks1[i][j]);

    for(i=0; i<2; i++)
        for(j=0; j<2; j++)
            scanf("%d",&marks2[i][j]);


    for(i=0; i<2; i++)
    {

        for(j=0; j<2; j++)
        {
            printf("%d ",marks1[i][j]+marks2[i][j]);
        }
    }


    return 0;
}
