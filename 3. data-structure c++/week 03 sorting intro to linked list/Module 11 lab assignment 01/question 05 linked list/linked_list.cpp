#include<bits/stdc++.h>
using namespace std;
class node_structure{
public:
    int data;
    node_structure* next;


};
class Linked_List{
public:

    node_structure* head;

    LinkedList()
    {
        head = NULL;
    }

    node_structure* NewNode_fun(int value)
    {
        node_structure* NewNode  = new node_structure;

        NewNode->data = value;
        NewNode->next = NULL;
        return NewNode;

    }

    void InsertAtHead(int value)
    {
        node_structure *a = NewNode_fun(value);
        if(head == NULL)
        {
            head = a; // head a te point kore ace.
            return;
        }

        a->next = head;
        head = a;

    }

    void Travers()
    {
        node_structure* a = head;
        while( a != NULL)
        {
            cout<<a->data<<" ";

            a = a->next;
        }
    }


    int getSize()
    {
        int sz = 0;
        node_structure* a = head;

        while( a != NULL)
        {
           sz++;
        }
        return sz;

    }

    int getValue(int value)
    {
        node_structure *a = head;
        int index = 0;
        while(a != NULL)
        {
            if(a->data == value)
            {
                return index;
            }
            else
            {

                a = a->next;
                index++;
            }

        }
        return -1;

    }

    void printReverse()
    {
        node_structure* a = head;
    }

    void swapFirst()
    {
        node_structure* a = head;

    }



};
int main()
{
    Linked_List l;
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(5);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);

//    cout<<l.getValue(2)<<"\n";
//
//    cout<<l.getValue(6)<<"\n";
//
//    l.printReverse();
//    l.Travers();
//    l.swapFirst();
//    l.Travers();
//    l.printReverse();


    return 0;
}
