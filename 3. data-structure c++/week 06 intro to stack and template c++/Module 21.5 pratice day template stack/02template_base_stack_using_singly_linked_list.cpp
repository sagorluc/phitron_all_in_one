#include<bits/stdc++.h>
using namespace std;

template<class T>
class node{
public:
    T data;
    node<T> *next;

};

template<class T>
class singly_linked_list{
public:
    node<T> *head;
    int sz;

    // constructor
    singly_linked_list()
    {
        head = NULL;
        sz = 0;
    }

    // creating new node
    node<T> *create_node(T value)
    {
        node<T> *newnode = new node<T>;

        newnode->data = value;
        newnode->next = NULL;

        return newnode;
    }

    // insert value at head
    void insert_at_head(T value)
    {
        node<T> *newnode = create_node(value);
        sz++;
        // corner case
        if(head == NULL)
        {
            head = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }

    // delete value at head
    void delete_at_head()
    {
        if(head == NULL)
        {
            cout<<"empty stack.\n";
            return;
        }
        node<T> *tmp = head;
        head = tmp->next;

        delete tmp;
        sz--;
        return;
    }

    // travers all the value
    void Travers()
    {
        node<T> *tmp = head;
        while(tmp != NULL)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<"\n";
    }

    // size of singly linked list
    int get_size()
    {
        return sz;
    }

};

template<class T>
class STACK{
public:
    singly_linked_list<T> slt;

    // constructor
    STACK()
    {

    }

    // push value in stack
    void PUSH(T value)
    {
       slt.insert_at_head(value);
    }

    // remove value from stack
    void POP()
    {
        slt.delete_at_head();
    }

    // read top most element at stack.
    T TOP()
    {
        if(slt.get_size() == 0)
        {
            cout<< "stack is empty.\n";
            T a;
            return a;
        }

        return slt.head->data;
    }

    // print the value of stack
    void PRINT()
    {
        slt.Travers();
    }

};
int main()
{
    STACK<float> s;

    s.PUSH(4.5);
    s.PUSH(3.1);
    s.PUSH(2);
    s.PUSH(1);
    s.PRINT();
    s.POP();
    s.PRINT();

    STACK<char> ct;

    ct.PUSH('d');
    ct.PUSH('c');
    ct.PUSH('b');
    ct.PUSH('a');
    ct.PRINT();
    ct.POP();
    ct.PRINT();
    ct.POP();
    ct.PRINT();
    ct.POP();
    ct.PRINT();
    ct.POP();
    ct.PRINT();
    ct.POP();
    ct.PRINT();


    return 0;
}
