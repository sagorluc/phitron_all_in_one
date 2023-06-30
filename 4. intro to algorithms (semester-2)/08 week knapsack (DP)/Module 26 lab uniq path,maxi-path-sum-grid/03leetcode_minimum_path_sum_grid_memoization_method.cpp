#include<bits/stdc++.h>
using namespace std;

/// time complexity- O(n*m)
/// space complexity- O(n*m)

/**
- state -> fun(n,m) -> minimum cost from (0,0) to (n,m)
- recurrence -> fun -> min(fun(n-1,m) + arr[n,m], fun(n,m-1) + arr[n,m])
- base case -> fun(0,0) = 1

*/

const int N = 101;
const int M = 201;
int dp[N][M];
vector<vector<int>> arr(N, vector<int>(M));

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
    int row, col;
    cin >> row >> col;

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            cin >> arr[i][j];

    for(int i=0; i<=row; i++)
        for(int j=0; j<=col; j++)
            dp[i][j] = -1;

    cout<< solve2(row-1,col-1,arr) <<endl;

    return 0;
}

///int dp[205][205];
///int fun(vector<vector<int>>& v,int i,int j,int n,int m)
///{
///    if(i==n-1 && j==m-1) return v[i][j];
///    if(i>=n || j>=m) return INT_MAX-101;
///   if(dp[i][j] != -1) return dp[i][j];
///    cout<<v[i][j]<<endl;
///    int ans1=fun(v,i,j+1,n,m);
///    int ans2=fun(v,i+1,j,n,m);
///    return dp[i][j]=min(ans1,ans2)+v[i][j];
///
///}
