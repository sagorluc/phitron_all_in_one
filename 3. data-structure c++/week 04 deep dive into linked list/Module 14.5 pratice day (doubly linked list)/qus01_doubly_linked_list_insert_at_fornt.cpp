#include<bits/stdc++.h>
using namespace std;
class node{
public:

    int data;
    node *next;
    node *previus;

};

class LinkedList{

public:

    node *head;

    // constructor
    LinkedList()
    {
        head = NULL;
    }

    void Doubly_insert_at_front(int data)
    {
        node *NewNode = new node;

        NewNode->data = data;
        NewNode->next = NULL;
        NewNode->previus = NULL;


        node *tmp = head;

        // corner case
        if( head == NULL)
        {
            head = NewNode;
            return;
        }
        NewNode->next = tmp;
        tmp->previus = NewNode;
        head = NewNode;

    }

    void Travers()
    {
        node *tmp = head;

        if( tmp == NULL)
            cout<<tmp;

        while( tmp != NULL)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->next;

        }
       cout<<"\n";

    }


};
int main()
{
    LinkedList l;

    l.Doubly_insert_at_front(5);
    l.Doubly_insert_at_front(4);
    l.Doubly_insert_at_front(3);
    l.Doubly_insert_at_front(2);
    l.Doubly_insert_at_front(1);
    l.Doubly_insert_at_front(0);
    l.Travers();


    return 0;
}
