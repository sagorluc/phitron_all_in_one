#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>primes;
    vector<bool>visited(n+1);

    //time complexity- O(n*n/2) O(nlogn)
    //i = 2, n/2
    //i = 3, n/3
    //i = 4, 0 bcz 4 not prime.eitar time e loop chole nai
    //i = 5, n/5
    //i = 6, 0 bcz 6 not prime.eitar time e loop chole nai
    // n/2 + n/3 + n/4 + n/5 + n/6...
    // O(nlogn)
    for(int i=2; i<n; i++)
    {
        if(visited[i]==false)
        {
            primes.push_back(i);
            for(int x=2; i*x<=n; x++)
            {
                visited[i*x]=true;
            }
        }
    }
    cout<<"total size  = "<<primes.size()<<"\n";
    for(int i=0; i<primes.size(); i++)
        cout<<primes[i]<<" ";


    return 0;
}
