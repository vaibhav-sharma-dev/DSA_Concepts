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


void nodes_in_subtree(node *root, int k)
{
    if (root==nullptr || k<0)
    {
        cout << root->data << " ";
        return;
    }

    nodes_in_subtree(root->left, k-1);
    nodes_in_subtree(root->right, k-1);
}


int nodes_k_distance(node *root, node* n, int k)
{
    if (root==nullptr)
        return -1;

    if (root==n)
    {
        nodes_in_subtree(root, k);
        return 0;
    }

    int left_d = nodes_k_distance(root->left, n, k);
    if (left_d!=-1)
    {
        
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
}