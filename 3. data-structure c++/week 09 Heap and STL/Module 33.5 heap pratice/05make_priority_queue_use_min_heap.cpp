#include<bits/stdc++.h>
using namespace std;

template<typename t>

class Min_Heap
{
public:
    vector<t> nodes;

    Min_Heap()
    {

    }

    // O(log n)
    void up_heapify(t index)
    {
        while(index > 0 && nodes[index] < nodes[(index - 1)/2])
        {
            swap(nodes[index], nodes[(index - 1)/2]);
            index = (index - 1)/2;
        }
    }

    // O(log n)
    void Insert(t value)
    {
        nodes.push_back( - value);
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

            if(left < nodes.size() && nodes[largest] > nodes[left])
                largest = left;
            if(right < nodes.size() && nodes[largest] > nodes[right])
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
       return nodes[0]* -1;
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

template<typename t>

class min_heap_priority_queue
{
public:
    Min_Heap<t> m;

    void Push(t value)
    {
       m.Insert(value);

    }

    void Pop(t index)
    {
       m.Delete(index);

    }

    t Top()
    {
      return m.get_max();
    }

    void Print()
    {
        m.print();
    }

};
int main()
{
    min_heap_priority_queue<int> mh;

    mh.Push(5);
    mh.Push(7);
    mh.Push(6);
    mh.Push(4);
    mh.Push(10);
    mh.Push(8);
    mh.Push(12);

    mh.Print();

    mh.Pop(0);
    mh.Print();

    cout<<"top is : "<<mh.Top()<<"\n\n";



    return 0;
}


