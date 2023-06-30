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

    // O(logn)
    t extract_max()
    {
        if(nodes.empty())
        {
            cout<<"heap is empty.\n";
            t a;
            return a;
        }

        int ret = nodes[0];
        Delete(0);
        return ret;
    }


    // time complexity- O(n)
    void build_heap_from_array(vector<t> v)
    {
        nodes = v;
        t leaf = nodes.size();
        t non_leaf = leaf / 2 - 1;

        for(int i=non_leaf; i>=0; i--)
            down_heapify(i);


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

// time complexity- O(n log n)
template<typename t>
vector<t> heap_sort(vector<t>a)
{
    Max_Heap<t> h;
    h.build_heap_from_array(a);

    vector<t> ans;

    for(int i=0; i<a.size(); i++) // loop cholce n time.that's why the total function time complexity- O(n log n)
    {
        ans.push_back(h.extract_max()); // extract_max function time complexity- O(log n)
    }

    return ans;
}

int main()
{
    int n,k;
    cin >> n >> k;

    vector<int> v;

    for(int i=0; i<n; i++)
    {
        int in;
        cin >> in;
        v.push_back(in);
    }

    vector<int> ans = heap_sort(v);

    for(int i=0; i<k; i++)
        cout<<ans[i]<<" ";





    return 0;
}

