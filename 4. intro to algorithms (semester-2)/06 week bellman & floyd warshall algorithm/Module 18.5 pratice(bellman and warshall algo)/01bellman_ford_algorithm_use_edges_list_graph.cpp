#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;
const int Infi = 1e9;
int dis[mxN];
vector<pair<int,pair<int,int>>> edge_list;

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;

        edge_list.push_back({u,make_pair(v,w)}); // take input by edge list
    }

    for(int i=1; i<=nodes; i++)
        dis[i] = Infi;

    int src = 1;
    dis[src] = 0;

    for(int i=1; i<=nodes-1; i++)
    {
        for(int node=1; node<=nodes; node++)
        {
            for(pair<int,pair<int,int>> adj_node : edge_list)
            {

                int u = adj_node.first;
                int v = adj_node.second.first;
                int w = adj_node.second.second;

                if(u == node)
                {
                    if(dis[u] + w < dis[v])
                        dis[v] = dis[u] + w;

                }

            }
        }
    }

    for(int i=1; i<=nodes; i++)
        cout<< dis[i] <<" ";
    cout<<"\n";




    return 0;
}
