/*
--> x[3]
--> i<5
--> 5
--> 1 2 3 4 5
--> sum = 0
--> sum 0 + 1 = 1
--> sum 1 + 2 = 3
--> sum 3 + 3 = 6
--> sum 6 + 4 = 10
--> sum 10 + 5 = 15
--> 0 + 1 + 2 + 3 + 4 + 5 = 15

--> 3
--> 5 6 7
--> x = 1
--> x * 5 = 1 * 5 = 5
--> x * 6 = 5 * 6 = 30
--> x * 7 = 30 * 7 = 210
--> 1 * 5 * 6 * 7 = 210
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    //int x,x1,x2,x3,x4,x5,x6,x7,x8,x9,x10;
    int x[n];

    for(int i=0; i<n; i++)// input loop
    {
        cin >> x[i];
    }
    int sum = 0;
    for(int i=0; i<n; i++)// summation loop
    {
        sum = sum + x[i];
    }
    cout<<sum<<"\n";

    int y = 1;
    for(int i=0; i<n; i++)
    {
      y = y * x[i];
    }
    cout<<y<<endl;


    return 0;
}
