#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    node *left;
    node *right;

};

class binary_search_tree
{

public:

    node *head;

    binary_search_tree()
    {
        head = NULL;

    }

    node *create_new_node(int value)
    {
        node *newnode = new node;

        newnode->value = value;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
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

            int l = -1;
            int r = -1;

            if(tmp->left != NULL)
            {
                l = tmp->left->value;
                q.push(tmp->left);
            }
            if(tmp->right != NULL)
            {
                r = tmp->right->value;
                q.push(tmp->right);
            }

            cout<<"node : "<<tmp->value<<" left-side : "<<l<<" right-side : "<<r<<"\n";

        }
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

        node *current = head; // current node;
        node *previus = NULL; // parent node;

        while(current != NULL)
        {
            // newnode is grater then current node then insert value at right side;
            if(newnode->value > current->value)
            {
                previus = current;
                current = current->right;
            }
            // other wise insert at left side;
            else
            {
                previus = current;
                current = current->left;
            }

        }
        // compare agein.newnode value jodi previus or parent value grater then hoy tahole right side e insert hobe.
        if(newnode->value > previus->value)
        {
            previus->right = newnode;
        }
        // other wise left side insert hobe.
        else
        {
            previus->left = newnode;
        }
    }

    // searching value in binary tree.
    bool Searching(int value)
    {
        node *tmp = head;

        while(tmp != NULL)
        {
            if(value > tmp->value)
            {
                tmp = tmp->right;
            }
            else if(value < tmp->value)
            {
                tmp = tmp->left;
            }
            else
            {
                return true;
            }
        }
        return false;

    }

    void delete_value(int value)
    {
        node *current = head;
        node *previus = NULL;

        while(current != NULL)
        {
            if(value > current->value)
            {
                previus = current;
                current = current->right;
            }
            else if(value < current->value)
            {
                previus = current;
                current = current->left;
            }
            else
            {
                break;
            }
        }
        // currrent null hole not fuond anything.
        if(current == NULL)
        {
            cout<< "value not found \n";
            return;
        }
        // case 1: both chilled is NULL;
        if(current->left == NULL && current->right == NULL)
        {
            if(previus->left != NULL && previus->left->value == current->value)
            {
                previus->left = NULL;
            }
            else
            {
                previus->right = NULL;
            }
            delete current;
            return;
        }

        // case 2: if the node has only one chilled.
        if(current->left == NULL && current->right != NULL)
        {
            if(previus->left != NULL && previus->left->value == current->value)
            {
                previus->left = current->right;
            }
            else
            {
                previus->right = current->right;
            }
            delete current;
            return;
        }

        if(current->left != NULL && current->right == NULL)
        {
            if(previus->left != NULL && current->left->value == current->value)
            {
                previus->left = current->left;
            }
            else
            {
                previus->right = current->left;
            }
            delete current;
            return;
        }




    }


};
int main()
{
    binary_search_tree bst;

    bst.insert_value(6);
    bst.insert_value(4);
    bst.insert_value(3);
    bst.insert_value(5);
    bst.insert_value(7);
    bst.insert_value(8);

    // case 1;
//    bst.delete_value(8);
//    bst.BFS_traversal();

    // case 2;
    bst.delete_value(3);
    bst.BFS_traversal();

    cout<<bst.Searching(8);


    return 0;
}



