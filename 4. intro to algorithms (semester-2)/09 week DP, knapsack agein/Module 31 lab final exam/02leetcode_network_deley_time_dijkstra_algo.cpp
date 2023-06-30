
#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

const int N = 1010;

vector<pair<int,int>> adj_list[N];

int dijkstra_opti(int source, int target, int n)
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> dist(n+1, INF);

    dist[source] = 0;

    pq.push({0, source});

    while(!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u])
            continue;

        for(auto v : adj_list[u])
        {
            int to = v.first;
            int weight = v.second;
            if(dist[u] + weight < dist[to])
            {
                dist[to] = dist[u] + weight;
                pq.push({dist[to], to});
            }
        }
    }

    if(dist[target] == INF)
        return -1;
    else
        return dist[target];
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

    int source;
    cin >> source;

    int minTime = -1;
    for(int i=1; i<=n; i++)
    {
        if(i == source)
            continue;
        int time = dijkstra_opti(source, i, n);
        if(time == -1)
        {
            cout << "-1" << endl;
            return 0;
        }
        minTime = max(minTime, time);
    }

    cout << minTime << endl;

    return 0;
}

