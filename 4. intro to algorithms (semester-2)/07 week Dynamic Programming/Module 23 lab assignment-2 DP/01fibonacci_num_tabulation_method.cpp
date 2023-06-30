
/// ==> TABULATION METHOD

#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int dp[mxN];

int main()
{
    int n;
    cin >> n;

    /// handle base case
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    /// loop over the states
    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cout<< dp[n] <<"\n";

    return 0;
}
