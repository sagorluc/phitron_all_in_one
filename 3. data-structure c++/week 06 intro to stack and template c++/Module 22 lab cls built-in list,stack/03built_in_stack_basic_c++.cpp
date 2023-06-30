#include<bits/stdc++.h>
using namespace std;
int main()
{
    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout<<"total size of stack-> "<<st.size()<<"\n";

    cout<<st.top() <<" ";

    st.pop();
    cout<<st.top()<<" ";

    st.pop();
    cout<<st.top()<<" ";

    st.pop();


    return 0;
}
