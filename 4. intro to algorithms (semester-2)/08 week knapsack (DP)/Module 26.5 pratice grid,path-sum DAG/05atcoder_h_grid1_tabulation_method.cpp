#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mx_h = 1005;
const int mx_w = 1005;
const ll mod = 1e9 + 7;

ll dp[mx_h][mx_w];
char st[mx_h][mx_w];
int h,w;

int main()
{
    cin >> h >> w;

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin >> st[i][j];

    /// base case
    dp[0][0] = 1;

    /// loop over the states
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(i > 0 and st[i][j] == '.')
               dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;

            if(j > 0 and st[i][j] == '.')
                dp[i][j] = (dp[i][j] + dp[i][j-1]) % mod;

        }
    }

    cout<< dp[h-1][w-1] <<"\n";


    return 0;
}
