#include<bits/stdc++.h>
using namespace std;

/*
// for any kind of graph traverse by DFS traversal
// visited_array
void DFS(int node)
{
   cout<< node <<"\n";

   visited_array[node] = 1;

   for all adj_node of node:
        if(visited_array[adj_node] == 0)
            dfs(adj_node);


--> time complexity- O(v + e)
--> space complexity- O(v)

}

*/
const int N = 1e5;

int visited[N];

vector<int> adj_list[N];
// adj_list[1] -> 2,4,6
// 1-> 2, 1-> 4, 1-> 6

// adj_list[2] -> 1,3,5
// 2-> 1, 2-> 3, 2-> 5

void dfs(int node)
{
    cout<< node <<" ";

    visited[node] = 1;

    for(int adj_node : adj_list[node])
    {
        if(visited[adj_node] == 0)
            dfs(adj_node);
    }

}
/*

   0----1-----2-----3
        |     |
        |     |
        5-----4

output-> 0,1,2,3,4,5
node = 6
edge = 6

6 6

0 1
1 2
2 3
2 4
4 4
5 1

*/
int main()
{
    int node, edge;
    cin >> node >> edge;

    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int src = 2;
    dfs(src);

    return 0;
}
