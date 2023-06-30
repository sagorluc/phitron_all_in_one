#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long int n, sum = 0, mis;
    cin >>n;
    vector<long long int> a;
    a.resize(n);

    for(long long int i=0; i<n-1; i++)
        cin>>a[i];

    for(long long int i=0; i<n-1; i++)
    {
        sum = sum + a[i];
    }

    for(long long int i=0; i<n-1; i++)
    {
        mis = (n * (n + 1)/2) - sum;

    }

    cout<<mis<<"\n";



    return 0;
}
