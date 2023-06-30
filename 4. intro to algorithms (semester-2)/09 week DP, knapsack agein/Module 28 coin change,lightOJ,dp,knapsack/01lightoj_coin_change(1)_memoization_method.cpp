#include<bits/stdc++.h>
using namespace std;

/**
- states-> dp(n,k) -> number of ways to make sum=k from
  coins 1 to n without crossing limit.

- recurrence-> dp(n,k) = dp(n-1, k) +
                       = dp(n-1, k-coin[n])+ /// last elem one time only
                       = dp(n-1, k - 2*coin[n]) + /// last elem tow time only

                       .....
                       = dp(n-1, k - limit[n] * coin[n]) /// limit of n time

- base case-> dp(0,0) = 1.

*/

const int N = 52;
const int M = 1010;
const long long mod = 100000007;

int limit[N];
int dp[N][M];
int coin[N];

int sum_of_target(int n, int k)
{
    /// base case
    if(n == 0)
    {
        if(k == 0)
            return 1;
        else
            return 0;
    }

    /// check if the result already exists
    if(dp[n][k] != -1)
        return dp[n][k];

    /// calculate the result from smaller sub-problem
    int ans1 = sum_of_target(n-1, k);

    for(int i=1; i<=limit[n]; i++)
    {
        if(k - i*coin[n] < 0)
            break;

        int ans2 = sum_of_target(n-1, k - i * coin[n]);
        ans1 = (ans1 + ans2)%mod;

    }

    dp[n][k] = ans1;
    return ans1;
}
int main()
{
    int t;
    cin >> t;

    for(int i=1; i<=t; i++)
    {
        int n,k;
        cin >> n >> k;

        for(int i=1; i<=n; i++)
            cin >> coin[i];

        for(int i=1; i<=n; i++)
            cin >> limit[i];

        for(int i=0; i<=n; i++)
            for(int j=0; j<=k; j++)
                dp[i][j] = -1;

        int res = sum_of_target(n,k);

        cout<<"Case " <<i<<":"<<res<<"\n";

    }




    return 0;
}
