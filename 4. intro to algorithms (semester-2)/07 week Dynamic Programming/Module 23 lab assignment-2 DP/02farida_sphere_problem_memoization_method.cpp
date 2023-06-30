
/// ==> MEOMOIZATION METHOD

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mxN = 2e5;
ll dp[mxN];

ll mx_point(ll n, vector<ll> v)
{
    /// base case
    if(n == 0)
        return 0;
    if(n == 1)
        return v[0];
    if(n == 2)
        return max(v[0], v[1]);

    /// check if the result already exists
    if(dp[n] != -1)
        return dp[n];

    ll ans1 = v[n-1] + mx_point(n-2, v);
    ll ans2 = mx_point(n-1, v);

    ll res = max(ans1, ans2);
    dp[n] = res;

    return res;



}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    int k = 1;
    while(t--)
    {
        ll n;
        cin >> n;

        vector<ll> v(n);

        ll mx = 0;

        for(int i=0; i<n; i++)
            cin >> v[i];

        for(int i=1; i<=n; i++)
            dp[i] = -1;

        ll ans = mx_point(n,v);

        cout<< "Case "<<k<<": "<< ans <<"\n";
        k++;

    }

    return 0;
}
