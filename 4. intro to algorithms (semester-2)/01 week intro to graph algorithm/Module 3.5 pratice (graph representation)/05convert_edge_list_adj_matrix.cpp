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

    int matrix[n + 1][n + 1];

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            matrix[i][j] = 0;

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<adj_list[i].size(); j++)
        {
            matrix[i][adj_list[i][j]] = 1;
            matrix[adj_list[i][j]][i] = 1;
        }
    }

    for(int i=0; i<=n; i++)
    {

        for(int j=0; j<=n; j++)
            cout<< matrix[i][j] <<" ";

        cout<<"\n";
    }

    return 0;
}

