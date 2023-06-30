#include<bits/stdc++.h>
using namespace std;

/// time complexity-> O(n*m)
/// space complexity-> O(n*m)

/**
- state-> fun(n,m) -> number of unique paths from (0,0) to (n,m)
- recurrence-> fun(n,m) -> f(n-1,m) + f(n,m-1)
- base case -> f(0,0) = 1

*/


const int N = 101;
int dp[N][N];

int unique_path(int row, int col)
{
    /// base case
    if(row == 0 && col == 0)
        return 1;

    /// check if the result already exists
    if(dp[row][col] != -1)
        return dp[row][col];

    int ans = 0;
    /// calculate the result from smaller sub-problems
    /// handle corner case
    if(row > 0)
        ans += unique_path(row-1, col);

    /// handle corner case
    if(col > 0)
        ans += unique_path(row, col-1);

    dp[row][col] = ans;
    return ans;

}

int main()
{
    int row,col;
    cin >> row >> col;

    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            dp[i][j] = -1;


    cout<< unique_path(row-1, col-1) <<endl;


    return 0;
}
