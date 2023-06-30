#include<bits/stdc++.h>
using namespace std;

const int Infi = 1e9;
const int mxN = 1e3 + 3;
int dis[mxN][mxN];

int main()
{
    int nodes, edges;
    cin >> nodes >> edges;

    for(int i=1; i<=nodes; i++)
        for(int j=1; j<=nodes; j++)
            dis[i][j] = Infi;

    for(int i=0; i<edges; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;

        dis[u][v] = w;
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

    for(int i=1; i<=nodes; i++)
        for(int j=1; j<=nodes; j++)
            cout<<dis[i][j]<<" ";
    cout<<"\n";

    return 0;
}
/**
time complexity-> O(v^3)
space complexity-> O(v^2)

*/
