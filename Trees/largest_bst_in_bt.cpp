#include <iostream>
#include <climits>

using namespace std;

struct node
{
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

struct node_info
{
    int max;
    int min;
    int size;
    int ans;
    bool is_bst;
};


node_info largest_bst_in_bt (node *root)
{
    if (root==nullptr)
        return {INT_MIN, INT_MAX, 0, 0, true};

    if (root->left==nullptr && root->right==nullptr)
        return {root->data, root->data, 1, 1, true};

    node_info left_info = largest_bst_in_bt(root->left);
    node_info right_info = largest_bst_in_bt(root->right);

    node_info curr_info;
    curr_info.size = 1 + left_info.size + right_info.size;

    if (left_info.max<root->data && right_info.min>root->data && left_info.is_bst && right_info.is_bst)
    {
        curr_info.max = max(right_info.max, max(root->data, left_info.max));
        curr_info.min = min(left_info.min, min(root->data, right_info.min));
        curr_info.ans = curr_info.size;
        curr_info.is_bst = true;

        return curr_info;
    }

    curr_info.ans = max(left_info.ans, right_info.ans);
    curr_info.is_bst = false;

    return curr_info;
}


int main()
{
    node *root = new node(15);
    root->left = new node(20);
    root->right = new node(30);
    root->left->left = new node(5);

    cout << largest_bst_in_bt(root).ans;
}