#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    //memory complexity - O(n)
    //time complexity - O(n^2)
    for(int i=1; i<n; i++)
    {
        int index = i;
        while(index >= 1)
        {
            if(a[index-1] > a[index])
            {
                swap(a[index-1],a[index]);
                index--;
            }
            else
                break;
        }
        //cout<<"considering = "<<i<<"--> ";
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }
   // cout<<"after sorting "<<"\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";

    return 0;
}
/*
insertion sort
time complexity
0+1+2+3+....+n-1

O(n^2)
*/
