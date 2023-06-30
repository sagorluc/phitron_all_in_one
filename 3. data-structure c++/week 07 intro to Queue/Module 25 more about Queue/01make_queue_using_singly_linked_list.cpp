#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int data;
    node *next;

};

class QUEUE{

public:

    node *head;
    node *tail;
    int sz;

    // constructor
    QUEUE()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node *create_new_node(int value)
    {
        node *Newnode = new node;

        Newnode->data = value;
        Newnode->next = NULL;

        return Newnode;
    }

    void Insert_tail_enqueue(int value)
    {
        sz++;
        node *tailnode = create_new_node(value);

        // corner case
        if(head == NULL)
        {
            head = tailnode;
            tail = tailnode;
            return;
        }
        tail->next =tailnode;
        tail = tailnode;
    }

    void delete_head_dequeue()
    {
        // corner case
        if(sz == 0)
        {
            cout<< "Queue is empty.\n";
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
        node *tmp = head;

        head = head->next;
        delete tmp;
        sz--;
    }

    int FRONT()
    {
        // corner case
        if(sz == 0)
        {
            cout<<"Queue is empty.\n";
            return -1;
        }
        return head->data;
    }

    int get_size()
    {
       return sz;
    }



};
int main()
{
    QUEUE q;

    q.Insert_tail_enqueue(5);
    q.Insert_tail_enqueue(6);
    q.Insert_tail_enqueue(7);
    q.Insert_tail_enqueue(8);

    cout<<"Queue size is : "<<q.get_size()<<"\n";

    cout<<q.FRONT()<<" ";
    q.delete_head_dequeue();

    cout<<q.FRONT()<<" ";
    q.delete_head_dequeue();

    cout<<q.FRONT()<<" ";
    q.delete_head_dequeue();

    cout<<q.FRONT()<<" ";
    q.delete_head_dequeue();

    cout<<"\nQueue size is : "<<q.get_size()<<"\n";

    return 0;
}

