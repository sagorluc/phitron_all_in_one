#include<bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int visited[mxN];
int level[mxN];

vector<int> adj_list[mxN];

void bfs(int src)
{
    queue<int> q;

    visited[src] = 1;
    level[src] = 0;
    q.push(src);

    while(q.empty() == false)
    {
        int head = q.front();
        q.pop();

        for(int adj_node : adj_list[head])
        {
            if(visited[adj_node] == 0)
            {
                visited[adj_node] = 1;

                level[adj_node] = level[head]+1;

                q.push(adj_node);
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

    int src = 1;
    bfs(src);

    if(visited[nodes] == 0)
        cout<< "impossible\n";
    else
    {
        int k = level[nodes];
        cout<<k+1<<"\n";
    }
    return 0;
}


