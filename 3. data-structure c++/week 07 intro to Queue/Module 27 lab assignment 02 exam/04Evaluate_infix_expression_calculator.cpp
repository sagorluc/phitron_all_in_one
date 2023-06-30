#include<bits/stdc++.h>
using namespace std;

int precedende(char ch)
{
    if(ch == '+' || ch == '-')
        return 0;
    else if(ch == '*' || ch == '/')
        return 1;

    return -1;
}


int calculate_of_num(char ch, int a, int b)
{
    if(ch == '+')
    {
        return a + b;
    }
    else if(ch == '-')
    {
        return a - b ;
    }
    else if(ch == '*')
    {
        return a * b;
    }
    else if(ch == '/')
    {
        return a/b;
    }

    return -1;
}


int main()
{
    string s;
    cin >> s;

    int l = sizeof(s)/sizeof(string);
    stack<char> operand;
    stack<int> oper;

    int ans;
    int i = 0;
    while(s[i] != '\0')
    {
        if(s[i] == '(')
        {
            operand.push('(');
        }
        else if(s[i] == ')')
        {
            while(operand.top() != '(')
            {
                int v1 = oper.top();
                oper.pop();

                int v2 = oper.top();
                oper.pop();

                ans = calculate_of_num(operand.top(),v2,v1);
                oper.push(ans);
                operand.pop();
            }
            operand.pop();
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            while(!operand.empty() && precedende(operand.top()) >= precedende(s[i]))
            {
                int v1 = oper.top();
                oper.pop();

                int v2 = oper.top();
                oper.pop();

                ans = calculate_of_num(operand.top(),v2,v1);
                oper.push(ans);
                operand.pop();
            }
            operand.push(s[i]);
        }
        else
        {
            oper.push(int(s[i])- 48);
        }
        i++;
    }


    while(!operand.empty())
    {
        int v1 = oper.top();
        oper.pop();

        int v2 = oper.top();
        oper.pop();

        ans = calculate_of_num(operand.top(),v2,v1);
        oper.push(ans);
        operand.pop();
    }

    cout << oper.top();
    return 0;
}
