#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;
int nodes,edges,q;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nodes >> edges >> q;

    // matrix initialize and set the value infinite
    vector<vector<int>> dist(nodes+1, vector<int>(nodes+1, INF));

    for(int i=0; i<edges; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;

        dist[a][b] = c;
        dist[b][a] = c;

    }

    for(int k=1; k<=nodes; k++)
    {
        for(int u=1; u<=nodes; u++)
        {
            for(int v=1; v<=nodes; v++)
            {
                dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
            }
        }
    }

    for(int i=0; i<q; i++)
    {
        int a,b;
        cin >> a >> b;

        if(dist[a][b] == INF)
            cout<< -1 <<"\n";
        else
            cout<< dist[a][b] <<"\n";
    }

    return 0;
}
