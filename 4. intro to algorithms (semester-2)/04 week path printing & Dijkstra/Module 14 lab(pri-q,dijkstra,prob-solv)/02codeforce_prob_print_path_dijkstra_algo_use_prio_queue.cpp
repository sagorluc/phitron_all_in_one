#include<bits/stdc++.h>
using namespace std;

/**
    w
u -----> v

    a
u -----> x

u -> (v,w), (x,a)

time complexity-> O(|E| log |V|)
space complexity-> O(m)
*/

const int mxN = 1e5 + 5;
const long long Infi = 1e18;

int visited[mxN], parent[mxN];
long long des[mxN];
vector<pair<int, int>> adj_list[mxN];
int nodes, edges;

void dijakstra(int src_node)
{
    // set value of distance array to infinite.
    for(int i=1; i<=nodes; i++)
        des[i] = Infi;

    // set value of distance array source node 0.
    des[src_node] = 0;

    // take an empty reverse priority queue and set distance 0.
    priority_queue<pair<long long, int>> pq;

    pq.push({0, src_node}); // set distance 0, and source node

    while(pq.empty() == false)
    {

        // pick the minimum distance value.
        pair<long long, int> head = pq.top(); // first->distance, second->value
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

    // taking edge with cost
    for(int i=0; i<edges; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;

        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});

    }

    int src = 2;
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

        current_node = parent[current_node]; // assign current node parent in the current node

    }

    reverse(path.begin(), path.end());

    for(int node : path)
        cout<< node <<" ";
    cout<<"\n";

    return 0;
}

