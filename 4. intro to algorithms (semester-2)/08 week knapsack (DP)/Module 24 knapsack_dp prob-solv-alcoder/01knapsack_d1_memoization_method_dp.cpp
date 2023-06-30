#include<bits/stdc++.h>
using namespace std;

/// 1. state: knapsack(n,cap) -> maximum profit considering
///    object 1 to n capacity = cap

/// 2. recurrence
///    knapsack(n,cap) -> max{val[n] + knapsack(n-1, cap - w[n])
///                           knapsack(n-1, cap)
///                          }

/// 3. base case
///    knapsack(0, x) = 0;

const int N = 102;
const int M = 1e5 + 5;
long long dp[N][M];
int val[N], w[N];

long long knapsack(int n, int cap)
{
    /// 1.base case
    if(n == 0)
        return 0;

    /// check if the result already exists
    if(dp[n][cap] != -1)
        return dp[n][cap];

    /// handle corner case
    if(cap < w[n])
    {
        long long ans = knapsack(n-1, cap);
        dp[n][cap] = ans;
        return ans;
    }

    /// 2 recurrence
    long long ans1 = val[n] + knapsack(n-1, cap - w[n]);
    long long ans2 = knapsack(n-1, cap);

    long long ans3 = max(ans1, ans2);

    dp[n][cap] = ans3;

    return ans3;



}
int main()
{
    int n, cap;
    cin >> n >> cap;

    for(int i=1; i<=n; i++)
        cin >> w[i] >> val[i];

    for(int i=0; i<=n; i++)
        for(int j=0; j<=cap; j++)
            dp[i][j] = -1;

    long long ans = knapsack(n,cap);

    cout<< ans <<"\n";


    return 0;
}
