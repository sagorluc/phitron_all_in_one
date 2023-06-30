#include<bits/stdc++.h>
using namespace std;
int zero = 0;
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

    void deleteZero()
    {
        doubly_node *tmp = head;
        int cur = 0;

        while(tmp != NULL)
        {
            tmp = tmp->next;
            cur++;

            if(cur != 0)
               cout<<tmp->data;


        }
    }


};
int main()
{
    DOUBLY_LINKED_LIST dl;

    dl.insert_at_head(5);
    dl.insert_at_head(0);
    dl.insert_at_head(0);
    dl.insert_at_head(2);
    dl.insert_at_head(0);
    dl.Travers();
    dl.deleteZero();
    dl.Travers();
    return 0;
}
