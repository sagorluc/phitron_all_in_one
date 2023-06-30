#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *next;
    node *previus;

};
class doubly_linked_list{

public:
    node *head;
    node *tail;
    int sz;

    // constructorf
    doubly_linked_list()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node *creatnode(int value)
    {
        node *Newnode = new node;

        Newnode->data = value;
        Newnode->next = NULL;
        Newnode->previus = NULL;

        return Newnode;

    }

    // tc O(1)
    void Insert_at_tail(int value)
    {
        node *Newnode = creatnode(value);

        // corner case
        if(sz == 0)
        {
            head = Newnode;
            tail = Newnode;
            sz++;
            return;
        }

        tail->next = Newnode;
        Newnode->previus = tail;
        tail = Newnode;
        sz++;
    }

    // tc O(1)
    void Insert_at_head(int value)
    {
        node *Newnode = creatnode(value);

        // corner case
        if(sz == 0)
        {
            head = Newnode;
            tail = Newnode;
            sz++;
            return;
        }

        head->previus = Newnode;
        Newnode->next = head;
        head = Newnode;
        sz++;
    }

    // tc O(1)
    void delete_at_tail()
    {
        // corner case
        if(sz == 0)
        {
            cout<<"deque is empty.\n";
            return;
        }
        // corner case
        if(sz == 1)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }

       node *tmp = tail;

       tail = tail->previus;
       delete tmp;
       tail->next = NULL;
       sz--;

    }

    // tc O(1)
    void delete_at_head()
    {
        // corner case
        if(sz == 0)
        {
            cout<<"Deque is empty.\n";
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
        head->previus = NULL;
        sz--;
    }

    // tc O(1)
    int print_front()
    {
        // corner case
        if(sz == 0)
        {
            cout<< "Deque is empty.\n";
            return -1;
        }

        return head->data;
    }

    // tc O(1)
    int print_back()
    {
        //corner case
        if(sz == 0)
        {
            cout<<"Deque is empty.\n";
            return -1;
        }
        return tail->data;
    }

    // tc O(1)
    int print_size()
    {
        return sz;
    }


};

class DEQUE{

public:

    doubly_linked_list dl;

    // push-back function.
    void PUSH_BACK(int value)
    {
        dl.Insert_at_tail(value);
    }

    // push-front function.
    void PUSH_FRONT(int value)
    {
        dl.Insert_at_head(value);
    }

    // pop-back function.
    void POP_BACK()
    {
        dl.delete_at_tail();
    }

    // pop-front function.
    void POP_FRONT()
    {
        dl.delete_at_head();
    }

    // front function.
    int FRONT()
    {
       return dl.print_front();

    }

    // back function.
    int BACK()
    {
       return dl.print_back();
    }

    // size function.
    int SIZE()
    {
       return dl.print_size();
    }




};
int main()
{
    DEQUE d;

    d.PUSH_BACK(5);
    d.PUSH_BACK(6);
    d.PUSH_BACK(7);
    cout<<"back : "<<d.BACK()<<" front : "<<d.FRONT()<<"\n";

    d.PUSH_FRONT(8);
    cout<<"back : "<<d.BACK()<<" front : "<<d.FRONT()<<"\n";

    d.POP_BACK();
    cout<<"back : "<<d.BACK()<<" front : "<<d.FRONT()<<"\n";

    d.POP_FRONT();
    cout<<"back : "<<d.BACK()<<" front : "<<d.FRONT()<<"\n";


    return 0;
}
