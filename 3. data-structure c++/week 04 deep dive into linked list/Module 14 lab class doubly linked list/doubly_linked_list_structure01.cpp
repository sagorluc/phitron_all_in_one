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

};


int main()
{

    return 0;
}
