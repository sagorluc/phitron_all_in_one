
/// ===> MEMOIZATION METHOD

#include<bits/stdc++.h>
using namespace std;

const int N = 101;
const int M = 1010;

int dp[N][M];

int rob_max(vector<int> nums, int i, bool j)
{
    /// base case
    if(i >= nums.size() or (i==nums.size()-1 and j))
        return 0;

    /// check if the result already exists
    if(dp[i][j] != -1)
        return dp[i][j];

    /// calculate the result from smaller sub-problem
    int yes_rob = 0, not_rob = 0;

    if(i==0)
        yes_rob = rob_max(nums,i+2,1) + nums[i];
    else
        yes_rob = rob_max(nums,i+2,j) + nums[i];

    not_rob = rob_max(nums,i+1,j);

    int ans = max(yes_rob, not_rob);

    dp[i][j] = ans;

    return ans;
}

int rob(vector<int> nums)
{
    return rob_max(nums,0,0);
}

int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<v.size(); i++)
        cin >> v[i];

    memset(dp, -1, sizeof(dp));

    int res = rob(v);

    cout<< res <<"\n";


    return 0;
}
