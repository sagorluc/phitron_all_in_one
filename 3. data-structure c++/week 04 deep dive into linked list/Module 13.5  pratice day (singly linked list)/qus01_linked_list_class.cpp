#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node *next;

};

class Singly_linked_list{
public:
    node* head;
    int sz;

    // constructor.
    Singly_linked_list()
    {
        head = NULL;
        sz = 0;
    }

    node *CreatNewnode(int value)
    {
        node *NewNode = new node;
        NewNode->data = value;
        NewNode->next = NULL;

        return NewNode;

    }

    // function for insert value at front
    // time complexity- O(1).
    void InserAtFront(int value)
    {
        node *Front_node = CreatNewnode(value);

        // corner case
        if(head == NULL)
        {
            head = Front_node;
            return;
        }
        node *a = head;

        Front_node->next = a;
        head = Front_node;

    }
    // function for print/read data.
    // time complexity- O(n).
    void Travers()
    {
        node *a = head;

        while( a != NULL)
        {
            cout<<a->data<<" ";
            a = a->next;

        }
        cout<<"\n";
    }



};
int main()
{
    Singly_linked_list sl;

    sl.InserAtFront(5);
    sl.InserAtFront(4);
    sl.InserAtFront(3);
    sl.InserAtFront(2);
    sl.InserAtFront(1);
    sl.Travers();

    sl.InserAtFront(0);
    sl.Travers();

    return 0;
}
