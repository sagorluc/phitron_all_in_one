#include<bits/stdc++.h>
using namespace std;

vector<string> merge_sort(vector<string> s)
{
    // corner case
    if(s.size() == 0)
        return s;
    if(s.size() == 1)
        return s;

    int mid = s.size() / 2;

    vector<string> a;
    vector<string> b;

    for(int i=0; i<mid; i++)
        a.push_back(s[i]);

    for(int i=mid; i<s.size(); i++)
        b.push_back(s[i]);

    vector<string> sorted_a = merge_sort(a);
    vector<string> sorted_b = merge_sort(b);

    vector<string> sorted_all;

    int idx_1 = 0;
    int idx_2 = 0;

    for(int i=0; i<s.size(); i++)
    {
        if(idx_1 == sorted_a.size())
        {
            sorted_all.push_back(sorted_b[idx_2]);
            idx_2++;
        }
        else if(idx_2 == sorted_b.size())
        {
            sorted_all.push_back(sorted_a[idx_1]);
            idx_1++;
        }
        else if(sorted_a[idx_1] < sorted_b[idx_2])
        {
            sorted_all.push_back(sorted_a[idx_1]);
            idx_1++;
        }
        else
        {
            sorted_all.push_back(sorted_b[idx_2]);
            idx_2++;
        }

    }

    return sorted_all;



}
int main()
{
    int n;
    cin >> n;

    vector<string> s(n);

    for(int i=0; i<n; i++)
        cin >> s[i];

    vector<string> ans = merge_sort(s);

    for(int i=0; i<ans.size(); i++)
        cout<< ans[i] << " ";




    return 0;
}


//#include<bits/stdc++.h>
//using namespace std;
//
//// time complexity of merge sort - O(nlogn).
//
//vector<string> merge_sort(vector<string>a)
//{
//    //base case
//    if(a.size() == 0)
//        return a;
//    if(a.size() == 1)
//        return a;
//
//    //array ke divide kora holo
//    int mid = a.size()/2;
//
//    //array er divide tow part declare kora holo
//    vector<string>b;
//    vector<string>c;
//
//    for(int i=0; i<mid; i++)
//        b.push_back(a[i]);
//
//    for(int i=mid; i<a.size(); i++)
//        c.push_back(a[i]);
//
//    //tow chilled ke coll kora holo recursivly call kora holo
//    vector<string> sorted_b = merge_sort(b);
//    vector<string> sorted_c = merge_sort(c);
//
//    // array a[] ke conquer/merge korte hobe
//
//    vector<string> sorted_a;
//    int index1 = 0;
//    int index2 = 0;
//
//    int sz = a.size();
//
//    for(int i=0; i<sz; i++)
//    {
//        //index1 ses hole index2 theke nebe
//        if(index1 == sorted_b.size())
//        {
//            sorted_a.push_back(sorted_c[index2]);
//            index2++;
//        }
//        //index2 ses hole index1 theke nebe
//        else if(index2 == sorted_c.size())
//        {
//            sorted_a.push_back(sorted_b[index1]);
//            index1++;
//        }
//        //sorted_b index1 choto hole sorted_b index1 er value sorted_a te joma korte
//        //and index1++ ek kore barbe.
//        else if(sorted_b[index1] < sorted_c[index2])
//        {
//            sorted_a.push_back(sorted_b[index1]);
//            index1++;
//        }
//        //sorted_c index2 boro hole sorted_a te joma korbe and index2++
//        // ek kore barbe.
//        else
//        {
//            sorted_a.push_back(sorted_c[index2]);
//            index2++;
//        }
//    }
//    return sorted_a;
//
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<string>a(n);
//
//    for(int i=0; i<n; i++)
//        cin >> a[i];
//
//
//    vector<string> ans = merge_sort(a);
//
//    for(int i=0; i<ans.size(); i++)
//        cout<<ans[i]<<" ";
//
//    return 0;
//}

