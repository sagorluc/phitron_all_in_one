#include<bits/stdc++.h>
using namespace std;

class student{

public:
    string name;
    int st_id;
    int st_ag;

    //constructor.
    student(string name, int st_id, int st_ag)
    {
        this->name = name;
        this->st_id = st_id;
        this->st_ag = st_ag;

    }
    //printing function
    void print()
    {
        cout<<name<<"\n";
        cout<<st_id<<"\n";
        cout<<st_ag<<"\n";

    }
    //destructor
    ~student()
    {
        cout<<"called";
        print();
    }

};



int main()
{
//    student s("sagor",10,20);
//    s.print();

    //daynamic object

    student *s1 = new student("jakir",20,30);
    //(*s1).print();
    s1->print();




    return 0;
}
