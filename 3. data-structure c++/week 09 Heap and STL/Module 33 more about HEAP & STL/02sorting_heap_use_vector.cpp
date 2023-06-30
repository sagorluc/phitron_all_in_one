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

    // time complexity- O(logn)
    void delete_index(int index)
    {
        // corner case
        if(index >= nodes.size())
            return;

        swap(nodes[index], nodes[nodes.size() - 1]);
        nodes.pop_back();
        down_heapify(index);
    }

    // time complexity- O(1)
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

    // time complexity- O(logn)
    int extract_max()
    {
        // corner case
        if(nodes.empty())
        {
            cout<<"heap is empty\n";
            return -1;
        }

        int ret = nodes[0];
        delete_index(0);
        return ret;

    }

    // time complexity- O(n)
    void build_heap_from_array(vector<int> v)
    {
        nodes = v;
        int leaf = nodes.size();
        int non_leaf = leaf / 2 - 1;

        for(int i=non_leaf; i>=0; i--)
            down_heapify(i);

    }


};

// time complexity- O(n log n)
vector<int> heap_sort(vector<int>a)
{
    Max_Heap h;
    h.build_heap_from_array(a);

    vector<int> ans;

    for(int i=0; i<a.size(); i++) // loop cholce n time.that's why the total function time complexity- O(n log n)
    {
        ans.push_back(h.extract_max()); // extract_max function time complexity- O(log n)
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{

    vector<int> a = {1,2,3,4,10,9,5,7};

    vector<int> sorted_a = heap_sort(a);

    for(int i=0; i<a.size(); i++)
        cout<<sorted_a[i]<<" ";


    return 0;
}




