#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int visited[mxN];
vector<int> adj_list[mxN];
int parent[mxN];

/**
-> question 7 weighted graph

9 15
1 2 2
1 3 1
1 10 5
1 9 18
2 3 7
2 5 20
2 6 13
2 8 15
2 10 6
3 5 9
5 7 5
6 7 1
6 8 21
8 9 7
9 10 6

*/

int dfs_cycle_detection(int src_node)
{
    visited[src_node] = 1;

    for(int adj_node : adj_list[src_node])
    {
        if(visited[adj_node] == 0) // unvisited node
        {
            parent[adj_node] = src_node;

            int got_cycle = dfs_cycle_detection(adj_node);

            if(got_cycle == true)
                return true;
        }

        else if(parent[src_node] != adj_node)
            return true;

    }
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
        adj_list[v].push_back(u);

    }

    for(int i=1; i<=nodes; i++)
    {
        if(visited[i] == 0)
        {
            bool got_cycle = dfs_cycle_detection(i);

            if(got_cycle == true)
            {
                cout<<"cycle exists\n";
                return 0;
            }
            else
            {
                cout<<"no cycle\n";
                return 0;
            }
        }

    }

    return 0;
}
