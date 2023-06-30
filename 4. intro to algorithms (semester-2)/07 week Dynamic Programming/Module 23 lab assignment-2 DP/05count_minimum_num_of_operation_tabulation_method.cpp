
/// ==> TABULATION METHOD

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mxN = 1e5;

ll dp[mxN];

int main()
{
    ll n;
    cin >> n;

    /// base case
    dp[1] = 0;

    /// loop over the states
    for (int i=2; i<=n; i++)
    {
        /// subtract 1
        dp[i] = dp[i - 1] + 1;

        /// divisible by 2
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i/2] + 1);

        /// divisible by 3
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i/3] + 1);

    }

    cout  << dp[n] << "\n";

    return 0;
}
