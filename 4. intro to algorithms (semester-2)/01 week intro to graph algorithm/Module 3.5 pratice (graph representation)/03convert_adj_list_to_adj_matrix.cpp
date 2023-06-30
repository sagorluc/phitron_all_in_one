#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int nodes, edge;
    cin >> nodes >> edge;

    vector<int> adj_list[nodes+1];

    for(int i=1; i<=edge; i++)
    {
        int u, v;
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    int mat[nodes + 1][nodes + 1];

    //memset(mat, 0, sizeof(mat));

    for(int i=0; i<=nodes; i++)
        for(int j=0; j<=nodes; j++)
            mat[i][j] = 0;

    for(int i=0; i<=nodes; i++)
    {
        for(int j=0; j< adj_list[i].size(); j++)
        {
            mat[i][adj_list[i][j]] = 1;
            mat[adj_list[i][j]][i] = 1;
        }
    }

    for(int i=0; i<=nodes; i++)
    {
        for(int j=0; j<=nodes; j++)
            cout<< mat[i][j]<<" ";

        cout<< "\n";
    }

    return 0;
}













//int main()
//{
//    int n; // number of vertices
//    cin >> n;
//
//    vector<vector<int>> adj_list(n); // adjacency list
//
//    for (int i = 0; i < n; i++)
//    {
//        int m; // number of neighbors
//        cin >> m;
//
//        for (int j = 0; j < m; j++)
//        {
//            int neighbor;
//            cin >> neighbor;
//            adj_list[i].push_back(neighbor);
//        }
//    }
//
//    // create adjacency matrix
//    vector<vector<int>> adj_matrix(n, vector<int>(n, 0));
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < adj_list[i].size(); j++)
//        {
//            int neighbor = adj_list[i][j];
//            adj_matrix[i][neighbor] = 1;
//        }
//    }
//
//    // print adjacency matrix
//    for (auto row : adj_matrix)
//    {
//        for (auto val : row)
//        {
//            cout << val << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}

