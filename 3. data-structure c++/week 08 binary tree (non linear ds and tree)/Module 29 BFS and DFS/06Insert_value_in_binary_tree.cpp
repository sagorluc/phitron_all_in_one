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
    // constructor
    binary_tree()
    {
        head = NULL;
    }

    node *create_new_node(int id)
    {
        node *Newnode = new node;

        Newnode->node_id = id;
        Newnode->left_side = NULL;
        Newnode->right_side = NULL;
        Newnode->parent = NULL;

        return Newnode;
    }

    void insert_value(int value)
    {
        node *newnode = create_new_node(value);

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


};
int main()
{
    binary_tree bt;

    bt.insert_value(0);
    bt.insert_value(1);
    bt.insert_value(2);
    bt.insert_value(3);
    bt.insert_value(4);
    bt.insert_value(5);
    bt.BFS();




    return 0;
}





