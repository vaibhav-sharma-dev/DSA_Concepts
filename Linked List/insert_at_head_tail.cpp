#include <iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node (int item)
    {
        data = item;
        next = NULL;
    }
};

void insert_at_tail(node * &head, int item)
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

void insert_at_head(node * &head, int head_val)
{
    node *n = new node(head_val);

    n->next = head;
    head = n;
}

int main()
{
    node *head = NULL;

    int size;
    cin >> size;

    for (int i=1; i<=size; i++)
        insert_at_tail(head, i);

    int head_val;
    cin >> head_val;

    insert_at_head(head, head_val);

    while (head!=NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}