#include<bits/stdc++.h>
using namespace std;
class Max_Heap
{

public:
    vector<int> nodes;

    // constructor
    Max_Heap()
    {


    }
    // time complexity- O(log n)
    void up_heapify(int index)
    {
        while(index > 0 && nodes[index] > nodes[(index - 1)/2])
        {
            swap(nodes[index], nodes[(index - 1)/2]);
            index = (index - 1)/2;
        }

    }
    // time complexity- O(logn)
    void INSERT(int x)
    {
        nodes.push_back(x); // time complexity- O(1)
        up_heapify(nodes.size() - 1); // time complexity- O(log n)
    }
    // time complexity- O(n)
    void print_heap()
    {
        for(int i=0; i<nodes.size(); i++)
        {
            cout<<nodes[i]<<" ";
        }
        cout<<"\n";
    }

    // time complexity- O(logn)
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


};
int main()
{
    Max_Heap heap;

    heap.INSERT(4);
    heap.INSERT(7);
    heap.INSERT(9);
    heap.INSERT(1);
    heap.INSERT(10);
    heap.INSERT(20);
    heap.INSERT(30);
    heap.print_heap();

    heap.delete_index(0);
    heap.print_heap();

    return 0;
}

