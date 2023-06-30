#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    deque<char> cd;

    for(int i=0; i<s.size(); i++)
        cd.push_back(s[i]);

    char x,y;
    int flag = 1;

    while(cd.size() > 1)
    {

        x = cd.front();
        y = cd.back();

        cd.pop_front();
        cd.pop_back();

        if( x != y )
            flag = 0;

    }

    if(flag == 1)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}
