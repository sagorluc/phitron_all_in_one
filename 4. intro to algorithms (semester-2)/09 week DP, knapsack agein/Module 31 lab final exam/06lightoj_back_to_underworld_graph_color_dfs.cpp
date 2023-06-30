#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+5;

vector<int> adj_list[N];
bool visited[N];
int color[N];

void dfs(int u, int c)
{
    visited[u] = true;
    color[u] = c;
    for (int v : adj_list[u])
    {
        if (!visited[v])
            dfs(v, 3 - c);
        else if (color[v] == c)
            color[v] = 3; /// invalid
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T,t=0;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;

        memset(visited, false, sizeof(visited));
        memset(color, 0, sizeof(color));

        for (int i = 1; i <= n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }


        for (int i = 1; i <=N-5; i++)
        {
            if (!visited[i] && !adj_list[i].empty())
                dfs(i, 1);
        }

        int vam = 0, lykans = 0, ans;
        for (int i = 1; i <= N-5; i++)
        {
            if (color[i] == 1)
                vam++;

            else if (color[i] == 2)
                lykans++;
        }
        ans = max(vam,lykans);
        cout << "Case " << ++t << ": " << ans << "\n";
    }
    return 0;
}
