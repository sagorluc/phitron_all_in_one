#include<bits/stdc++.h>
using namespace std;

const int MAX_SIZE = 10;

template<class T>
class STACK{
public:
    T arr[10];

    int stack_size;

    //constructor
    STACK()
    {
        stack_size = 0;
    }

    // add the element at the top.
    void PUSH(T value)
    {
        // corner case.
        if(stack_size + 1 > MAX_SIZE)
        {
            cout<<"stack is full.\n";
            return;
        }
        stack_size = stack_size + 1;
        arr[stack_size - 1] = value;
    }

    // remove the top most elements
    void POP()
    {
        // corner case
        if(stack_size == 0)
        {
            cout<<"stack is empty.\n";
            return;
        }
        stack_size = stack_size -1;
    }
    // returns the top most element.
    T TOP()
    {
        // corner case
        if(stack_size == 0)
        {
            cout<< "stack is empty.\n";
            T a;
            return a;
        }
       return arr[stack_size - 1];
    }



};
int main()
{
    STACK<float> st;

    st.PUSH(10.5);
    cout<<st.TOP()<<" ";
    st.PUSH(9.4);
    cout<<st.TOP()<<" ";
    st.PUSH(8.6);
    cout<<st.TOP()<<" ";
    st.PUSH(7.2);
    cout<<st.TOP()<<" ";
    st.PUSH(5.3);
    cout<<st.TOP()<<" ";
    st.PUSH(3.4);

    STACK<char> ct;

    ct.PUSH('a');
    cout<<ct.TOP()<<" ";
    ct.PUSH('b');
    cout<<ct.TOP()<<" ";
    ct.PUSH('c');
    cout<<ct.TOP()<<" ";
    ct.PUSH('d');
    cout<<ct.TOP()<<" ";

//    st.POP();
//    cout<<st.TOP()<<" ";
//
//    st.POP();
//    cout<<st.TOP()<<" ";
//
//    st.POP();
//    cout<<st.TOP()<<" ";
//
//    st.POP();
//    cout<<st.TOP()<<" ";

//    st.POP();
//    cout<<st.TOP()<<" ";
//
//    st.POP();
//    cout<<st.TOP()<<" ";
//
//    st.POP();
//    cout<<st.TOP()<<" ";
//
//    st.POP();
//    cout<<st.TOP()<<" ";
//
//    st.POP();
//    cout<<st.TOP()<<" ";
//
//    st.POP();
//    cout<<st.TOP()<<" ";

    return 0;
}
