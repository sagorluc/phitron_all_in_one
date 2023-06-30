#include<bits/stdc++.h>
using namespace std;

const int N = 20005;
int visited[N];
int color[N];
vector<long long> adj_list[N];
int vam = 0, lykans = 0;

void clr()
{
    for(int i=0; i<N; i++)
        adj_list[i].clear();
}
void bfs(int src)
{
    queue<int> q;
    q.push(src);

    color[src] = 1;
    vam++;

    while(q.empty() == false)
    {
        int head = q.front();
        q.pop();

        for(int i=0; i<adj_list[head].size(); i++)
        {
            int child = adj_list[head][i];
            if(color[child] == 0)
                q.push(child);

            else if(color[head] == 1)
            {
                color[child] = 2;
                lykans++;
            }
            else
            {
                color[child] = 1;
                vam++;
            }
        }

    }
}
int main()
{
    int t,test = 0;
    cin >> t;

    while(t--)
    {
        clr();
        int n, ans = 0;
        cin >> n;

        for(int i=0; i<n; i++)
        {
            int u,v;
            cin >> u >> v;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }

        memset(color, 0, sizeof(color));

        for(int i=0; i<N; i++)
        {
            int vam = 0, lykans = 0;

            if(color[i] == 0 and adj_list[i].size() > 0)
                bfs(i);

            ans += max(vam, lykans);
        }
        cout<< "Case "<< ++test <<": "<<ans<<"\n";

    }


    return 0;
}
