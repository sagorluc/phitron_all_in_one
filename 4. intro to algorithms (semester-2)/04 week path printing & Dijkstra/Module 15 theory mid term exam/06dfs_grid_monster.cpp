#include<bits/stdc++.h>
using namespace std;

const int mxN = 1010;
char maze[mxN][mxN];
bool visited[mxN][mxN];
string path;
int nodes, edges, start_x, start_y;

bool is_inside(int x, int y)
{   // check the borders
    if(x<1 || x>nodes || y<1 || y>edges)
        return false;

    // wall, monster or already visited nodes
    if(maze[x][y] == '#' || maze[x][y] == 'M' || visited[x][y])
        return false;
    else
        return true;
}

bool DFS(int x, int y)
{
    visited[x][y] = true;

    // append the border cell to the path
    if(x == 1 || x == nodes || y == 1 || y == edges)
    {
        path = path + maze[x][y];
        return true;
    }

    // Moving Down
    if(is_inside(x+1, y))
    {
        path = path + 'D';

        if(DFS(x+1,y))
            return true;

        path.pop_back();
    }

    // Moving Left
    if(is_inside(x, y-1))
    {
        path = path + 'L';

        if(DFS(x, y-1))
            return true;

        path.pop_back();
    }

    // Moving Up
    if(is_inside(x-1, y))
    {
        path = path + 'U';

        if(DFS(x-1, y))
            return true;

        path.pop_back();
    }

    // Moving Right
    if(is_inside(x, y+1))
    {
        path = path + 'R';

        if(DFS(x, y+1))
            return true;

        path.pop_back();
    }

    return false;
}

int main()
{
    cin >> nodes >> edges;

    for(int i=1; i<=nodes; i++)
    {
        for(int j=1; j<=edges; j++)
        {
            cin >> maze[i][j];

            if(maze[i][j] == 'A')
            {
                start_x = i;
                start_y = j;
            }
        }
    }

    if(DFS(start_x,start_y) == true)
        cout << "YES\n" << path.size()-1 << "\n" << path << "\n";

    else
        cout << "NO\n";


    return 0;
}

