#include<bits/stdc++.h>
using namespace std;
/**
problem-> https://cses.fi/problemset/task/1669

4 5
1 3
2 1
2 4
3 2
3 4

*/

const int mxN = 2e5;
int visited[mxN];
vector<int> adj_list[mxN];

bool dfs_cycle_detected(int node)
{
    visited[node] = 1;

    for(int adj_node : adj_list[node])
    {
        /**
            -visited[adj_node] == 0 -> unexplored node | apply dfs
            -visited[adj_node] == 1 -> "paused" node | cycle detected
            -visited[adj_node] == 2 -> "done" node | continue

        */

        if(visited[adj_node] == 0)
        {
            bool got_cycle = dfs_cycle_detected(adj_node);

            if(got_cycle)
                return true;
        }
        else if(visited[adj_node] == 1)
            return true;

        else if(visited[adj_node] == 2)
            continue;
    }
    visited[node] = 2;
    return false;


}

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin >> u >> v;

        adj_list[u].push_back(v);

    }

    bool cycle_exists = false;

    for(int i=1; i<=nodes; i++)
    {
        if(visited[i] == 0)
        {
            bool got_cycle = dfs_cycle_detected(i);

            if(got_cycle)
            {
                cycle_exists = true;
                break;
            }
        }
    }

    if(cycle_exists == true)
        cout<< "cycle exists\n";
    else
        cout<<"not cycle exists\n";


    return 0;
}
