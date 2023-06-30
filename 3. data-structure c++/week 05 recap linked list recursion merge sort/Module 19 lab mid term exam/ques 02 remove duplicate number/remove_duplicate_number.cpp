#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> v;
    v.resize(n);

    for(int i=0; i<n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int i,j,t = 0;

    for( i=0; i<n; i++)
    {

        for(j=0; j < t; j++)
        {
            if(v[i] == v[j])
                break;
        }
        if(j == t)
        {
            v[t] = v[i];
            t++;
        }

    }

    for(int i=0; i<t; i++)
        cout<<v[i]<<" ";




    return 0;
}
