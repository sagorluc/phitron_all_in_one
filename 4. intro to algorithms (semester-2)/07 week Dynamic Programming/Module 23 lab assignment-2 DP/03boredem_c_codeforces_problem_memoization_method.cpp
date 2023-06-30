
/// ==> MEMOIZATION METHOD

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mxN = 2e5;

ll dp[mxN];

int mx_point(int n)
{
    /// base case
    if(n == 0)
        return 0;
    if(n == 1)
        return dp[1];

    int res = mx_point(n-2) + n * dp[n];

    return max(mx_point(n-1), res);

}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    int mx = 0;

    for(int i=0; i<v.size(); i++)
    {
        cin >> v[i];
        mx = max(mx, v[i]);
    }

    for(int i=0; i<n; i++)
        dp[v[i]]++;

    int ans = mx_point(mx);

    cout<< ans <<"\n";

    return 0;
}
