#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i];

    int x;
    cin >> x;

    vector<int> v1(x);
    for(int i=0; i<x; i++)
        cin >> v1[i];

    set<int> st1, st2, union_set;

    for(int i=0; i<v.size(); i++)
        st1.insert(v[i]);


    for(int i=0; i<v1.size(); i++)
        st2.insert(v1[i]);

    union_set.insert(st1.begin(), st1.end());
    union_set.insert(st2.begin(), st2.end());

    for(auto it=union_set.begin(); it != union_set.end(); it++)
        cout<< *it <<" ";



    return 0;
}
