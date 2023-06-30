#include<bits/stdc++.h>
using namespace std;

template<typename t>
class QUEUE
{
public:
    t *a;
    int arr_capacity;
    int start;
    int endd;
    int que_size;

    // constructor
    QUEUE()
    {
        a = new t[1];
        arr_capacity = 1;
        start = 0;
        endd = -1;
        que_size = 0;
    }

    void increse_capacity()
    {
        t *tmp = new t[arr_capacity * 2];

        for(int i=0; i<arr_capacity; i++)
            tmp[i] = a[i];

        swap(a,tmp);
        delete []tmp;

        arr_capacity = arr_capacity * 2;
    }

    void Enqueue(t value)
    {
        // corner case
        if(que_size + 1 == arr_capacity)
        {
            increse_capacity();
        }

        endd++;
        a[endd] = value;
        que_size++;
    }

    void Dequeue()
    {
        //corner case
        if(que_size == 0)
        {
            cout<<"Queue is empty\n";
            return;
        }
        start++;
        que_size--;

    }

    t Front()
    {
        // corner case
        if(que_size == 0)
        {
            cout<<"Queue is empty.\n";
            t a;
            return a;
        }
        return a[start];
    }

    int get_size()
    {
        return que_size;
    }



};
int main()
{
    QUEUE<int> q;

    q.Enqueue(5);
    q.Enqueue(6);
    q.Enqueue(7);
    cout<<"total size is : "<<q.get_size()<<"\n";
    cout<<q.Front()<<" ";

    q.Dequeue();
    cout<<q.Front()<<" ";

    q.Dequeue();
    cout<<q.Front()<<"\n";

    q.Dequeue();

    cout<<"total size is : "<<q.get_size()<<"\n\n";


    QUEUE<char> cq;

    cq.Enqueue('a');
    cq.Enqueue('b');
    cq.Enqueue('c');
    cout<<"total size is : "<<cq.get_size()<<"\n";
    cout<<cq.Front()<<" ";

    cq.Dequeue();
    cout<<cq.Front()<<" ";

    cq.Dequeue();
    cout<<cq.Front()<<"\n";

    cq.Dequeue();

    cout<<"total size is : "<<cq.get_size()<<"\n";

    return 0;
}
