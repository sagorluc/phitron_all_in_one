#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x = 10;
    int* y = &x;

    cout<<x<<endl;  //it will show value of main x.
    cout<<*y<<endl; //it will show value of x =10.
    cout<<y<<endl;  //it will show address of x.

    x = 100;

    cout<<x<<endl;
    cout<<*y<<endl;
    cout<<y<<endl;


    return 0;
}
