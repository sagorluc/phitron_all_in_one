#include<bits/stdc++.h>
using namespace std;
class student{
public:
    string name;
    int st_id;
    int st_ag;

    //empty constructor
    student()
    {

    }

    //constructor
    student(string n, int id, int ag)
    {
        name = n;
        st_id = id;
        st_ag = ag;

    }

    void print()
    {
        cout<<name<<" ";
        cout<<st_id<<" ";
        cout<<st_ag<<" ";
        cout<<"\n";
    }

};

  bool comp(student a, student b)
    {
       return a.st_id < b.st_id;
    }

int main()
{
//    student s("sagor",12,26);
//    s.print();

    vector<student>s;
    for(int i=0; i<10; i++)
    {
        s.push_back(student("sagor",20-i,26));
    }

//    student s[10];
//    for(int i=1; i<10; i++)
//    {
//        s[i] = student("sagor",10-i,15);
//    }
    for(int i=0; i<10; i++)
    {
        s[i].print();

    }

    cout<<"after sort\n";

    sort(s.begin(), s.end(),comp);

    for(int i=1; i<10; i++)
    {
        s[i].print();

    }


    return 0;
}
