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
        nodes.push_back(value);
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
    t get_min()
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
    t extract_min()
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

    // O(n)
    void build_heap_from_array(vector<t>v)
    {
      nodes = v;
      t leaf = nodes.size();
      t non_leaf = leaf/2-1;

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

template<typename t>
// O(n log n)
vector<t> min_sort(vector<t> a)
{
    Min_Heap<t> m;
    m.build_heap_from_array(a);

    vector<t> ans;

    for(int i=0; i<a.size(); i++)
    {
        ans.push_back(m.extract_min());
    }

    return ans;

}
int main()
{

    vector<int> sorted_a = {2,5,7,8,6,9,1};

    vector<int> res = min_sort(sorted_a);

    for(int i=0; i<sorted_a.size(); i++)
        cout<<res[i]<<" ";

    cout<<"\n\n";

    vector<char> ch = {'b','e','f','a','d','c'};

    vector<char> ans = min_sort(ch);

    for(int i=0; i<ch.size(); i++)
        cout<<ans[i]<<" ";



    return 0;
}


