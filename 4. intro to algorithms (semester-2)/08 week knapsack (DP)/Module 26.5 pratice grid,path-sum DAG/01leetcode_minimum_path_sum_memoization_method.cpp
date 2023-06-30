#include<bits/stdc++.h>
using namespace std;

int dp[201][201];

int solve2(int i, int j, vector<vector<int>>&grid)
{
    /// base case
    if(i == 0 && j == 0)
        return grid[0][0];

    /// if out of bound
    if( i < 0 || j < 0)
        return 1e9;

    /// check the result already exists
    if(dp[i][j] != -1)
        return dp[i][j];

    // recursive calls
    int up = grid[i][j] + solve2(i-1, j, grid);

    int left = grid[i][j] + solve2(i, j-1, grid);

    int ans = min(up, left);

    return dp[i][j] = ans;
}

int main()
{
    int m,n;
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> v[i][j];

    for(int i=0; i<=m; i++)
        for(int j=0; j<=n; j++)
            dp[i][j] = -1;

    int res = solve2(m-1,n-1,v);

    cout<< res <<endl;

    return 0;
}
