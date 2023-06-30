#include<bits/stdc++.h>
using namespace std;

/// time complexity-> O(n*k)
/// space complexity-> O(n)

const int mxN = 1e5;

int dp[mxN];
int n,k;

int sum_of_nbonacci(int n)
{
    /// 1. handle base case
    if(n <= k)
        return 1;

    /// 2. check if the result already exists
    if(dp[n] != -1)
        return dp[n];

    int sum = 0;
    /// 3. recurrence
    for(int i=1; i<=k; i++)
    {
        sum = sum + sum_of_nbonacci(n-i);
    }

    dp[n] = sum;
    return sum;
}

int main()
{

    cin >> n >> k;

    for(int i=1; i<=n; i++)
        dp[i] = -1;

    cout<< sum_of_nbonacci(n) <<endl;

    return 0;
}
