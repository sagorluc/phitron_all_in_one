#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cin >> n >> e;

    vector<vector<int>> adj_list(n + 1);

    for(int i=0; i<e; i++)
    {
        int l,r;
        cin >> l >> r;

        adj_list[l].push_back(r);
        adj_list[r].push_back(l);
    }

    for(int i=0; i<=n; i++)
    {
        cout<<i<<"->";

        for(auto j : adj_list[i])
            cout<< j <<" ";

        cout<<"\n";
    }

    return 0;
}
