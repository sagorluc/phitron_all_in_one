#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int node_id;
    node *left_side;
    node *right_side;
    node *parent;

};
class binary_tree
{

public:

    node *head;

    //constructor
    binary_tree()
    {
        head = NULL;
    }

    node *create_new_node(int id)
    {
        node *newnode = new node;

        newnode->node_id = id;
        newnode->left_side = NULL;
        newnode->right_side = NULL;
        newnode->parent = NULL;

        return newnode;
    }

    void insert_id(int id)
    {
        node *newnode = create_new_node(id);

        if(head == NULL)
        {
            head = newnode;
            return;
        }

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
            {
                tmp->left_side = newnode;
                newnode->parent = tmp;
                return;
            }
            if(tmp->right_side != NULL)
            {
                q.push(tmp->right_side);
            }
            else
            {
                tmp->right_side = newnode;
                newnode->parent = tmp;
                return;
            }

        }

    }
    // bfs travers
    void BFS_traversal()
    {
        if(head == NULL)
            return;

        queue<node*> q;
        q.push(head);

        while(!q.empty())
        {
            node *tmp = q.front();
            q.pop();

            int p = -1;
            int l = -1;
            int r = -1;

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

            cout<<"node : "<<tmp->node_id<<" left-side : "<<l<<" right-side : "<<r<<"\n";

        }
    }


};
int main()
{
    binary_tree bt;

    bt.insert_id(0);
    bt.insert_id(1);
    bt.insert_id(2);
    bt.insert_id(3);
    bt.BFS_traversal();



    return 0;
}
