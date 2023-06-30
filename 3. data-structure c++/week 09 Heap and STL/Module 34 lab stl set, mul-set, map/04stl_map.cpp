#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string, int> mp; // key and value.

    // time complexity- O(logn)
    mp["cow"] = 1;
    mp["goat"] = 2;
    mp["bird"] = 3;

    // print value of key.
    cout<<mp["cow"]<<"\n";

    cout<<mp["goat"]<<"\n";

    cout<<mp["bird"]<<"\n";

    mp["cat"] = 2;
    cout<<mp["cat"]<<"\n";

    mp["cat"] = 5;
    cout<<mp["cat"]<<"\n";

    // time complexity- O(n)
    for(auto it : mp)
        cout<<"key : "<<it.first<<" , "<<"value : "<<it.second<<"\n";

    cout<<"\n\n";

    // mep er key gula sort/distinct thake.value sort/distinct tahke nah.
    map<int, int> m;

    m[69] = 1;
    m[57] = 4;
    m[84] = 5;
    m[47] = 2;
    m[97] = 4;


    m[1000000] = 6;

    // time complexity- O(n)
    cout<<"print the map 2 : \n";
    for(auto it : m)
        cout<<"key : "<<it.first<<" , "<<"value : "<<it.second<<"\n";

    cout<<"\n\n";

    return 0;
}
