#include<bits/stdc++.h>
using namespace std;

const int N = 1005;

int n, m;
int grid[N][N];
bool visited[N][N];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int dfs(int x, int y, int dep)
{
    visited[x][y] = true;

    int vol = dep;

    for (int i=0; i<4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                !visited[nx][ny] && grid[nx][ny] > 0)
        {
            int nv = dfs(nx, ny, grid[nx][ny]);
            vol += nv;
        }
    }
    return vol;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                visited[i][j] = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> grid[i][j];

        int ans = 0;

        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
            {
                if (visited[i][j] == 0 && grid[i][j] > 0)
                    ans = max(ans, dfs(i, j, grid[i][j]));
            }
        }
        cout << ans <<"\n";
    }
    return 0;
}
