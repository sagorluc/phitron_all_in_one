#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a;
    cout<<"before inserting"<<endl;
    for(int i=0; i<10; i++)
    {
        a.push_back(i);
        cout<<a[i]<<" ";
    }

    cout<<endl<<"after inserting"<<endl;
    a.insert(a.begin()+ 5,256);
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";

    cout<<endl<<"after eraseing"<<endl;
    a.erase(a.begin()+1);
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";

    cout<<endl<<"after delete last number"<<endl;
    a.pop_back();
    for(int i=0; i<10; i++)
        cout<<a[i]<<" ";

    return 0;
}
