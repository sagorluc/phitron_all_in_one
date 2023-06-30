#include<bits/stdc++.h>
using namespace std;
class node{
public:

    int data;
    node *next;
    node *previus;

};

class stack_doubly_linked_list{

public:
    node *head;
    int sz;

    // constructor

    stack_doubly_linked_list()
    {
        head = NULL;
        sz = 0;
    }

    node *Create_new_node(int value)
    {
        node *newnode = new node;

        newnode->data = value;
        newnode->next = NULL;
        newnode->previus = NULL;

        return newnode;

    }

    // push value at head. time complexity- O(1)
    void insert_at_head(int value)
    {
        sz++;
        node *newnode = Create_new_node(value);

        // corner case
        if(head == NULL)
        {
            head = newnode;
            return;
        }

        node *tmp = head;

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

        node *tmp = head;
        node * b = head;

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

class STACK{

public:

    stack_doubly_linked_list stk;

    // constructor

    STACK() // Constructor is empty bcz value set korar moto kicui nei
    {

    }

    // print the most top value in stack.
    int TOP()
    {
        if(stk.get_size() == 0)
        {
            cout<< "stack is empty.\n";
            return -1;
        }

        return stk.head->data;
    }

    // push the value in stack.
    void PUSH(int value)
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
    STACK st;

    st.PUSH(3);
    cout<<st.TOP()<<"\n";
    st.PUSH(4);
    cout<<st.TOP()<<"\n";
    st.PUSH(5);
    cout<<st.TOP()<<"\n";

    st.POP();
    cout<<st.TOP()<<"\n";
    st.POP();
    cout<<st.TOP()<<"\n";
    st.POP();
    cout<<st.TOP()<<"\n";

    return 0;
}
