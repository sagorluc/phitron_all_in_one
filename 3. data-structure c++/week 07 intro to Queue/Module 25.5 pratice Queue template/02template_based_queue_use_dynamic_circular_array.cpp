#include<bits/stdc++.h>
using namespace std;
template<typename t>
class dynamic_circular_array_queue{
public:
    t *a;
    int arr_capacity;
    int start;
    int endd;
    int queue_sz;

    // constructor
    dynamic_circular_array_queue()
    {
        a = new t[1];
        arr_capacity = 1;
        start = 0;
        endd = -1;
        queue_sz = 0;
    }

    void remove_arr_circuler()
    {
        // if start is over then endd;
        if(start > endd)
        {
            t *tmp = new t[arr_capacity];
            int idx = 0;

            for(int i=start; i<arr_capacity; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }

            for(int i=0; i<=endd; i++)
            {
                tmp[idx] = a[i];
                idx++;
            }

            swap(tmp,a);
            start = 0;
            endd = arr_capacity-1;
            delete []tmp;
        }

    }

    void incrase_capacity()
    {
        // remove array circule
        remove_arr_circuler();

        t *tmp = new t[arr_capacity * 2];

        for(int i=0; i<arr_capacity; i++)
            tmp[i] = a[i];

        swap(a,tmp);
        arr_capacity = arr_capacity * 2;
        delete []tmp;
    }

    void insert_enqueue(t value)
    {
        if(queue_sz == arr_capacity)
        {
            incrase_capacity();
        }

        endd++;

        if(endd == arr_capacity)
            endd = 0;

        a[endd] = value;
        queue_sz++;
    }

    void delete_dequeue()
    {
        if(queue_sz == 0)
        {
            cout<<"Queue is empty.\n";
            return;
        }
       start++;
       if(start == arr_capacity)
            start = 0;

       queue_sz--;

    }

    t FRONT()
    {
        if( queue_sz == 0)
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
    dynamic_circular_array_queue<int> dq;

    dq.insert_enqueue(5);
    dq.insert_enqueue(6);
    dq.insert_enqueue(7);
    dq.insert_enqueue(8);

    cout<<"Queue size is : "<<dq.get_size()<<"\n";
    cout<<dq.FRONT()<<" ";
    dq.delete_dequeue();

    cout<<dq.FRONT()<<" ";
    dq.delete_dequeue();

    cout<<dq.FRONT()<<" ";
    dq.delete_dequeue();

    cout<<dq.FRONT()<<"\n";
    dq.delete_dequeue();
    cout<<"Queue size is : "<<dq.get_size()<<"\n\n";


    dynamic_circular_array_queue<float> fq;

    fq.insert_enqueue(5.2);
    fq.insert_enqueue(6.6);
    fq.insert_enqueue(7.3);
    fq.insert_enqueue(8.89);

    cout<<"Queue size is : "<<fq.get_size()<<"\n";
    cout<<fq.FRONT()<<" ";
    fq.delete_dequeue();

    cout<<fq.FRONT()<<" ";
    fq.delete_dequeue();

    cout<<fq.FRONT()<<" ";
    fq.delete_dequeue();

    cout<<fq.FRONT()<<"\n";
    fq.delete_dequeue();
    cout<<"Queue size is : "<<fq.get_size()<<"\n\n";

    return 0;
}
