#include<bits/stdc++.h>
using namespace std;
/*

    undirected
    weighted
--------------------

         2
       0----1
        5 /   \ 6
         2 --- 3
            4

    [
        [0-> 1, 2]
        [1-> 2, 5]
        [1-> 3, 6]
        [2-> 3, 4]

    ]

*/
int main()
{
    int nodes = 4;

    vector<vector<int> > edge_list;
//    {
//        {0,1, 2},
//        {1,2, 5},
//        {1,3, 6},
//        {2,3, 4}
//
//    };

    edge_list.push_back({0,1, 2});
    edge_list.push_back({1,2, 5});
    edge_list.push_back({1,3, 6});
    edge_list.push_back({2,3, 4});

    for(int i=0; i<edge_list.size(); i++)
        cout<< edge_list[i][0] <<" edge-> "<< edge_list[i][1]<<" weight->  "<< edge_list[i][2]<<"\n";


    return 0;
}

