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

int main()
{
    int n,m,ans;
    cin >> n >> m;

    for(int i=1; i<=n; i++)
        cin >> nums[i];

    /// base case
    dp[0][0] = 1;

    for(int i=1; i<=m; i++)
        dp[0][i] = 0;

    /// loop over the states
    for(int i=1; i<=n; i++)
    {
        for(int target=1; target<=m; target++)
        {
            /// calculate result from smaller sub-problem
            int ans1 = dp[i-1][target];

            /// handle corner case
            if(target < nums[i])
                dp[i][target] = ans1;

            int ans2 = dp[i-1][target - nums[i]];

            ans = ans1 or ans2;

            dp[i][target] = ans;

        }
    }

    if(dp[n][m] == 1)
        cout<<"yes\n";
    else
        cout<< "no\n";


    return 0;
}

