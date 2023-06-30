#include<bits/stdc++.h>
using namespace std;

/**
    w
u -----> v

    a
u -----> x

u -> (v,w), (x,a)

time complexity-> O(n^2)
space complexity-> O(n)

*/

const int mxN = 1e5 + 5;
const int Infi = 1e5;

int visited[mxN];
int des[mxN];
vector<pair<int, int>> adj_list[mxN];
int nodes, edges;

void dijakstra(int src_node)
{
    // set value of distance array to infinite.
    for(int i=1; i<=nodes; i++)
        des[i] = Infi;

    // set value of distance array source node 0.
    des[src_node] = 0;

    // mark all nodes as unvisited.
    for(int i=0; i<nodes; i++)
    {
        int selected_node = -1;

        // mark all nodes as unvisited.
        for(int j=1; j<=nodes; j++)
        {
            if(visited[j] == 1)
                continue;

        // pick the unvisited node with minimum distance of node

            // selected_node = 2
            // j = 4
            // des[2] > des[4] -> selected_node= j

            if(selected_node == -1 || des[selected_node] > des[j] )
                selected_node = j;
        }

        // visited the all selected node.
        visited[selected_node] = 1;

        // for all adjacency node of node.
        for(auto adj_entry : adj_list[selected_node]) // pair
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;

            if(des[selected_node] + edge_cost < des[adj_node] )
                des[adj_node] = des[selected_node] + edge_cost;
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

    // print the minimum distance of cost for all the nodes
    for(int i=1; i<=nodes; i++)
        cout<< des[i] <<" ";
    cout<<"\n";

    return 0;
}
