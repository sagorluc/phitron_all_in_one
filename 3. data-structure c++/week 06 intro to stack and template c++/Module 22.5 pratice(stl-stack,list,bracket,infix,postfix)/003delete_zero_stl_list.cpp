#include<bits/stdc++.h>
using namespace std;

list<int> l;

void deleteZero()
{
    auto it = l.begin();

    while(it != l.end())
    {
       if(*it == 0)
            it = l.erase(it);
       else
          it++;
    }
}

void PRINT(list<int>l)
{
    auto it = l.begin();

    while( it != l.end())
    {
       cout<<*it<<" ";
       it++;
    }
    cout<< "\n";
}
int main()
{


    l.push_back(0);
    l.push_back(2);
    l.push_back(0);
    l.push_back(0);
    l.push_back(5);

    deleteZero();
    PRINT(l);

//    while(l.empty() == false)
//    {
//        cout<<l.back()<<" ";
//
//        l.pop_back();
//
//    }


    return 0;
}

