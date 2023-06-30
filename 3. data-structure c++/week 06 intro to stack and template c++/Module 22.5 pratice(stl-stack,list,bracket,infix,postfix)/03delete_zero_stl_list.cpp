#include<bits/stdc++.h>
using namespace std;
// this code is got some problem.
// answering problem
void deleteZero(list<int> &l, int value)
{
    if(value == 0)
    {
        l.remove(0);
        return;
    }

    auto it = l.begin();

    int update = 0;
    while(it != l.end())
    {
        if(*it == 0)
            update++;
        else
            break;

    }
    if(update > value)
       it = l.erase(it);
    else
        it++;

}

int main()
{
    int n;
    cin >> n;

    list<int> l;
    for(int i=0; i<n; i++)
    {
        int in;
        cin >> in;
        l.push_back(in);
    }
    int k;
    cin >> k;

    deleteZero(l,k);

    while(l.empty() == false)
    {
        cout<<l.back()<<" ";
        l.pop_back();
    }
    return 0;
}
