#include<bits/stdc++.h>
using namespace std;

const int mx=1005;
int visited[mx][mx];
int grid[mx][mx];
int n,m,i,j;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

bool is_inside(pair<int,int>coor)
{
    int x = coor.first;
    int y = coor.second;

    if(x>=0 && x<n && y>=0 && y<m)
    {
        return true;
    }
    return false;
}

bool is_safe(pair<int,int>coor)
{
    int x = coor.first;
    int y = coor.second;

    if(grid[x][y]==-1)
    {
        return false;
    }
    return true;
}

void BFS(pair<int,int>src)
{
    queue<pair<int,int>>q;

    q.push(src);
    visited[src.first][src.second]=1;
    //grid[src.first][src.second]=-1;

    while(q.size())
    {
        pair<int,int>head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for(i=0; i<4; i++)
        {
            int new_x = x+dx[i];
            int new_y = y+dy[i];
            pair<int,int>adj_node = {new_x,new_y};

            if(is_inside(adj_node) && is_safe(adj_node) && visited[new_x][new_y]==0)
            {
                q.push(adj_node);
                visited[new_x][new_y]=1;
                //grid[new_x][new_y]=-1;
            }
        }
    }
}
pair<int, int> find_unvisited() {

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0; j < m ; j++) {
            if(visited[i][j] == 0 && grid[i][j] == 0) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main()
{
    int cnt=0;
    cin>>n>>m;

    for(i=0; i<n; i++)
    {
        string input;
        cin>>input;
        for(j=0; j<m; j++)
        {
            if(input[j]=='#')
            {
                grid[i][j] = -1;
            }
        }
    }

    // for(i=0; i<n; i++)
    // {
    //     for(j=0; j<m; j++)
    //     {
    //         if(visited[i][j]==0 && grid[i][j]==0)
    //         {
    //             pair<int,int>src= {i,j};
    //             BFS(src);
    //             cnt++;
    //         }
    //     }
    // }
     while(true) {
        pair<int,int>src = find_unvisited();
        if(src == pair<int,int>(-1, -1)) {
            break;
        }
        BFS(src);
        cnt++;
    }
    cout<<cnt;
}

