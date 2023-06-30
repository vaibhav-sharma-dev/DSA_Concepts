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


bool check_bst(node *root, node* max=NULL, node* min=NULL)
{
    if (root==nullptr)
        return true;

    if (min!=nullptr && root->data<=min->data)
        return false;

    if (max!=nullptr && root->data>=max->data)
        return false;

    if (check_bst(root->left, root, min) && check_bst(root->right, max, root))
        return true;

    else
        return false;
}


int main()
{
    node *root = new node (1);
    root->left = new node (0);
    root->right = new node(3);

    cout << check_bst(root, NULL, NULL);
}