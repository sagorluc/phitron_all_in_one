#include<bits/stdc++.h>
using namespace std;
/**

Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output: 3

#have to check

while there exists an empty cell
    - find an empty unvisited cell
    - rum bfs() from that cell


*/
int n,m;
const int mxN = 2002;
int maze[mxN][mxN];
int visited[mxN][mxN];
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

                q.push(adj_node);
            }
        }
    }
}

pair<int, int> find_visited()
{
  for(int i=0; i<n; i++)
  {
      for(int j=0; j<m; j++)
      {
          if(visited[i][j] == 0 && maze[i][j] == 0)
          return {i,j};
      }
  }
  return {-1, -1};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++)
    {
        string input;
        cin >> input;

        // converting grid to graph
        for(int j=0; j<m; j++)
        {
            if(input[j] == '#')
                maze[i][j] = -1;
        }
    }

//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<m; j++)
//            cout<< maze[i][j]<<" ";
//        cout<<"\n";
//    }
//    cout<<"\n";

//    bfs(src);

    int room_cnt = 0;

    while(true)
    {
        pair<int,int> unvisited_pos = find_visited();

        if(unvisited_pos == pair<int,int>(-1, -1))
            break;

        bfs(unvisited_pos);
        room_cnt++;
    }
    cout<< room_cnt <<"\n";

    return 0;
}

