#include<bits/stdc++.h>
using namespace std;

// structure
class node{
 public:
    int data;
    node *next;


};
class LinkedList{

public:

    node *head; //1st pointer ta creat kora holo
    int sz;

    //constructor
    LinkedList()
    {
        head = NULL; //initially head NULL e point kore thakbe.

        sz = 0;
    }

    //creat a new node with data = value and next = NULL
    node* CreatNewNode(int value)
    {
        node *newnode = new node;

        newnode->data = value;
        newnode->next = NULL;

        return newnode;
    }

    // insert new value at head
    void InsertAtHead(int value)
    {
        sz++; //  jokhone new value insert korbo size barbe.

        node *a = CreatNewNode(value); // new node a creat kora holo.jate kore head e value insert kora jay.

        if(head == NULL)
        {
             head = a; // head a te point kore ace.
             return;
        }
        //if head is not NULL
        a->next = head; // a er next ke porer head er shatha connect korbe.
        head = a; // porer head take ager a er shthe connect korte hobe.


    }

    // print the linked list
    void Travers()
    {
        node* a = head; // a head e point kora holo.
        if(head == NULL)
           cout<<a;
        while(a != NULL) // a null na houya porjonto loop cholbe.
        {
            cout<<a->data<<" "; // a er vitore je data/value ace setake read kora holo.
            a = a->next; // ek ek kore a er next ke update kora holo.

        }
        cout<<"\n";


    }

    //search for a single value
    int SearchDistinctValue(int value)
    {
        node *a = head; // a ke head e point kora holo.
        int index = 0;
        while(a != NULL)
        {
            if(a->data == value) // frist node a er index  er data and value == hole porer index e jaoyar jonno index return kora holo.
                return index;

            a = a->next; // frist node a er next ke porer node er next e jaoyer jonno index++ kora holo.
            index++;
        }
        return -1; // er node e kicu na paile -1 return korbe.

    }

    //search all possible occurrence
    void SearchAllValue(int value)
    {
        node *a = head;
        int index = 0;
        while(a != NULL)
        {
            if(a->data == value)
               cout<<value<<" value is found at "<<index<<"\n";

            a = a->next;
            index++;
        }
    }

    // linked list length print korbe.
    int getSize()
    {
        // O(1).

        return sz;

        // time complexity O(n);

//        int sz = 0; // length size initially 0;
//        node *a = head; // new node a create kore head e point koralam.
//
//        while( a != NULL) // a NULL na hole loop e dhukbe.
//        {
//            sz++;          // joto gulo value pabe segulo ++ kore sz variable e store korbe.
//
//        }
//        return sz; // sz ke return kore dilam.

    }

};
int main()
{
    LinkedList l;

    cout<<l.getSize()<<"\n";
    l.InsertAtHead(10);
    cout<<l.getSize()<<"\n";

    l.InsertAtHead(20);
    cout<<l.getSize()<<"\n";

    l.InsertAtHead(30);
    cout<<l.getSize()<<"\n";


    return 0;
}

