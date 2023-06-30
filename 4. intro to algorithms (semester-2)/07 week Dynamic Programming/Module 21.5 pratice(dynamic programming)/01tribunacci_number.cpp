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

index 1 2 3 4 5 6
value 1,1,1,3,5,9

*/

const int N = 1e5;
int dp[N];

int main()
{
    int n;
    cin >> n;

    // base case
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    // loop through the state
    for(int i=4; i<=n; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    cout<<dp[n]<<"\n";


    return 0;
}
