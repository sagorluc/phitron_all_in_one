#include<bits/stdc++.h>
using namespace std;

const int mxN = 2e5 + 10;
int visited[mxN];
int level[mxN];
int parent[mxN];
vector<int> adj_list[mxN];

void bfs(int src_node)
{
    queue<int> q;

    visited[src_node] = 1;
    level[src_node] = 1;
    q.push(src_node);


    parent[src_node] = -1;

    while(q.empty() == false)
    {
        int head = q.front();
        q.pop();

        for(int adj_node : adj_list[head])
        {
            if(visited[adj_node] == 0)
            {
                parent[adj_node] = head;

                visited[adj_node] = 1;
                level[adj_node] = level[head] + 1;
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

    // print level.

    int destination_node = nodes;

    if(visited[destination_node] == 0)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }

    cout<<level[destination_node]<<"\n";

    int selected_node = destination_node;

    // print path.

    vector<int> path;

    while(true)
    {
        path.push_back(selected_node);

        if(selected_node == src)
            break;
        selected_node = parent[selected_node];

    }

    reverse(path.begin(), path.end());

    for(int node : path)
        cout<<node<<" ";
    cout<<"\n";



    return 0;
}
