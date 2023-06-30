#include<bits/stdc++.h>
using namespace std;

// unsolved problem
vector<int> coins ;

int Coin_change(int n)
{
   // base case
   if(n == 0)
        return 0;

   int ans = 100000000;
   for( int i = 0; i<coins.size(); i++)
   {
       if( n >= coins[i])
       {
           ans = min( ans, 1 + Coin_change(n-coins[i]));
       }
   }
   return ans;
}

int main()
{
    int n, target;
    cin >> n >> target;

    coins.resize(n);

    for(int i=0; i<n; i++)
        cin >> coins[i];

    cout<< Coin_change(n) << "\n";

    return 0;
}
