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

#include<bits/stdc++.h>
using namespace std;
using ll=long long;
pair<int,int> dir[4] = {{0,-1},{0,+1},{-1,0},{+1,0}};
const int maxN =1010;
char grid[maxN][maxN];
bool visited[maxN][maxN];
int n,m;

bool inside(int row,int col)
{
    if(row>=1 && row<=n && col>=1 && col<=m && grid[row][col]=='.' && !visited[row][col])
        return true;
    return false;
}
void dfs(int row,int col)
{
    visited[row][col]=true;

    for(int i=0; i<=3; i++)
    {
        int dx,dy;
        dx=dir[i].first;
        dy=dir[i].second;
        if(inside(row+dx,col+dy))
            dfs(row+dx,col+dy);
    }
}
void solve()
{
    cin >> n >> m;
    for(int row=1; row<=n; row++)
        for(int col=1; col<=m; col++)
            cin >> grid[row][col];

    int rooms=0;

    for(int row=1; row<=n; row++)
    {
        for(int col=1; col<=m; col++)
        {
            if(grid[row][col]=='.' && !visited[row][col])
            {
                rooms++;
                dfs(row,col);
            }
        }
    }
    cout << rooms << '\n';
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t=1;
    //cin >> t;

    while(t--)
        solve();
    return 0;
}
