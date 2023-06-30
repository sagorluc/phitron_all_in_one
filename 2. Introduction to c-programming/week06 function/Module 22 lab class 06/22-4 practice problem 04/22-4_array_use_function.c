#include<stdio.h>
int add_them(int n, int nums[]);

int main()
{
    int ara[]={13, 74, 74, 6, 3, 6, 345, 54,174};

    int sum = add_them(9,ara);
    printf("%d",sum);

    return 0;
}

int add_them(int n, int nums[])
{
    int i,sum=0;
    for(i=0; i<n; i++)
    {
        sum += nums[i];
    }
    return sum;
}
