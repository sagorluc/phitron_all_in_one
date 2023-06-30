#include<bits/stdc++.h>
using namespace std;
void deleteValue(list<int> & l , int value)
{
   auto it = find(l.begin(), l.end(), value);

   if(it != l.end())
    l.erase(it);

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
    list<int> l;

    l.push_back(7);
    l.push_back(3);
    l.push_back(8);
    l.push_back(4);
    l.push_back(5);
    l.push_back(4);
    PRINT(l);
    deleteValue(l,4);
    PRINT(l);


    return 0;
}
