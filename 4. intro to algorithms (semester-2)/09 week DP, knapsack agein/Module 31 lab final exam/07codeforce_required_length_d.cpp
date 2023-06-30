#include<bits/stdc++.h>

using namespace std;

int size_v(long long x)
{
    int cnt = 0;
    while (x > 0)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}

vector<long long> numbers(long long x)
{
    vector<long long> ans;

    while (x > 0)
    {
        if (x % 10 != 0)
            ans.push_back(x % 10);

        x /= 10;
    }
    return ans;
}

void bfs(long long src, int sz)
{
    queue<long long> q;

    set<long long> visited;

    int oper = 0;

    q.push(src);

    visited.insert(src);

    while (!q.empty())
    {
        int size = q.size();

        while (size-- > 0)
        {
            long long val = q.front();
            q.pop();

            vector<long long> nums = numbers(val);

            if (size_v(val) == sz)
            {
                cout << oper << "\n";
                return;
            }

            for (long long num : nums)
            {
                long long new_val = num * val;
                if (new_val > 0 && visited.find(new_val) ==
                    visited.end() && size_v(new_val) <= sz)
                {
                    visited.insert(new_val);
                    q.push(new_val);
                }
            }
        }
        oper++;
    }
    cout << -1 << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long x;
    int n;
    cin >> n >> x;
    bfs(x, n);

    return 0;
}
