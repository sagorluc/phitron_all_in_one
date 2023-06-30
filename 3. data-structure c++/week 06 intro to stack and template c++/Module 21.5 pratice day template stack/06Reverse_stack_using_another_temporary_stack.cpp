#include<bits/stdc++.h>
using namespace std;
/*
problem
reverse the element in stack
-> 4, 2, 3, 1, 5

solved
-> 5, 1, 3, 2, 4


*/

template<class T>
class node{
public:

    T data;
    node *next;
    node *previus;

};

template<class T>
class doubly_linked_list{

public:

    node<T> *head;
    int sz;

    //constructor
    doubly_linked_list()
    {
       head = NULL;
       sz = 0;
    }

    node<T> *creat_node(T value)
    {
        node<T> *newnode = new node<T>;

        newnode->data = value;
        newnode->next = NULL;
        newnode->previus = NULL;

        return newnode;
    }

    void Insert_at_head(T value)
    {
        sz++;
        node<T> *newnode = creat_node(value);
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

    void delete_at_head()
    {
        // corner case
        if(head == NULL)
            return;

        node<T> *tmp = head;

        tmp = head->next;

        if(tmp != NULL)
            tmp->previus = NULL;

        head = tmp;
        sz--;

    }

    void Travers()
    {
        node<T> *tmp = head;

        while(tmp != NULL)
        {
            cout<< tmp->data<< " ";
            tmp = tmp->next;
        }
        cout<< "\n";
    }

    T get_size()
    {
        return sz;
    }


};

template<class T>
class STACK{
public:

    doubly_linked_list<T> ds;

    // constructor
    STACK()
    {


    }

    void PUSH(T value)
    {
        ds.Insert_at_head(value);
    }

    void POP()
    {
        ds.delete_at_head();
    }

    int TOP()
    {
        if(ds.get_size() == 0)
        {
            cout<<"stack is empty.\n";
            T a;
            return a;
        }

        return ds.head->data;

    }

    void PRINT()
    {
        ds.Travers();
    }

    int get_size()
    {
        return ds.get_size();
    }



};
int main()
{

    STACK<int> s;

    s.PUSH(5);
    s.PUSH(1);
    s.PUSH(3);
    s.PUSH(2);
    s.PUSH(4);
    s.PRINT();

    // sort stack using another temponary stack.
    STACK<int> tmp;

    while(s.get_size() > 0)
    {
        tmp.PUSH(s.TOP());
        s.POP();
    }

    swap(s,tmp);
    s.PRINT();


    return 0;
}

