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


};
int main()
{
    Max_Heap heap;

    heap.INSERT(4);
    heap.INSERT(7);
    heap.INSERT(9);
    heap.INSERT(1);
    heap.INSERT(10);
    heap.print_heap();

    return 0;
}
