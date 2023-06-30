#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a = {5,7,8,9,6,5};

    for(int i=0; i<10; i++)
    {
        cout<<"before size"<<a.size()<<"\n";
        a.push_back(i);
        cout<<"after size"<<a.size()<<"\n";
    }

    a.insert(a.begin()+4,12);

      for(int i=0; i<10; i++)
        cout<<a[i]<<endl;


    return 0;
}
