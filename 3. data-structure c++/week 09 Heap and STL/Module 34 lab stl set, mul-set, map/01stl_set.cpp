#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> st;

    // n = number of element currently in set.
    // time complexity- O(lon n)
    st.insert(5);
    st.insert(3);
    st.insert(4);
    st.insert(7);
    st.insert(3);
    st.insert(4);

    // time complexity- O(n)
    cout<<"printing set :"<<"\n";
    for(auto i : st)
        cout<<i<<" ";
    cout<<"\n";

    // time complexity- O(1)
    cout<<"set size : "<<"\n";
    cout<<"total distenct : "<<st.size()<<"\n";

    // time complexity- O(n)
    cout<<"second method to print : "<<"\n";
    for(auto it = st.begin(); it != st.end(); it++)
        cout<< *it <<" ";
    cout<<"\n";

    // n = number of element currently in set.
    // time complexity- O(log n)
    st.erase(5);
    // time complexity- O(n)
    cout<<"printing set after erase element of 5 :"<<"\n";
    for(auto i : st)
        cout<<i<<" ";
    cout<<"\n";


    // n = number of element currently in set.
    // time complexity- O(log n)
    st.erase(4);
    // time complexity- O(n)
    cout<<"printing set after erase element of 4 :"<<"\n";
    for(auto i : st)
        cout<<i<<" ";
    cout<<"\n";

    // find element O(log n)
    cout<<"finding element in set : "<<"\n";
    if(st.find(7) != st.end())
        cout<<"7 found"<<"\n";
    else
        cout<<"not found"<<"\n";




    return 0;
}
