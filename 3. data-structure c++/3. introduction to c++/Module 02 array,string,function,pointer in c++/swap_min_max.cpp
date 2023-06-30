#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a = 5, b = 10;

    swap(a,b); //swaping the value.
    cout<<"a = "<<a<<endl<<"b = "<<b<<endl;

    cout<<endl;

    int mini = min(a,b);
    cout<<"minimum value is = "<<mini<<endl;

    cout<<endl;

    int maxi = max(a,b);
    cout<<"maximum value is = "<<maxi<<endl;
    cout<<endl;

    int c=2,d=5,e=15,f=7,g=19;
    int maxx = max({c,d,e,f,g});
    cout<<"maximum value is = "<<maxx<<endl;

    cout<<endl;

    int minii = min({c,d,e,f,g});
    cout<<"minimum value = "<<minii<<endl;



    return 0;
}
