#include<bits/stdc++.h>
using namespace std;
int main()
{
    deque<int> dq;

    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(4);

    dq.pop_back();
    dq.pop_front();

    cout<<dq.size()<<"\n";
    cout<<dq.front()<<"\n";
    cout<<dq.back()<<"\n";
    return 0;
}
