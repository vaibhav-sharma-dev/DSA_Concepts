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

node * reverse_list(node * &head)
{
    node *prev = NULL;
    node *curr = head;
    node *next_e;

    while (curr!=NULL)
    {
        next_e = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next_e;
    }

    head = prev;

    return head;
}

int main()
{
    node *head = NULL;
    
    int size;
    cin >> size;

    for (int i=1; i<=size; i++)
        create_node(head, i);

    node * result = reverse_list(head);

    while (head!=NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}