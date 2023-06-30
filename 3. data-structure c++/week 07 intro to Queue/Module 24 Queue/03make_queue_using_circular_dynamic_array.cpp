#include<bits/stdc++.h>
using namespace std;


class QUEUE
{

public:
    int *a;
    int arr_capacity;
    int start;
    int endd;
    int queue_sz;

    // constructor
    QUEUE()
    {
        a = new int[1];
        arr_capacity = 1;
        start = 0;
        endd = -1;
        queue_sz = 0;
    }

    // time complexity- O(n)
    void remove_array_circular()
    {
        if(start > endd)
        {
            int *tmp = new int[arr_capacity];

            int idx = 0;
            for(int i=start; i<arr_capacity; i++)
            {
                // idx ke tmp push kore travers korar jonno ++ korlam.
                tmp[idx] = a[i];
                idx++;
            }

            for(int i=0; i<=endd; i++)
            {
                // idx ke tmp push kore travers korar jonno ++ korlam.
                 tmp[idx] = a[i];
                 idx++;
            }


            swap(tmp,a);
            start = 0;
            endd = arr_capacity -1;
            delete []tmp;
        }

    }

    // tmime complexity- O(n)
    void Increase_capacity()
    {
        // frist array circular remove kora holo.
        remove_array_circular();

        // now increase the size.
        int *tmp = new int[arr_capacity * 2];

        for(int i=0; i<arr_capacity; i++)
            tmp[i] = a[i];

        swap(a,tmp);
        arr_capacity = arr_capacity * 2;
        delete []tmp;
    }

    // time complexity- O(1)
    void insert_or_enqueue(int value)
    {

        // corner case
        if(queue_sz == arr_capacity)
        {
            Increase_capacity();
        }

        endd++;
        // if endd is equal equal the MAX SIZE then endd will start from 0 or frist.
        if(endd == arr_capacity)
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
        if(start == arr_capacity)
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

