#include<bits/stdc++.h>
using namespace std;

// fibonacci series
// time complexity- O(2^n)
int fib(int n)
{
    if( n <= 1)
        return n;

    return fib(n-1) + fib(n-2);
}

int main()
{
    int n;
    cin >> n;

    cout<< fib(n)<<" ";
    return 0;
}

/*

Exponential complexity.

time complexity- O(2^n)
space complexity- O(1)

*/


