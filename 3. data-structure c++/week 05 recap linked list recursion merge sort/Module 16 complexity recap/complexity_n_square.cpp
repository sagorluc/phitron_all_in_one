#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; // constant.time complexity- O(1)
    cin >> n; // constant. time complexity- O(1)

    //vector<int> v; // constant.time complexity- O(1)
    vector<int> v(n * n); // vector resize(n). time complexity O(n^2). space complexity- O(n^2)

    for(int i=0; i<n * n; i++) // loop n time choltece. time complexity- O(n^2)
        cin >> v[i];

//    for(int i=0; i<n; i++) // loop n time choltece. time complexity- O(n)
//    {
//        int in;
//        cin >> in;
//        v.push_back(in);
//    }

    int sum = 0; // time complexity- O(1)
    for(int i=0; i<n * n; i++) // loop n time cholce. time comeplexity- O(n^2)
    {
        sum = sum + v[i]; // sum operation cholce. time complecxity- O(1)
    }

    cout<< sum << " "; // time complexity- O(1)

    return 0;
}
/*

-> n^2 + n^2 + n^2 = 3n^2
-> cencle constant 3
time complexity- O(n^2)

space complexity- O(n^2)



*/

