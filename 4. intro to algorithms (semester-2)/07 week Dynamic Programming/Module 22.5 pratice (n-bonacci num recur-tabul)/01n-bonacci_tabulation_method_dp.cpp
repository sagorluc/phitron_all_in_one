#include<bits/stdc++.h>
using namespace std;

/// time complexity-> O(n*k)
/// space complexity-> O(n)

const int mxN = 1e5;
int dp[mxN];

int main()
{
    int n,k;
    cin >> n >> k;

    /// 1. base case
    for(int i=1; i<=k; i++)
        dp[i] = 1;


    /// 2. loop over the states
    for(int i=k+1; i<=n; i++) /// loop start from k = 4+1 = 5
    {
        dp[i] = 0;

        for(int j=i-k; j<i; j++) /// loop start from i = 5 - 4 = 1
        {
            dp[i] = dp[i] + dp[j];
        }

    }
    cout<< dp[n] <<"\n";


    return 0;
}
