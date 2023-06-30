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

    void built_binary_tree()
    {
        //node *allnode[6]; // 6 size er ekta binary tree bulit korbo.

        for(int i=0; i<6; i++)
            allnode[i] = create_new_node(i);

        allnode[0]->left_side = allnode[1];
        allnode[0]->right_side = allnode[2];

        allnode[1]->left_side = allnode[5];
        allnode[1]->parent = allnode[0];

        allnode[2]->left_side = allnode[3];
        allnode[2]->right_side = allnode[4];
        allnode[2]->parent = allnode[0];

        allnode[5]->parent = allnode[1];

        allnode[3]->parent = allnode[2];
        allnode[4]->parent = allnode[2];

        head = allnode[0]; // head/root ke 0 te point kora holo

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

    bt.built_binary_tree();
    bt.DFS_preorder(bt.head);

    return 0;
}



