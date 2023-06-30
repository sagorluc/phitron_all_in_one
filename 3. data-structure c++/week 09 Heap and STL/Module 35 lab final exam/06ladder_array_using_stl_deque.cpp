#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int>v(n);

    for(int i=0; i<n; i++)
        cin >> v[i];

    deque<int> dq;

    for(int i=0; i<v.size(); i++)
        dq.push_back(v[i]);


    sort(dq.begin(), dq.end());

    for(auto it : dq)
        cout<< it <<" ";

    return 0;
}
