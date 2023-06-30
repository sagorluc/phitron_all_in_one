#include<bits/stdc++.h>
using namespace std;
int main()
{
    //normal data types declaretion
    int a;
    float b;
    double c;

    vector data types declaretion
    vector<int>a;
    vector<float>b;
    vector<double>c;

    for(int i=0; i<10; i++)
    {
        cout<<"before push "<<a.size()<<endl;
        a.push_back(i);
        cout<<"after push "<<a.size()<<endl<<endl;

    }

    //a.insert(a.begin()+a.size()-1,102);
    a.insert(a.begin()+2,54);


    for(int i=0; i<10; i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<endl;

    a.erase(a.begin()+2);
    cout<<"after delete"<<endl;


    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i]<<endl;
    }

    vector<int>a = {1,2,3,4,5,6,7,8,9,10};
    a.resize(7);
    for(int i=0; i<a.size(); i++)
    {
        cout<<a[i]<<endl;

    }

    return 0;
}
