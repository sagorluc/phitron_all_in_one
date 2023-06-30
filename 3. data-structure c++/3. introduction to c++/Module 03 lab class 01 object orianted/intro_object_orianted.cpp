/*
--> class and object
--> object orianted programming
*/
#include<bits/stdc++.h>
using namespace std;

class student{
public:
    string name = "sagor";
    int st_id;
    int st_ag;
    string fathers_name;
    string mothers_name;

    void print_info()
    {
     cout<<name<<" "<<st_id<<" "<<st_ag<<" "<<fathers_name<<" "<<mothers_name<<"\n";

    }
};

class ractangle{
public:
    int height,width;

    //area
    int area()
    {
        return height*width;
    }

    //perimeter
    int perimeter()
    {
        return 2*(height*width);
    }


};
//recursiv class
class person{
public:
    student s;
    string name;
    person *f,*m;

    void info()
    {
        cout<<"name = "<<name<<"\n";
        cout<<"father name = "<<f->name<<"\n";
        cout<<"mother name = "<<m->name<<"\n";
    }

};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    person p;
    p.f = new person;
    p.m = new person;
    p.name = "A";
    p.f->name = "B";
    p.m->name = "C";
    p.info();cout<<"\n";

    p.s.print_info();

//    ractangle r , r1; //class and object.
//
//    r.height = 40;
//    r.width = 20;
//    cout<<r.area()<<"\n";
//    cout<<r.perimeter()<<"\n";
//
//    r1.height = 20;
//    r1.width = 40;
//    cout<<r.area()<<"\n";
//    cout<<r.perimeter()<<"\n";

//    student s;
//    s.name = "sagor ahmed";
//    s.st_id = 1774;
//    s.st_ag = 24;
//    s.fathers_name = "md. shahjahan mia";
//    s.mothers_name = "mst. bimala begum";
//
//    s.print_info();cout<<"\n";
//
//    student s2;
//    s2.name = "jakir uzzaman";
//    s2.st_id = 1865;
//    s2.st_ag = 26;
//    s2.fathers_name = "nuzrul";
//    s2.mothers_name = "parvin";
//
//    s2.print_info();




    return 0;
}
