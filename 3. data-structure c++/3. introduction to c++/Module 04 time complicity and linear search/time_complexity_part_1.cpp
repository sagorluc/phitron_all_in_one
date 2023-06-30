#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;

    int maxx = max({a,b,c});
    int mini = min({a,b,c});

    int sum = a+b+c;
    int multi = a*b*c;

    cout<<maxx<<"\n";
    cout<<mini<<"\n";
    cout<<sum<<"\n";
    cout<<multi<<"\n";



    return 0;
}

/*
3 number

max
min
sum
multi

*/
