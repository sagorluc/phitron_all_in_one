#include<bits/stdc++.h>
using namespace std;
// unsolved problem.
class node{

public:

    int data;
    node* next;
    node* previus;

};
class Doubly_linked_list{

public:
    node* head;
    int sz;

    // constructor
    Doubly_linked_list()
    {
        head = NULL;
        sz = 0;
    }

    void Insert_at_head(int value)
    {
        node* NewNode = new node;

        NewNode->data = value;
        NewNode->next = NULL;
        NewNode->previus = NULL;

        // corner case
        if(head == NULL)
        {
            head = NewNode;
            return;
        }

        node* a = head;

        NewNode->next = a;
        a->previus = NewNode;
        head = NewNode;


    }

    void Travers()
    {
        node* a = head;

        // corner case
        if(a == NULL)
            cout<<a;

        while( a != NULL)
        {
            cout<<a->data<<" ";
            a = a->next;

        }
        cout<<"\n";
    }

    void Delete_any_index( int index)
    {

        if( index >= sz)
            cout<< " size doesn't exist.\n";

        node* a = head;
        int current_index = 0;
        while( current_index != index)
        {
            a = a->next;
            current_index++;
        }

        node *b = a->previus;
        node *c = a->next;

        b->next = c;
        c->previus = b;

        if(b != NULL)
            b->next = c;
        if(c != NULL)
            c->previus = b;

        delete a;

        if(index == 0)
            head = c;

        sz--;
    }

    int getsize()
    {
        return sz;
    }



};
int main()
{
    Doubly_linked_list dl;

    dl.Insert_at_head(5);
    dl.Insert_at_head(4);
    dl.Insert_at_head(3);
    dl.Insert_at_head(2);
    dl.Insert_at_head(1);
    dl.Delete_any_index(4);
    dl.Travers();
    cout<<dl.getsize()<<"\n";
    dl.Travers();


    return 0;
}
