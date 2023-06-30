#include <bits/stdc++.h>
using namespace std;

const int mxN = 1002;
const int mxM = 1002;

int n, m;
char grid[mxN][mxM];
bool visited[mxN][mxM];

// Recursively mark all squares in the current room
void dfs(int row, int col, int&room_size)
{
    // out of bounds
    if (row < 0 || row >= n || col < 0 || col >= m)
        return;

    // wall or already visited
    if (grid[row][col] == '#' || visited[row][col])
        return;

    visited[row][col] = true;
    room_size++;

    // moving left,right,up and down
    dfs(row - 1, col, room_size);
    dfs(row + 1, col, room_size);
    dfs(row, col - 1, room_size);
    dfs(row, col + 1, room_size);
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    // Count the number of rooms and the length of the longest room
    int num_of_room = 0;
    int mx_room_size = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && visited[i][j] == 0)
            {
                // Found an unvisited floor square
                num_of_room++;

                int room_size = 0;

                dfs(i, j, room_size);
                mx_room_size = max(mx_room_size, room_size);
            }
        }
    }

    cout <<"Rooms - "<< num_of_room << "\n";
    cout <<"Length of the longest room - "<< mx_room_size << "\n";

    return 0;
}

