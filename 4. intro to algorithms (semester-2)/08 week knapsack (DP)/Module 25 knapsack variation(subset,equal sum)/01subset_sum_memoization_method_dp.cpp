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

*/

const int N = 1010;
const int M = 1e5 + 5;

int dp[N][M];
int nums[N];

bool fun_sum(int n, int target)
{
    /// base case
    if(n == 0)
    {
        if(target == 0)
            return 1;
        else
            return 0;

    }

    /// check if the result already exists
    if(dp[n][target] != -1)
        return dp[n][target];

    /// calculate result from smaller states

    int ans1 = fun_sum(n-1, target);

    /// handle corner case
    if(target < nums[n])
    {
        dp[n][target] = ans1;
        return ans1;
    }

    int ans2 = fun_sum(n-1, target - nums[n]);

    int ans = ans1 or ans2;

    dp[n][target] = ans;

    return ans;

}

int main()
{
    int n,target;
    cin >> n >> target;

    for(int i=1; i<=n; i++)
        cin >> nums[i];

    for(int i=0; i<=n; i++)
        for(int j=0; j<=target; j++)
            dp[i][j] = -1;

    bool ans = fun_sum(n, target);

    if(ans == 1)
        cout<<"yes\n";
    else
        cout<< "no\n";


    return 0;
}
