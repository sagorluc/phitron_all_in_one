
/// ==> MEMOIZATION METHOD

#include<bits/stdc++.h>
using namespace std;

long long dp[40];

int trib(int n)
{
    /// base case
    if(n == 0)
        return 0;
    if(n == 1 || n == 2)
        return 1;

    /// check if the result already exists
    if(dp[n] != -1)
        return dp[n];

    return trib(n-1) + trib(n-2) + trib(n-3);


}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        dp[i] = -1;

    cout<< trib(n) <<"\n";

    return 0;
}
