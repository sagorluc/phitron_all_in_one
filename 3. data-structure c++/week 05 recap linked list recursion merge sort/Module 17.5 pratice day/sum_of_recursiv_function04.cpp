#include<bits/stdc++.h>
using namespace std;

int fib(vector<int> a,int n) {
    if( n == 0)
        return 0;

    return a[n-1] + fib(a,n-1);
}
int main()
{
    int n;
    cin >> n;

    vector<int>a(n);
    for( int i=0; i<n; i++)
        cin >> a[i];

    int ans = fib(a,n);
    cout<< ans << " ";


    return 0;
}
Sagor10@@##
