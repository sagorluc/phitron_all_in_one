
/// ==> TABULATION METHOD

#include<bits/stdc++.h>
using namespace std;

int dp[40];

int main()
{
    int n;
    cin >> n;

    /// base case
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;

    /// loop over the states
    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];

    cout<< dp[n] <<"\n";


    return 0;
}
