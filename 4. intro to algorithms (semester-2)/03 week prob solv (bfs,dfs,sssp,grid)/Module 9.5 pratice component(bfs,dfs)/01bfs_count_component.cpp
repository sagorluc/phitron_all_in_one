#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int visited[mxN];
vector<int> adj_list[mxN];

void bfs(int src)
{
    queue<int> q;

    visited[src] = 1;
    q.push(src);

    while(q.empty()==false)
    {
        int head = q.front();
        q.pop();

        for(int adj_node : adj_list[head])
        {
            if(visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                q.push(src);
            }
        }
    }
}

int main()
{
    int nodes,edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++)
    {
        int u,v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }

    int cnt = 0;

    for(int i=1; i<=nodes; i++)
    {
        if(visited[i] == false)
        {
            bfs(i);
            cnt++;
        }
    }
    cout<< cnt <<"\n";


    return 0;
}
