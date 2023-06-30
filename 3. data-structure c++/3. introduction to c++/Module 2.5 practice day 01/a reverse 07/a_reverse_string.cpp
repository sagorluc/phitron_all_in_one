#include<bits/stdc++.h>
using namespace std;
int main()
{
    int L,R;
    cin >> L >> R;

    string S;
    cin >> S;

    L--,R--; // 1 kore komano holo

    reverse(S.begin() + L, S.begin() + R + 1);

//    for(int i=L-1,j=R-1; i<j; i++,j--)
//    {
//            int tmp = S[i];
//            S[i] = S[j];
//            S[j] = tmp;
//
//    }

    cout<<S<<"\n";


    return 0;
}
