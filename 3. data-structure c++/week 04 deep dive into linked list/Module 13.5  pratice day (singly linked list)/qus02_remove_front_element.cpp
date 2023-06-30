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

    void DeleteAtFront()
    {
        // corner case
        if( head == NULL)
            return;

        node *a = head;
        a = head;
        head = a->next;

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
    sl.Travers();
    sl.DeleteAtFront();
    sl.Travers();

    return 0;
}
