#include<stdio.h>
int main()
{
    int row=3;
    int col=3;
    int i,j;
    int mat1[row][col],mat2[row][col];
    int ans[row][col];

    printf("Enter the frist metrix element \n");
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
            scanf("%d",&mat1[i][j]);

    printf("Enter the second metrix of element \n");
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
            scanf("%d",&mat2[i][j]);

    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            //ei part ta loop diye korte hole following the below instruction.
            //ekhane loop use kore calculation korte hobe
            //calculation er result ta kono ekta variable e save korter hobe .
            //ans[i][j] = result.

            ans[i][j] = mat1[i][0]*mat2[0][j] + mat1[i][1]*mat2[1][j] + mat1[i][2]*mat2[2][j];

            //mat1 er i row er shate mat2 er j col er gun korbo.
        }
    }
    printf("multiply of the metrix \n");


    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d",ans[i][j]);
        }
        printf("\n");

    }


    return 0;
}
