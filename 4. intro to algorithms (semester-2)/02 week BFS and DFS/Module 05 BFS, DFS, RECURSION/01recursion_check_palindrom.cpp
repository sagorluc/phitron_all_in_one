#include<bits/stdc++.h>
using namespace std;
bool is_palindrom(string str)
{
    // for recursion always must be we have to check base case 1st.
    if(str == "" || str.size() == 1)
        return true;

    int n = str.size();

    string smallest_str = str.substr(1, n-2);

    return is_palindrom(smallest_str) && (str[0] == str.back());

}
int main()
{
    string str;
    cin >> str;

    if(is_palindrom(str))
        cout<< "Yes\n";
    else
        cout<< "No\n";


    return 0;
}
