#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> pq;

    // push() time complexity- O(logn)
    pq.push(5);
    pq.push(6);
    pq.push(7);
    pq.push(8);
    pq.push(9);


    while(pq.size() != 0)
    {
        // top() time complexity- O(1)
       cout<<pq.top()<<" ";

       // pop() time complexity- O(logn)
       pq.pop();
    }

    return 0;
}
