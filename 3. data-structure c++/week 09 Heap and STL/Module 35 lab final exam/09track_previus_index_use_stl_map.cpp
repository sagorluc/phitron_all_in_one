#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> mp;

    string s;

    for(int i=0; i<n; i++)
    {
        cin >> s;

        if(mp.count(s) == 0)
            cout<<"-1"<<"\n";
        else
            cout<<mp[s]<<"\n";

        mp[s] = i;
    }

    return 0;
}
