#include<bits/stdc++.h>
using namespace std;

/// time complexity-> O(n+m)
/// space complexity-> O(n)

/**
- state-> fun(n) -> longest distance from root to node n

- recurrence-> fun(n) -> max{(p_1),(p_2),...(p_m)} + 1.
                         where p_i is an immediate parent of node n

- base case-> fun(root) = 0

normally we do in graph node to child
node --- [child_1, child_2,.......]

for dynamic programing we will do child to parent
child ---[parent_1, parent_2,.....]

*/
const int N = 1e5 + 5;
vector<int> parent_list[N];
int dp[N];

int root, target_node;

int maxi_dist(int dist_node)
{
    /// handle base case
    if(dist_node == root)
        return 0;

    /// check if the result already exists
    if(dp[dist_node] != -1)
        return dp[dist_node];

    /// calculate the result from the smaller sub-problem
    int ans = 0;

    for(int parent : parent_list[dist_node])
    {
        int parent_dist = maxi_dist(parent);
        ans = max(ans, parent_dist);
    }
    ans++;
    dp[dist_node] = ans;
    return ans;


}

int main()
{
    int node,edge;
    cin >> node >> edge;

    for(int i=0; i<edge; i++)
    {
        int u,v; /// there exists an edge from u to v(u--> v)
        cin >> u >> v;

        parent_list[v].push_back(u);
    }

    for(int i=1; i<=node; i++)
        dp[i] = -1;

    cin >> root >> target_node;

    cout<< maxi_dist(target_node) << endl;

    return 0;
}
