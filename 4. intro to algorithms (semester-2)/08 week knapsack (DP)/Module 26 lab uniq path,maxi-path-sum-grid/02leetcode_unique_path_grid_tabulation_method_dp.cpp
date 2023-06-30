#include<bits/stdc++.h>
using namespace std;

/// time complexity-> O(n*m)
/// space complexity-> O(n*m)

/**
- state-> fun(n,m) -> number of unique paths from (0,0) to (n,m)
- recurrence-> fun(n,m) -> f(n-1,m) + f(n,m-1)
- base case -> f(0,0) = 1

*/


const int N = 101;
int dp[N][N];

int main()
{
    int row,col;
    cin >> row >> col;

    /// handle base case
    dp[0][0] = 1;

    /// loop over the states
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(i == 0 && j == 0)
                continue;

          int ans = 0;
          /// handle corner case
          if(i > 0)
           ans += dp[i-1][j];
          if(j > 0)
           ans += dp[i][j-1];

          dp[i][j] = ans;

        }
    }
    cout<< dp[row-1][col-1] <<endl;


    return 0;
}

