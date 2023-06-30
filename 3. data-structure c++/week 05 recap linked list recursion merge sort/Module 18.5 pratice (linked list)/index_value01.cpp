#include<bits/stdc++.h>
using namespace std;
class node{

public:

    int data;
    node *next;
    node *previus;
};

class Linked_list{

        node *head;
        int sz;
public:

        // constructor
        Linked_list()
        {
            head = NULL;
            sz = 0;
        }

        node *create_new_node(int value)
        {
            node *create_node = new node;

            create_node->data = value;
            create_node->next = NULL;
            create_node->previus = NULL;

            return create_node;
        }

        void Insert_value_at_head(int value)
        {
            node *Newnode = create_new_node(value);

            if(head == NULL)
            {
                head = Newnode;
                return;
            }

            Newnode->next = head;
            head = Newnode;
        }

        void Travers()
        {
            node *tmp = head;

            while(tmp != NULL)
            {
                cout<< tmp->data << " ";
                tmp = tmp->next;
            }
            cout<<"\n";
        }

        int get_value(int index)
        {
            node *tmp = head;

            // corner case
//            if( index >= sz)
//                return -1;

            int cur_index = 0;
            while(tmp != NULL)
            {
                if(cur_index == index)
                    return tmp->data;

                cur_index++;

                tmp = tmp->next;

            }
            return -1;
        }




};
int main()
{
    Linked_list l;

    l.Insert_value_at_head(5);
    l.Insert_value_at_head(4);
    l.Insert_value_at_head(6);
    l.Insert_value_at_head(2);
    l.Insert_value_at_head(3);
    l.Travers();

    cout<<l.get_value(0);


    return 0;
}
