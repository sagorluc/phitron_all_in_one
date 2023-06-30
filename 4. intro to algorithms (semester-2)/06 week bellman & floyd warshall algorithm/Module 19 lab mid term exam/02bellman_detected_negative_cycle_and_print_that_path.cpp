#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 1e5 + 5;
const ll INF = 1e18;

vector<pair<int,ll>> adj_list[mxN];
ll dist[mxN];
int parent[mxN];

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;

    for(int i=1; i<=nodes; i++)
        dist[i] = INF;

    for(int i=0; i<edges; i++)
    {
        int u,v; ll w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v,w});
    }

    int src = 1;
    dist[src] = 0;

    bool yes_negative = false;
    int last_updated_node = -1;

    for(int i=1; i<=nodes; i++)
    {
        for(int node=1; node<=nodes; node++)
        {
            for(pair<int,ll> adj_node : adj_list[node])
            {
                int u = node;
                int v = adj_node.first;
                int w = adj_node.second;

                if(dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;

                    parent[v] = u;

                    if(i == nodes)
                    {
                        yes_negative = true;
                        last_updated_node = v;
                    }
                }
            }
        }
    }

    if(yes_negative == true)
    {
        cout<< "YES\n";

        int selected_node = last_updated_node;

        for(int i=1; i<=nodes; i++)
            selected_node = parent[selected_node];

        vector<int> cycle;

        int first_node = selected_node;

        cycle.push_back(selected_node);

        while(true)
        {
            selected_node = parent[selected_node];
            cycle.push_back(selected_node);

            if(selected_node == first_node)
                break;

        }
        reverse(cycle.begin(), cycle.end());

        for(int nodee : cycle)
            cout<< nodee <<" ";
        cout<<"\n";

    }
    else
        cout<< "NO\n";




    return 0;
}

