#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5 + 5;
const int INF = 1e6 + 6;
vector<pair<int,int>> adj_list[mxN];
int visited[mxN];
int parent[mxN];
int des[mxN];
int nodes,edges;

void dijakstra(int src_node)
{
    for(int i=1; i<=nodes; i++)
        des[i] = INF;

    des[src_node] = 0;

    priority_queue<pair<long long, int>> pq;

    pq.push({0, src_node}); // set distance 0, and source node

    while(pq.empty() == false)
    {

        // pick the minimum distance value.
        pair<long long, int> head = pq.top();
        pq.pop();

        int selected_node = head.second;

        if(visited[selected_node])
            continue;
        else
            visited[selected_node] = 1;


        // for all adjacency node of node.
        for(auto adj_entry : adj_list[selected_node]) // pair
        {
            int adj_node = adj_entry.first;

            int edge_cost = adj_entry.second;

            if(des[selected_node] + edge_cost < des[adj_node] )
            {
                des[adj_node] = des[selected_node] + edge_cost;

                parent[adj_node] = selected_node;

                pq.push({-des[adj_node], adj_node});
            }
        }
    }

}

int main()
{
    cin >> nodes >> edges;


    for(int i=0; i<edges; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;

        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});

    }

    int src = 1;
    dijakstra(src);

    // if we not reach to destination return -1;
    if(visited[nodes] == 0)
    {
        cout<<-1<<"\n";
        return 0;
    }

    // path printing

    int current_node = nodes;

    vector<int> path;

    while(true)
    {
        path.push_back(current_node);

        if(current_node == src)
            break;

        current_node = parent[current_node];
    }

    reverse(path.begin(), path.end());

    for(int node : path)
        cout<< node <<" ";
    cout<<"\n";


    return 0;
}
