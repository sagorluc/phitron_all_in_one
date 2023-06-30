#include<bits/stdc++.h>
using namespace std;
/**
6 6
0 1
1 2
2 3
1 5
2 4
5 4

*/
const int N = 1e5;
vector<int> arr[N]; //space-> O(V) vertex/node
int visited[N] = {0};
int check[N] = {0};

void dfs(int src)
{
    cout<< src <<" ";

    visited[src] = 1;

    for(int child : arr[src])
    {
        if(visited[child] == 1)
            check[child]++;
        else if(visited[child] == 0)
        {
            check[child]++;
            dfs(child);

        }

    }

}
int main()
{
    int node,edge;
    cin>>node>>edge;

    //Build adjacency list/Graph
    for(int i=0; i<edge; i++)
    {
        int x,y;
        cin>>x>>y;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    dfs(0);

    cout<< "\nfor DFS :\n";

    for(int i=0; i<node; i++)
        cout<< i <<"->"<<check[i]<< "" <<"\n";

}
