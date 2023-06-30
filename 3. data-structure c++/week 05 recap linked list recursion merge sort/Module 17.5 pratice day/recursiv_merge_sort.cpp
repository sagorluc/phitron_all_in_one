#include<bits/stdc++.h>
using namespace std;

vector<int> merge_sort(vector<int>a)
{
    // base case
    if(a.size() <= 1)
        return a;

    vector<int>left;
    vector<int>right;

    int mid = a.size()/2;

    for(int i=0; i<mid; i++)
        left.push_back(a[i]);

    for(int i=mid; i<a.size(); i++)
        right.push_back(a[i]);

    vector<int> left_side_sort = merge_sort(left);
    vector<int> right_side_sort = merge_sort(right);

    // merge/conqure and corner case
    vector<int> conqure_tow_side;
    int idx1 = 0;
    int idx2 = 0;

    for(int i=0; i<a.size(); i++)
    {
        if(idx1 == left_side_sort.size())
        {
            conqure_tow_side.push_back(right_side_sort[idx2]);
            idx2++;
        }
        else if(idx2 == right_side_sort.size())
        {
            conqure_tow_side.push_back(left_side_sort[idx1]);
            idx1++;
        }
        else if(left_side_sort[idx1] < right_side_sort[idx2])
        {
            conqure_tow_side.push_back(left_side_sort[idx1]);
            idx1++;
        }
        else
        {
            conqure_tow_side.push_back(right_side_sort[idx2]);
            idx2++;
        }
    }

    return conqure_tow_side;



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
