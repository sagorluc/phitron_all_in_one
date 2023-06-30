#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;

/// - state: fun(n,x)-> maximum happiness till day-n if
///        we pick task x on day n

/// - recurrence: fun(n,x)-> max{
///                          fun(n-1, y) where x != y + happiness[n][x]
///                         }

/// - base case: fun(1,x) = happiness[1][x]

int happiness[mxN][4];
int dp[mxN][4];

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=3; j++)
            cin >> happiness[i][j];

    /// 1. base case
    for(int task=1; task<=3; task++)
        dp[1][task] = happiness[1][task];


    /// 2. loop over the states
    for(int day=1; day<=n; day++)
    {
        for(int current_task=1; current_task<=3; current_task++)
        {
            int mx_profit = 0;

            for(int last_task=1; last_task<=3; last_task++)
            {
                /// handle corner case
                if(current_task != last_task)
                {
                    int current_profit = dp[day-1][last_task] + happiness[day][current_task];
                    mx_profit = max(mx_profit, current_profit);

                }

            }
            dp[day][current_task] = mx_profit;
        }
    }

    int ans = max({dp[n][1], dp[n][2], dp[n][3]});
    cout<< ans <<endl;




    return 0;
}
