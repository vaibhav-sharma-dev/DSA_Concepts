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

void right_view(node *root)
{
    if (root==nullptr)
        return;

    queue<node*> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();

        for (int i=0; i<size; i++)
        {
            node *curr = q.front();
            q.pop();

            if (i==0)
                cout << curr->data << " ";

            if (curr->left!=nullptr)
                q.push(curr->left);

            if (curr->right!=nullptr)
                q.push(curr->right);
        }
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

    right_view(root);
}