#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
const int maxN = 1000;
bool visited[maxN];
int adj_matrix[maxN][maxN];
vector<int> parent(maxN);
int n;
void bfs(int s)
{
    queue<int> q;
    // cout << s << " ";
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (int child = 0; child <= n; child++)
        {
            if (adj_matrix[node][child] == 1 && !visited[child])
            {
                // cout << child << " ";
                q.push(child);
                visited[child] = true;
                parent[child] = node;
            }
        }
    }
}
void solve()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            cin >> adj_matrix[i][j];

    int src = 1, destination = 5;

    bfs(3);

    // cout << '\n';
    // for (int i = 0;i <= n;i++)
    //     cout << parent[i] << " ";
    // cout << '\n';

    int x = destination;

    vector<int> path;

    while (parent[x] != -1)
    {
        path.push_back(x);
        x = parent[x];
    }
    reverse(path.begin(), path.end());
    cout << src << " ";

    for (auto val : path)
        cout << val << " ";
    cout << '\n';
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    t = 1;
    //cin >> t;
    while (t--)
        solve();
    return 0;
}



