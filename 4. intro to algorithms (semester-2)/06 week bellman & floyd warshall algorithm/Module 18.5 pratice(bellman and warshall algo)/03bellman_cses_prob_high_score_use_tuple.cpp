#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int mxN = 2505;
int n, m;
vector<tuple<int, int, long long>> edges; // vector of edges
long long dist[mxN];

bool bellman_ford()
{
    for(int i=1; i<=n; i++)
        dist[i] = -INF;

    dist[1] = 0;

    for (int i = 1; i <= n - 1; ++i)
    {
        for (auto [u, v, w] : edges)
        {
            if (dist[u] != -INF && dist[u] + w > dist[v])
            {
                dist[v] = dist[u] + w;

            }
        }
    }

    // negative cycle detected
    for (auto [u, v, w] : edges)
    {
        if (dist[u] != -INF && dist[u] + w > dist[v])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int a, b;
        long long x;
        cin >> a >> b >> x;
        edges.push_back({a, b, x});
    }

    if(dist[n] == true)
        cout<< -1 <<"\n";
    else
        cout<< dist[n] <<"\n";

    return 0;
}
