#include<bits/stdc++.h>
using namespace std;

// time complexity- O(2n)

int fib(int n)
{
    if(n <= 2)
        return 1;
    return fib(n-1) + fib(n-2);

}
int main()
{
    int n;
    cin >> n;

    cout<<fib(n)<<"\n";

    return 0;
}
