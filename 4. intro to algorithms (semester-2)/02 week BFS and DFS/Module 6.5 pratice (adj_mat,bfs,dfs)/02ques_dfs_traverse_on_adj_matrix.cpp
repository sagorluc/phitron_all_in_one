#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 100;

int n;
int adj[MAXN][MAXN];
bool visited[MAXN];

//using recursion
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    memset(adj, 0, sizeof(adj)); // set 0 in array
    memset(visited, false, sizeof(visited)); // set 0 in array

    // number of node
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }

    dfs(0);

    return 0;
}
