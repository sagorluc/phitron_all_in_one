#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;
const int INF = 1e5;

vector<pair<int,int>> adj_list[mxN];
int dist[mxN];

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;

    for(int i=1; i<=nodes; i++)
        dist[i] = INF;

    for(int i=0; i<edges; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v,w});
    }

    int src = 1;
    dist[src] = 0;

    bool yes_negative = false;

    for(int i=1; i<=nodes; i++)
    {
        for(int node=1; node<=nodes; node++)
        {
            for(pair<int,int> adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if(dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;

                    if(i == nodes)
                        yes_negative = true;
                }
            }
        }
    }

    if(yes_negative == true)
        cout<< "YES\n";
    else
        cout<< "NO\n";




    return 0;
}
