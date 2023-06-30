#include<bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> qi;

    // enqueue
    qi.push(5);
    qi.push(6);
    qi.push(7);
    qi.push(8);

    cout<<"Queue size is : "<<qi.size()<<"\n";
    cout<<qi.front()<<" ";

    qi.pop();
    cout<<qi.front()<<" ";

    qi.pop();
    cout<<qi.front()<<" ";

    qi.pop();
    cout<<qi.front()<<" ";
    qi.pop();
    cout<<"\nQueue size is : "<<qi.size()<<"\n\n";

    cout<<qi.empty()<<"\n";

    queue<char> qc;

    qc.push('a');
    qc.push('b');
    qc.push('c');
    qc.push('d');

    cout<<"Queue size is : "<<qc.size()<<"\n";
//    qc.pop();
    cout<<qc.front()<<" ";

    qc.pop();
    cout<<qc.front()<<" ";

    qc.pop();
    cout<<qc.front()<<" ";

    qc.pop();
    cout<<qc.front()<<" ";
    qc.pop();
    cout<<qc.front()<<" ";


    cout<<"\nQueue size is : "<<qc.size()<<"\n";



    return 0;
}
