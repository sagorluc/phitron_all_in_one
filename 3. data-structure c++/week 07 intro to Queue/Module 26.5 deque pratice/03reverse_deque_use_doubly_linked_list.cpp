#include<bits/stdc++.h>
using namespace std;
template<typename t>
class node
{
public:
    t data;
    node<t> *next;
    node<t> *previus;

};
template<typename t>
class DOUBLY_DEQUE
{
public:
    node<t> *head;
    node<t> *tail;
    int sz;
    t rev;

    // constructor
    DOUBLY_DEQUE()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rev = 0;
    }

    node<t> *creatnewnode(t value)
    {
        node<t> *newnode = new node<t>;

        newnode->data = value;
        newnode->next = NULL;
        newnode->previus = NULL;

        return newnode;

    }

    void insert_at_tail(t value)
    {
        node<t> *Newnode = creatnewnode(value);
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

    void insert_at_head(t value)
    {
        node<t> *Newnode = creatnewnode(value);
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

    void delete_at_tail()
    {
        // corner case
        if(sz == 0)
        {
            cout<<"Deque is empty.\n";
            return;
        }
        if(sz == 1)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node<t> *tmp = tail;
        tail = tail->previus;
        delete tmp;
        tail->next = NULL;
        sz--;
    }

    void delete_at_head()
    {
        // corner case
        if(sz == 0)
        {
            cout<<"Deque is empty.\n";
            return;
        }
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
        head->previus = NULL;
        sz--;

    }

    t print_front()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty.\n";
            t a;
            return a;
        }
        return head->data;
    }

    t print_back()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty.\n";
            t a;
            return a;
        }
        return tail->data;
    }

    void REVERSE_DEQUE()
    {
        if(rev == 0)
            rev = 1;
        else
            rev =0;
    }

    void PUSH_BACK(t value)
    {
        if(rev == 0)
            insert_at_tail(value);
        else
            insert_at_head(value);
    }

    void PUSH_FRONT(t value)
    {
        if(rev == 0)
            insert_at_head(value);
        else
            insert_at_tail(value);
    }

    void POP_BACK()
    {
        if(rev == 0)
            delete_at_tail();
        else
            delete_at_head();
    }

    void POP_FRONT()
    {
        if(rev == 0)
            delete_at_head();
        else
            delete_at_tail();

    }

    t FRONT()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty.\n";
            t a;
            return a;
        }

        if(rev == 0)
            return head->data;
        else
            return tail->data;
    }

    t BACK()
    {
        if(sz == 0)
        {
            cout<<"Deque is empty.\n";
            t a;
            return a;
        }

        if(rev == 0)
            return tail->data;
        else
            return head->data;

    }

};

int main()
{
    DOUBLY_DEQUE<int> d;

    d.PUSH_BACK(5);
    d.PUSH_BACK(10);
    d.PUSH_BACK(15);
    d.PUSH_FRONT(20);
    d.REVERSE_DEQUE();
    cout<<"back : "<<d.BACK()<<" front : "<<d.FRONT()<<"\n";


    d.POP_FRONT();
    cout<<"back : "<<d.BACK()<<" front : "<<d.FRONT()<<"\n";

    d.POP_BACK();
    cout<<"back : "<<d.BACK()<<" front : "<<d.FRONT()<<"\n";


    DOUBLY_DEQUE<char> cd;

    cd.PUSH_BACK('a');
    cd.PUSH_BACK('b');
    cd.PUSH_BACK('c');
    cd.PUSH_FRONT('d');
    cd.REVERSE_DEQUE();
    cout<<"back : "<<cd.BACK()<<" front : "<<cd.FRONT()<<"\n";


    cd.POP_FRONT();
    cout<<"back : "<<cd.BACK()<<" front : "<<cd.FRONT()<<"\n";

    cd.POP_BACK();
    cout<<"back : "<<cd.BACK()<<" front : "<<cd.FRONT()<<"\n";


    return 0;
}

