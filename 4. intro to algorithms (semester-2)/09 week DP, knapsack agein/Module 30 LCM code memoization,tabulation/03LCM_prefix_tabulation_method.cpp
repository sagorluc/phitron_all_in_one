#include<bits/stdc++.h>
using namespace std;

/**
states: LCM(i,j) -> length of longest common subsequence
                    between strings s[i..n] and t[j..m]

recurrence: LCM(i,j) -> 1 + LCM(i-1, j-1) if(s[i-1] == t[j-1])
                        else max(LCM(i-1,j), LCM(i,j-1))

base case: LCM(i,m) = 0
           LCM(n,j) = 0

*/

const int N = 3003;
int dp[N][N];

int main()
{
    string s,t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    /// base case
    for(int i=0; i<=n; i++)
        dp[i][0] = 0;

    for(int j=0; j<=m; j++)
        dp[0][j] = 0;

    /// loop over the states
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            /// calculate the result from smaller sub-problems
            if(s[i-1] == t[j-1]) /// start form 0 index
              dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout<< dp[n][m] <<endl;


    return 0;
}
/// time complexity- O(n*m)
/// space complexity- O(n*m)
