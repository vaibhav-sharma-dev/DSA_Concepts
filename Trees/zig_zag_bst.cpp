#include<iostream>
#include<stack>

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


void zig_zag_traverse(node *root)
{
    if (root!=nullptr)
    {
        stack<node*> curr_level;
        stack<node*> next_level;
        bool left_to_right = true;

        curr_level.push(root);

        while (!curr_level.empty())
        {
            node *temp = curr_level.top();
            curr_level.pop();

            if (temp)
            {
                cout << temp->data << " ";

                if (left_to_right)
                {   
                    if (temp->left)
                        next_level.push(temp->left);

                    if (temp->right)
                        next_level.push(temp->right);
                }

                else
                {
                    if (temp->right)
                        next_level.push(temp->right);

                    if (temp->left)
                        next_level.push(temp->left);
                }
            }
            if (curr_level.empty())
            {
                left_to_right = !left_to_right;
                swap(curr_level, next_level);
            }
        }
    }
}


int main()
{
    node* root = new node(12);

    root->left = new node(9);
    root->right = new node(15);

    root->left->left = new node(5);
    root->left->right = new node(10);

    zig_zag_traverse(root);
}