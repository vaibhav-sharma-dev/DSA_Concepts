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


node * build_bst(int arr[], int start, int end)
{
    if (start>end)
        return nullptr;

    int mid = (start+end)/2;
    node *n = new node(arr[mid]);

    n->left = build_bst(arr, start, mid-1);
    n->right = build_bst(arr, mid+1, end);

    return n;
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
    int arr[] = {1, 2, 3, 4, 5};
    node * root = build_bst(arr, 0, 4);

    preorder_travel(root);
}