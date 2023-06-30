#include<bits/stdc++.h>
using namespace std;

/**
states: LCM(i,j) -> length of longest common subsequence
                    between strings s[i..n] and t[j..m]

recurrence: LCM(i,j) -> 1 + LCM(i+1, j+1) if(s[i] == t[j])
                        else max(LCM(i+1,j), LCM(i,j+1))

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
        dp[i][m] = 0;

    for(int j=0; j<=m; j++)
        dp[n][j] = 0;

    /// loop over the sates
    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            /// calculate the result from smaller sub-problems
            if(s[i] == t[j])
                dp[i][j] = 1 + dp[i+1][j+1];
            else
               dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
        }
    }

    cout<< dp[0][0] <<endl;



    return 0;
}

/// time complexity- O(n*m)
/// space complexity- O(n*m)
