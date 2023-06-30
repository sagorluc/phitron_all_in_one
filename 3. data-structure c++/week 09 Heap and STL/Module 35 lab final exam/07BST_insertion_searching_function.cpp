#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int value;
    node* Left;
    node* Right;
};


class BST
{
public:
    node *root;
    BST()
    {
        //Write your code here
        root = NULL;
    }

    node *creat_new_node(int value)
    {
        node *newnode = new node;

        newnode->value = value;
        newnode->Left = NULL;
        newnode->Right = NULL;

        return newnode;
    }

    void Insert(int value)
    {
        //Write your code here
        node *newnode = creat_new_node(value);

        if(root == NULL)
        {
            root = newnode;
            return;
        }

        node *current = root;
        node *previus = NULL;

        if(newnode->value > current->value)
        {
            previus = current;
            current = current->Right;
        }
        else
        {
            previus = current;
            current = current->Left;
        }

        if(newnode->value > previus->value)
            previus->Right = newnode;
        else
            previus->Left = newnode;
    }

    bool Search(int value)
    {
        node *tmp = root;

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

    // DFS inorder traverse
    void DFS_travers(node *tmp)
    {
        if(tmp == NULL)
            return;

        DFS_travers(tmp->Left);
        cout<<tmp->value<<" ";
        DFS_travers(tmp->Right);
    }

    // BFS travers
    void BFS_traversal()
    {
        if(root == NULL)
            return;

        queue<node*> q;
        q.push(root);

        while(!q.empty())
        {
            node *tmp = q.front();
            q.pop();

            int l = -1;
            int r = -1;

            if(tmp->Left != NULL)
            {
                l = tmp->Left->value;
                q.push(tmp->Left);
            }
            if(tmp->Right != NULL)
            {
                r = tmp->Right->value;
                q.push(tmp->Right);
            }

            cout<<"node : "<<tmp->value<<" left-side : "<<l<<" right-side : "<<r<<"\n";

        }
    }
};
int main()
{
    BST bst;
    bst.Insert(10);
    bst.Insert(20);
    bst.Insert(25);
    bst.Insert(50);
    bst.Insert(8);
    bst.Insert(9);

    cout<<"DFS visit : ";
    bst.DFS_travers(bst.root);

    cout<<"\n";

    bst.BFS_traversal();

    cout<<bst.Search(10)<<"\n"; //1
    cout<<bst.Search(9)<<"\n"; //1
    cout<<bst.Search(20)<<"\n"; //0
    cout<<bst.Search(60)<<"\n"; //0

    return 0;
}
