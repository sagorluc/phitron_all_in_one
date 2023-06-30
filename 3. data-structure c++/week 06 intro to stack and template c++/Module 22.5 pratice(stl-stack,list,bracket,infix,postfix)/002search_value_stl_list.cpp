#include<bits/stdc++.h>
using namespace std;

bool searchValue(list<int>l, int value)
{
    auto it = l.begin();
    while(it != l.end())
    {
        if(*it == value)
            return true;
        else
            it++;
    }
    return false;
}

void PRINT(list<int>l)
{
    auto it = l.begin();
    while(it != l.end())
    {
        cout<< *it << " ";
        it++;
    }
    cout<<"\n";
}
int main()
{
    list<int> l;

    l.push_back(3);
    l.push_back(2);
    l.push_back(6);
    l.push_back(4);
    l.push_back(5);

    bool ans = searchValue(l,3);

    if(ans)
        cout<< "true\n";
    else
        cout<<"false\n";

    return 0;
}
