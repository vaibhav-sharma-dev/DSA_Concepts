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

void preorder_travel(node *root)
{
    if (root==nullptr)
        return;

    cout << root->data << " ";

    preorder_travel(root->left);
    preorder_travel(root->right);
}

void inorder_travel(node *root)
{
    if (root==nullptr)
        return;

    inorder_travel(root->left);
    cout << root->data << " ";
    inorder_travel(root->right);
}

void postorder_travel(node *root)
{
    if (root==nullptr)
        return;

    postorder_travel(root->left);
    postorder_travel(root->right);
    cout << root->data << " ";
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

    preorder_travel(root);
    cout << endl;
    inorder_travel(root);
    cout << endl;
    postorder_travel(root);
}