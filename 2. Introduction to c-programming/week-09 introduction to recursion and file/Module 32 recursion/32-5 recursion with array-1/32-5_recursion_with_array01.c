#include<stdio.h>
int solve(int ar[], int i, int x)
{
    if(i==x) return 0;

    int summ_ar = solve(ar,i+1,x);

    return summ_ar + ar[i];


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
    int total_summ = solve(ar,0,n);
    printf("total array of sum = %d",total_summ);


    return 0;
}
