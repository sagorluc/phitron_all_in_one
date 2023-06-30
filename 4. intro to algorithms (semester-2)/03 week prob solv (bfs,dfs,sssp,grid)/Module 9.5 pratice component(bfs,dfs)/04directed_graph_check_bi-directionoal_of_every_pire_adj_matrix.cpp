#include<bits/stdc++.h>
using namespace std;

const int mxN = 1002;
int adj_mat[mxN][mxN];
int n,m;

bool check_bi_diretionoal()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(adj_mat[i][j] == 1 && adj_mat[j][i] != 1)
                return false;
        }
    }
    return true;

}

int main()
{

    cin >> n >> m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> adj_mat[i][j];

    bool conn = check_bi_diretionoal();

    if(conn)
        cout<< "graph is bi-directional\n";
    else
        cout<<"graph is not bi-directional\n";


    return 0;
}
