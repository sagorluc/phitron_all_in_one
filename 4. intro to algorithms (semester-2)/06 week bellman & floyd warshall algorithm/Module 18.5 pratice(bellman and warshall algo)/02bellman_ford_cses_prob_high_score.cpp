#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e17;
const long long NINF = INF * (-1);
const int N = 3000;
long long dist[N];
vector<vector<long long>> edges;
int n, m;

void bellman_ford(int src)
{
    for (int i = 2; i <= n; i++)
    {
        dist[i] = INF;
    }

    dist[src] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (dist[u] == INF)
                continue;
            dist[v] = min(dist[v], dist[u] + w);
            dist[v] = max(dist[v], NINF);
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            long long u = edges[j][0], v = edges[j][1], w = edges[j][2];
            if (dist[u] == INF)
                continue;
            dist[v] = max(dist[v], NINF);
            if (dist[u] + w < dist[v])
            {
                dist[v] = NINF;
            }
        }
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, (-1) * w});
    }

    bellman_ford(1);

    if (dist[n] == NINF)
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << dist[n] * (-1) << "\n";

    return 0;
}
