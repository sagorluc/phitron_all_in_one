#include<bits/stdc++.h>
using namespace std;
int main()
{


    for(int i=0; i<n; i++) // time complexity- O(n * n^2 = n^3)
    {
       for(int j=0; j<n; j++) // time complexity- O(n*n = n^2)
       {
           for(int k=0; k<n; k++) // time complexity- O(n)
           {
               cout<< i << j << k <<"\n";
           }
       }
    }


    return 0;
}

/*

time complexity- O(n^3)
space complexity- O(1)

*
