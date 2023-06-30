#include<bits/stdc++.h>
using namespace std;
const int N = 201;

int dp[N][N];

int main()
{
    int m,n;
    cin >> m >> n;

    vector<vector<int>> v(m, vector<int>(n));

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin >> v[i][j];


    int x = v.size();
    int y = v[0].size();

    /// base case
    dp[0][0] = v[0][0];

    for(int i=1; i<m; i++)
        dp[i][0] = dp[i-1][0] + v[i][0];

    for(int j=1; j<n; j++)
        dp[0][j] = dp[0][j-1] + v[0][j];

    for(int i=1; i<m; i++)
        for(int j=1; j<n; j++)
            dp[i][j] = min(dp[i-1][j],dp[i][j-1])+v[i][j];

    cout<< dp[m-1][n-1]<<"\n";

    return 0;
}
