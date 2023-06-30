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
    // constructor
    doubly_linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    node *creat_new_node(int value)
    {
        node *newnode = new node;

        newnode->data = value;
        newnode->next = NULL;
        newnode->previus = NULL;

        return newnode;

    }

    // time complexity- O(1)
    void insertHead(int value)
    {
        node *newnode = creat_new_node(value);

        // corner case
        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }

        node *tmp = head;

        newnode->next = tmp;
        tmp->previus = newnode;
        head = newnode;

    }

    // time complexity- O(1)
    void insertTail(int value)
    {
        node *Newnode = creat_new_node(value);

        // corner case
        if(tail == NULL)
        {
            head = Newnode;
            tail = Newnode;
            return;
        }

        tail->next = Newnode;
        Newnode->previus = tail;
        tail = Newnode;
    }

    //time complexity- O(n)
    void insertMid(int value)
    {
        node *newnode = creat_new_node(value);

        // corner case
        if(head == NULL)
        {
            insertHead(value);
            return;
        }

        node *tmp = head;
        node *tmp1 = head;

        while(tmp1 != NULL && tmp1->next != NULL)
        {
           tmp = tmp->next;
           tmp1 = tmp1->next->next->next;
        }

        if(tmp->next != NULL)
            tmp->next->previus = newnode;


        newnode->next = tmp->next;
        newnode->previus = tmp;
        tmp->next = newnode;

    }

    void traverse()
    {
        node *tmp = head;

        while(tmp != NULL)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<"\n";
    }




};
int main()
{
    doubly_linked_list dl;

    dl.insertHead(1);
    dl.insertHead(2);
    dl.insertHead(3);
    dl.insertHead(4);

    dl.insertTail(6);
    dl.insertTail(7);


    dl.insertMid(5);


    dl.traverse();

    return 0;
}
