#include<bits/stdc++.h>
using namespace std;
class singly_node{

public:
    int data;
    singly_node* next;
};

class Singly_linked_list{

public:
    singly_node* head;

    // constructor
    Singly_linked_list()
    {
        head = NULL;
    }

    void Insert_at_head( int value)
    {
        singly_node* singly_newnode = new singly_node;

        singly_newnode->data = value;
        singly_newnode->next = NULL;

        singly_newnode->next = head;
        head = singly_newnode;
    }

    void Travers()
    {
        singly_node *tmp = head;

        while(tmp != NULL)
        {
            cout<< tmp->data << " ";

            tmp = tmp->next;
        }
        cout<< "\n";
    }

    void Insert_at_any_index(int index, int value)
    {
        if(index == 0)
        {
            Insert_at_head(value);
            return;
        }

        singly_node *tmp = head;

        int cur_index = 0;
        while(cur_index != index-1)
        {
           if(tmp == NULL)
             break;

           tmp = tmp->next;
           cur_index++;
        }
        if( tmp == NULL)
        {
            cout<< "can't insert. \n";
            return;
        }

        // tmp NULL na hole

        singly_node *Newnode = new singly_node;
        Newnode->data = value;
        Newnode->next = NULL;

        Newnode->next = tmp->next;
        tmp->next = Newnode;
    }


};
int main()
{
    Singly_linked_list sl;

    sl.Insert_at_head(5);
    sl.Insert_at_head(4);
    sl.Insert_at_head(3);
    sl.Insert_at_head(2);
    sl.Insert_at_head(1);
    sl.Travers();

    sl.Insert_at_any_index(3, 15);
    sl.Travers();

    return 0;
}

