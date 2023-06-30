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

bool balanced_height(node *root, int *height)
{
    if (root==nullptr)
        return true;

    int left_ht = 0;
    int right_ht = 0;

    if (balanced_height(root->left, &left_ht)==false)
        return false;

    if (balanced_height(root->right, &right_ht)==false)
        return false;

    *height = max(left_ht, right_ht) + 1;

    if (abs(left_ht-right_ht)<=1)
        return true;

    return false;
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
    //root->right->right->right = new node(8);
    //root->right->right->right->right = new node(9);

    int height = 0;
    cout << balanced_height(root, &height);
}