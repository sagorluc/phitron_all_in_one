#include<bits/stdc++.h>
using namespace std;

/**
# DP Steps recursive-method
============================

- Define state
- Identify the recursive equation from the smaller problems
- Define base case

- fib(n) -> calculate the n-th fibonacci number
- fib(n) = fib(n-1) + fib(n-2)
- fib(1) = 1, fib(2) = 1

*/

const int N = 101;

int dp[N]; // dp array

int fib(int n)
{
    if(n <= 2)
        return 1;
    // check if the current states is already solved
    if(dp[n] != -1)
        return dp[n];

    // calculate from smaller sub-problems
    int ans = fib(n-1) + fib(n-2);
    dp[n] = ans;
    return dp[n];

}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++) // mark all states as unvisited
        dp[i] = -1;

    //memset(dp, -1, sizeof(dp)); // initially set value -1

    cout<< fib(n) <<"\n";

    return 0;
}
