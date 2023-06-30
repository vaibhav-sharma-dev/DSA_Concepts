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

void level_order_traverse(node *root)
{
    if (root==nullptr)
        return;
        
    queue<node*> q;
    q.push(root);
    q.push(nullptr);

    while(!q.empty())
    {
        node *n = q.front();
        q.pop();

        if (n!=nullptr)
        {
            cout << n->data << " ";

            if (n->left!=nullptr)
                q.push(n->left);

            if (n->right!=nullptr)
                q.push(n->right);
        }

        else if (!q.empty())
            q.push(nullptr);
    }

}

int sum_k_level(node *root, int key)
{
    if (root==nullptr)
        return -1;

    queue<node *> q_sum;
    q_sum.push(root);
    q_sum.push(nullptr);

    int level = 0;
    int sum = 0;

    while (!q_sum.empty())
    {
        node *n = q_sum.front();
        q_sum.pop();

        if (n!=nullptr)
        {
            if (level==key)
                sum = sum + n->data;

            if (n->left!=nullptr)
                q_sum.push(n->left);

            if (n->right!=nullptr)
                q_sum.push(n->right);
        }

        else if (!q_sum.empty())
        {
            level++;
            q_sum.push(nullptr);
        }
    }

    return sum;
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

    level_order_traverse(root);
    cout << endl;

    cout << sum_k_level(root, 2);
}