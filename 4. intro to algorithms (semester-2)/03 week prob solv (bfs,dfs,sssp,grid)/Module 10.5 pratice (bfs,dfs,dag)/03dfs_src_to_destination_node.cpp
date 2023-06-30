#include<bits/stdc++.h>
using namespace std;
/**

*/
const int mxN = 1e5;
int visited[mxN];
int path[mxN];
vector<int> adj_list[mxN];

int dfs(int src, int dst)
{
    stack<int> s;

    visited[src] = 1;

    s.push(src);

    while(s.empty() == false)
    {
        int head = s.top();
        s.pop();

        if(head == dst)
            return head;

        for(int adj_node : adj_list[head])
        {
            if(visited[adj_node] == 0)
            {
                visited[adj_node] = 1;

                path[adj_node] = head;

                s.push(adj_node);
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

    int last = dfs(src,dst);

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

