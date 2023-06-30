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
/// time complexity- O(n*m)
/// space complexity- O(n*m)

const int N = 3003;
int dp[N][N];
string s,t;
int n,m;

int LCM(int i, int j) /// two cursor or pointer i,j
{
    /// base case
    if(i == n or j == m)
        return 0;

    /// check if the result already exists
    if(dp[i][j] != -1)
        return dp[i][j];

    /// calculate the result from smaller sub-problem
    if(s[i] == t[j])
        return 1 + LCM(i+1, j+1);
    else
        return max(LCM(i+1,j), LCM(i,j+1));

}

int main()
{
    cin >> s >> t;

    n = s.size();
    m = t.size();

    for(int i=0; i<=n; i++)
        for(int j=0; j<=m; j++)
            dp[i][j] = -1;

    cout<< LCM(0,0)<<endl;


    return 0;
}

/**
input:
axyb
abyxb

output:
ayb -> 3

input:
ayc
aby

output:
ay -> 2

*/
