#include<bits/stdc++.h>
using namespace std;
/*
problem to solved (infix expression convert to postfix expression)

infix expression
-> a+b*c+d

convert to postfix expression

-> abc*+d+

*/


int precidence(char ch )
{
    if(ch == '+' || ch == '-')
        return 0;
    else if(ch == '*' || ch == '/')
        return 1;
}
int main()
{
    string s;

    cin >> s;

    stack<char> st;

    string ans = "";

    for(int i=0; i<s.size(); i++)
    {
        char now = s[i];

        // if now is operand.
        if(now >= 'a' && now <= 'z')
            ans = ans + now; // ans e now ke add korlam.operand gulo ans e store hobee.
        else
        {
            while(st.size() && precidence(st.top()) >= precidence(now)) // st.size() empty na hole and precidence er
                                                                        // st.top() now-precdence er boro or soman hole
            {
                ans = ans + st.top(); // st.top() ke ans add korbo.st top() er prce boro hoy now er prec er chaite.ans e operator sore hobe
                st.pop(); // st.pop() kore remove korbo loop the bahir houyer jonno
            }
            st.push(now); // while condition kaj na hole direct st te push hobe now.
        }
    }

    while(st.size()) // st.size() value thakle
    {
        ans = ans + st.top(); // st.top() ans add hobe
        st.pop(); // st.pop() remove hobe.
    }

    cout<< ans;

    return 0;
}
