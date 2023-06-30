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
        if(head == NULL && tail == NULL)
        {
            insertHead(value);
            insertTail(value);
            return;
        }

        node *tmp = head;
        node *tmp1 = tail;

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

    // time complexity- O(n)
    void print()
    {
        node *tmp = head;

        while(tmp != NULL)
        {
            cout<<tmp->data<<" ";
            tmp = tmp->next;
        }
        cout<<"\n";
    }

    // time complexity- O(1)
    void Merge(doubly_linked_list a)
    {
        // corner case
        if(a.head == NULL)
            return;

        if(head == NULL && tail == NULL)
        {
            head = a.head;
            tail = a.tail;
            return;
        }

        tail->next = a.head;
        a.head->previus = tail;
        tail = a.tail;

    }




};
int main()
{
    doubly_linked_list a;
    doubly_linked_list b;

	a.insertHead(1);
	a.insertTail(5);
	a.insertMid(3);
	a.insertHead(0);
	a.insertTail(10);
	a.print(); // prints  0 1 3 5 10

	b.insertHead(10);
	b.insertTail(50);
	b.insertMid(30);
	b.insertHead(9);
	b.insertTail(100);
	b.print(); // prints  9 10 30 50 100

	a.Merge(b);
	a.print(); // prints  0 1 3 5 10 9 10 30 50 100
	b.print(); // prints  9 10 30 50 100




    return 0;
}

