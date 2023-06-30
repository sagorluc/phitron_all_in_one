#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
public:

    T data;
    node *next;
    node *previus;

};

template<class T>
class stack_doubly_linked_list{

public:
    node<T> *head;
    int sz;

    // constructor

    stack_doubly_linked_list()
    {
        head = NULL;
        sz = 0;
    }

    node<T> *Create_new_node(T value)
    {
        node<T> *newnode = new node<T>;

        newnode->data = value;
        newnode->next = NULL;
        newnode->previus = NULL;

        return newnode;

    }

    // push value at head. time complexity- O(1)
    void insert_at_head(T value)
    {
        sz++;
        node<T> *newnode = Create_new_node(value);

        // corner case
        if(head == NULL)
        {
            head = newnode;
            return;
        }

        node<T> *tmp = head;

        newnode->next = tmp;
        tmp->previus = newnode;
        head = newnode;
    }

    // delete the value at head.time complexity- O(1)
    void delete_at_head()
    {
        // corner case
        if(head == NULL)
            return;

        node<T> *tmp = head;
        node<T> * b = head;

        b = head->next;
        delete tmp;

        if( b != NULL)
            b->previus = NULL;

        head = b;
        sz--;

    }
    // size of the linked list. time complexity- O(1)
    int get_size()
    {
        return sz;
    }

};

// stack using doubly linked list.

template<class T>
class STACK{

public:

    stack_doubly_linked_list<T> stk;

    // constructor

    STACK() // Constructor is empty bcz value set korar moto kicui nei
    {

    }

    // print the most top value in stack.
    T TOP()
    {
        if(stk.get_size() == 0)
        {
            cout<< "stack is empty.\n";
            T a;
            return a;
        }

        return stk.head->data;
    }

    // push the value in stack.
    void PUSH(T value)
    {
        stk.insert_at_head(value);
    }

    // delete the most top value in stack.
    void POP()
    {
       stk.delete_at_head();
    }


};

int main()
{
    STACK<double> stk;

    stk.PUSH(3.3);
    stk.PUSH(4.2);
    stk.PUSH(5.5);
    cout<<stk.TOP()<<"\n";

    stk.POP();
    cout<<stk.TOP()<<"\n";

    stk.POP();
    cout<<stk.TOP()<<"\n";

    stk.POP();
    cout<<stk.TOP()<<"\n";

    STACK<char> st;

    st.PUSH('a');
    st.PUSH('b');
    st.PUSH('c');
    cout<<st.TOP()<<"\n";

    st.POP();
    cout<<st.TOP()<<"\n";
    st.POP();
    cout<<st.TOP()<<"\n";
    st.POP();
    cout<<st.TOP()<<"\n";



    return 0;
}

