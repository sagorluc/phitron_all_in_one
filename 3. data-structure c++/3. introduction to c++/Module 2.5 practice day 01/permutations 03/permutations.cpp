#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin >> n;

    if(n == 1)
    {
        cout<<"1\n";
        return 0;
    }
    if(n == 2 or n == 3)
    {
        cout<<"NO SOLUTION \n";
        return 0;
    }

    vector<long long int> even, odd;

    for(long long int i=1; i<=n; i++)
    {
        if(i % 2 == 0)
        {
            even.push_back(i);
        }
        else
        {
            odd.push_back(i);
        }
    }

    for(long long int i=0; i<even.size(); i++)
        cout<<even[i]<<" ";


    for(long long int i=0; i<odd.size(); i++)
        cout<<odd[i]<<" ";




    return 0;
}
