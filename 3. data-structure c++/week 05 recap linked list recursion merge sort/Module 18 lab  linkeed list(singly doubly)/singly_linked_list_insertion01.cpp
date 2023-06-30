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

    return 0;
}
