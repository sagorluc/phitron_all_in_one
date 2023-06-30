#include<bits/stdc++.h>
using namespace std;

/**
-> Dijkstra algorithm

// input -> a weighted graph and a source.
// output -> distance of all nodes from the source.

 if u -> v got edges

 d[u] + c(u,v) < d[v]
 d[v] = d[u] + c(u,v);

    space complexity -> O(n) + O(n) + O(1) = O(n)
    time complexity -> O(n) + O(n^2) + O(1) = O(n^2)

    - create a distance array "d"
    - initialize all values of "d" to infinity
    - d[source] = 0;
    - create a visited array and mark all nodes as unvisited

    - for i = 0 to n-1
        - pick the unvisited node with the minimum d[node]
        - visited[node] = 1;

        - for all adj_node of node
            - if d[node] + c(node, adj_node) < d[adj_node]
            - d[adj_node] = d[node] + c(node, adj_node)

        output array of "d".

input: directed graph
6 8
1 2 10
1 3 15
2 6 15
2 4 12
3 5 10
4 6 1
4 5 2
6 5 5
output
0 10 15 22 24 23

input: undirected graph
9 14
0 1 4
0 7 8
1 7 11
1 2 8
2 8 2
2 5 4
2 3 7
3 4 9
3 5 14
4 5 10
5 6 2
6 8 6
6 7 1
7 8 7
output-> 22 14 9 0 10 12 13 16 100000;


*/

typedef long long ll;
const int mxN = 1e5 + 5;
const ll infi = 1e5;
int visited[mxN];
vector<pair<int, int>> adj_list[mxN];
ll dis[mxN];
int nodes,edges;

void dijkstra(int src)
{
    for(int i=1; i<=nodes; i++)
        dis[i] = infi;

    dis[src] = 0;

    for(int i=0; i<nodes; i++)
    {
        int selected_node = -1;

        // mark all node as unvisited
        for(int j=1; j<=nodes; j++)
        {
            if(visited[j] == 1)
                continue;

            // pick the unvisited node with minimum distance node
            if(selected_node == -1 || dis[selected_node] > dis[j])
                selected_node = j;

        }

        visited[selected_node] = 1;

        // check for adjacency node.
        for(auto child : adj_list[selected_node]) // pair
        {
            int adj_node = child.first;
            int edge_cost = child.second;

            if(dis[selected_node] + edge_cost < dis[adj_node])
                dis[adj_node] = dis[selected_node] + edge_cost;

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

    int src = 2;
    dijkstra(src);

    for(int i=1; i<=nodes; i++)
        cout<<dis[i]<<" ";
    cout<<"\n";


    return 0;
}
