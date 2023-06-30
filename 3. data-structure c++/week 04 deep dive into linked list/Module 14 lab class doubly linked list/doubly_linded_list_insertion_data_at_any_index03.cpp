#include<bits/stdc++.h>
using namespace std;

class doubly_node{

public:

    int data;
    doubly_node *next; // next ekta pointer
    doubly_node *previus; // previus ekta pointer

};

class Doubly_Linked_List{

public:

    doubly_node *head; // frist node ta kothay ace head seta mone rakhbe ba dhore rakhbe.

    int sz;

    // constructor for set value
    Doubly_Linked_List()
    {
        sz = 0;
        head = NULL;

    }

    // function of create a newnode with the given data and return it.

    doubly_node *Create_Double_NewNode(int value)
    {
        doubly_node *New_Node = new doubly_node;

        New_Node->data = value;
        New_Node->next = NULL;
        New_Node->previus = NULL;

        return New_Node;

    }

    // function for insert value at head.
    // time complexity- O(1).

    void InsertAtHead(int value)
    {
        doubly_node *New_Node =  Create_Double_NewNode(value);

       // base case
        if(head == NULL)
        {
            head = New_Node;
            return;
        }

        // head is not NULL
        sz++;
        doubly_node *a = head; // temponary variable of (a).

        New_Node->next = a; // newnode er next ke a er shathe point koralam.
        a->previus = New_Node; // a er previus ke newnode er shathe point koralam.
        head = New_Node; // tarpor head ke update kore newnode e point koralam.



    }

    // function for traverse data/value
    // time complexity - O(1).

    void Travers()
    {
        doubly_node *a = head;

        // base case
        if( a == NULL)
            cout<<a;

        // a is not NULL
        while( a != NULL)
        {
            cout<<a->data<<" "; // data/value print korbe.

            a = a->next; // a er next next kore NULL porjonto cholbe.

        }
        cout<<"\n";

    }

    // chack the size / length of double linked list.
    // time complexity- O(1).
    int getSize()
    {
        return sz;
    }

    // function for insert the data / value at any index
    // time complexity -

    void InsertValueAtAnyIndex(int index, int data)
    {

        // base case
        if( index == 0)
        {
            InsertAtHead(data);
            return;
        }

        // if head is not NULL
        sz++;
        doubly_node *a = head;

        int current_index = 0;
        while( current_index != index-1)
        {
            a = a->next;
            current_index++;
        }

        doubly_node *Insert = Create_Double_NewNode(data);

        Insert->next = a->next;
        Insert->previus = a;

        doubly_node *b = head;
        b->previus = Insert;
        a->next = Insert;

    }

};


int main()
{
    Doubly_Linked_List l;

    cout<<"size of linked list = "<<l.getSize()<<"\n";
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(30);
    l.InsertAtHead(40);
    l.Travers();
    cout<<"size of linked list = "<<l.getSize()<<"\n";

    l.InsertValueAtAnyIndex(1, 15);
    l.Travers();
    cout<<"size of linked list = "<<l.getSize()<<"\n";


    return 0;
}


