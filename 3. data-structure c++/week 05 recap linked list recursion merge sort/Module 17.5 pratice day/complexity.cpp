#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    for(int k=1; k<=n; k=k*2)
    {
        for(int i=1; i<=n; i++)
        {
            cout<<"k = "<<k<<" "<<"i = "<<i<<"\n";
        }
    }


    return 0;
}
/*

k = 1
i = 1 2 3 ...n
k = 2
i = 1 2 3 ...n
k = 4
i = 1 2 3 ...n

k = logbase2n
i = O(n)
time complexity- O(n)

*/
