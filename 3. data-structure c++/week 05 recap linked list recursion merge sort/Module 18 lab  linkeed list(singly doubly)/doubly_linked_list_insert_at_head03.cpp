#include<bits/stdc++.h>
using namespace std;
class doubly_node{

public:
    int data;
    doubly_node *next;
    doubly_node *previus;
};

class doubly_linked_list{

public:
    doubly_node *head;

    // constructor
    doubly_linked_list()
    {
        head = NULL;
    }

    void Insert_at_head(int value)
    {
        doubly_node *NewNode = new doubly_node;

        NewNode->data = value;
        NewNode->next = NULL;
        NewNode->previus = NULL;

        // corneer case
        if(head == NULL)
        {
            head = NewNode;
            return;
        }

        NewNode->next = head;
        head->previus = NewNode;
        head = NewNode;
    }

    void Travers()
    {
        doubly_node *tmp = head;

        while( tmp != NULL)
        {
            cout<< tmp->data<<" ";
            tmp = tmp->next;

        }
        cout<< "\n";
    }




};

int main()
{
    doubly_linked_list dl;

    dl.Insert_at_head(5);
    dl.Insert_at_head(4);
    dl.Insert_at_head(3);
    dl.Insert_at_head(2);
    dl.Insert_at_head(1);
    dl.Travers();

    return 0;
}
