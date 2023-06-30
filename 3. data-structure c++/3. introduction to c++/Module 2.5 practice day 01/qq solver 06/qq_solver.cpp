#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int a = s[0] - '0'; // convert string to integer.
    int b = s[2] - '0'; // convert string to integer.

    int product = a * b;

    cout<<product<<"\n";

    return 0;
}
