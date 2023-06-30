#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& coins, int x, vector<int>& dp)
{
    /// base case
    if (x==0)
        return 0;
    if (x<0)
        return INT_MAX;

    /// check if the result already exists
    if (dp[x] != -1)
        return dp[x];

    int mini= INT_MAX;

    /// calculate the result from smaller sub-problem
    for (int i=0; i<coins.size(); i++)
    {
        int ans= solve(coins,x-coins[i],dp);

        if (ans!= INT_MAX)
            mini= min(mini,1+ans);
    }
    return dp[x]= mini;
}
int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1,-1);

    int ans= solve(coins,amount,dp);

    if (ans== INT_MAX)
        return -1;
    else
        return ans;

}
int main()
{
    int n,k;
    cin >> n;

    vector<int> v(n);

    for(int i=0; i<v.size(); i++)
        cin >> v[i];

    cin >> k;

    int res = coinChange(v,k);

    if(res == INT_MAX)
        cout<< -1 <<endl;
    else
        cout<< res <<endl;

    return 0;
}
