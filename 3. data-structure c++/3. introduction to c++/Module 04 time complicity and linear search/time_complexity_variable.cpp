#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>a(n);
    //a.resize(n);

    for(int i=0; i<n; i++)
    {
        cin>>a[i];

    }

    for(int i=0; i<n; i++)
    {
        string ans = "NO\n";
        for(int j=0; j<n; j++)
        {
            if(i==j)
                continue;
            if(a[i] == a[j])
            {
                ans = "YES\n";
            }

        }
        cout<<"i = "<<i<<" "<<ans;

    }

//    int maxx = a[0];
//    int mini = a[0];
//    int sum = 0;
//
//    for(int i=0; i<n; i++)
//    {
//        maxx = max(maxx,a[i]);
//        mini = min(mini,a[i]);
//        sum = sum + a[i];
//    }
//
//    cout<<maxx<<"\n";
//    cout<<mini<<"\n";
//    cout<<sum<<"\n";



    return 0;
}
/*
4
2 4 6 2

i = 0 , YES
i = 1 , NO
i = 2 , NO
i = 3 , YES


*/
/*

mixx
mini
sum

*/
