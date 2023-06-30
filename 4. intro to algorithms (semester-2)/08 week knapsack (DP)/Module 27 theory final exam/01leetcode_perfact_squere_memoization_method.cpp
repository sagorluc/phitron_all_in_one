
/// ===> MEMOIZATION METHOD

#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int dp[N];

int perfect_square(int n)
{
    /// base case
    if(n == 0)
        return 0;

    /// check if the result already exists
    if(dp[n] != -1)
        return dp[n];

    /// calculate the result from the smaller sub-problem
    int ans = INT_MAX;
    for(int i=1; i<=sqrt(n); i++)
    {
        int a = i*i;
        int b = perfect_square(n-a) + 1;
        ans = min(ans, b);
    }
    dp[n] = ans;
    return ans;

}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        dp[i] = -1;

    int res = perfect_square(n);
    cout<< res <<"\n";

    return 0;
}
