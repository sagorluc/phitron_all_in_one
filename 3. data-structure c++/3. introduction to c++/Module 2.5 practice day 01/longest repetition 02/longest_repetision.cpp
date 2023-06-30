#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin>>s;

//    sort(s.begin(),s.end());

    long long int cnt = 1, maxx = 0;

    for(long long int i=1; i<s.size(); i++)
    {



        if(s[i] == s[i-1])
        {
            cnt++;
        }

        else
        {
            if(cnt > maxx)
            {
                maxx = cnt;
            }
            cnt = 1;
        }
    }
    if(cnt > maxx)
    {
        maxx = cnt;
    }

    printf("%d\n",maxx);
    return 0;

}

