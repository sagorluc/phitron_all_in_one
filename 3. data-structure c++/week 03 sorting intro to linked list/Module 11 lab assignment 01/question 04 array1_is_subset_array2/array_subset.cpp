#include <bits/stdc++.h>
using namespace std;

int SubSetArray(int a[], int b[], int m, int n)
{
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i] == b[j])
            {
                flag = 1;
                break;
            }
            else
                flag = 0;
        }
    }
    if(flag == 1)
        return 1;
    else
        return 0;

}

int main()
{
    int n,m;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    cin >> m;

    int b[m];

    for(int i=0; i<m; i++)
        cin >> b[i];

   int x = sizeof(a) / sizeof(a[0]);
   int y = sizeof(b) / sizeof(b[0]);

   int res = SubSetArray(a, b, x, y);

    if (res == 1)
        cout<<"YES\n";
    else
        cout<<"NO\n";

    return 0;
}
