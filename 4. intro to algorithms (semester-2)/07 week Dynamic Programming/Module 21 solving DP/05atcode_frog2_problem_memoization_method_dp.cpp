#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int mxN = 1e6;
int h[N];
int dp[N];
int n,k;

int stone(int idx)
{
    // base case
    if(idx == n-1)
        return 0;

    if(dp[idx] != -1)
        return dp[idx];

    int ans = mxN;

    for(int i=1; i<=k; i++)
    {
        if(idx + i >= n)
            break;
        ans = min(ans, stone(idx+i) + abs(h[idx+i] - h[idx]));
    }

    dp[idx] = ans;

    return dp[idx];

}

int main()
{

    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin >> h[i];

    for(int i=1; i<=n; i++)
        dp[i] = -1;

    cout<< stone(1)<<"\n";





    return 0;
}
