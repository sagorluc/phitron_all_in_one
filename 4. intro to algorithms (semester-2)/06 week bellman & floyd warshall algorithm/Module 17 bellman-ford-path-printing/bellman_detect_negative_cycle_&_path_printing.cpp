#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll mxN = 1e5 + 5;
const ll Infi = 1e18;

vector<pair<ll,ll>> adj_list[mxN];
ll parent[mxN];
ll dis[mxN];

int main()
{
    ll nodes, edges;
    cin >> nodes >> edges;

    for(int i=1; i<=nodes; i++)
        dis[i] = Infi;

    for(int i=0; i<edges; i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;

        adj_list[u].push_back({v, w});
    }

    ll negative_cycle = false;
    ll last_updated_node = -1;

    for(int i=1; i<=nodes; i++) // iteration loop
    {
        for(int node=1; node<=nodes; node++) // node loop
        {
            for(pair<ll,ll> adj_node : adj_list[node]) // connected node to adjacency node loop
            {
                ll u = node;
                ll v = adj_node.first;
                ll w = adj_node.second;

                if(dis[u] + w < dis[v])
                {
                    dis[v] = dis[u] + w;

                    parent[v] = u;

                    if(i == nodes)
                    {
                        negative_cycle = true;
                        last_updated_node = v; // n-th iteration updated node.that mean its part of negative cycle or
                                              // node that can be reached from the negative cycle
                    }
                }
            }

        }
    }

  // path printing

  if(negative_cycle == false)
    cout<< "NO\n";
  else
  {
    cout<< "YES\n";

    ll selected_node = last_updated_node;

    for(int i=1; i<=nodes-1; i++)
        selected_node = parent[selected_node]; // n-1 times parent trace or track

        ll first_node = selected_node;

        vector<ll> cycle;
        cycle.push_back(selected_node); // until we back to selected_node we trace the parent

        while(true)
        {
            selected_node = parent[selected_node]; // track the parent node and push to cycle vector
            cycle.push_back(selected_node);

            if(selected_node == first_node)
                break;
        }

        reverse(cycle.begin(), cycle.end());

        for(int nodee : cycle)
            cout<< nodee <<" ";
        cout<<"\n";


  }

    return 0;
}
