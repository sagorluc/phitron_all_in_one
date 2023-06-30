#include<bits/stdc++.h>
using namespace std;
class node{

public:

    int data;
    node *next;
};

class SINGLY_LINKED_LIST{

    node *head;
    int sz;
public:

    SINGLY_LINKED_LIST()
    {
        head = NULL;
        sz = 0;
    }

    node *creat_node(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->next = NULL;

        return newnode;
    }

    void insert_at_head(int value)
    {
        sz++;
        node *newnode = creat_node(value);

        if(head == NULL)
        {
            head = newnode;
            return;
        }

        newnode->next = head;
        head = newnode;

    }

    int get_size()
    {
        return sz;
    }

    double getAverage()
    {
        node *tmp = head;

        if(!head)
            return -1;

        int sum = 0;
        double avg = 0.0;

        while(tmp != NULL)
        {
            sum = sum + tmp->data;
            tmp = tmp->next;


        }

        avg = (double)sum / get_size();

        return avg;


    }


};
int main()
{

    SINGLY_LINKED_LIST sl;


    sl.insert_at_head(7);
    sl.insert_at_head(4);
    sl.insert_at_head(6);
    sl.insert_at_head(2);
    sl.insert_at_head(3);
    cout<<sl.getAverage()<<"\n";






    return 0;
}

