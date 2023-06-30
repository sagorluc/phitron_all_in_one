#include<bits/stdc++.h>
using namespace std;
/**
    wrong code.does not work.

    input:

    8 11
    7 8
    7 3
    7 6
    3 1
    1 2
    1 4
    4 0
    0 2
    0 6
    6 3
    3 2

*/

const int mxN = 1e5;
int visited[mxN];
vector<int> adj_list[mxN];
int level[mxN];

void dfs(int src)
{
    visited[src] = 1;
    level[src] = 0;

    for(int adj_node : adj_list[src])
    {
        if(visited[adj_node] == 0)
        {
            visited[adj_node] = 1;
            level[adj_node] = level[src]+1;
            dfs(adj_node);
        }
    }

}

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }

    int src = 3;
    dfs(src);

    for(int i=0; i<=nodes; i++)
    {
       cout<<i<<"->"<<level[i]<<"\n";
    }
    cout<<"\n";


    return 0;
}


