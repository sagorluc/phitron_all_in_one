#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    stack<char> st;

    for(int i=0; i<s.size(); i++)
    {
        int cur = s[i];

        if( cur == '(' || cur == '{' || cur == '[')
            st.push(cur);
        else
        {
            // corner case
            if(st.empty())
            {
                cout<< "stack is empty.\n";
                return 0;
            }
            else if(cur == ')' && st.top() == '(')
                st.pop();

            else if(cur == '}' && st.top() == '{')
                st.pop();

            else if(cur == ']' && st.top() == '[')
                st.pop();
            else
            {
                cout<< "NO\n";
                return 0;
            }
        }
    }

    if(st.empty())
        cout<<"YES.\n";
    else
        cout<<"NO\n";

    return 0;
}
