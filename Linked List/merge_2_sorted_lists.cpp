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

//1 4 5 7 8 9
//2 3 6

node *merge_sorted_list(node * &head1, node * &head2)
{
    node *new_head = new node(-1);
    node *temp = new_head;

    while (head1!=NULL && head2!=NULL)
    {
        if (head1->data<=head2->data)
        {
            temp->next = head1;
            head1 = head1->next;
        }

        else if (head1->data>head2->data)
        {
            temp->next = head2;
            head2 = head2->next;
        }

        temp = temp->next;
    }

    if (head1==NULL)
        temp->next = head2;

    else if (head2==NULL)
        temp->next = head1;

    return new_head->next;
}

node * merge_recursive(node * &head1, node * &head2)
{
    if (head1==NULL)
        return head2;

    if (head2==NULL)
        return head1;

    node *result;

    if (head1->data<head2->data)
    {
        result = head1;
        result->next = merge_recursive(head1->next, head2);
    }

    else    
    {
        result = head2;
        result->next = merge_recursive(head1, head2->next);
    }

    return result;
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
    node *head1 = NULL;
    node *head2 = NULL;

    int size1;
    cin >> size1;

    for (int i=1; i<=size1; i++)
    {
        int item;
        cin >> item;
        create_list(head1, item);
    }

    int size2;
    cin >> size2;

    for (int i=1; i<=size2; i++)
    {
        int item;
        cin >> item;
        create_list(head2, item);
    }

    node *new_head = merge_sorted_list(head1, head2);
    //node *rec_head = merge_recursive(head1, head2);

    display_list(new_head);
    //display_list(rec_head);
}