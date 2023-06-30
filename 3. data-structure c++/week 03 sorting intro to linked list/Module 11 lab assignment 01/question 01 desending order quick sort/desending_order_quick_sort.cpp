#include<bits/stdc++.h>
using namespace std;
vector<int> quick_sort(vector<int>(a))
{
    //base case
    if(a.size() == 0)
        return a;
    if(a.size() == 1)
        return a;

    //int pivot = a.size()-1;
    int pivot = rand() % a.size();

    vector<int> left_a;
    vector<int> right_b;

    //sorting left side and right side.
    for(int i=0; i<a.size(); i++)
    {
        if(i == pivot)
            continue;
        if(a[i] >= a[pivot])
        {
            left_a.push_back(a[i]);

        }
        else
        {
            right_b.push_back(a[i]);
        }
    }

    // recursivly coll
    vector<int> sorted_left = quick_sort(left_a);
    vector<int> sorted_right = quick_sort(right_b);

    //merge all arrays element and keep in this variable.
    vector<int> sorted_all;

    for(int i=0; i<sorted_left.size(); i++)
        sorted_all.push_back(sorted_left[i]);

    sorted_all.push_back(a[pivot]);

    for(int i=0; i<sorted_right.size(); i++)
        sorted_all.push_back(sorted_right[i]);

    return sorted_all;


}
int main()
{
    int n;
    cin >> n;
    vector<int>a;

    for(int i=0; i<n; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }


    vector<int> res = quick_sort(a);

    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";

    return 0;
}
