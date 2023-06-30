#include<bits/stdc++.h>
using namespace std;
class node
{
    float fl;
    char ch;
    node *next;
    node *next_to_next;

    node *head;

    // constructor
    node()
    {
       head = NULL;
    }

    node *createNewNode(float value, char chaar)
    {
        node newnode = new node;
        newnode->fl = value;
        newnode->ch = chaar;
        newnode->next = NULL;
        newnode->next_to_next = NULL;

        return newnode;
    }

};
int main()
{


    return 0;
}
