#include<stdio.h>
int main()
{

  //baki kaj module 34-2 te kora hoyecha.

    return 0;
}

int whowins(a[][4],int n)
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
