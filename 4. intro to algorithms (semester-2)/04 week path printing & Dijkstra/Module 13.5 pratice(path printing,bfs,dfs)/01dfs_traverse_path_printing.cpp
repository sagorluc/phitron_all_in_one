#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int visited[mxN];
vector<int> adj_list[mxN];
int parent[mxN];

void dfs(int src_node)
{
    visited[src_node] = 1;
    //parent[src_node] = 0;

    for(int adj_node : adj_list[src_node])
    {
        if(visited[adj_node] == 0)
        {
            parent[adj_node] = src_node;
            visited[adj_node] = 1;
            dfs(adj_node);
        }
    }

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

    int src = 1;
    dfs(src);

    int destination_node = n;

    // print path.

    vector<int> path;

    while(true)
    {
        path.push_back(destination_node);

        if(destination_node == src)
            break;
        destination_node = parent[destination_node];

    }

    reverse(path.begin(), path.end());

    for(int node : path)
        cout<<node<<" ";
    cout<<"\n";


    return 0;
}
