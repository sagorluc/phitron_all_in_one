#include<bits/stdc++.h>
using namespace std;

vector<int> merge_sort(vector<int> a)
{
    // base case
    if( a.size() <= 1)
        return a;

    // divided part
    vector<int> left;
    vector<int> right;

    int mid = a.size() / 2;

    for(int i=0; i<mid; i++)
        left.push_back(a[i]);

    for(int i=mid; i<a.size(); i++)
        right.push_back(a[i]);

    // recursivly call
    vector<int> left_sort = merge_sort(left);
    vector<int> right_sort = merge_sort(right);

    // conquer and index update
    vector<int> all_sort;
    int idx = 0;
    int idx1 = 0;

    for(int i=0; i<a.size(); i++)
    {
        // index chack and update..corner case.left side ses hole right side theke nibo and
        // right side er index update korbo and right side ses hole left side theke nebo.and
        // left side index update korbo.

        if( idx ==  left_sort.size())
        {
            all_sort.push_back(right_sort[idx1]);
            idx1++;
        }
        else if(idx1 == right_sort.size())
        {
            all_sort.push_back(left_sort[idx]);
            idx++;
        }
        // value merge and conqure.left side er value right side er value er choto hole
        // left side k push korbo and left side er index ke update korbe.
        // right side er value left side er value er choto hole
        // right side ke push korbo and right side er index ke update korbe.

        else if(left_sort[idx] < right_sort[idx1])
        {
            all_sort.push_back(left_sort[idx]);
            idx++;
        }
        else if(left_sort[idx] > right_sort[idx1])
        {
            all_sort.push_back(right_sort[idx1]);
            idx1++;
        }
    }



    return all_sort;




}
int main()
{
    int n;
    cin >> n;

    vector<int> a;
    a.resize(n);

    for(int i=0; i<n; i++)
        cin >> a[i];

    vector<int> res = merge_sort(a);

    for(int i=0; i<res.size(); i++)
        cout<< res[i] << " ";


    return 0;
}

/*

time complexity- O(nlogn)
space complexity- O(n)


*/
