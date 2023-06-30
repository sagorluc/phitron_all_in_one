#include<bits/stdc++.h>
using namespace std;

class student{

public:
    string name;
    int st_id;
    int st_age;
    string father_name;
    string mother_name;

    student()
    {


    }

    //constructor. a function that return nothing.
    student(string s, int id, int ag, string f_name, string m_name)
    {
        name = s;
        st_id = id;
        st_age = ag;
        father_name = f_name;
        mother_name = m_name;

    }

    //constructor over load.

    student(string s, int id, int ag)
    {
        name = s;
        st_id = id;
        st_age = ag;


    }


    void print_info()
    {
        cout<<name<<"\n";
        cout<<st_id<<"\n";
        cout<<st_age<<"\n";
        cout<<father_name<<"\n";
        cout<<mother_name<<"\n";
    }



};


int main()
{
    student s("sagor",40,26,"shahjahan","bimala");
    s.print_info();

    student s1("sagor",40,26);
    s1.print_info();

    student s3;


    return 0;
}
