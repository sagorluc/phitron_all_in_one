#include<bits/stdc++.h>
using namespace std;

/**
input

    6 6
    0 1
    2 3
    1 5
    1 2
    2 4
    5 4

output

    Node 0->level 0
    Node 1->level 1
    Node 2->level 2
    Node 3->level 3
    Node 4->level 3
    Node 5->level 2


*/

const int mxN = 2002;
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

    int src= 0;
    bfs(src);

    for(int i=0; i<nodes; i++)
        cout<<"Node "<< i <<"->level "<<level[i]<<"\n";


    return 0;
}



