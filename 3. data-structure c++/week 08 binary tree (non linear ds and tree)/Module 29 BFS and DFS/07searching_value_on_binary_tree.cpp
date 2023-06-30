#include<bits/stdc++.h>
using namespace std;
class node
{
public:

    int node_id;
    int value;
    node *left_side;
    node *right_side;
    node *parent;

};

class binary_tree
{

public:
    node *head;
    node *allnode[6];
    // constructor
    binary_tree()
    {
        head = NULL;
    }

    node *create_new_node(int id, int value)
    {
        node *Newnode = new node;

        Newnode->node_id = id;
        Newnode->value = value;
        Newnode->left_side = NULL;
        Newnode->right_side = NULL;
        Newnode->parent = NULL;

        return Newnode;
    }

    void insert_value(int id, int value)
    {
        node *newnode = create_new_node(id, value);

        // corner case
        if(head == NULL)
        {
            head = newnode;
            return;
        }

        // start BFS visit
        queue<node*>q;
        q.push(head);

        while(!q.empty())
        {
            node *tmp = q.front();
            q.pop();

            if(tmp->left_side != NULL)
            {
                q.push(tmp->left_side);

            }
            else
            {   // insert in left chilled of node
                tmp->left_side = newnode;
                newnode->parent = tmp;
                return;
            }
            if(tmp->right_side != NULL)
            {
                q.push(tmp->right_side);
            }
            else
            {   // insert in right chilled of node
                tmp->right_side = newnode;
                newnode->parent = tmp;
                return;
            }
        }

    }

    void DFS_postorder(node *tmp)
    {
        if(tmp == NULL)
            return;

        DFS_postorder(tmp->left_side);
        DFS_postorder(tmp->right_side);
        cout<<tmp->node_id<<" ";

    }

    void BFS()
    {
        // corner case
        if(head == NULL)
            return;

        queue<node*>q;

        q.push(head);

        while(!q.empty())
        {
            node *tmp = q.front();
            q.pop();

            int p = -1, l = -1,  r = -1;

            if(tmp->left_side != NULL)
            {
                l = tmp->left_side->node_id;
                q.push(tmp->left_side);
            }
            if(tmp->right_side != NULL)
            {
                r = tmp->right_side->node_id;
                q.push(tmp->right_side);
            }
            if(tmp->parent != NULL)
                p = tmp->parent->node_id;

            cout<<"node id = "<<tmp->node_id<<" left child : "<<l<<" right chiled : "<<r<<" parent : "<<p<<"\n";
        }
    }

    // DFS Search
    void Search(node *tmp, int value)
    {
        // corner case
        if(tmp == NULL)
            return;

        if(tmp->value == value)
        {
            cout<<tmp->node_id<<" ";
        }
        // recursivly call.
        Search(tmp->left_side, value);
        Search(tmp->right_side, value);

    }


};
int main()
{
    binary_tree bt;

    bt.insert_value(0, 5);
    bt.insert_value(1, 10);
    bt.insert_value(2, 10);
    bt.insert_value(3, 9);
    bt.insert_value(4, 8);
    bt.insert_value(5, 5);
    bt.insert_value(6, 7);

    bt.BFS();

    cout<<"\n";
    bt.Search(bt.head, 5);

     cout<<"\n";
    bt.Search(bt.head, 10);

    cout<<"\n";
    bt.Search(bt.head, 9);




    return 0;
}






