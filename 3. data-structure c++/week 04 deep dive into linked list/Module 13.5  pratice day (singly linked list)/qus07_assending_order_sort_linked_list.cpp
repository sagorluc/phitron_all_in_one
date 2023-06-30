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

    void Insert_At_Tail(int data)
    {
        node *NewNode = new node;

        NewNode->data = data;
        NewNode->next = NULL;

        // corner case
        if( head == NULL)
        {
            head = NewNode;
            return;
        }

        node *tmp = head;

        while( tmp->next != NULL )
        {
           tmp = tmp->next;

        }
        tmp->next = NewNode;

    }

    void Travers()
    {
        node *tmp = head;

        // corner case

        if( head == NULL)
            return;

        while( tmp != NULL)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->next;

        }
        cout<<"\n";
    }

    void sort_assending_order()
    {
        node *tmp = head;

        while( tmp != NULL )
        {


        }
    }


};
int main()
{
    LinkedList l;

    l.Insert_At_Tail(4);
    l.Insert_At_Tail(2);
    l.Insert_At_Tail(5);
    l.Insert_At_Tail(1);
    l.Insert_At_Tail(3);
    l.Travers();




    return 0;
}
