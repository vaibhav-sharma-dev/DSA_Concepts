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


bool identical_bst(node *root1, node *root2)
{
    if (root1==nullptr && root2==nullptr)
        return true;

    if (root1==nullptr || root2==nullptr)
        return false;

    bool con_1 = root1->data == root2->data;
    bool con_2 = identical_bst(root1->left, root2->left);
    bool con_3 = identical_bst(root1->right, root2->right);

    if (con_1 && con_2 && con_3)
        return true;

    return false;
}


int main()
{
    node* root1 = new node(12);

    root1->left = new node(9);
    root1->right = new node(15);

    root1->left->left = new node(5);
    root1->left->right = new node(10);
    
    node* root2 = new node(12);

    root2->left = new node(9);
    root2->right = new node(15);

    root2->left->left = new node(5);
    root2->left->right = new node(11);

    if (identical_bst(root1, root2))
        cout << true;

    else cout << false;

}