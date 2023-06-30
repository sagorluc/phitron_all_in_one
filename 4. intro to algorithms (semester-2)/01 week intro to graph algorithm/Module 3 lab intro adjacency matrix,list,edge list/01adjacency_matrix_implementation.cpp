#include<bits/stdc++.h>
using namespace std;
/*

-> adjacency matrix

        -> undirected.
        -> unweighted.
    --------------------

       A---B
          / \
         C---D

    -> converting to alphabet to integer.
    -> A-> 0
    -> B-> 1
    -> C-> 2
    -> D-> 3

       0---1
          / \
         2---3

    -> 0-> 1
    -> 1-> 0
    -> 1-> 2
    -> 1-> 3
    -> 2-> 1
    -> 2-> 3
    -> 3-> 1
    -> 3-> 2


    -> undirected.
    -> weighted.
--------------------

         2
       0----1
        5  / \ 6
          2---3
            4

    -> 0-> 1
    -> 1-> 0
    -> 1-> 2
    -> 1-> 3
    -> 2-> 1
    -> 2-> 3
    -> 3-> 1
    -> 3-> 2

    mat[0][1] = 2;
    mat[1][0] = 2;
    mat[1][2] = 5;
    mat[1][3] = 6;


    -> directed.
    -> weighted.
---------------------
         2
       0--->1
           ^ ^
        5 /   \ 6
         2 <-- 3
            4

    -> 0-> 1
    -> 2-> 1
    -> 3-> 1
    -> 3-> 2

    mat[0][1] = 2;
    mat[2][1] = 5;
    mat[3][1] = 6;
    mat[3][2] = 4;

->  matrix-> (# of nodes * # of nodes)
->             nodes = 4*4
->  matrix[nodes][nodes]

-> matrix[nodes][nodes] = 0
-> matrix[nodes][nodes] = 1
            if and only if( i-->j )



*/
// time complexity- O(n^2)
// space complexity- O(n^2)

int main()
{
    int node = 4;

    int mat[node][node];// time complexity- O(n^2).

    for(int i=0; i<node; i++) // time complexity- O(n^2)
        for(int j=0; j<node; j++)
            mat[i][j] = 0;

    mat[0][1] = 1;
    mat[1][0] = 1;

    mat[1][2] = 1;
    mat[1][3] = 1;

    mat[2][1] = 1;
    mat[2][3] = 1;

    mat[3][1] = 1;
    mat[3][2] = 1;

    for(int i=0; i<node; i++) // time complexity- O(n^2)
    {
        for(int j=0; j<node; j++)
        {
            cout<< mat[i][j] << " ";
        }
        cout<< "\n";
    }

    return 0;
}
