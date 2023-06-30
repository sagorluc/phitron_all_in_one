#include<bits/stdc++.h>
using namespace std;
const int MAX_SIZE = 500;
class QUEUE{

public:
    int a[MAX_SIZE];
    int start;
    int endd;
    int queue_sz;

    // constructor
    QUEUE()
    {
        start = 0;
        endd = -1;
        queue_sz = 0;
    }

    // time complexity- O(1)
    void insert_or_enqueue(int value)
    {
        // corner case
        if(queue_sz == MAX_SIZE)
        {
            cout<<"Queue is full.\n";
            return;
        }

        endd++;
        // if endd is equal equal the MAX SIZE then endd will start from 0 or frist.
        if(endd == MAX_SIZE)
            endd = 0;

        a[endd] = value;
        queue_sz++;
    }

    // time complexity-O(1)
    void delete_or_dequeue()
    {
        // corner case
        if(queue_sz == 0)
        {
            cout<<"queue is empty.\n";
            return;
        }

        start++;

        // if start is equal equal max size of array then start will start from 0 or frist.
        if(start == MAX_SIZE)
            start = 0;

        queue_sz--;
    }

    // time complexity- O(1)
    int FRONT()
    {
        // corner case
        if(queue_sz == 0)
        {
            cout<<"queue is empty.\n";
            return -1;
        }
        return a[start];
    }

    // time complexity- O(1)
    int SIZE()
    {
        return queue_sz;
    }



};
int main()
{
    QUEUE q;

    q.insert_or_enqueue(5);
    q.insert_or_enqueue(6);
    q.insert_or_enqueue(7);
    q.insert_or_enqueue(8);

    cout<<"Q size = "<<q.SIZE()<<"\n";
    cout<<q.FRONT()<<" ";
    q.delete_or_dequeue();

    cout<<q.FRONT()<<" ";
    q.delete_or_dequeue();

    cout<<q.FRONT()<<" ";
    q.delete_or_dequeue();

    cout<<q.FRONT()<<"\n";
    q.delete_or_dequeue();
    cout<<"Q size = "<<q.SIZE()<<"\n";


    return 0;
}
