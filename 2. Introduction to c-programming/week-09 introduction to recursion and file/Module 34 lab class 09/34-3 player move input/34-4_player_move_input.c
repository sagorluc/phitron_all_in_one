#include<stdio.h>
#include<stdbool.h>

// baki kaj module 34-2 function e kora hoyece.

int main()
{
    bool player1 = true;
    bool player2 = false;
    while(true)
    {
        grid(a,n);
        if(player1==true)//jodi player1 sotti hoy
        {
            //player1 er kaj

            int r,c;
            flag:
            printf("Player 1 turn (X), Enter row and column : ");
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
            printf("Player 2 turn (O), Enter row and column : ");
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

    }


    return 0;
}
