#include<bits/stdc++.h>
using namespace std;
/*
->time complexity =
->memory complexity =

fibonacci serise
f[0] = 0
f[1] = f[0] + f[1] = 0+1 = 1
f[2] = f[1] + f[2] = 1+1 = 2
f[3] = f[2] + f[3] = 2+1 = 3
f[4] = f[3] + f[4] = 3+1 = 4

*/
int called;
int fib(int n)
{

    if(n==0)
        return 0;
    if(n==1)
        return 1;
    //fib(n-1)+fib(n-2)
    int x = fib(n-1);
    called++;
    int y = fib(n-2);
    called++;
    return x+y;

}
int main()
{
    int n;
    cin>>n;

    cout<<"fib = "<<fib(n)<<"\n";
    cout<<"called = "<<called<<"\n";


    return 0;
}
