#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
int dp[N];

/**
# DP Steps Memorization-Method (recursive)
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

int trib(int n)
{
    // base case
    if(n <= 3)
        return 1;

    // check if the result already exists
    if(dp[n] != -1)
        return dp[n];

    // recursive equation
    int ans = trib(n-1) + trib(n-2) + trib(n-3);
    dp[n] = ans;
    return ans;

}

int main()
{
    int n;
    cin >> n;

    for(int i=1; i<=n; i++)
        dp[i] = -1;

    cout<< trib(n)<<"\n";

    return 0;
}
