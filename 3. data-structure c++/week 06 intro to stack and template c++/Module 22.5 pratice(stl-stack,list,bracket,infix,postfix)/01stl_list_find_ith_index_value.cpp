#include<bits/stdc++.h>
using namespace std;
int getValue(list<int> l,int index)
{
   // corner case
   if(l.size() <= index)
        return -1;
   else
   {
       auto it = l.begin();
       advance(it, index);
       return *it;
   }

}
int main()
{
    int n, k;
    cin >> n;

    list<int> l;

    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;

        l.push_back(x);
    }

    cin >> k;

    int res = getValue(l,k);

    cout<<res;

    return 0;
}
