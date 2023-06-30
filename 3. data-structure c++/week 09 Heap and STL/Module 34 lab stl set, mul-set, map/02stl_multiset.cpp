#include<bits/stdc++.h>
using namespace std;
int main()
{
    multiset<int> ml;

    // time complexity- O(log n)
    ml.insert(5);
    ml.insert(7);
    ml.insert(4);
    ml.insert(3);
    ml.insert(4);
    ml.insert(7);

    // time complexity- O(n)
    for(auto i : ml)
        cout<<i<<" ";
    cout<<"\n";

    // print size O(1)
    cout<<"total size of multiset is : "<<ml.size()<<"\n";

    // erase O(log n)
    ml.erase(4);
    // time complexity- O(n)
    cout<<"multiset after erasing 4"<<"\n";
    for(auto i : ml)
        cout<<i<<" ";
    cout<<"\n";

    // erase a single occurrence O(log n)
    cout<<"after erasing only single occurrence"<<"\n";
    ml.erase(ml.find(7));
    // time complexity- O(n)
    for(auto i : ml)
        cout<<i<<" ";
    cout<<"\n";

    // find element in multiset O(log n)
    cout<<"finding element in multiset : "<<"\n";
    if(ml.find(5) != ml.end())
        cout<<"5 found"<<"\n";
    else
        cout<<"not found"<<"\n";




    return 0;
}
