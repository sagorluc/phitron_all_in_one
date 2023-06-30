#include<bits/stdc++.h>
using namespace std;

/**
# DP Steps Tabulation-Method (iterative)
=========================================

- Define state
- Identify the recursive equation from the smaller problems
- Define base case

- fib(n) -> calculate the n-th fibonacci number
- fib(n) = fib(n-1) + fib(n-2)
- fib(1) = 1, fib(2) = 1

*/

const int N = 101;
int dp[N]; // dp array

int main()
{
    int n;
    cin >> n;

    // 1. base case
    dp[1] = 1;
    dp[2] = 1;

    // 2. loop through the states
    for(int i=3; i<=n; i++)
       // 2.1 and calculate the result from smaller sub-problems
        dp[i] = dp[i-1] + dp[i-2];

    cout<< dp[n] <<" ";

    return 0;
}
