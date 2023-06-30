#include<bits/stdc++.h>
using namespace std;
/*
6
1 4 6 2 8 7
2 4

output-> 1 8 7


*/
vector<int> RemoveElements(vector<int>c, int n, int a, int b)
{
    vector<int> r;

    for(int i=0; i<n; i++)
    {
        if(i <= a || i >= b)
        {
           r.push_back(c[i]);
        }

    }
    return r;


}
int main()
{
    int n,a,b;
    cin >> n;

    vector<int> c;

    for(int i=0; i<n; i++)
    {
        int in;
        cin >> in;
        c.push_back(in);

    }

    cin >> a >> b;

    int d = sizeof(c) / sizeof(c[0]);

    vector<int> res = RemoveElements(c,,a,b);

    for(int i=0; i<c.size(); i++)
        cout<< res[i] <<" ";





    return 0;
}
