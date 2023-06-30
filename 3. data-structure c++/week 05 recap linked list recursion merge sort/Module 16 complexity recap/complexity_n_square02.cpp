#include<bits/stdc++.h>
using namespace std;
int main()
{


    for(int i=0; i<n; i++) // time complexity- O(n * n-i = n^2)
    {
       for(int j = i; j < n; j++) // time complexity- O(n-i)
       {
            cout<< i << " " << j << " ";
       }
    }


    return 0;
}

/*
i = 0
j = n time
i = 1
j = n-1 time
i = 3
j = n-2 time
..
..
i = n-1
j = 1

1 + 2 + 3 + .... + n

time complexity- O(n^2)
space complexity- O(1)

*/

