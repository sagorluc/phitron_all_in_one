#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=0; i<n; i++) // time complexity- O(n)
    {
        cout<< i << "\n";
    }

    for(int i=0; i<n; i++) // time complexity- O(n)
    {
        for(int j=0; j<n; j++) // time complexity- O(n)
        {
            cout<< i << j << "\n";
        }
    }

    return 0;
}

/*

(n * n) + n + O(1) = n^2

time complexity- O(n^2)
space complexity- O(1)


*/
