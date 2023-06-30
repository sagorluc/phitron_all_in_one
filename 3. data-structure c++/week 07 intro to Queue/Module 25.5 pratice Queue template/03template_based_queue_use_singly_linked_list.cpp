#include<bits/stdc++.h>
using namespace std;

template<typename t>
class node{

public:
    t data;
    node<t> *next;

};

template<typename t>
class singly_queue{

public:
    node<t> *head;
    node<t> *tail;
    int sz;

    //costructor
    singly_queue()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node<t> *create_node(t value)
    {
        node<t> *Newnode = new node<t>;

        Newnode->data = value;
        Newnode->next = NULL;

        return Newnode;
    }

    void enqueue_at_tail(t value)
    {   sz++;
        node<t> *Newnode = create_node(value);

        // corner case
        if(head == NULL)
        {
            head = Newnode;
            tail = Newnode;
            return;
        }
        tail->next = Newnode;
        tail = Newnode;
    }

    void delete_dequeue()
    {
        // corner case
        if(sz == 0)
        {
            cout<<"Queue is empty.\n";
            return;
        }
        // corner case
        if(sz == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node<t> *tmp = head;

        head = head->next;
        delete tmp;
        sz--;
    }

    t FRONT()
    {
        // corner case
        if(sz == 0)
        {
            cout<<"Queue is empty.\n";
            t a;
            return a;
        }
        return head->data;
    }

    int get_size()
    {
        return  sz;
    }


};
int main()
{
    singly_queue<int> sq;

    sq.enqueue_at_tail(5);
    sq.enqueue_at_tail(6);
    sq.enqueue_at_tail(7);
    sq.enqueue_at_tail(8);

    cout<<"Queue size is : "<<sq.get_size()<<"\n";
    cout<<sq.FRONT()<<" ";
    sq.delete_dequeue();

    cout<<sq.FRONT()<<" ";
    sq.delete_dequeue();

    cout<<sq.FRONT()<<" ";
    sq.delete_dequeue();

    cout<<sq.FRONT()<<"\n";
    sq.delete_dequeue();
    cout<<"Queue size is : "<<sq.get_size()<<"\n\n";


    singly_queue<char> cq;

    cq.enqueue_at_tail('a');
    cq.enqueue_at_tail('b');
    cq.enqueue_at_tail('c');
    cq.enqueue_at_tail('d');

    cout<<"Queue size is : "<<cq.get_size()<<"\n";
    cout<<cq.FRONT()<<" ";
    cq.delete_dequeue();

    cout<<cq.FRONT()<<" ";
    cq.delete_dequeue();

    cout<<cq.FRONT()<<" ";
    cq.delete_dequeue();

    cout<<cq.FRONT()<<"\n";
    cq.delete_dequeue();
    cout<<"Queue size is : "<<cq.get_size()<<"\n\n";

    return 0;
}
