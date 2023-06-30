#include<bits/stdc++.h>
using namespace std;
bool Search(list<int> l,int value)
{
    auto fnd = find(l.begin(), l.end(), value);

    if(fnd != l.end())
        return 1;
    else
        return 0;

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
        l.push_front(in);

    }
        int k;
        cin >> k;

    int ans = Search(l,k);

    if(ans == 1)
        cout<<"true\n";
    else
        cout<<"false\n";


    return 0;
}
