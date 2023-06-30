
/// ===> MEMOIZATION METHOD

#include <bits/stdc++.h>
using namespace std;

const int N = 3005;
int dp[N][N];

string LCS(string s, string t)
{
    int n = s.size();
    int m = t.size();

    /// base case
    for(int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for(int j = 0; j <= m; j++)
        dp[0][j] = 0;

    /// calculate the result from the smaller sub-problem
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    string ans = "";
    int i = n, j = m;
    while(i > 0 && j > 0)
    {
        if(s[i-1] == t[j-1])
        {
            ans += s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string s, t;
    cin >> s >> t;

    memset(dp, -1, sizeof(dp));

    string ans = LCS(s, t);

    cout << ans << "\n";

    return 0;
}

