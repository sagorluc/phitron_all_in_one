#include<bits/stdc++.h>
using namespace std;

//int binarySearch(vector<int>a, int k)
//{

//    int low = 0;
//    int high = n-1;
//
//    int mid;
//
//    while(high >= low)
//    {
//        mid = (low + high)/2;
//
//        if(n > a[mid])
//        {
//            low = mid+1;
//        }
//        else
//        {
//            high = mid-1;
//        }
//
//    }

int occurrence(vector<int>a, int n, int k)
{
        int cnt = 0;
        for(int i=0; i<n-1; i++)
        {
            for(int j=i+1; j<n-1; j++)
            {
                if(a[i] == a[j])
                    cnt = cnt + 1;
            }


        }
        return cnt;

}



int main()
{
        int n,k;
        cin >> n;

        vector<int>a;

        for(int i=0; i<n; i++)
        {
            int input;
            cin >> input;
            a.push_back(input);
        }
        cin >> k;

        int ans = occurrence(a,n,k);

        if(ans)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";

        return 0;
}
