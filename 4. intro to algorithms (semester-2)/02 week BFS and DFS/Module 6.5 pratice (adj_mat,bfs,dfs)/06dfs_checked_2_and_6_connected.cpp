#include<bits/stdc++.h>
using namespace std;

const int maxN = 1000;
vector<int> visited(maxN);
vector<int> adj_list[maxN];

int dfs(int src, int target)
{
    visited[src] = 1;

    for(int child : adj_list[src])
    {
        if(visited[child] == 0)
            dfs(child,target);

        if(child == target)
            return 1;
    }
    return 0;
}

int main()
{
    int n,e;
    cin >> n >> e;

    for(int i=0; i<e; i++)
    {
        int u,v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int conn = dfs(2,6);

    if(conn == 1)
        cout<< "2 and 6 are connected\n";
    else
        cout<< "2 and 6 not connected\n";

    return 0;
}

