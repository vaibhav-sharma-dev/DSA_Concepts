#include<iostream>
#include<queue>

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

void sum_replacement(node * &root)
{
    if (root==nullptr)
        return;

    sum_replacement(root->left); 
    sum_replacement(root->right);

    if (root->left!=NULL)
        root->data = root->data + root->left->data;

    if (root->right!=NULL)
        root->data = root->data + root->right->data;
}

void preorder_travel(node *root)
{
    if (root==nullptr)
        return;

    cout << root->data << " ";

    preorder_travel(root->left);
    preorder_travel(root->right);
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

    sum_replacement(root);
    preorder_travel(root);
}