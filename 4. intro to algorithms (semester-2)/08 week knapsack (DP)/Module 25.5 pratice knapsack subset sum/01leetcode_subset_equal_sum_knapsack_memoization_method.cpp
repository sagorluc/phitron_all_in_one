#include<bits/stdc++.h>
using namespace std;

/**
- state: fun(n, target)-> return true if
         it is possible to create a subset from numbers
         1 to n and from the sum "target"

- recurrence: fun(n, target)-> fun(n-1, target) OR
              fun(n-1, target - num[n])

- base case: fun(0, target) = 1 if target == 0
                                else 0

3
1 2 5

4
1 5 11 5

4
2 4 1 3

4
2 4 1 4

*/

const int N = 1010;
const int M = 1e5 + 5;
int dp[N][M];

bool solve(int idx, int sum, vector<int>& nums, vector<vector<int>>& dp)
{
    if (sum == 0)
        return true;

    if (idx == 0)
        return nums[0] == sum;

    if (dp[idx][sum] != -1)
        return dp[idx][sum];

    bool notTaken = solve(idx-1, sum, nums, dp);

    bool taken = false;

    if (nums[idx] <= sum)
        taken = solve(idx-1, sum-nums[idx], nums, dp);

    return dp[idx][sum] = notTaken || taken;
}
bool canPartition(vector<int>& nums)
{
    int n = nums.size();
    int totalSum = 0;

    for (int i = 0; i < n; i++)
        totalSum += nums[i];

    if (totalSum % 2)
        return false;

    int sum = totalSum / 2;

    vector<vector<int>> dp(n, vector<int>(sum+1, -1));

    return solve(n-1, sum, nums, dp);
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i=0; i<n; i++)
    {
        int in;
        cin >> in;
        nums.push_back(in);
    }

    for(int i=0; i<=n; i++)
        for(int j=0; j<=nums.size(); j++)
            dp[i][j] = -1;

    bool res = canPartition(nums);

    if(res)
        cout<< "yes\n";
    else
        cout<< "no\n";



    return 0;
}

