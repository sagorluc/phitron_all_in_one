#include<bits/stdc++.h>
using namespace std;
/*
access modifiers
-->public
-->privet
-->protected
*/

class student{

private:

    string name = "sagor";
    int st_id = 74;
    int st_ag;
    string fathers_name;
    string mothers_name;

public:



    void print_info()
    {
     cout<<name<<" "<<st_id<<" "<<st_ag<<" "<<fathers_name<<" "<<mothers_name<<"\n";

    }
    void set_info(string s, int id, int ag)
    {
        name = s;
        st_id = id;
        st_ag = ag;

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

class user{

 protected:
     string name;
     int idd;
};

class admin: user{ //inherite to user

private:
    string designation;
public:
    void sett(string s, int id, string dg)
    {
        name = s;
        idd = id;
        designation = dg;
    }

    void print()
    {
        cout<<name<<"\n";
        cout<<idd<<"\n";
        cout<<designation<<"\n";
    }



};
int main()
{
    student s;

    s.set_info("sagor",10,26);
    s.print_info();

    admin ad;

    ad.sett("sagor",10,"jakir");
    ad.print();


//    cout<<s.st_id;
//    cout<<s.name;// it's private.


    return 0;
}
