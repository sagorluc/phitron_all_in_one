
/// ===> DFS TRAVERSE

#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int n, ax, ay, bx, by, cx, cy;
bool visited[N][N];

/// check validity of move
bool valid(int x, int y)
{
    return (x >= 1 and x <= n and y >= 1 and
            y <= n and !visited[x][y]);
}


void dfs(int x, int y)
{
    visited[x][y] = true;


    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int a = x + dx;
            int b = y + dy;

            if (valid(a, b))
            {
                if (a == cx && b == cy)
                {
                    cout<<"YES\n";
                    exit(0);
                }

                dfs(a, b);
            }
        }
    }
}

int main()
{
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;

    /// marking danger for the queen
    for (int i = 1; i <= n; i++)
    {
        visited[ax][i] = true;
        visited[i][ay] = true;

        if (ax + i <= n and ay + i <= n)
            visited[ax+i][ay+i] = true;

        if (ax + i <= n and ay - i >= 1)
            visited[ax+i][ay-i] = true;

        if (ax - i >= 1 and ay + i <= n)
            visited[ax-i][ay+i] = true;

        if (ax - i >= 1 and ay - i >= 1)
            visited[ax-i][ay-i] = true;
    }

    dfs(bx, by);

    /// if can't reach to the destination
    cout << "NO\n";

    return 0;
}
