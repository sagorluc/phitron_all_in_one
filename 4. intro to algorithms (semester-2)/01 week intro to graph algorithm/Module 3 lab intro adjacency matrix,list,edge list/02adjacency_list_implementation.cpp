#include<bits/stdc++.h>
using namespace std;
/*

-> adjacency list--> use linked list and vector.

    undirected
    unweighted
----------------------

   A---B
      / \
     C---D

-> converting alphabet to integer.

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

-> adjacency list

    -> 0-> 1
    -> 1-> 0,2,3
    -> 2-> 1,3
    -> 3-> 1,2

    directed
    unweighted
--------------------

         2
       0--->1
           ^ ^
        5 /   \ 6
         2 <-- 3
            4

-> adjacency list

    -> 0-> 1
    -  1-> 0
    -> 2-> 1
    -> 3-> 2
    -> 3-> 1

    adj_list[0] = {1};
    adj_list[1] = {};
    adj_list[2] = {1};
    adj_list[3] = {1};

time complexity--> O(1) + O(n^2) + O(n^2) = O(n^2)
space complexity--> O(1) + O(n) + O(n^2) + O(1) = O(n^2)

*/
int main()
{
    int nodes = 4; // tm-> O(1) sp-> O(1)

    vector<int> adj_list[nodes]; //tm-> O(1) sp-> O(n)

    //time complexity- O(E*2) = O(E) wrost case-> O(n^2)
    // sp-> O(n^2)
    adj_list[0] = {1};
    adj_list[1] = {0,2,3};
    adj_list[2] = {1,3};
    adj_list[3] = {1,2};

    // time complexity- O(2*E) = O(E) = O(n^2)
    // sp-> O(1)
    for(int i=0; i<nodes; i++)
    {
        cout<< i <<" -> ";

        for(int j=0; j< adj_list[i].size(); j++)
        {
            cout<< adj_list[i][j] <<" ";
        }
        cout<<"\n";
    }

    return 0;
}
