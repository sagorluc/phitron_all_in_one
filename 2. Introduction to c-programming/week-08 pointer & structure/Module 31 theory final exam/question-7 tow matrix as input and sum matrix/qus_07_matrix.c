#include<stdio.h>
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);

    printf("\n");

    int a[n][m],b[n][m],c[n][m];

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        scanf("%d",&a[i][j]);

    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
        scanf("%d",&b[i][j]);

        printf("\n");

    for(i=0; i<n; i++)
    {
       for(j=0; j<m; j++)
        {
         c[i][j] = a[i][j] + b[i][j];
         printf("%d ",c[i][j]);
        }

        printf("\n");

    }

   return 0;
}
