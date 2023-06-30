#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; // constant.time complexity- O(1)
    cin >> n; // constant. time complexity- O(1)

    //vector<int> v; // constant.time complexity- O(1)
    vector<int> v(n); // vector resize(n). time complexity O(n). space complexity- O(n)

    for(int i=0; i<n; i++) // loop n time choltece. time complexity- O(n)
        cin >> v[i];

//    for(int i=0; i<n; i++) // loop n time choltece. time complexity- O(n)
//    {
//        int in;
//        cin >> in;
//        v.push_back(in);
//    }

    int sum = 0; // time complexity- O(1)
    for(int i=0; i<n; i++) // loop n time cholce. time comeplexity- O(n)
    {
        sum = sum + v[i]; // sum operation cholce. time complecxity- O(1)
    }

    cout<< sum << " "; // time complexity- O(1)

    return 0;
}
/*

-> n + n + n = 3n
-> cencle constant 3
time complexity- O(n)

space complexity- O(n)



*/
