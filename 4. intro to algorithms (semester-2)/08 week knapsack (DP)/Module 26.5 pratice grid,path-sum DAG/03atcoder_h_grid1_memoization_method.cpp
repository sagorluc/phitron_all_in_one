#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx_h = 1005;
const int mx_w = 1005;
const ll mod = 1e9 + 7;

ll dp[mx_h][mx_w];
char st[mx_h][mx_w];
int h,w;

int dfs(int row, int col)
{
    if(row == h || col == w || st[row][col] == '#')
        return 0;

    if(row == h-1 and col == w-1)
        return 1;

    if(dp[row][col] != -1)
        return dp[row][col];

    int ans = (dfs(row+1, col) % mod + dfs(row, col+1) % mod)%mod;
    dp[row][col] = ans;

    return ans;

}
int main()
{

    cin >> h >> w;

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin >> st[i][j];

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            dp[i][j] = -1;

    cout<< dfs(0,0) <<"\n";



    return 0;
}
