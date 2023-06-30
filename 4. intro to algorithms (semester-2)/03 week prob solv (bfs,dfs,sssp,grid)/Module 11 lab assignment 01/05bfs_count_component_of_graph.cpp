#include<bits/stdc++.h>
using namespace std;

const int mxN = 1000;
int visited[mxN];
vector<int> adj_list[mxN];

void bfs(int node)
{
    queue<int> q;

    visited[node] = 1;
    q.push(node);

    while(q.empty() == false)
    {
        int head = q.front();
        q.pop();

        for(int adj_node : adj_list[head])
        {
            if(visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
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

    // count component

    int cnt = 0;

    for(int i=0; i<nodes; i++)
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
