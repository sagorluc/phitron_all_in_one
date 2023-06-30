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

    // DFS inorder travers.
    void DFS_inorder(node *tmp)
    {
        if(tmp == NULL)
            return;

        DFS_inorder(tmp->left_side);
        cout<<tmp->node_id<<" ";
        DFS_inorder(tmp->right_side);
    }

//    // count total node of binary tree.
//    int count_total_node(node *root)
//    {
//        if(root == NULL)
//            return 0;
//
//        return (count_total_node(root->left_side) + count_total_node(root->right_side) + 1);
//    }
//
//    // check is this the complate binary tree.
//    bool complate_binary_tree(node *root,int index, int number_node )
//    {
//        if(root == NULL)
//            return true;
//
//        if(index >= number_node)
//            return false;
//
//        return(complate_binary_tree(root->left_side, 2 * index + 1, number_node) && complate_binary_tree(root->right_side, 2 * index + 1, number_node));
//
//    }

    bool isCompleteBinaryTree(node* root)
    {
        if (root == NULL)
        {
            return true;
        }

        queue<node*> q;
        q.push(root);

        bool has_one_child = false;

        while (!q.empty())
        {
            node* curr = q.front();
            q.pop();


            if (curr->left_side) // (curr->Left!=NULL) একই  বুঝাই
            {
                if (has_one_child)
                {
                    return false;
                }
                q.push(curr->left_side);
            }
            else
            {
                has_one_child = true;
            }

            if (curr->right_side) // (curr->Right!=NULL) একই  বুঝাই
            {
                if (has_one_child)
                {
                    return false;
                }
                q.push(curr->right_side);
            }
            else
            {
                has_one_child = true;
            }
        }

        return true;
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
    bt.insert_id(5);
    bt.DFS_inorder(bt.head);

    cout<<"\ncomplate : "<<bt.isCompleteBinaryTree(bt.head);



    return 0;
}



