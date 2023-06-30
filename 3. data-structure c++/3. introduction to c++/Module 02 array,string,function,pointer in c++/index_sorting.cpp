#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a = {2,5,3,1,4};

    cout<<"bfore sorting"<<endl;
    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i]<<" ";

    }
    cout<<endl;

    //sort(a.begin(),a.end());

    //sort from index 1 to index 3.
    sort(a.begin()+1,a.begin()+3+2);
    cout<<"after sorting"<<endl;

    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i]<<" ";

    }



    return 0;
}

