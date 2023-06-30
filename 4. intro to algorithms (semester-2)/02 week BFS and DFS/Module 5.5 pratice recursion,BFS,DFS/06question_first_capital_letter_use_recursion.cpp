#include<bits/stdc++.h>
using namespace std;

char getCapital(string str)
{
    // base case
    if(str.size() == 0)
        return '\0';

    else if(str[0] >= 'A' && str[0] <= 'Z')
        return str[0];
    else
        return getCapital(str.substr(1));

    }
int main()
{
    string str;
    cin >> str;

    cout<< getCapital(str) <<"\n";


    return 0;
}
