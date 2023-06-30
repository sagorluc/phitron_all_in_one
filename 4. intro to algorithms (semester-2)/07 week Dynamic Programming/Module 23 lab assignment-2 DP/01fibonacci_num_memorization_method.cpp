

/// ==> MEMOIZATION METHOD

#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int dp[mxN];

int fib(int n)
{
    /// base case
    if(n == 0 )
        return 0;
    if(n <= 2)
        return 1;

    /// check if the result already exists
    if(dp[n] != -1)
        return dp[n];

    int ans = fib(n-1) + fib(n-2);
    dp[n] = ans;

    return ans;

}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        dp[i] = -1;

    cout<< fib(n) <<"\n";

    return 0;
}
