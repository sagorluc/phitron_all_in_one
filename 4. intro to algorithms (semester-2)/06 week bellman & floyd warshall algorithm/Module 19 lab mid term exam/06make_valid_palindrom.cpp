#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    unordered_map<char, int> mp;

    for(auto ch : s)
        mp[ch]++;

    int oddcnt = 0;

    for(auto odd : mp)
    {
        if(odd.second % 2 != 0)
            oddcnt++;

    }

    if(oddcnt <= 1)
        cout<< "YES\n";
    else
        cout<< "NO\n";

    return 0;


}
