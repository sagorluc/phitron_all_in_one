#include<bits/stdc++.h>
using namespace std;

/// Memorization method
/// time complexity-> O(n)
/// space complexity-> O(n)

const int N = 1e5;
int dp[N];

int solve(int n)
{
    //base case
    if(n<=2)
        return n;

    if(dp[n] != -1)
        return dp[n];

    dp[n]=solve(n-1)+solve(n-2);
    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        dp[i] = -1;

    cout<< solve(n) <<"\n";



    return 0;
}
