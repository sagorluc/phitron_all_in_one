#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
        cin >> a[i];

    int x;
    cin>>x;
    vector<int>b(x);
    for(int i=0; i<x; i++)
        cin>>b[i];

    sort(a.begin(),a.end());

    int low = 0,high = n-1;

    while(high>=low)
    {
        int mid = (low+high)/2;
        if(a[mid]==b[x])
        {
            cout<<"YES"<<" ";
            break;
        }
        if(a[mid]>b[x])
        {
            high = mid - 1;
        }
        else
        {
            low = mid+1;
        }

    }
    cout<<"NO\n";

    return 0;
}
