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
    node *allnode[6];
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

    void insert_id(int id)
    {
        node *newnode = create_new_node(id);

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
            {
                // insert in left chilled of node
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
                // insert in right chilled of node
                tmp->right_side = newnode;
                newnode->parent = tmp;
                return;
            }
        }

    }

    void DFS_preorder(node *tmp)
    {
        if(tmp == NULL)
            return;

        cout<<tmp->node_id<<" ";
        DFS_preorder(tmp->left_side);
        DFS_preorder(tmp->right_side);

    }
};
int main()
{
    binary_tree bt;

    bt.insert_id(0);
    bt.insert_id(1);
    bt.insert_id(2);
    bt.insert_id(3);
    bt.insert_id(4);
    bt.DFS_preorder(bt.head);

    return 0;
}




