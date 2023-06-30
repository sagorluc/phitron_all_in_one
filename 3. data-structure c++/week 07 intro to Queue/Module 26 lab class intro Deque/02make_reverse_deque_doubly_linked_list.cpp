#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node *previus;

};
class doubly_linked_list
{

public:
    node *head;
    node *tail;
    int sz;
    int rev;

    // constructorf
    doubly_linked_list()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rev = 0;
    }

    node *creatnode(int value)
    {
        node *Newnode = new node;

        Newnode->data = value;
        Newnode->next = NULL;
        Newnode->previus = NULL;

        return Newnode;

    }

    // insert at tail.time complexity- O(1)
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

    // insert at head.time complexity- O(1)
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

    // delete at tail.time complexity- O(1)
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

    // delete at head.time complexity- O(1)
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

    // print front.time complexity- O(1)
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

    // print back.time complexity- O(1)
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

    // print size.time complexity- O(1)
    int print_size()
    {
        return sz;
    }

    // reverse deque.time complexity- O(1)


};

class DEQUE
{

public:

    doubly_linked_list dl;


    void rev_deuqe()
    {
        if(dl.rev == 0)
        {
             dl.rev = 1;
        }
        else
        {
             dl.rev = 0;
        }
    }

    // push-back function.time complexity-O(1)
    void PUSH_BACK(int value)
    {
        if(dl.rev == 0)
        {
            dl.Insert_at_tail(value);
        }
        else
        {
            dl.Insert_at_head(value);
        }
    }

    // push-front function.time complexity-O(1)
    void PUSH_FRONT(int value)
    {
        if(dl.rev == 0)
        {

            dl.Insert_at_head(value);
        }
        else
        {
            dl.Insert_at_tail(value);
        }
    }

    // pop-back function.time complexity-O(1)
    void POP_BACK()
    {
        if(dl.rev == 0)
        {
            dl.delete_at_tail();
        }
        else
        {
            dl.delete_at_head();
        }
    }

    // pop-front function.time complexity-O(1)
    void POP_FRONT()
    {
        if(dl.rev == 0)
        {
            dl.delete_at_head();
        }
        else
        {
            dl.delete_at_tail();
        }
    }

    // front function.time complexity-O(1)
    int FRONT()
    {
        if(dl.rev == 0)
        {
            return dl.print_front();
        }
        else
        {
            return dl.print_back();
        }

    }

    // back function.time complexity-O(1)
    int BACK()
    {
        if(dl.rev == 0)
        {
            return dl.print_back();
        }
        else
        {
            return dl.print_front();
        }
    }




};
int main()
{
    DEQUE d;

    d.PUSH_BACK(5);
    d.PUSH_BACK(10);
    d.PUSH_BACK(15);
    d.PUSH_FRONT(20);
    d.rev_deuqe();
    cout<<"back : "<<d.BACK()<<" front : "<<d.FRONT()<<"\n";


    d.POP_FRONT();
    cout<<"back : "<<d.BACK()<<" front : "<<d.FRONT()<<"\n";

    d.POP_BACK();
    cout<<"back : "<<d.BACK()<<" front : "<<d.FRONT()<<"\n";


    return 0;
}

