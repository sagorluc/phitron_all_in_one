#include<bits/stdc++.h>
using namespace std;


list<int>l;
int getValue(int index)
{
    if(l.size()<=index)
        return -1;
    auto it = l.begin();
    advance(it,index);
    return *it;
}

bool searchValue(int value){
    auto it = l.begin();
    while(it!=l.end()){
        if(*it==value){
            return true;
        }
        it++;
    }
    return false;
}


void deleteZero(){
    auto it = l.begin();
    while(it!=l.end()){
        if(*it==0){
            it = l.erase(it);
        }
        else{
            it++;
        }

    }
}

void print(list<int>l)
{
    auto it = l.begin();
    while(it!=l.end())
    {
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}

int main()
{

    l.push_back(3);
    l.push_back(2);
    l.push_back(0);
    l.push_back(4);
    l.push_back(5);
    print(l);

    //Question-01
    cout<<getValue(2)<<endl;

    //Question-02
    if(searchValue(10)){
        cout<<"True\n";
    }else{
        cout<<"False\n";
    }

    //Question-03
    deleteZero();
    print(l);
}

