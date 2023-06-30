#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    stack<char> st;

    for(int i=0; i<s.size(); i++)
    {
        int now = s[i];

        if(now == '(' or now == '{' or now == '[')
            st.push(now);
        else
        {
            // corner case
            if(st.empty())
            {
                cout<<"No\n";
                return 0;
            }
            if(now == ')' && st.top() == '(')
                st.pop();
            else if(now == '}' && st.top() == '{')
                st.pop();
            else if(now = ']' && st.top() == '[')
                st.pop();
            else
            {
                cout<<"No\n";
                return 0;
            }

        }
    }

    if(st.empty())
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}
