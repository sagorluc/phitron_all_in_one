#include<bits/stdc++.h>
using namespace std;

const int max_size = 100;
class Queque{

public:
    int a[max_size];
    int start;
    int endd;

    // constructor
    Queque()
    {
        start = 0;
        endd = -1;
    }

    void Enqueue(int value)
    {
        if(endd+1 >= max_size)
        {
            cout<<"Queue is full\n";
            return;
        }

        endd++;
        a[endd] = value;

    }

    void Dequeue()
    {
        if(start > endd)
        {
            cout<<"Queue is empty \n";
            return;
        }

        start++;

    }

    int Front()
    {
       if(start > endd)
       {
           cout<<"Queue is empty \n";
           return -1;
       }
       return a[start];

    }


};
int main()
{
    Queque d;

    d.Enqueue(5);
    d.Enqueue(6);
    d.Enqueue(7);
    d.Enqueue(8);
    cout<<d.Front()<<" ";

    d.Dequeue();
    cout<<d.Front()<<" ";

    d.Dequeue();
    cout<<d.Front()<<" ";

    d.Dequeue();
    cout<<d.Front()<<" ";




    return 0;
}
