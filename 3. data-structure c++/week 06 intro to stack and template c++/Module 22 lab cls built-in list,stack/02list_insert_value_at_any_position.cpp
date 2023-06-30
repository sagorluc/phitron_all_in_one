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

 // insert value at any index. O(n)
void Insert_at_any_index(list<int> &l, int index, int value) // pass by refarencce
{
    auto it = l.begin();// declare iterator O(1)

    advance(it, index);// iterator and index/position.moving index by advance functon O(index)

    l.insert(it, value);// iterator and value O(1)

}

// delete value at any index O(n)
void delete_at_any_index(list<int> &l, int index) // pass by refarence
{
    auto it = l.begin(); // declare iterator and point to the list begin O(1)
    advance(it, index); // moving index by advance function O(indexx)

    l.erase(it); // remove the value from the list O(1)
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

    // insert value at any index
    Insert_at_any_index(l, 2, 65); // list, index, value
    PRINT(l);

    // delete value at any index
    delete_at_any_index(l, 3);
    PRINT(l);

    // size
    cout<<"the size of list-> "<<l.size()<<"\n";

    return 0;
}
