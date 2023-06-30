
/// ===> MEMOIZATION METHOD

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1000;
char grid[N][N];
ll dp[N][N];
ll mod = 1e9 + 7;
int x;

int numsOfPaths(int row, int col)
{
    /// base case
    if(row == x or col == x or grid[row][col] == '*')
        return 0;
    if(row == x-1 and col == x-1)
        return 1;

    /// check if the result already exists
    if(dp[row][col] != -1)
        return dp[row][col];

    /// calculate the result from the smaller sub-problem
    ll ans = (numsOfPaths(row+1, col) % mod +
               numsOfPaths(row,col+1) % mod) % mod;

    dp[row][col] = ans;
    return ans;

}
int main()
{
    cin >> x;

    for(int i=0; i<x; i++)
        for(int j=0; j<x; j++)
            cin >> grid[i][j];

    for(int i=0; i<x; i++)
        for(int j=0; j<x; j++)
            dp[i][j] = -1;

    cout<< numsOfPaths(0,0) <<"\n";

    return 0;
}
