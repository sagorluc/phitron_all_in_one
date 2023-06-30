#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;

    int a[n];

    for(int i=0; i<n; i++)
        cin >> a[i];

    map<int,int> m;

    int first_duplicate = -1;

    for(int i=0; i<n; i++)
    {
        if(m.find(a[i]) == m.end())
            m[a[i]] = i;
        else
        {
            first_duplicate = a[i];
            break;
        }

    }

    if(first_duplicate == -1)
        cout<< "there is no duplicate number in array\n";
    else
        cout<<"First duplicate element is "<<first_duplicate<<", first occurring at index "<<m[first_duplicate]<<".\n";







    return 0;
}
