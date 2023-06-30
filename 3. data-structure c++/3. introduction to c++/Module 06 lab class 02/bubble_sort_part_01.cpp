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

    //sorting
    // n ta pass
    //time complexity - O(n^2)
    //memory complexity- O(n)
    for(int i=0; i<n; i++)
    {
        int last = n-1-i;
        //before sorting last to frist sort hobe
        //cout<<last<<" ";
        bool sorted = true;
        for(int j=0; j<=last-1; j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                sorted = false;
            }
        }
        if(sorted)
            break;
        cout<<"after passing = "<<i<<"\n";
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\n";

    }
    cout<<"\n"<<"after sorting \n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";


    return 0;
}



/*

7
3 2 5 4 7 6 1

pass = 0, cnt = n-1
pass = 1, cnt = n-2
..
pass = n-1, cnt = 0

sum =((n-1)*n)/2
O(n^2)


*/
