#include<bits/stdc++.h>
using namespace std;

const int mxN = 1000;
int visited[mxN];
vector<int> adj_list[mxN];
int color[mxN];

bool check_bipartite(int src)
{
    visited[src] = true;

    for(int adj_node : adj_list[src])
    {
        // for unvisited child
        if(visited[adj_node] == false)
        {
            visited[adj_node] = true;

            // if the child color opposite to it's parent color
            color[adj_node] = (color[src] == false);

            // if the child rooted at parent node is not bipartite
            if(check_bipartite(adj_node) == false)
                return false;
        }
        // if child and parent color are same
        else if(color[adj_node] == color[src])
            return false;
    }
    return true;

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

    int src = 0;

    if(check_bipartite(src))
        cout<< "YES\n";
    else
        cout<< "NO\n";

    return 0;
}
