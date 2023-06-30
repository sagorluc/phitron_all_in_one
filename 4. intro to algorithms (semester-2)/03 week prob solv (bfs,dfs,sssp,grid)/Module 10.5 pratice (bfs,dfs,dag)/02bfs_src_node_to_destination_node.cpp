#include<bits/stdc++.h>
using namespace std;
/**
1. Start by initializing a queue and adding the source node to it.
2. While the queue is not empty, dequeue the first node in the queue.
3. If this node is the destination node, we have found the path! We can backtrack from the destination node to the source node by following the parent pointers that were set during the BFS.
4. If the node is not the destination node, iterate over its neighbors and enqueue any neighbors that have not been visited yet. Set the parent pointer of each neighbor to the current node.
5. Repeat steps 2-4 until either the destination node is found or the queue is empty.

*/
const int mxN = 1e5;
int visited[mxN];
int path[mxN];
vector<int> adj_list[mxN];

int bfs(int src, int dst)
{
    queue<int> q;

    visited[src] = 1;
    path[dst] = -1;

    q.push(src);

    while(q.empty() == false)
    {
        int head = q.front();
        q.pop();

        if(head == dst)
            return head;

        for(int adj_node : adj_list[head])
        {
            if(visited[adj_node] == 0)
            {
                visited[adj_node] = 1;
                path[adj_node] = head;
                q.push(adj_node);
            }
        }
    }
    return -1;

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

    int src,dst;
    cin >> src >> dst;

    int last = bfs(src,dst);

    if(last == -1)
        cout<<"path not founded\n";
    else
    {
        vector<int> v;
        v.push_back(last);

        while(last != src)
        {
            last = path[last];
            v.push_back(last);
        }

        for(int i=v.size()-1; i>=0; i--)
            cout<< v[i] <<" ";
        cout<<"\n";
    }

    return 0;
}
