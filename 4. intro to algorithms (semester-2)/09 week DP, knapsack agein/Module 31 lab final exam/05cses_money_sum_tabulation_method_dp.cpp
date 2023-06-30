/// ===> TABULATION METHOD

#include<bits/stdc++.h>
using namespace std;

const int N = 1000001;

int main()
{
    int n;
    cin >> n;

    vector<int> coin(n);

    for(int i=0; i<n; i++)
        cin >> coin[i];

    vector<vector<bool>> dp(n+1, vector<bool>(N, false));
    /// base case
    dp[0][0] = true;

    /// loop over the states
    for(int i=1; i<= n; i++)
    {
        for(int j=0; j<=N-1; j++)
        {
            dp[i][j] = dp[i-1][j];

            if(j >= coin[i - 1])
                dp[i][j] = dp[i][j] or dp[i-1][j - coin[i-1]];
        }
    }

    int cnt = 0;

    for(int i=1; i<=N-1; i++)
    {
        if(dp[n][i])
            cnt++;
    }

    cout<< cnt <<"\n";

    for(int i=1; i<=N-1; i++)
    {
        if(dp[n][i])
            cout<< i <<" ";

    }
    cout<<"\n";

    return 0;
}
