
///====> BFS TRAVERSE

#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
bool vis[N][N];
bool dan[N][N];

int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};
int n,ax, ay, bx, by, cx, cy;


int bfs()
{
    queue<pair<int, int>> q;
    q.push({bx, by});

    vis[bx][by] = true;



    while(q.empty() == false)
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();


        if(x == cx and y == cy)
            return true;

        /// moving up,down,left,right and diagonal
        for(int i=0; i<8; i++)
        {
            int a = x + dx[i];
            int b = y + dy[i];


            if(a >= 1 and a <= n and b >= 1 and b <=n and
                    !vis[a][b] and !dan[a][b])
            {
                q.push({a,b});
                vis[a][b] = true;
            }

        }

    }
    return false;
}

int main()
{
    cin >> n;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    /// marking the danger for the queen
    for(int i=1; i<=n; i++)
    {
        dan[ax][i] = true;
        dan[i][ay] = true;

        if(ax+i <= n and ay+i <=n )
            dan[ax+i][ay+i] = true;

        if(ax+i <= n and ay-i >= 1 )
            dan[ax+i][ay-i] = true;

        if(ax-i >= 1 and ay+i <=n )
            dan[ax-i][ay+i] = true;

        if(ax-i >= 1 and ay-i >= 1 )
            dan[ax-i][ay-i] = true;

    }

    if(bfs() == true)
        cout<< "YES\n";
    else
        cout<< "NO\n";



    return 0;
}
