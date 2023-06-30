#include<stdio.h>
int solve(int ar[], int x)
{                               //int* ar[] pointer.
    if(ar[0]==x) return 0;      //if(n==0) return 0;
    int ar_summ = solve(ar+1,x); //solve(ar+1,n-1);
    return ar_summ + ar[0]; //*(ar) is same thing as ar[0];
}
int main()
{
    int n;
    scanf("%d",&n);

    int ar[n],i;
    for(i=0; i<n; i++)
    {
        scanf("%d",&ar[i]);

    }
    int total_summ = solve(ar,n);
    printf("total array of sum = %d",total_summ);



    return 0;
}
