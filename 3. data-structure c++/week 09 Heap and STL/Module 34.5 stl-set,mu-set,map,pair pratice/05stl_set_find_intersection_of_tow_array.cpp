#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];

    for(int i=0; i<n; i++)
        cin >> a[i];

    int x;
    cin >> x;

    int b[x];

    for(int i=0; i<x; i++)
        cin >> b[i];

    set<int> s(a, a+n);
    set<int> s1(b, b+x);

    set<int> ans;

    for(auto i=s.begin(); i != s.end(); i++)
    {
        if(s1.find(*i) != s1.end())
            ans.insert(*i);
    }


    for(auto it : ans)
        cout<<it<<" ";
    return 0;
}



