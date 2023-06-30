#include<bits/stdc++.h>
using namespace std;

const int N = 101;
int dp[N][N];
string s;
string t;
int ans;
int sum(int i, int j)
{
    /// base case
    if(i == 0 or j == 0)
        return 0;
    /// check the result already exists
    if(dp[i][j] != -1)
        return dp[i][j];

    /// calculate the result from the smaller sub-problem
    if(s[i] == t[j])
        return sum(i+1, j+1) + 1;
    else
        return max(sum(i+1, j), sum(i,j+1));

}

int main()
{
    cin >> s;
    cin >> t;

    memset(dp, -1, sizeof(dp));

    int res = sum(0,0);

    cout<< res <<"\n";



    return 0;
}

//int LCS(int i,int j){
//    if(i<0 or j<0) return 0 ;
//    if(dp[i][j]!=-1) return dp[i][j];
//
//    if(st1[i]==st2[j])
//        dp[i][j] = LCS(i-1,j-1)+1;
//    else
//        dp[i][j] = max(LCS(i-1,j),LCS(i,j-1));
//
//    return dp[i][j];
//}
