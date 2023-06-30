#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mxN = 1e5 + 5;
const ll infi = 9e18;

int visited[mxN];
ll dis[mxN];
vector<pair<int, int>> adj_list[mxN];
int nodes, edges, q, a, b;

void dijkstra(int src)
{
    for (int i = 1; i <= nodes; i++)
        dis[i] = infi;

    dis[src] = 0;

    priority_queue<pair<ll, int>> pq;
    // priority_queue<pair<ll,ll>, vector<pair<ll,ll>, greater<pair<ll,ll>>> pq; // min heap
    pq.push({0, src});

    while (pq.empty() == false)
    {


        pair<int, int> head = pq.top();
        pq.pop();

        int selected_node = head.second;

        if (visited[selected_node] == true)
            continue;
        visited[selected_node] = 1;

        for (auto adj_entry : adj_list[selected_node]) // pair
        {
            int adj_node = adj_entry.first;
            int edge_cost = adj_entry.second;

            if (dis[selected_node] + edge_cost < dis[adj_node])
            {
                dis[adj_node] = dis[selected_node] + edge_cost;
                pq.push({-dis[adj_node], adj_node});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nodes >> edges >> q;

    for (int i = 0; i < edges; i++)
    {
        int u, v, w, q;
        cin >> u >> v >> w;

        adj_list[u].push_back({v, w});
        adj_list[v].push_back({u, w});
    }

    for (int i = 0; i < q; i++)
    {

        cin >> a >> b;

        dijkstra(a);

        if (dis[b] == infi)
        {
            cout << -1 << "\n";
        }
        else
        {
            cout << dis[b] << "\n";
        }

        memset(dis, 0, sizeof(dis)); // assign 0 in distance array
        memset(visited, 0, sizeof(visited)); // assign 0 in visited array
    }

    return 0;
}
