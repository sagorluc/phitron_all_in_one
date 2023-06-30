#include<bits/stdc++.h>
using namespace std;
/*

-> adjacency list--> use linked list and vector.

    directed
    weighted
--------------------

         2
       0--->1
           ^ ^
        5 /   \ 6
         2 <-- 3
            4

-> adjacency list

    -> 0-> 1
    -> 1-> 0
    -> 2-> 1
    -> 3-> 2
    -> 3-> 1

    0-> (1, 2)
    1-> ()
    2-> (1, 5)
    3-> (2, 4), (1, 6)

time complexity--> O(1) + O(n^2) + O(n^2) = O(n^2)
space complexity--> O(1) + O(n) + O(n^2) + O(1) = O(n^2)

*/
int main()
{
    int nodes = 4; // tm-> O(1) sp-> O(1)

    vector<pair<int, int> > adj_list[nodes]; //tm-> O(1) sp-> O(n)

    // initialization system
    adj_list[0] = {{2,3}};
    adj_list[1] = {{}};
    adj_list[2] = {{1,5}};
    adj_list[3] = {{2,4}, {1,6}};

    // push_back in vector system
//    adj_list[0].push_back({1, 2});
//    adj_list[1].push_back({});
//    adj_list[2].push_back({1, 5});
//    adj_list[3].push_back({2, 4});
//    adj_list[3].push_back({1, 6});

    // time complexity- O(2*E) = O(E) = O(n^2)
    // sp-> O(1)
    for(int i=0; i<nodes; i++)
    {
        cout<< i <<" -> ";

        for(int j=0; j< adj_list[i].size(); j++)
        {
            cout<<"("<< adj_list[i][j].first <<", "<< adj_list[i][j].second<<"), ";
        }
        cout<<"\n";
    }

    return 0;
}

