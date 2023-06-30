#include<bits/stdc++.h>
using namespace std;
int x = 5;
int y = 10;
int z = 11;

int fun(int a, int b)
{

    return a+b;

}
namespace info
{
    int x=6;
    int y=7;
    int z=8;

}

int main()
{
    int x=10;

    cout<<info::x<<endl;
    cout<<x<<endl;

    int a=4,b=5;
    x = fun(a,b);
    cout<<x<<endl;
    cout<<info::y<<endl;
    cout<<info::z<<endl;


    return 0;
}
