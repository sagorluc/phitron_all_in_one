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

    //destructor/belete memory.
    //when we work with memory allocation
    //then we need to use destructor.
    ~student()
    {
        cout<<"called";
        print_info();
    }



};


//recursiv class
class person{
public:
    string name;
    person *f,*m; //f.name//string f //m.name//string m; it's same thing as person f,m;

    //new constructor for new person.
    person()
    {
        f = NULL;
        m = NULL;

    }

    //constructor
    person(string name, string f_name, string m_name)
    {
        this->name = name;
        f = new person;
        m = new person;
        f->name = f_name;
        m->name = m_name;

    }

    void info()
    {
        cout<<"name = "<<name<<"\n";
        cout<<"father name = "<<f->name<<"\n";
        cout<<"mother name = "<<m->name<<"\n";
    }

//    //destructor
    ~person()
    {
        cout<<"called"<<"\n";
        if(f != NULL)
        delete f;
        if(m != NULL)
        delete m;

    }



};
int main()
{

    person p("sagor","shahjahan","bimala");
    p.info();

//    student s("sagor",40,26,"shahjahan","bimala");
//    s.print_info();
//
//    student s1("sagor",40,26);
//    s1.print_info();
//
//    student s3;


    return 0;
}
