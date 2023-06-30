#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> in_degree(N + 1, 0);

    vector<vector<int>> adj_list(N + 1);

    for (int i = 0; i < M; i++)
    {
        int x, y;
        cin >> x >> y;
        adj_list[x].push_back(y);
        in_degree[y]++;
    }

    vector<int> dp(N + 1, 0);
    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (in_degree[i] == 0)
        {
            dp[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj_list[u])
        {
            in_degree[v]--;
            dp[v] = (dp[v] + dp[u]) % MOD;
            if (in_degree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
