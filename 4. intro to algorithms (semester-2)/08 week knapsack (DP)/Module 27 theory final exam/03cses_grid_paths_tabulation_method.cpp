
/// ===> TABULATION METHOD

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1010;
char grid[N][N];
ll dp[N][N];
ll mod = 1e9 + 7;
int x;

int main()
{
    cin >> x;

    for(int i=0; i<x; i++)
        for(int j=0; j<x; j++)
            cin >> grid[i][j];

    /// base case
    if(grid[0][0] == '.')
            dp[0][0] = 1;


    /// loop over the states
    for(int i=0; i<x; i++)
    {
        for(int j=0; j<x; j++)
        {
           if(i == 0 and j == 0)
            continue;

           if(i > 0 and grid[i][j] == '.')
                dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;

           if(j > 0 and grid[i][j] == '.')
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;

        }
    }

    cout<< dp[x-1][x-1] <<"\n";


    return 0;
}
