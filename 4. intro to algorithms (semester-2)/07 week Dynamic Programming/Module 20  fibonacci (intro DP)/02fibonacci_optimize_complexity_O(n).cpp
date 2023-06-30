#include<bits/stdc++.h>
using namespace std;

// time complexity- O(n)

typedef long long ll;

ll arr[101];

/**

arr[3] = 2
arr[4] = 3
arr[5] = 5

if arr[6] not calculate then the initially value 0
arr[6] = 0

*/

ll fib(ll n)
{
    if(n <= 2)
        return 1;

    // check if fib(n) is already calculate
    if(arr[n] != 0)
        return arr[n];

    // if not calculate then calculate
    arr[n] = fib(n - 1) + fib(n - 2);
    return arr[n];

}

int main()
{
    ll n;
    cin >> n;

    cout<< fib(n) <<"\n";
    return 0;
}
