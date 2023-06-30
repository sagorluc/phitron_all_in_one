/**

6 6
0 1
1 2
2 3
1 5
2 4
5 4


*/


#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int> arr[N]; //space-> O(V) vertex/node
int visited[N] = {0};
int check[N] = {0};


void BFS(int source)
{
    memset(visited,false,sizeof(visited)); // set 0 in array

    queue<int>q;
    q.push(source);

    while(!q.empty())
    {
        int frnt = q.front();
        q.pop();

        if(visited[frnt]==true)
        {
            continue;
        }

        //task
        cout<<frnt<<" ";
        visited[frnt] = true;

        for(auto child: arr[frnt])
        {
            if(visited[child]==0)
            {
                q.push(child);
                check[child]++;
            }
            else if (visited[child]==1)
            {
                check[child]++;
            }

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

    BFS(0);

    cout<<"\n";
    cout<< "for BFS :\n";
    for (int i = 0; i < node; i++)
    {
        cout << "Vertex" << i << "-> " << check[i] << "" << endl;
    }

}
