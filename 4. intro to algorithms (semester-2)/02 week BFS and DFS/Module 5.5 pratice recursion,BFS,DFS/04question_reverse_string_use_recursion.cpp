#include<bits/stdc++.h>
using namespace std;
int n;
void Reverse(string str)
{
    // base case
    if(str == "" || str.size() == 1)
        return;

    if(str.size() == n)
        cout<< str[n-1];

    Reverse(str.substr(1));

    cout<< str[0];
}
int main()
{
    string str;
    cin >> str;

    n = str.size();

    Reverse(str);

    return 0;
}
