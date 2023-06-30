#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 500;
class QUEUE{

public:

    int a[MAX_SIZE];
    int start;
    int endd;

    // constructor
    QUEUE()
    {
        start = 0;
        endd = -1;
    }

    // time complexity- O(1)
    void Insert_or_enqueue(int value)
    {
        // corner case
        if(endd+1 >= MAX_SIZE)
        {
            cout<< " Queue is full.\n";
            return;
        }
        // if queue is not full.
        endd++; // value insert or enqueue korar jonno end ke pluse korte hobe.
        a[endd] = value; // array te value insert kora holo.
    }

    // time complexity- O(1)
    void delete_or_dequeue()
    {
        // corner case
        if(start > endd)
        {
            cout<<"Queue is empty.\n";
            return;
        }

        //if queue is not empty
        start++;
    }

    // time complexity- O(1)
    int FRONT()
    {
        // corner case
        if(start > endd)
        {
            cout<<"queue is empty.\n";
            return -1;
        }
        // if queue is not empty
        return a[start]; // arry er first elem is front elem.
    }

   // time complexity- O(1)
    int queue_size()
    {
        if(start > endd)
        {
            cout<<"queue is empty.\n";
            return -1;
        }

        // if queue is not empty.

        return endd - start + 1;
    }


};
int main()
{
    QUEUE q;

    q.Insert_or_enqueue(5);
    q.Insert_or_enqueue(6);
    q.Insert_or_enqueue(7);
    q.Insert_or_enqueue(8);

    cout<<"Q size = "<<q.queue_size()<<"\n";
    cout<<q.FRONT()<<" ";
    q.delete_or_dequeue();

    cout<<q.FRONT()<<" ";
    q.delete_or_dequeue();

    cout<<q.FRONT()<<" ";
    q.delete_or_dequeue();

    cout<<q.FRONT()<<"\n";
    q.delete_or_dequeue();
    cout<<"Q size = "<<q.queue_size()<<"\n";


    return 0;
}

