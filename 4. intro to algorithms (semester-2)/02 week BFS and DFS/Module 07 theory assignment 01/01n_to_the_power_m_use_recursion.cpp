#include<bits/stdc++.h>
using namespace std;

typedef int i;

int Power(i a, i b)
{
    // base case
    if(b == 0)
        return 1;

    return a * Power(a,b-1);
}
int main()
{
    i n,m;
    cin >> n >> m;

    cout<< Power(n,m);

    return 0;
}
