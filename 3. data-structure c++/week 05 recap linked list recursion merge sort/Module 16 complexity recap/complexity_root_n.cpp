#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    for( int i=1; i*i<=n; i++) // i^2. time complexity- O(root n)
    {
        if(n % i == 0)
        {
            cout<< i <<"\n";
            cout<<  (n/i) << "\n";
        }
    }

    return 0;
}

/*
time complexity- O(root n)
space complexity- O(1)

*/
