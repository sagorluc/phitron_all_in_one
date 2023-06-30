
// problem link-> https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;

/**
- tabulation-method(iteration)
===================================

- state: stone(n) -> cost of reaching n-th stone from first stone

- recurrence: stone(n) = min( stone(n-1) + abs( h[n] - h[n-1] ),
                              stone(n-2) + abs( h[n] - h[n-2] )

                             )
- base case: stone(1) = 0


*/

const int N = 1e5 + 5;
int dp[N];
int h[N];

int main()
{
    int n, ans1, ans2, res;
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> h[i];


    // base case
    dp[1] = 0;

    // loop through the state
    for(int i=2; i<=n; i++)
    {
        ans1 = ( dp[i-1] + abs( h[i] - h[i-1]) );

        // edge/corner case
        if(i == 2)
        {
            dp[i] = ans1;
            continue;
        }

        ans2 = ( dp[i-2] + abs( h[i] - h[i-2]) );

        dp[i] = min(ans1, ans2);

    }

    cout<< dp[n] <<"\n";


    return 0;
}
