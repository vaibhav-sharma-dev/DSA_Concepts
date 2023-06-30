#include <iostream>
using namespace std;

class node
{
    public:
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


node * build_bst(node *root, int val)
{
    if (root==nullptr)
        return new node(val);

    if (val<root->data)
        root->left = build_bst(root->left, val);

    else
        root->right = build_bst(root->right, val);

    return root;
}


node *search_bst(node* root, int val)
{
    if (root==nullptr)
        return nullptr;

    if (root->data==val)
        return root;

    if (val<root->data)
        return search_bst(root->left, val);

    return search_bst(root->right, val);
}


node * inorder_successor(node *root)
{
    node *current = root;
    while (current!=nullptr && current->left!=nullptr)
        current = current->left;

    return current;
}


node *delete_bst(node *root, int key)
{
    if (root->data>key)
        root->left = delete_bst(root->left, key);

    else if (root->data<key)
        root->right = delete_bst(root->right, key);

    else 
    {
        if (root->left==nullptr)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right==nullptr)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = inorder_successor(root->right);
        root->data = temp->data;
        root->right = delete_bst(root->right, temp->data);
    }

    return root;
}


void inorder_travel(node *root)
{
    if (root==nullptr)
        return;

    inorder_travel(root->left);
    cout << root->data << " ";
    inorder_travel(root->right);
}


int main()
{
    node *root = nullptr;

    int bst_arr[] = {4, 2, 5, 1, 3, 6};
    for (int i=0; i<6; i++)
        root = build_bst(root, bst_arr[i]);

    // root = build_bst(root, 4);
    // build_bst(root, 2);
    // build_bst(root, 5);
    // build_bst(root, 1);
    // build_bst(root, 3);
    // build_bst(root, 6);

    int key = 5;
    node *key_address = search_bst(root, key);
    cout << key_address->data << endl;

    inorder_travel(root);
    cout << endl;
    delete_bst(root, key);
    inorder_travel(root);

}