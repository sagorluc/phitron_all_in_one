#include<bits/stdc++.h>
using namespace std;
/*

problem to solve regular bracket sequence

-> {[()()]{}} = valid.

-> ((()[]{}) = Invalid.

*/
int main()
{
    string st;
    cin >> st;

    stack<char> s;

    for(int i=0; i<st.size(); i++)
    {
        int now = st[i];

        if(now == '(' || now == '{' || now == '[') // opening bracker push kora holo.
                s.push(now);
        else
        {
            // corner case
            if(s.empty())
            {
                cout<<"Invalid braket.\n";
                return 0;
            }

            if(now == ')' && s.top() == '(') // closeing bracket and top er opening bracket match hole remove hobe.
                s.pop();

            else if(now == '}' && s.top() == '{') // closeing bracket and top er opening bracket match hole remove hobe.
                s.pop();

            else if(now == ']' && s.top() == '[') // closeing bracket and top er opening bracket match hole remove hobe.
                s.pop();

            else
            {
                cout<< "Invalid.\n";
                return 0;
            }
        }
    }

    if(s.empty()) // loop er matching remove sese jodi stack empty hoy tahole valid stack.
        cout<<"Valid.\n";
    else
        cout<<"Invalid.\n";

    return 0;
}
