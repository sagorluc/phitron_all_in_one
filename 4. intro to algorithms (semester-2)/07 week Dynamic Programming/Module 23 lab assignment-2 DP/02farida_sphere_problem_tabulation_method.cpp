
/// ==> TABULATION METHOD

#include<bits/stdc++.h>

using namespace std;
typedef long long int ll;
const ll mx = 2e5;
ll dp[mx];

ll mx_coin(int n, vector<ll> v)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return v[0];

    dp[0] = 0;
    dp[1] = v[0];

    for (int i = 2; i <= n; i++)
        dp[i] = max(dp[i - 1], v[i - 1] + dp[i - 2]);


    return dp[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;

        vector<ll> v(n);

        for (int j = 0; j < n; j++)
            cin >> v[j];

        ll res = mx_coin(n, v);

        cout << "Case " << i << ": " << res << "\n";
    }
    return 0;
}
