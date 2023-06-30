#include<bits/stdc++.h>
using namespace std;
class node
{
public:
    int value;
    node *Left;
    node *Right;

};

class binary_search_tree
{
public:
    node *head;

    // constructor
    binary_search_tree()
    {
        head = NULL;
    }

    node *createnewnode(int value)
    {
        node *newnode = new node;

        newnode->value = value;
        newnode->Left = NULL;
        newnode->Right = NULL;

        return newnode;
    }

    void insert_value(int value)
    {
        node *newnode = createnewnode(value);

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
                current = current->Right;
            }
            // other wise insert at left side;
            else
            {
                previus = current;
                current = current->Left;
            }

        }
        // compare agein.newnode value jodi previus or parent value grater then hoy tahole right side e insert hobe.
        if(newnode->value > previus->value)
        {
            previus->Right = newnode;
        }
        // other wise left side insert hobe.
        else
        {
            previus->Left = newnode;
        }
    }

    //delete value on binary search tree. time complexity- O(height) or O(h)
    void delete_value(int value)
    {
        node *current = head;
        node *previus = NULL;

        while(current != NULL)
        {
            if(value > current->value)
            {
                previus = current;
                current = current->Right;
            }
            else if(value < current->value)
            {
                previus = current;
                current = current->Left;
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
        if(current->Left == NULL && current->Right == NULL)
        {
            if(previus->Left != NULL && previus->Left->value == current->value)
            {
                previus->Left = NULL;
            }
            else
            {
                previus->Right = NULL;
            }
            delete current;
            return;
        }

        // case 2: if the node has only one chilled.
        if(current->Left == NULL && current->Right != NULL)
        {
            if(previus->Left != NULL && previus->Left->value == current->value)
            {
                previus->Left = current->Right;
            }
            else
            {
                previus->Right = current->Right;
            }
            delete current;
            return;
        }

        if(current->Left != NULL && current->Right == NULL)
        {
            if(previus->Left != NULL && previus->Left->value == current->value)
            {
                previus->Left = current->Left;
            }
            else
            {
                previus->Right = current->Left;
            }
            delete current;
            return;
        }

        // case 3: node has tow chilled .

        node *tmp = current->Right;
        while(tmp->Left != NULL)
        {
            tmp = tmp->Left;

        }
        int saved = tmp->value;
        delete_value(saved);
        current->value = saved;

    }

// searching value in binary tree.
    bool Searching(int value)
    {
        node *tmp = head;

        while(tmp != NULL)
        {
            if(value > tmp->value)
            {
                tmp = tmp->Right;
            }
            else if(value < tmp->value)
            {
                tmp = tmp->Left;
            }
            else
            {
                return true;
            }
        }
        return false;

    }

    // dfs traversal
    void DFS_Inorder(node *tmp)
    {
        if(tmp == NULL)
            return;

        DFS_Inorder(tmp->Left);
        cout<<tmp->value<<" ";
        DFS_Inorder(tmp->Right);

    }

    // find maximum value on binary search tree
    int find_maximum_value(node *root)
    {
        node *current = root;

        while(current->Right != NULL)
        {
           current = current->Right;
        }

        return current->value;
    }

    // find minimum value on binary tree.
    int find_minimum_value(node *root)
    {
        node *current = root;

        while(current->Left != NULL)
        {
            current = current->Left;

        }

        return current->value;
    }

    int check_valid_bst(node *root)
    {


        if( root == NULL)
            return true;

        if(root->Left != NULL && find_maximum_value(root->Left) > root->value)
            return false;
        if(root->Right != NULL && find_minimum_value(root->Right) < root->value)
            return false;
        if(check_valid_bst(root->Left) && check_valid_bst(root->Right))
            return true;

        return false;

    }

};
int main()
{
    binary_search_tree bt;

    bt.insert_value(6);
    bt.insert_value(4);
    bt.insert_value(3);
    bt.insert_value(5);
    bt.insert_value(7);
    bt.insert_value(8);
    bt.insert_value(9);
    bt.DFS_Inorder(bt.head);

    cout<<"\n";

    bt.delete_value(6);
    bt.DFS_Inorder(bt.head);

    cout<<"\nsearching value : "<<bt.Searching(0);

    cout<<"\nthe maximum value is : "<<bt.find_maximum_value(bt.head);

    cout<<"\nthe minimum value is : "<<bt.find_minimum_value(bt.head);

    cout<<"\nis valid : "<<bt.check_valid_bst(bt.head);



    return 0;
}



