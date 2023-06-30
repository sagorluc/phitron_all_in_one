#include<bits/stdc++.h>
using namespace std;
class node{

public:

    int data;
    node *next;

};

class LinkedList{

public:

    node *head;

    // constructor
    LinkedList()
    {
        head = NULL;
    }

    void InsertAtLast(int value)
    {
        node *Insert_last = new node;

        Insert_last->data = value;
        Insert_last->next = NULL;

        // corner case

        if(head == NULL)
        {
            head = Insert_last;
            return;
        }

        node *tmp = head;

        while( tmp->next != NULL )
        {
            tmp = tmp->next;

        }
        tmp->next = Insert_last;

    }

    void Travers()
    {
        node *tmp = head;

        // corner case
        if( head == NULL )
            return;

        while( tmp != NULL )
        {
           cout<<tmp->data<<" ";
           tmp = tmp->next;
        }
        cout<<"\n";
    }

    // function of find element in linked list.
    // time complexity- O(n).
    void Find_given_element(int to_find)
    {
        node *tmp = head;

        while( tmp != NULL)
        {
            if( tmp->data == to_find)
            {
                cout<<"True"<<"\n";
                return;
            }
            tmp = tmp->next;

        }
        cout<<"False"<<"\n";


    }


};
int main()
{
    LinkedList l;

    l.InsertAtLast(1);
    l.InsertAtLast(2);
    l.InsertAtLast(3);
    l.InsertAtLast(4);
    l.InsertAtLast(5);
    l.InsertAtLast(0);
    l.Travers();
    l.Find_given_element(5);


    return 0;
}

