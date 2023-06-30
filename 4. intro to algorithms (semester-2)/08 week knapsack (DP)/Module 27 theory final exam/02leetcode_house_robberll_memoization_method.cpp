#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> dp;

int rob_house(vector<int> nums)
{
    /// base case
    if(nums.size() == 0)
        return 0;
    if(nums.size() == 1)
        return nums[0];
    if(nums.size() == 2)
        return max(nums[0], nums[1]);

    /// rob first house
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);

    for(int i=2; i<nums.size(); i++)
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);

    int first_house = dp[nums.size()-2];

    /// rob second house
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);

    for(int i=3; i<nums.size(); i++)
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);

    int second_house = dp[nums.size() - 1];

    int ans = max(first_house, second_house);

    dp[nums.size()] = ans;
    return ans;


}
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i=0; i<n; i++)
        cin >> v[i];

    int res = rob_house(v);

    cout<< res <<"\n";

    return 0;
}
