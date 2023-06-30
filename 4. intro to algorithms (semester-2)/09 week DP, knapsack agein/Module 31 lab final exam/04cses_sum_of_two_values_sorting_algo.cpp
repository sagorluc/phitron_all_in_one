#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 2e5 + 5;
ll arr[N];

int main()
{
    int n,x;
    cin >> n >> x;

    map<int, int> mp;

    for(int i=1; i<=n; i++)
    {
        int num;
        cin >> num;
        int sub_res = x - num;

        if(mp.find(sub_res) != mp.end())
        {
            cout<< mp[sub_res] <<" "<< i <<"\n";
            return 0;
        }
        mp[num] = i;

    }

    cout<<"IMPOSSIBLE\n";

    return 0;
}
