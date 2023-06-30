#include <iostream>
using namespace std;


struct node 
{
    int data;
    node *left;
    node *right;

    node (int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calc_pointers(node *root, node **first, node **next, node **last, node **temp)
{
    if (root==nullptr)
        return;
    
    calc_pointers(root->left, first, next, last, temp);

    if (*temp && root->data<(*temp)->data)
    {
        if (!*first)
        {
            *first = *temp;
            *next = root;
        }

        else 
            *last = root;
    }

    *temp = root;
    calc_pointers(root->right, first, next, last, temp);
}


void restore_bst(node *root)
{
    node *first = nullptr;
    node *next = nullptr;
    node *last = nullptr;
    node *temp = nullptr;

    calc_pointers(root, &first, &next, &last, &temp);

    if (first && last)
        swap (&(first->data), &(last->data));

    else if (first && next)
        swap (&(first->data), &(next->data));
}


void inorder_traverse(node *root)
{
    if (root==nullptr)
        return;

    inorder_traverse(root->left);
    cout << root->data << " ";
    inorder_traverse(root->right);
}


int main()
{
    node *root = new node(6);
    root->left = new node(9);

    root->left->left = new node(1);
    root->left->right = new node(4);

    root->right = new node(3);
    root->right->right = new node(13);

    inorder_traverse(root);
    cout << endl;

    restore_bst(root);
    inorder_traverse(root);
}
