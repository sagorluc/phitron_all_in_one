#include<stdio.h>
int solve(int i, int n)
{
    if(i > n) return 0;
    int right_sum = solve(i+1,n);
    return right_sum + i;
}
int main()
{
    int n;
    scanf("%d",&n);

    int total_sum;
    total_sum = solve(1,n);

    printf("sum is %d\n",total_sum);



    return 0;
}

