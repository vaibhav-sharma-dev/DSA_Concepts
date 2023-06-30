#include <iostream>
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
    while(temp->next!=NULL)
        temp = temp->next;

    temp->next = n;
}

void delete_node(node * &head, int key)
{
    if (head==NULL)
        return;

    if (key==1 || head->next==NULL)
    {
        node *delete_head = head;
        head = head->next;

        delete delete_head;
        return;
    }

    node *temp = head;
    
    while (temp->next->data!=key)
        temp = temp->next;

    node * to_delete = temp->next;
    temp->next = temp->next->next;

    delete to_delete;
}

int main()
{
    node * head = NULL;
    int size;
    cin >> size;

    for (int i=1; i<=size; i++)
        create_list(head, i);


    int key;
    cin >> key;

    delete_node(head, key);

    while (head!=NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}