#include<bits/stdc++.h>
using namespace std;
/**
same edge multiple times and different different cost
then we will took the minimum of cost.

1 --> 2 4
1 --> 2 6
1 --> 2 7
*/
const long long int Infi = 1e18;
const int mxN = 1e3 + 3;
long long int dis[mxN][mxN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges, q;
    cin >> nodes >> edges >> q;

    for(int i=1; i<=nodes; i++)
        for(int j=1; j<=nodes; j++)
            dis[i][j] = Infi;

    for(int i=0; i<edges; i++)
    {
        int u,v; long long w;
        cin >> u >> v >> w;

        dis[u][v] = min(dis[u][v], w); // undirected graph and same edge multiple times
        dis[v][u] = min(dis[v][u], w); // undirected graph and same edge multiple times
    }

    // diagonal all value is zero
    for(int i=1; i<=nodes; i++)
        dis[i][i] = 0;

    for(int k=1; k<=nodes; k++) // intermediate node
    {
        for(int u=1; u<=nodes; u++) // all possible pair node
        {
            for(int v=1; v<=nodes; v++) // all possible pair node
            {
                dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
            }
        }
    }

    for(int i=0; i<q; i++)
    {
        int a,b;
        cin >> a >> b;

        if(dis[a][b] == Infi)
            cout<< -1 <<"\n";
        else
            cout<<dis[a][b]<<"\n";
    }

    return 0;
}
/**
time complexity-> O(v^3)
space complexity-> O(v^2)

*/

