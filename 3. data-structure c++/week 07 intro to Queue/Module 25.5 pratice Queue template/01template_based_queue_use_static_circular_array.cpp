#include<bits/stdc++.h>
using namespace std;
const int max_size = 10;
template<typename t>
class circular_static_queue{

public:
    t a[max_size];
    int start;
    int endd;
    int queue_sz;

    // constructor
    circular_static_queue()
    {
        start = 0;
        endd = -1;
        queue_sz = 0;
    }

    void insert_enqueue(t value)
    {
        // corner case
        if(queue_sz == max_size)
        {
            cout<<"Queue is full.\n";
            return;
        }
        endd++;
        // if endd cross the border will make it circular
        if(endd == max_size)
            endd = 0;

        a[endd] = value;
        queue_sz++;

    }

    void delete_dequeue()
    {
        // corner case
        if(queue_sz == 0)
        {
            cout<<"Queue is empty.\n";
            return;
        }
        start++;
        // if start cross the border will make it circular
        if(start == max_size)
            start = 0;

        queue_sz--;
    }

    t FRONT()
    {
        // corner case
        if(queue_sz == 0)
        {
            cout<<"Queue is empty.\n";
            t a;
            return a;
        }
       return a[start];
    }

    int get_size()
    {
        return queue_sz;
    }





};
int main()
{
    circular_static_queue<int> cq;

    cq.insert_enqueue(5);
    cq.insert_enqueue(6);
    cq.insert_enqueue(7);
    cq.insert_enqueue(8);

    cout<<"Queue size is : "<<cq.get_size()<<"\n";
    cout<<cq.FRONT()<<" ";
    cq.delete_dequeue();

    cout<<cq.FRONT()<<" ";
    cq.delete_dequeue();

    cout<<cq.FRONT()<<" ";
    cq.delete_dequeue();

    cout<<cq.FRONT()<<"\n";
    cq.delete_dequeue();
    cout<<"Queue size is : "<<cq.get_size()<<"\n\n";


    circular_static_queue<char> q;

    q.insert_enqueue('a');
    q.insert_enqueue('b');
    q.insert_enqueue('c');
    q.insert_enqueue('d');

    cout<<"Queue size is : "<<q.get_size()<<"\n";
    cout<<q.FRONT()<<" ";
    q.delete_dequeue();

    cout<<q.FRONT()<<" ";
    q.delete_dequeue();

    cout<<q.FRONT()<<" ";
    q.delete_dequeue();

    cout<<q.FRONT()<<"\n";
    q.delete_dequeue();
    cout<<"Queue size is : "<<q.get_size()<<"\n\n";


    circular_static_queue<double> d;

    d.insert_enqueue(2.1);
    d.insert_enqueue(9.3);
    d.insert_enqueue(10.35);
    d.insert_enqueue(5.5);

    cout<<"Queue size is : "<<d.get_size()<<"\n";
    cout<<d.FRONT()<<" ";
    d.delete_dequeue();

    cout<<d.FRONT()<<" ";
    d.delete_dequeue();

    cout<<d.FRONT()<<" ";
    d.delete_dequeue();

    cout<<d.FRONT()<<"\n";
    d.delete_dequeue();
    cout<<"Queue size is : "<<d.get_size()<<"\n";




    return 0;
}
