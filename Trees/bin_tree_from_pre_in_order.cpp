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

int search(int in_order[], int start, int end, int key)
{
    for (int i=start; i<=end; i++)
    {
        if (in_order[i]==key)
            return i;
    }

    return -1;
}

node * build_tree(int pre_order[], int in_order[], int in_start, int in_end)
{
    static int idx = 0;

    if (in_start>in_end)
        return nullptr;

    int curr_val = pre_order[idx];
    node *n = new node(curr_val);

    idx++;

    if (in_start==in_end)
        return n;
    
    int curr_idx = search(in_order, in_start, in_end, curr_val);

    n->left = build_tree(pre_order, in_order, in_start, curr_idx-1);
    n->right = build_tree(pre_order, in_order, curr_idx+1, in_end);

    return n;
    
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
    int pre_order[] = {1, 2, 4, 3, 5};
    int in_order[] = {4, 2, 1, 5, 3};

    node *root = build_tree(pre_order, in_order, 0, 4);
    inorder_travel(root);
}