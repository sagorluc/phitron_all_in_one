#include<bits/stdc++.h>
using namespace std;
vector<int> quick_sort(vector<int>a)
{
    int pivot = rand() % (a.size());

    // corner case
    if(a.size() <= 1)
       return a ;

    vector<int> left_side;
    vector<int> right_side;

    for(int i=0; i<a.size(); i++)
    {
        if(i == pivot)
            continue;

        if(a[i] >= a[pivot])
            left_side.push_back(a[i]);
        else
            right_side.push_back(a[i]);

    }

    vector<int> sorted_left = quick_sort(left_side);
    vector<int> sorted_right = quick_sort(right_side);

    vector<int> merge_tow_side;

    for(int i=0; i<sorted_left.size(); i++)
        merge_tow_side.push_back(sorted_left[i]);

    merge_tow_side.push_back(a[pivot]);

    for(int i=0; i<sorted_right.size(); i++)
        merge_tow_side.push_back(sorted_right[i]);

    return merge_tow_side;
}
int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for(int i=0; i<n; i++)
        cin >> a[i];

    vector<int> res = quick_sort(a);

    for(int i=0; i<res.size(); i++)
        cout<< res[i] << " ";

    return 0;
}
