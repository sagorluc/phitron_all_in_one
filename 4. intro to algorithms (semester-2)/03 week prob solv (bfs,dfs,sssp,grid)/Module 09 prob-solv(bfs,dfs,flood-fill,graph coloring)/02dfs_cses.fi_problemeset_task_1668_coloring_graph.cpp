#include<bits/stdc++.h>
using namespace std;
/**

    Input:

    5 3
    1 2
    1 3
    4 5
    Output: 1 2 2 1 2

    number of node 5
    number of edge 3

   (1) (2)- color
    1---2
    |
    3
   (2)

   (1) (2)
    4---5



*/
typedef long long ll;

const ll mxN = 2e5 + 5;
ll visited[mxN];
vector<ll> adj_list[mxN];
ll color[mxN];

bool dfs(ll src)
{
    visited[src] = 1;

    for(ll adj_node : adj_list[src])
    {
        // if unvisited nodes
        if(visited[adj_node] == 0)
        {
            // assign different color to the adjacency node
            if(color[src] == 1)
                color[adj_node] = 2;
            else
                color[adj_node] = 1;

            bool is_bicolorable = dfs(adj_node);

            if(is_bicolorable == false)
                return false;
        }

        // if visited nodes
        else
        {
            // check if color is same or different
            if(color[src] == color[adj_node])
                return false;
        }
    }
    return true;
}
int main()
{
    ll nodes,edges;
    cin >> nodes >> edges;

    for(ll i=0; i<edges; i++)
    {
        ll u,v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }

    ll src = 0;
    dfs(src);

    // set color
    bool is_bicolorable = true;

    for(ll i=1; i<=nodes; i++)
    {
        if(visited[i] == 0)
        {
            color[i] = 1;

            bool ok = dfs(i);

            if(!ok)
            {
                is_bicolorable = false;
                break;
            }
        }
    }

    if(is_bicolorable == false)
        cout<< "IMPOSSIBLE"<<"\n";
    else
    {
        for(int i=1; i<=nodes; i++)
            cout<< color[i] <<" ";
        cout<<"\n";
    }


    return 0;
}
