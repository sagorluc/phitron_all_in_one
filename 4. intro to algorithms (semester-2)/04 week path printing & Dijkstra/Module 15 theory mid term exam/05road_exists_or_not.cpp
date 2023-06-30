#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mxN = 2e5 + 10;
int visited[mxN];
int parent[mxN];
vector<ll> adj_list[mxN];

void bfs(int src_node)
{
    queue<int> q;
    visited[src_node] = 1;
    q.push(src_node);

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
                q.push(adj_node);
            }
        }

    }

}

int main()
{
    ll nodes,edges;
    cin >> nodes >> edges;

    for(int i=0; i<edges; i++)
    {
        int a,b;
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int src = 1;
    bfs(src);

    int distination = nodes;

    if(visited[distination] == 0)
        cout<< "NO\n";
    else
        cout<<"YES\n";

    return 0;
}
