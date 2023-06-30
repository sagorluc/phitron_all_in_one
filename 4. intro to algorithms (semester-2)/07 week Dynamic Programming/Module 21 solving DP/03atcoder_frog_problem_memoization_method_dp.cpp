
// problem link-> https://atcoder.jp/contests/dp/tasks/dp_a

#include<bits/stdc++.h>
using namespace std;

/**

Memoization->method(recursive)
=================================

- state: stone(n) -> cost of reaching n-th stone from first stone

- recurrence: stone(n) = min( stone(n-1) + abs( h[n] - h[n-1] ),
                              stone(n-2) + abs( h[n] - h[n-2] )

                             )
- base case: stone(1) = 0


*/

const int N = 1e5 + 5;
int h[N];  // height array
int dp[N]; // dp array

int stone(int n)
{
    // base case
    if(n <= 1)
        return 0;

    // check if the result already exists
    if(dp[n] != -1)
        return dp[n];

    // recurrence
    int ans = ( stone(n-1) + abs( h[n] - h[n-1] ) ); // n=2 -> n-1=1

    // edge/corner case handle
    if(n == 2)
    {
        dp[n] = ans;
        return ans;
    }

    int ans1 = ( stone(n-2) + abs( h[n] - h[n-2] ) ); // n=2 -> n-2=0 not corrent

    int res = min(ans, ans1);

    dp[n] = res;

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        cin >> h[i];

    for(int i=1; i<=n; i++)
        dp[i] = -1;

    cout<< stone(n) <<" ";

    return 0;
}
