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

    // function of find the i-th index value
    // time coomplexity- O(n).
    void Find_Value(int index)
    {
        node *a = head;
        int cnt = 0;

        while(index != cnt)
        {
            cnt++;
            a = a->next;

        }
        cout<<a->data<<"\n";

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

    sl.Find_Value(2);



    return 0;
}

