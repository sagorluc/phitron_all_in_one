#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int n, moves = 0;
   cin >> n;

   vector<long long int> a(n);

   for(long long int i=0; i<n; i++)
        cin >> a[i];

   for(long long int i=1; i<n; i++)
   {
       if(a[i] < a[i-1])
       {
           moves = moves + a[i-1] - a[i];
           a[i] = a[i-1];
       }
   }

   cout<<moves<<"\n";

    return 0;
}
