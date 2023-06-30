#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx_h = 1005;
const int mx_w = 1005;

ll dp[mx_h][mx_w];
int h, w;
ll mod = 1e9+7;

int main()
{
    cin >> h >> w;

    /// base case
    dp[0][0] = 1;

    for(int i=0; i<h; i++)
    {
        string s;
        cin >> s;

        for(int j=0; j<w; j++)
        {
            if(i == 0 and j == 0)
                continue;

            if(s[j] == '.')
            {
                if(i > 0)
                {
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= mod;
                }

                if(j > 0)
                {
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
            }
            else
                dp[i][j] = 0;

        }

    }

    cout<< dp[h-1][w-1] <<"\n";

    return 0;
}
