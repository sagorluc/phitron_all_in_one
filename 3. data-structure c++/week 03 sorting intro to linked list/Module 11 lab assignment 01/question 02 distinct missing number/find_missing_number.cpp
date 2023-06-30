#include<bits/stdc++.h>
using namespace std;

int FindMissingNumber(vector<int>a)
{
    int frist,second,total;

    frist  = a.size()+1;
    second = a.size()+2;
    total = (frist * second)/2;
    for (int i = 0; i < a.size(); i++)
    total = total - a[i];

    return total;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a;

    for(int i=1; i<n; i++)
    {
        int input;
        cin >> input;
        a.push_back(input);
    }

    int miss =  FindMissingNumber(a);
    cout<<miss<<"\n";



    return 0;
}
