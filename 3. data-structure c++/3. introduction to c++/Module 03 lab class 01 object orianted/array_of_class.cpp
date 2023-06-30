#include<bits/stdc++.h>
using namespace std;

class student{

public:
    string name;
    int st_id;
    int st_ag;


    //empty constructor must need for array declearetion.
    student()
    {

    }

    //constructor.
    student(string name, int st_id, int st_ag)
    {
        this->name = name;
        this->st_id = st_id;
        this->st_ag = st_ag;

    }
    void print()
    {
        cout<<name<<" ";
        cout<<st_id<<" ";
        cout<<st_ag<<" ";

    }

};

int main()
{
    //int a[10];
    student s[10];

    for(int i=1; i<10; ++i)
    {
        s[i] = student("A",i,20);
    }

    for(int i=1; i<10; ++i)
    {

        s[i].print();
        cout<<"\n";
    }




    return 0;
}
