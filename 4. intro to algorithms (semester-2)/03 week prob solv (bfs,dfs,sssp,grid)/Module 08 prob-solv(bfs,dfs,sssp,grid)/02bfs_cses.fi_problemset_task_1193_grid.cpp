#include<bits/stdc++.h>
using namespace std;
/**
input:

5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9

# node = -1
. node = 0

    (5,6)--> right--> (5,7)
    (5,6)--> leftt--> (5,5)
    (5,6)--> up--> (4,6)
    (5,6)--> down--> (6,6)

    (x,y)--> right (x,y+1)
    (x,y)--> left (x,y-1)
    (x,y)--> up (x-1,y)
    (x,y)--> down (x+1,y)

    x  y
    -  -
    0  1
    0 -1
   -1  0
    1  0

  direction array
-------------------
    dx[] = {0, 0, -1, 1};
    dy[] = {1, -1, 0, 0};

    for(int i=0; i<4; i++)
    {
      int new_x = x + dx[i];
      int new_y = y + dy[i];

    }

    have to check for this problem
------------------------------------
    1. is the cell within the maze;
    2. is the cell forbidden/ wall
    3. is the cell unvisited?


*/

int n,m;
const int mxN = 2002;
int maze[mxN][mxN];
int visited[mxN][mxN];
int level[mxN][mxN];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

// check is the cell within the maze
bool is_maze(pair<int, int> coordinate)
{
    int x = coordinate.first;
    int y = coordinate.second;

    if(x >= 0 && x <= n && y >= 0 && y <= m)
        return true;
    else
        return false;

}

// check is the cell forbidden/wall
bool is_safe(pair<int,int> coordinate)
{
    int x = coordinate.first;
    int y = coordinate.second;

    if(maze[x][y] == -1)
        return false;
    else
        return true;

}


void bfs(pair<int,int>src)
{
    queue<pair<int,int>> q;

    visited[src.first][src.second] = 1;
    level[src.first][src.second] = 0;

    q.push(src);

    while(q.empty() == false)
    {
        pair<int,int> head = q.front();
        q.pop();

        int x = head.first;
        int y = head.second;

        for(int i=0; i<4; i++)
        {
            int new_x = x + dx[i]; // left,right,up,down
            int new_y = y + dy[i]; // left,right,up,down

            pair<int, int> adj_node = {new_x, new_y}; // get the adjacent node

            if(is_maze(adj_node) && is_safe(adj_node) && visited[new_x][new_y] == 0)
            {
                visited[new_x][new_y] = 1;

                level[new_x][new_y] = level[x][y] + 1;

                q.push(adj_node);
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    pair<int,int> src,dst;

    // all level should be -1
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            level[i][j] = -1;


    for(int i=0; i<n; i++)
    {
        string input;
        cin >> input;

        for(int j=0; j<m; j++)
        {
            if(input[j] == '#')
                maze[i][j] = -1;

            else if(input[j] == 'A')
                src = {i,j};

            else if(input[j] == 'B')
                dst = {i,j};

        }
    }

//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<m; j++)
//            cout<< maze[i][j]<<" ";
//        cout<<"\n";
//    }
//    cout<<"\n";f

    bfs(src);

    if(level[dst.first][dst.second] == -1)
        cout<< "No\n";
    else
        cout<<"Yes\n"<<level[dst.first][dst.second]<<"\n";

    return 0;
}
