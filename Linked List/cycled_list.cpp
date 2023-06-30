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

void create_cycle(node * &head, int pos)
{
    int ctr = 1;
    node *temp = head;
    node *cycle_node;

    while (temp->next!=NULL)
    {
        if (ctr==pos)
            cycle_node = temp;

        temp = temp->next;
        ctr++;
    }

    temp->next = cycle_node;
}

bool detect_cycle(node *head)
{
    node *fast = head;
    node *slow = head;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast==slow)
            return true;
    }

    return false;
}

void remove_cycle(node *&head)
{
    node *fast = head;
    node *slow = head;

    while (fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast==slow)
        {
            fast = head;
            break;
        }
    }

    while (fast->next!=slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    slow->next = NULL;
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

    create_cycle(head, pos);

    if (detect_cycle(head))
        remove_cycle(head);

    display_list(head);
}
