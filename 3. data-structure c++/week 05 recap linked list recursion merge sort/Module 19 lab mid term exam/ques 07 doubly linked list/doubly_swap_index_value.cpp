#include<bits/stdc++.h>
using namespace std;
class doubly_node{
public:
    int data;
    doubly_node *next;
    doubly_node *previus;
};

class DOUBLY_LINKED_LIST{

    doubly_node *head;
    int sz;

public:

    DOUBLY_LINKED_LIST()
    {
        head = NULL;
        sz = 0;
    }

    doubly_node *create_node(int value)
    {
        doubly_node *newnode = new doubly_node;

        newnode->data = value;
        newnode->next = NULL;
        newnode->previus = NULL;

        return newnode;
    }

    void insert_at_head(int value)
    {
        doubly_node *newnode = create_node(value);

        if(head == NULL)
        {
            head = newnode;
            return;
        }

        doubly_node *tmp = head;

        newnode->next = tmp;
        tmp->previus = newnode;
        head = newnode;
    }

    void Travers()
    {
        doubly_node *tmp = head;

        while(tmp != NULL)
        {
            cout<< tmp->data << " ";
            tmp = tmp->next;
        }
    }

    void SWAP(int i, int j)
    {

    }


};
int main()
{
    DOUBLY_LINKED_LIST dl;

    dl.insert_at_head(7);
    dl.insert_at_head(4);
    dl.insert_at_head(6);
    dl.insert_at_head(2);
    dl.insert_at_head(3);
    dl.Travers();

    return 0;
}
