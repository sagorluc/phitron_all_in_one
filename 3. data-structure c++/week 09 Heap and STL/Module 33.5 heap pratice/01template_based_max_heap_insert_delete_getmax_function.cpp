#include<bits/stdc++.h>
using namespace std;

template<typename t>

class Max_Heap
{
public:
    vector<t> nodes;

    Max_Heap()
    {

    }

    // O(log n)
    void up_heapify(t index)
    {
        while(index > 0 && nodes[index] > nodes[(index - 1)/2])
        {
            swap(nodes[index], nodes[(index - 1)/2]);
            index = (index - 1)/2;
        }
    }

    // O(log n)
    void Insert(t x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size() - 1);
    }

    // O(lon n)
    void Delete(t index)
    {
        if(index >= nodes.size())
            return;

        swap(nodes[index], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(index);
    }

    // O(log n)
    void down_heapify(t index)
    {
        while(1)
        {
            int largest = index;
            int left = 2*index + 1;
            int right = 2*index + 2;

            if(left < nodes.size() && nodes[largest] < nodes[left])
                largest = left;
            if(right < nodes.size() && nodes[largest] < nodes[right])
                largest = right;
            if(largest == index)
                break;

            swap(nodes[index], nodes[largest]);
            index = largest;

        }
    }

    // O(1)
    t get_max()
    {
        if(nodes.empty())
        {
            cout<<"heap is empty.\n";
            t a;
            return a;
        }
       return nodes[0];
    }

    // O(n)
    void print()
    {
        for(int i=0; i<nodes.size(); i++)
        {
            cout<<nodes[i]<<" ";
        }
        cout<<"\n";
    }

};
int main()
{
    Max_Heap<int> mh;

    mh.Insert(5);
    mh.Insert(7);
    mh.Insert(6);
    mh.Insert(4);
    mh.Insert(10);
    mh.Insert(8);
    mh.Insert(12);

    mh.print();

    mh.Delete(0);
    mh.print();

   cout<<"max is : "<<mh.get_max()<<"\n\n";


   Max_Heap<char> ch;

    ch.Insert('a');
    ch.Insert('b');
    ch.Insert('c');
    ch.Insert('d');
    ch.Insert('e');
    ch.Insert('f');
    ch.Insert('g');

    ch.print();

    ch.Delete(1);
    ch.print();

   cout<<"max is : "<<ch.get_max()<<"\n";



    return 0;
}
