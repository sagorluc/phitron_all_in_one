
/// ===> TABULATION METHOD
#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 5;
int dp[N];
int n,x;
int coin[N];

int main()
{
    cin >> n >> x;

    for(int i=0; i<n; i++)
        cin >> coin[i];

    /// base case
    dp[0] = 1;

    /// loop over the states
    for(int i=1; i<=x; i++)
    {
        for(int j=0; j<n; j++)
        {
            /// calculate the result from smaller sub-problem
            if(i >= coin[j])
            {
                dp[i] += dp[i - coin[j]];
                dp[i] %= mod;
            }
        }
    }

    cout<< dp[x] <<"\n";

    return 0;
}
