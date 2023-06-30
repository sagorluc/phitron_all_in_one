#include<bits/stdc++.h>
using namespace std;
class node{

    // node structure.
public:
    int data;
    node* next;

};

class Singly_linked_list{

public:
    node *head;

    // constructor
    Singly_linked_list()
    {
        head = NULL;
    }

    node *CreateNode(int value)
    {
        node *NewNode = new node;

        NewNode->data = value;
        NewNode->next = NULL;

        return NewNode;
    }

    // function of insert value at head.
    // time complexity- O(1).
    void InserValueAtHead(int value)
    {
        node *InsertNode = CreateNode(value);

        node *a = head;

        // corner case
        if( head == NULL)
        {
            head = InsertNode;
            return;
        }

        InsertNode->next = a;
        head = InsertNode;

    }

    // function of read/print the value
    // time complexity- O(1).
    void Travers()
    {
        node *a = head;

        while( a != NULL)
        {
            cout<<a->data<<" ";
            a  = a->next;

        }
        cout<<"\n";
    }

    // delete ay heade/front value
    // time complexity- O(1).
    void DeleteAtFront()
    {
        // corner case
        if( head == NULL)
            return;

        node *a = head;
        a = head;
        head = a->next;

    }

    // function of delete any index value
    // time complexity- O(n).
    void DeleteLastElement(int index)
    {
        if( index == 0)
        {
            DeleteAtFront();
            return;
        }

        node *a = head;
        int current_index = 0;

        while( current_index != index-1)
        {
           a = a->next;
           current_index++;
        }

        node *b = head;

        b = a->next;
        a->next = b->next;

        delete b;

    }






};
int main()
{
    Singly_linked_list sl;

    sl.InserValueAtHead(5);
    sl.InserValueAtHead(4);
    sl.InserValueAtHead(3);
    sl.InserValueAtHead(2);
    sl.InserValueAtHead(1);
    sl.DeleteLastElement(4);
    sl.Travers();

//    sl.DeleteAtFront();
//    sl.Travers();
//
//    sl.DeleteLastElement(4);
//    sl.Travers();

    return 0;
}
