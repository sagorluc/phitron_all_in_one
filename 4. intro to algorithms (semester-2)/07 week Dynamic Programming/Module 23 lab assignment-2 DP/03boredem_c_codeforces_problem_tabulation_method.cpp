
/// ==> TABULATION METHOD

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mxN = 2e5;

ll cnt[mxN];
ll dp[mxN];

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    int mx = 0;

    for(int i=0; i<n; i++)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    for(int i=0; i<n; i++)
        cnt[v[i]]++;

    /// base case
    dp[0] = 0;
    dp[1] = cnt[1];

    for(int i=2; i<=mx; i++)
        dp[i] = max(dp[i-1], i * cnt[i] + dp[i-2]);

    cout<< dp[mx] <<"\n";

    return 0;
}
