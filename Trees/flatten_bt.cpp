#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node* left;
    node* right;

    node (int val)
    {
        data = val;
        left = NULL;
        right = nullptr;
    }
};


void flatten_tree(node * &root)
{
    node* n = root;

    if (n->left!=nullptr)
    {
        flatten_tree(root->left);
        flatten_tree(root->right);

        node *temp = root->left;
        while (temp->right!=nullptr)
            temp = temp->right;

        temp->right = n->right;
        n->right = n->left;
        n->left = nullptr;

        n = n->right;
    }
}


int main()
{
    node* root = new node(1);

    root->left = new node(2);
    root->right = new node(3);

    root->left->left = new node(4);
    root->left->right = new node(5);

    root->right->left = new node(6);
    root->right->right = new node(7);

    flatten_tree(root);
    while (root!=nullptr)
    {
        cout << root->data << " ";
        root = root->right;
    }
}