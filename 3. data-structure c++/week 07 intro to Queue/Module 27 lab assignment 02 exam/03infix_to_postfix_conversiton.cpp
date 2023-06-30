#include<bits/stdc++.h>
using namespace std;

int prec(char ch)
{

    if (ch == '/' || ch == '*')
        return 1;
    else if (ch == '+' || ch == '-')
        return 0;
    else
        return -1;
}

int main()
{
    string s;
    cin >> s;

    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        char now = s[i];

        // If the current character is an operand, add it to our answer string.
        if ((now >= 'a' && now <= 'z') || (now >= 'A' && now <= 'Z') || (now >= '0' && now <= '9'))
            ans += now;   // Append the current character of string in our answer

        // If the current character of string is an '(', push it to the stack.
        else if (now == '(')
            st.push('(');

        // If the current character of string is an ')', append the top character of stack in our answer string
        // and pop that top character from the stack until an '(' is encountered.
        else if (now == ')')
        {
            while (st.top() != '(')
            {
                ans += st.top();    // Append the top character of stack in our answer
                st.pop();
            }
            st.pop();
        }

        //If an operator is scanned
        else
        {
            while (!st.empty() && prec(s[i]) <= prec(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(now);             // Push the current character of string in stack
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    cout << ans;
    return 0;
}
