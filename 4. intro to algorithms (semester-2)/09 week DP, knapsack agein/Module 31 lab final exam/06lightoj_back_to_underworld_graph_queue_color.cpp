#include<bits/stdc++.h>

using namespace std;

#define NOT_VISITED 0
#define BLACK 1
#define RED 2
const int N = 20005;
list<int> adj[N];
int color[N];



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc,n,t=0;


    cin >> tc;

    while(tc--)
    {
        cin >> n;

        memset(color, 0, sizeof color);

        for(int i = 0; i < N; i++)
            adj[i].clear();

        for(int i = 0; i < n; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;

        for(int i = 0; i < N    ; i++)
        {
            if(!adj[i].empty() && color[i] == NOT_VISITED)
            {
                int black = 0, red = 0;
                queue<int> q;
                q.push(i);
                color[i] = BLACK;
                black++;

                while(!q.empty())
                {
                    int node = q.front();
                    q.pop();

                    for(list<int>::iterator it = adj[node].begin(); it != adj[node].end(); it++)
                    {
                        if(color[*it] == NOT_VISITED)
                        {
                            q.push(*it);
                            if(color[node] == BLACK)
                            {
                                color[*it] = RED;
                                red++;
                            }
                            else
                            {
                                color[*it] = BLACK;
                                black++;
                            }
                        }
                    }
                }
                ans += max(red, black);
            }
        }

        cout<< "Case "<< ++t <<": "<<ans<<"\n";
    }

    return 0;
}
