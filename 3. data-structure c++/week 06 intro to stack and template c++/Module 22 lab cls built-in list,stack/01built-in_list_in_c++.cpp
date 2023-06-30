#include<bits/stdc++.h>
using namespace std;

// O(n)
void PRINT(list<int> l)
{
    //list<int>:: iterator a = l.begin();

    auto a = l.begin();

    while(a != l.end())
    {
        cout<< *a <<" ";
        a++;
    }
    cout<<"\n";
}

int main()
{
    list<int> l;

    // O(1)
    l.push_front(10);
    l.push_front(20);
    l.push_front(30);
    l.push_front(40);
    PRINT(l);

    // O(1)
    l.push_back(50);
    l.push_back(60);
    PRINT(l);

    // O(1)
    l.pop_back();
    PRINT(l);

    // O(1)
    l.pop_front();
    PRINT(l);


    return 0;
}
