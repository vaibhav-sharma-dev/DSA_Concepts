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


node * bst_from_preorder(int pre_order_arr[], int size, int key, int *pre_order_idx, int max, int min)
{
    if (*pre_order_idx>=size)
        return nullptr;

    node *root = nullptr;

    if (key>min && key<max)
    {
        root = new node(key);
        *pre_order_idx = *pre_order_idx + 1;
    

        if (*pre_order_idx<size)
            root->left = bst_from_preorder(pre_order_arr, size, pre_order_arr[*pre_order_idx], pre_order_idx, key, min);

        if (*pre_order_idx<size)
            root->right = bst_from_preorder(pre_order_arr, size, pre_order_arr[*pre_order_idx], pre_order_idx, max, key);
    }
    
    return root;
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
    int pre_order_arr[] = {10, 2, 1, 13, 11};
    int pre_order_idx = 0;
    
    node *root = bst_from_preorder(pre_order_arr, 5, pre_order_arr[0], &pre_order_idx, INT_MAX, INT_MIN);
    preorder_travel(root);
}