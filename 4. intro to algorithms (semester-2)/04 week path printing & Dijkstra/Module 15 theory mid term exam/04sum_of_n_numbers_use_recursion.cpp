#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int sum(ll arr[], int n)
{
    // base case
    if(n == 0)
        return 0;

    return arr[n - 1] + sum(arr, n-1);
}
int main()
{
    int n;
    cin >> n;

    ll arr[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    ll ans = sum(arr, n);

    cout<<ans<<"\n";

    return 0;
}
