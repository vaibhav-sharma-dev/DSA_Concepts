#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node * next;

    node (int item)
    {
        data = item;
        next = NULL;
    }
};

void create_node(node * &head, int item)
{
    node *n = new node(item);

    if (head==NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next!=NULL)
        temp = temp->next;

    temp->next = n;
}

node *reverse_k_nodes(node * &head, int key)
{
    node *prev = NULL;
    node *curr = head;
    node *next_e;
    int ctr = 0;

    while (curr!=NULL && ctr<key)
    {
        next_e = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_e;
        ctr++;
    }

    if (next_e!=NULL)
        head->next = reverse_k_nodes(next_e, key);
        
    return prev;
}

int main()
{
    node *head = NULL;
    
    int size;
    cin >> size;

    for (int i=1; i<=size; i++)
        create_node(head, i);

    int key;
    cin >> key;

    node *new_head = reverse_k_nodes(head, key);

    while (new_head!=NULL)
    {
        cout << new_head->data << "->";
        new_head = new_head->next;
    }
    cout << "NULL" << endl;
}