#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount)
{
    vector<int> dp(amount+1,INT_MAX);
    dp[0]= 0;
    for (int i=1; i<=amount; i++)
    {
        // trying to solve for each amount from 1 to x
        for (int j=0; j<coins.size(); j++)
        {
            if ( i-coins[j] >= 0 && dp[i-coins[j]] != INT_MAX)
                dp[i]= min(dp[i],1+dp[i-coins[j]]);
        }
    }
    if (dp[amount]== INT_MAX)
        return -1;
    else
        return dp[amount];

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
