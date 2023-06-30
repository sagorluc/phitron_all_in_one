#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
const int M = 1e5+5;
int memo[N];
vector<int> parent_list[N];
int root, dist;

int mx_path(int dist)
{
    ///base case
    if(dist == root)
        return 0;

    /// check if the result already exists
    if(memo[dist] != -1)
        return memo[dist];

    int ans = 0;
    for(int parent : parent_list[dist])
    {
        int parent_dist = mx_path(parent);
        ans = max(ans, parent_dist);
    }
    ans++;

    memo[dist] = ans;
    return ans;

}
int main()
{
    int node, edge;
    cin >> node >> edge;

    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin >> u >> v;
        parent_list[v].push_back(u);

    }

    for(int i=1; i<=node; i++)
        memo[i] = -1;

    cin >> root >> dist;


    cout<< mx_path(dist)<<endl;


    return 0;
}
