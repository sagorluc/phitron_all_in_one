#include<bits/stdc++.h>
using namespace std;
class MaxHeap
{

public:

    vector<int> nodes;

    // constructor
    MaxHeap()
    {


    }

    void up_heapify(int index)
    {
        while(index > 0 && nodes[index] > nodes[(index - 1)/2])
        {
            swap(nodes[index], nodes[(index - 1)/2]);
            index = (index - 1)/2;
        }

    }

    void INSERT(int x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size() - 1);
    }

    void print_heap()
    {
        for(int i=0; i<nodes.size(); i++)
        {
            cout<<nodes[i]<<" ";
        }
        cout<<"\n";
    }


    void down_heapify(int index)
    {
        while(1)
        {
            int largest = index;
            int left = 2*index + 1;
            int right = 2*index + 2;

            if(left < nodes.size() && nodes[largest] < nodes[left])
            {
                largest = left;
            }
            if(right < nodes.size() && nodes[largest] < nodes[right])
            {
                largest = right;
            }
            if(largest == index)
                break;
            swap(nodes[index], nodes[largest]);
            index = largest;

        }
    }

    void delete_index(int index)
    {
        // corner case
        if(index >= nodes.size())
            return;

        swap(nodes[index], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(index);
    }



    int get_max()
    {
        // corner case
        if(nodes.empty())
        {
            cout<<"heap is empty\n";
            return -1;
        }
        return nodes[0];
    }


};


class MinHeap
{
public:
    MaxHeap mx;
    void Insert(int x)
    {
        //Write your code here
        mx.INSERT(-x);
    }
    void Delete(int idx)
    {
        //Write your code here
        mx.delete_index(idx);
    }
    int getMin()
    {
        //Write your code here
        return -mx.get_max();
    }

    void print()
    {
        mx.print_heap();
    }
};

int main()
{
    MinHeap m;

    m.Insert(4);
    m.Insert(7);
    m.Insert(9);
    m.Insert(1);
    m.Insert(10);
    m.Insert(20);
    m.Insert(30);
    m.print();

    m.Delete(1);
    m.print();

    cout<<"minimum value : "<<m.getMin()<<"\n";



    return 0;
}
