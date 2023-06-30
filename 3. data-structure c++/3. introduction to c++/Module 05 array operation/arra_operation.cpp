/*

--> binnary search array of operation

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;

    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }

    int low = 0, high = n-1;

    bool flag = 0;
    while(high>=low)
    {
        int mid = (low+high)/2;
        cout<<" low = "<<low<<" high = "<<high<<" mid = "<<mid<<"\n";
        if(a[mid]==k)
        {
            cout<<"YES = "<<"index = "<<mid<<"\n";
            flag = 1;
            break;

        }
        if(a[mid] > k)
        {
            high = mid-1; //right hand side
        }
        else
        {
            //a[mid] < k
            low = mid+1; //left hand side.
        }

    }
    if(flag==0)
        cout<<"NO"<<"\n";



    return 0;
}
/*
sort array - n;
10 10
2 4 6 7 8 9 10 11 12 14

n - lenght array

q - query
k - YES/NO and INDEX

*/
