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

int main()
{
    int t,test = 0;
    cin >> t;

    while(t--)
    {
        int n,k;
        cin >> n >> k;

        for(int i=1; i<=n; i++)
            cin >> coin[i];

        for(int i=1; i<=n; i++)
            cin >> limit[i];

        for(int i=0; i<=n; i++)
            for(int j=0; j<=k; j++)
                dp[i][j] = 0;

        /// base case
        dp[0][0] = 1;

        /// loop over the states
        for(int i=1; i<=n; i++)
        {
            for(int target=0; target<=k; target++)
            {
                /// calculate the result from smaller sub-problem
                dp[i][target] = dp[i-1][target];

                for(int j=1; j<=limit[i]; j++)
                {
                    if(target < j*coin[i])
                        break;
                    int ans = dp[i-1][target - j*coin[i]]; /// one elem took j times

                    dp[i][target] = (dp[i][target] + ans) % mod;
                }
            }
        }
        cout<<"Case "<<++test <<": "<<dp[n][k]<<"\n";

    }
    return 0;
}
