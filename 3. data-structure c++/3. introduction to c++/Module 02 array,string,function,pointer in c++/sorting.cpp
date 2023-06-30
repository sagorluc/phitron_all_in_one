#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a = {2,5,3,1,4};

    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i]<<endl;

    }
    cout<<"bfore sorting"<<endl;
    sort(a.begin(),a.end());
    cout<<"after sorting"<<endl;

    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i]<<endl;

    }



    return 0;
}
