#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node(int item)
    {
        data = item;
        next = NULL;
    }
};

void create_list(node * &head, int item)
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

void append_k_nodes (node * &head, int size, int pos)
{
    node *tail = head;
    node *new_head;
    node *new_tail;

    int ctr = 1;

    while (tail->next!=NULL)
    {
        if (ctr==size-pos)
            new_tail = tail;

        if (ctr==size-pos+1)
            new_head = tail;

        tail = tail->next;
        ctr++;
    }

    new_tail->next = NULL;
    tail->next = head;
    head = new_head;
}

void display_list(node *head)
{
    while (head!=NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;

    int size;
    cin >> size;

    for (int i=1; i<=size; i++)
        create_list(head, i);

    int pos;
    cin >> pos;

    append_k_nodes(head, size, pos);

    display_list(head);
}