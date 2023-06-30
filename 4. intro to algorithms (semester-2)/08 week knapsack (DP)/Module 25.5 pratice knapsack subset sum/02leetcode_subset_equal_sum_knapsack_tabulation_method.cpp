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

int main()
{
    int x;

    cin >> x;
    vector<int> nums(x);

    for (int i = 0; i < x; i++)
    {
        cin >> nums[i];
    }

    int n = nums.size();
    int sum = 0;

    for (int num : nums)
        sum += num;

    if (sum % 2 != 0)
        return false;

    int target = sum / 2;

    vector<bool> dp(target + 1, false);

    dp[0] = true;

    for (int num : nums)
    {
        for (int i = target; i >= num; i--)
            dp[i] = dp[i] || dp[i - num];

    }

    cout<< dp[target] <<"\n";

    return 0;
}
