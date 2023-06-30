#include<bits/stdc++.h>
using namespace std;

/// tabulation method
/// time complexity-> O(n)
/// space complexity-> O(n)
int dp[101];

int main()
{
    int n;
    cin >> n;

    dp[1] = 1;
    dp[2] = 2;

    for(int i=3; i<=n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    cout<< dp[n]<<"\n";


    return 0;
}
