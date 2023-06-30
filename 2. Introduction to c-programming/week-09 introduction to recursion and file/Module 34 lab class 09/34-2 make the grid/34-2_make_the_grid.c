#include<stdio.h>
#include<stdbool.h>
void grid(int a[][4],int n)
{
    //printf kora holo sob row and col
    for(int i=1; i<=n; i++)//row
    {
        for(int j=1; j<=n; j++)//col
        {
            if(a[i][j]== -1) printf(" "); //-1 k remove kora holo.
            if(a[i][j]== 1) printf("x");
            if(a[i][j]== 2) printf("O");

            //printf("%d",a[i][j]);// -1 k print kora hoyecilo.

            if(j<n) printf("\t|\t");//col 1 ta kom print kora holo
        }
        if(i<n) printf("\n__________________________________");//row 1 ta kom print kora holo.
        printf("\n\n");
    }
}

// chack who wins function.
int whowins(int a[][4],int n)
{
    //frist case chack.

    for(int i=1; i<=n; i++)
    {
        if(a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][1] != -1 )

            return a[i][1];
    }

    //2nd case chack.

    for(int j=1; j<=n; j++)
    {
        if(a[1][j] == a[2][j] && a[2][j] == a[3][j] && a[1][j] != -1)

            return a[1][j];
    }

    //3rd case chack.

    if(a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[1][1] != -1)

        return a[1][1];

    //4th case chack.

    if(a[3][1] == a[2][2] && a[2][2] == a[1][3] && a[3][1] != -1)

        return a[3][1];

    return -1;
}

//this function will show only winer result.

void printWins(int a[][4], int n, int who)
{
    for(int i=1; i<=n; i++)//row
    {
        for(int j=1; j<=n; j++)//col
        {
            if(a[i][j]== who)
            {
                if(a[i][j]==1) printf("X");
                else printf("O");
            }
            else
            {
                printf(" ");
            }

            if(j<n) printf("\t|\t");//col 1 ta kom print kora holo
        }
        if(i<n) printf("\n__________________________________");//row 1 ta kom print kora holo
        printf("\n\n");
    }

}


int main()
{
    int n=3,row=4,col=4;
    int a[row][col]; // 2D array or metrix.

    for(int i=1; i<=n; i++)//row
    {
        for(int j=1; j<=n; j++)//col
        {
            a[i][j] = -1; //row and coll k -1 kore deoya holo.
        }
    }
    bool player1 = true;
    bool player2 = false;
    while(true)
    {
        printf("\n");
        grid(a,n);
        if(player1==true)//jodi player1 sotti hoy
        {
            //player1 er kaj

            int r,c;
flag:
            printf("\nPlayer 1 turn (X), Enter row and column : ");
            scanf("%d%d",&r,&c);
            if(a[r][c] != -1)
            {
                printf("Invalid Cell \n");
                goto flag;

            }
            a[r][c] = 1; //player1 er row col er mann 1.
            player1 = false; //player1 er dain ses hole tarmane tar kaj ses.so se false hoye jabe.
            player2 = true; //player2 sotti hoye jabe.

        }
        else
        {
            //player2 er kaj

            int r,c; //player er row and col.
flag2:
            printf("\nPlayer 2 turn (O), Enter row and column : ");
            scanf("%d%d",&r,&c);
            if(a[r][c] != -1)
            {
                printf("Invalid Cell \n");
                goto flag2;

            }
            a[r][c] = 2; //player2 row and col er mann 2.
            player2 = false;
            player1 = true;
        }

        //chack who wins.

        if(whowins(a,n) == 1)
        {
            printf("Player 1 won! \n");
            printWins(a,n,1);
            break;
        }
        else if(whowins(a,n) == 2)
        {
            printf("Player 2 won! \n");
            printWins(a,n,2);
            break;
        }

    }
    return 0;
}
