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

    void Insert_at_any_index(int index, int value)
    {

        // corner case
        if(head == NULL)
        {
            Insert_at_head(value);
            return;
        }

        doubly_node *tmp = head;
        int cur_index = 0;

        while(cur_index != index-1)
        {
            if(tmp == NULL)
                break;
            tmp = tmp->next;
            cur_index++;
        }

        if(tmp == NULL)
        {
            cout<<"cna't insert.\n";
            return;
        }

        // if not null
        doubly_node *NewNode = new doubly_node;

        NewNode->data = value;
        NewNode->next = NULL;
        NewNode->previus = NULL;

        NewNode->next = tmp->next;

        doubly_node *b = tmp->next;

        if(b != NULL)
            b->previus = NewNode;

        tmp->next = NewNode;
        NewNode->previus = tmp;




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
    dl.Insert_at_any_index(2, 15);
    dl.Travers();

    return 0;
}

