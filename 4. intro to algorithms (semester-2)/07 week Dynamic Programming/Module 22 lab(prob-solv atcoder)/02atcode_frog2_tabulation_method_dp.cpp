#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;
const long long INF = 2e9;

/// stone(n)-> cost of reaching n-th stone from 1st stone
/// recurrence-> stone(n) = for i=1 to k
///                       = min(stone (n-i) + abs(h[n] - h[n-i])))
/// base case = stone(1) = 0

/**

 2 <==== (2-1),(2-2) ...(2-4)
          1,  0 , -1, -2 (does't exists any negative value 0 to -2)

 Corner case => can't jump stone with number <= 0
*/

int h[mxN], dp[mxN];

int main()
{
    int n,k;
    cin >> n >> k;

    for(int i=1; i<=n; i++)
        cin >> h[i];

    /// 1. base case
    dp[1] = 0;

    /// 2. loop through the states
    for(int i=2; i<=n; i++)
    {
        dp[i] = INF;

        /// calculate from smaller sub problem
        for(int j=1; j<=k; j++)
        {
            int from_stone = i - j;
            /// corner case handle
            if(from_stone <= 0)
                break;

            int candidate_ans = dp[from_stone] + abs(h[i] - h[from_stone]);
            dp[i] = min(dp[i], candidate_ans);

        }

    }

    cout<< dp[n] <<"\n";


    return 0;
}
