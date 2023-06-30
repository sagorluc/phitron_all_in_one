#include <bits/stdc++.h>
using namespace std;

int rec_max(int a[], int n)
{
    if (n == 1)
        return a[0];

    return max(a[n-1], rec_max(a, n-1));
}

int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    int res = rec_max(a,n);

    cout <<  res;

    return 0;
}
