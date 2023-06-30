#include<stdio.h>
int main()
{
     int row,col;
     scanf("%d%d",&row,&col); //taking row and column user input.

     int a[row][col];


     for(int i=0; i<row; i++) // row loop for input.
     {
        for(int j=0; j<col; j++) // column loop for input.
        {
         scanf("%d",&a[i][j]);
        }
     }
    if(row==col) // condition for matching row and column.
    {
        int ans=1;
        for(int i=0; i<row; i++) //this loop for touching all the row index.
     {
        for(int j=0; j<col; j++) //this loop for touching all the column index.
        {
         if(i==j) //this condition for matching the rows and columns index.
         {
           //special chicking
           if(a[i][j] != 1)
           {
              ans=0;
           }
           continue;
         }
         if(a[i][j] != 0) //this condition for avoiding rows and columns 0 index.and return  ture.
         {
           ans=0;
         }
        }
     }
     if(ans==1) //if previous condition return true then this condition will print the original value.
     {
       printf("Identity\n");
     }
     else
     {
         printf("Not Identity\n");
     }
    }
    else
    {
        printf("Not Identity\n");
    }




    return 0;
}
