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


node *lowest_common_node (node *root, int n1, int n2)
{
    if (root==nullptr)
        return nullptr;

    if (root->data==n1 || root->data==n2)
        return root;

    node* left_node = lowest_common_node(root->left, n1, n2);
    node* right_node = lowest_common_node(root->right, n1, n2);

    if (left_node!=nullptr && right_node!=nullptr)
        return root;

    if (left_node==nullptr && right_node==nullptr)
        return nullptr;

    if (left_node!=nullptr)
        return lowest_common_node(root->left, n1, n2);

    return lowest_common_node(root->right, n1, n2);
}


int find_distance(node* root, int n, int distance)
{
    if (root==nullptr)
        return -1;

    if (root->data==n)
        return distance;

    int left = find_distance(root->left, n, distance+1);

    if (left!=-1)
        return left;

    return find_distance(root->right, n, distance+1);
}


int distance_bw_nodes(node* root, int n1, int n2)
{
    node *least_common_node = lowest_common_node(root, n1, n2);

    if (least_common_node==nullptr)
        return 0;

    int left_distance = find_distance(least_common_node, n1, 0);
    int right_distance = find_distance(least_common_node, n2, 0);

    return left_distance+right_distance;
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

    cout << distance_bw_nodes(root, 4, 7);
}