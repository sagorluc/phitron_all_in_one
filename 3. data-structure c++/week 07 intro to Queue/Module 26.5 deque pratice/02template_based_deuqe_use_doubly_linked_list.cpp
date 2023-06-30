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

    // constructor
    DOUBLY_DEQUE()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
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

};

template<typename t>
class DEQUE{
public:
    DOUBLY_DEQUE<t> dd;

    void PUSH_BACK(t value)
    {
        dd.insert_at_tail(value);

    }

    void PUSH_FRONT(t value)
    {
        dd.insert_at_head(value);
    }

    void POP_BACK()
    {
        dd.delete_at_tail();
    }

    void POP_FRONT()
    {
        dd.delete_at_head();
    }

    t FRONT()
    {
        return dd.print_front();;
    }

    t BACK()
    {
        return dd.print_back();

    }




};
int main()
{
    DEQUE<int> d;

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

    DEQUE<char> cd;

    cd.PUSH_BACK('a');
    cd.PUSH_BACK('b');
    cd.PUSH_BACK('c');
    cout<<"back : "<<cd.BACK()<<" front : "<<cd.FRONT()<<"\n";

    cd.PUSH_FRONT('d');
    cout<<"back : "<<cd.BACK()<<" front : "<<cd.FRONT()<<"\n";

    cd.POP_BACK();
    cout<<"back : "<<cd.BACK()<<" front : "<<cd.FRONT()<<"\n";

    cd.POP_FRONT();
    cout<<"back : "<<cd.BACK()<<" front : "<<cd.FRONT()<<"\n";

    return 0;
}
