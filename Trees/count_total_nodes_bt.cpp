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

int total_nodes(node* root)
{
    if (root==nullptr)
        return 0;
    return total_nodes(root->left) + total_nodes(root->right) + 1;
    return total_nodes(root->left) + total_nodes(root->right) + root->data;
}

int max_height(node* root)
{
    if (root==nullptr)
        return 0;

    int l_height = max_height(root->left) + 1;
    int r_height = max_height(root->right) + 1;

    return max(l_height, r_height);
}

int max_diameter(node *root, int* height)
{
    if (root==nullptr)
    {
        *height = 0;
        return 0;
    }

    int left_ht = 0;
    int right_ht = 0;

    int left_dm = max_diameter(root->left, &left_ht);
    int right_dm = max_diameter(root->right, &right_ht);
    
    int curr_dm = left_ht + right_ht + 1;
    *height = max(left_ht, right_ht) + 1;

    return max(curr_dm, max(left_dm, right_dm));
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

    cout << total_nodes(root) << endl;
    cout << max_height(root) << endl;

    int height = 0;
    cout << max_diameter(root, &height);
}
