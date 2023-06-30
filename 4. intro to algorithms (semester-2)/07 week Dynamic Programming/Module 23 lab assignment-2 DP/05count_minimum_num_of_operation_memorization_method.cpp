
/// ==> MEMOIZATION METHOD

#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;
const int mx = 2e9;

int cnt = 1;

int cnt_num(int n, unordered_map<int, int> dp)
{
    /// base case
    if(n == 1)
        return 0;

    /// check if the result already exists
    if(dp.find(n) != dp.end())
        return dp[n];

    int sub = mx, div2 = mx, div3 = mx;

    /// subtract by 1
    sub = cnt_num(n-1,dp) + cnt;

    /// divisible by 2
    if(n % 2 == 0)
        div2 = cnt_num(n/2, dp) + cnt;

    /// divisible by 3
    if(n % 3 == 0)
        div3 = cnt_num(n/3, dp) + cnt;

    int ans = min(sub,min(div2,div3));
    dp[n] = ans;
    return ans;

}
int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> dp;

    cout<< cnt_num(n,dp) <<"\n";

    return 0;
}
