#include<bits/stdc++.h>
using namespace std;

const int mxN = 1000;
int visited[mxN];
vector<int> adj_list[mxN];

bool dfs(int node)
{
    visited[node] = 1;

    for(int adj_node : adj_list[node])
    {
        if(visited[adj_node] == 0) // unexplored node
        {
            bool got_cycle = dfs(adj_node);

            if(got_cycle)
                return true;
        }
        else if(visited[adj_node] == 1) // paused node
            return true;

        else if(visited[adj_node] == 2) // done node
            continue;
    }
    visited[node] = 2;
    return false;

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

    }

    bool cycle_exists = false;

    for(int i=0; i<nodes; i++)
    {
        if(visited[i] == 0)
        {
            bool got_cycle = dfs(i);

            if(got_cycle)
            {
                cycle_exists = true;
                break;
            }
        }


    }

    if(cycle_exists == true)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}
